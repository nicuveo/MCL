//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_COLOR_HH_
# define MCL_COLOR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/variant.hpp>
# include "nauths/mcl/environment.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macro

# define MCL_DECL_constructor(R, D, S) Color(const S&);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  namespace il
  {

    // types

    typedef boost::variant<MCL_SPACES_ENUM> ColorData;

  }


  class Color : public il::ColorData
  {
    public:
      // types

      typedef il::ColorData Data;


      // constructors

      Color();

      BOOST_PP_SEQ_FOR_EACH(MCL_DECL_constructor, _, MCL_SPACES)


      // operators

      friend bool operator==(const Color& c1, const Color& c2);
      friend bool operator!=(const Color& c1, const Color& c2);


      // getters

            Data& data();
      const Data& data() const;

      SpaceType type() const;

      double alpha() const;
      double lightness() const;

      template <typename T> const T& get();
      template <typename T> const T& get(const Environment&);
      template <typename T>       T  get()                   const;
      template <typename T>       T  get(const Environment&) const;


      template <typename T> Color& to();
      template <typename T> Color& to(           const Environment&);
      template <typename T> Color  to()                              const;
      template <typename T> Color  to(           const Environment&) const;
                            Color& to(SpaceType);
                            Color& to(SpaceType, const Environment&);
                            Color  to(SpaceType)                     const;
                            Color  to(SpaceType, const Environment&) const;


      // modifiers

      void gray();
      void grey();
      void gray(const Environment&);
      void grey(const Environment&);
      Color grayed() const;
      Color greyed() const;
      Color grayed(const Environment&) const;
      Color greyed(const Environment&) const;
      template <typename T> static T grayed(T const&);
      template <typename T> static T greyed(T const&);
      template <typename T> static T grayed(T const&, const Environment&);
      template <typename T> static T greyed(T const&, const Environment&);

      void opaque();
      void transparent();
      void alpha(double);
      Color to_opaque() const;
      Color to_transparent() const;
      Color with_alpha(double) const;
      template <typename T> static T to_opaque(T const&);
      template <typename T> static T to_transparent(T const&);
      template <typename T> static T with_alpha(T const&, double);

      void lightness(double);
      void lightness(double, const Environment&);
      Color with_lightness(double) const;
      Color with_lightness(double, const Environment&) const;
      template <typename T> static T with_lightness(T const&, double);
      template <typename T> static T with_lightness(T const&, double, const Environment&);

      void clamp();
      void round(double to = MCL_DEFAULT_ROUND);
      Color clamped() const;
      Color rounded(double to = MCL_DEFAULT_ROUND) const;
      template <typename T> static T clamped(T const&);
      template <typename T> static T rounded(T const&, double to = MCL_DEFAULT_ROUND);
  };


  // operators

  MCL_IL_DECL_OPS(Color);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macro

# undef MCL_DECL_constructor



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color.hxx"



#endif /* !MCL_COLOR_HH_ */
