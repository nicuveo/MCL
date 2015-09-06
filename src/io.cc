//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cstring>
#include <boost/lexical_cast.hpp>
#include <nauths/npl/once.hh>
#include "nauths/mcl/constants.hh"
#include "nauths/mcl/io.hh"
#include "misc/trie.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_IMPL_enum_show(R, D, S) case spaces::S: return BOOST_PP_STRINGIZE(S);

#define MCL_IMPL_helpers(R, D, S)                                               \
  SpaceType BOOST_PP_CAT(_RETURN_, S)(std::istream&)   { return spaces::S;    } \
  Color     BOOST_PP_CAT(_CREATE_, S)(std::istream& x) { return create<S>(x); } \

#define MCL_IMPL_enum_trie(R, D, S)                                             \
  SPACE_TYPES.add(BOOST_PP_STRINGIZE(S), BOOST_PP_CAT(_RETURN_, S));            \
  COLORS.add(     BOOST_PP_STRINGIZE(S), BOOST_PP_CAT(_CREATE_, S));            \

#define MCL_IMPL_name_trie(R, D, C)                                             \
  MCL_IMPL_name_trie_(BOOST_PP_TUPLE_ELEM(5, 0, C))

#define MCL_IMPL_name_trie_(C)                                                  \
  COLORS.add(BOOST_PP_STRINGIZE(C),                                             \
             [](std::istream&) { return colors::C<RGBub>(); });                 \

#define MCL_IMPL_space_show(R, D, S)                                            \
  void                                                                          \
  show(std::ostream& ostr, const S& s)                                          \
  {                                                                             \
    ostr << s.type() << "(" << static_cast<double>(s[0]);                       \
    for (int i = 1; i < s.ALPHA; ++i)                                           \
      ostr << "," << static_cast<double>(s[i]);                                 \
    if (s.alpha() != Max<S>::alpha)                                             \
      ostr << "," << static_cast<double>(s.alpha());                            \
    ostr << ")";                                                                \
  }                                                                             \

#define MCL_EXPECT(E)                                                           \
  if (not (istr >> c) or c != E)                                                \
    erroneous_token<T>(E, c)
#define MCL_EXPECT2(E1, E2)                                                     \
  if (not (istr >> c) or (c != E1 and c != E2))                                 \
    erroneous_token<T>(E1, E2, c)
#define MCL_EXTRACT(INDEX)                                                      \
  if (istr >> n)                                                                \
    res[INDEX] = static_cast<typename T::Value>(n);                             \
  else                                                                          \
    erroneous_number<T>(INDEX)



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace mcl
{

  namespace
  {


    // globals

    il::Trie<SpaceType> SPACE_TYPES;
    il::Trie<Color>     COLORS;



    // traits

    template <typename T>
    struct Max
    {
      public:
        static constexpr double alpha = 1.0;
    };

    template <>
    struct Max<RGBf>
    {
      public:
        static constexpr float alpha = 1.f;
    };

    template <>
    struct Max<RGBub>
    {
      public:
        static constexpr byte alpha = 255;
    };



    // show visitor

    struct ShowVisitor : public boost::static_visitor<>
    {
      public:
        ShowVisitor(std::ostream& ostr)
          : ostr_(ostr)
        {
        }

        template <typename T>
        inline void
        operator()(const T& space) const
        {
          show(ostr_ , space);
        }

      private:
        std::ostream& ostr_;
    };



    // helpers

    bool skip(std::istream& istr)
    {
      char c;
      if (not (istr >> c))
        return false;
      istr.putback(c);
      return true;
    }

    const char* type_repr(SpaceType s)
    {
      switch (s)
      {
        BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_enum_show, _, MCL_SPACES)
      }

      return nullptr;
    }

    template <typename T>
    void erroneous_token(char e, char g)
    {
      throw std::runtime_error("read<" + show(T::type()) + ">: expected '" + e + "', got '" + g + "'");
    }

    template <typename T>
    void erroneous_token(char e1, char e2, char g)
    {
      throw std::runtime_error("read<" + show(T::type()) + ">: expected '" + e1 + "' or '" + e2 + "', got '" + g + "'");
    }

    template <typename T>
    void erroneous_number(int i)
    {
      throw std::runtime_error("read<" + show(T::type()) + ">: failed to extract value at index " + boost::lexical_cast<std::string>(i));
    }

    template <typename T>
    T create(std::istream& istr)
    {
      T res;
      char c;
      double n;

      MCL_EXPECT('(');
      MCL_EXTRACT(0);

      for (typename T::size_type i = 1; i < res.size() - 1; ++i)
      {
        MCL_EXPECT(',');
        MCL_EXTRACT(i);
      }

      MCL_EXPECT2(',', ')');

      if (c == ',')
      {
        MCL_EXTRACT(res.size() - 1);
        MCL_EXPECT(')');
      }

      return res;
    }

    BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_helpers, _, MCL_SPACES)



    // init

    DO_ONCE_AT_LAUNCH()
    {
      BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_enum_trie, _, MCL_SPACES);
      BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_name_trie, _, MCL_COLOR_NAMES);
    }


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // functions

  std::string
  show(SpaceType s)
  {
    return type_repr(s);
  }

  void
  show(std::ostream& ostr, SpaceType s)
  {
    ostr << type_repr(s);
  }


  void
  show(std::ostream& ostr, const Color& c)
  {
    boost::apply_visitor(ShowVisitor(ostr), c);
  }


  template <>
  SpaceType
  read(const std::string& s)
  {
    std::stringstream ss;
    std::streampos pos;
    SpaceType res;

    ss.str(s);
    res = SPACE_TYPES.get(ss);
    pos = ss.tellg();
    if (pos >= 0 and pos < (std::streampos) s.length())
      throw std::runtime_error("read<SpaceType>: unexpected \"" + s.substr(pos) + "\"");

    return res;
  }

  template <>
  Color
  read(const std::string& s)
  {
    std::stringstream ss;
    std::streampos pos;
    Color res;

    ss.str(s);
    res = COLORS.get(ss);
    pos = ss.tellg();
    if (pos >= 0 and pos < (std::streampos) s.length())
      throw std::runtime_error("read<Color>: unexpected \"" + s.substr(pos) + "\"");

    return res;
  }


  template <>
  SpaceType read(std::istream& istr)
  {
    if (not skip(istr))
      return spaces::XYZ;
    return SPACE_TYPES.get(istr);
  }

  template <>
  Color read(std::istream& istr)
  {
    if (not skip(istr))
      return Color();
    return COLORS.get(istr);
  }


  BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_space_show, _, MCL_SPACES)


}
