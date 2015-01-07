//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CONVERT_HXX_
# define MCL_CONVERT_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color.hh"
# include "nauths/mcl/convert.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_IMPL_id(R, D, SPACE)               \
  template <>                                   \
  inline SPACE                                  \
  to(const SPACE& c)                            \
  {                                             \
    return c;                                   \
  }                                             \
                                                \
  template <>                                   \
  inline SPACE                                  \
  to(const SPACE& c, const Environment&)        \
  {                                             \
    return c;                                   \
  }                                             \

# define MCL_IMPL_wrapper(R, D, SPACE)          \
  template <>                                   \
  inline SPACE                                  \
  to(const Color& c)                            \
  {                                             \
    return c.get<SPACE>();                      \
  }                                             \
                                                \
  template <>                                   \
  inline Color                                  \
  to(const SPACE& c)                            \
  {                                             \
    return c;                                   \
  }                                             \
                                                \
  template <>                                   \
  inline SPACE                                  \
  to(const Color& c, const Environment& e)      \
  {                                             \
    return c.get<SPACE>(e);                     \
  }                                             \
                                                \
  template <>                                   \
  inline Color                                  \
  to(const SPACE& c, const Environment&)        \
  {                                             \
    return c;                                   \
  }                                             \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // id

  BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_id, _, MCL_SPACES)


  // color wrapper

  BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_wrapper, _, MCL_SPACES)



  // reference

  template <>
  inline CMYK
  to(const RGB& c, const Environment& e)
  {
    const auto& p1 = e.rgb_profile();
    const auto& p2 = e.cmyk_profile();
    return p2(p1(c));
  }

  template <>
  inline CMYK
  to(const XYZ& c, const Environment& e)
  {
    const auto& p = e.cmyk_profile();
    return p(c);
  }

  template <>
  inline RGB
  to(const XYZ& c, const Environment& e)
  {
    const auto& p = e.rgb_profile();
    return p(c);
  }

  template <>
  inline RGB
  to(const CMYK& c, const Environment& e)
  {
    const auto& p1 = e.rgb_profile();
    const auto& p2 = e.cmyk_profile();
    return p1(p2(c));
  }

  template <>
  inline XYZ
  to(const CMYK& c, const Environment& e)
  {
    const auto& p = e.cmyk_profile();
    return p(c);
  }

  template <>
  inline XYZ
  to(const RGB& c, const Environment& e)
  {
    const auto& p = e.rgb_profile();
    return p(c);
  }



  // LCH

  template <>
  inline LCH
  to(const XYZ& c, const Environment& e)
  {
    return to<LCH>(to<LAB>(c, e), e);
  }

  template <>
  inline XYZ
  to(const LCH& c, const Environment& e)
  {
    return to<XYZ>(to<LAB>(c, e), e);
  }



  // general case

  template <typename T, typename F>
  inline T
  to(const F& c)
  {
    return to<T>(c, Environment::DEFAULT);
  }

  template <typename T, typename F>
  inline T
  to(const F& c, const Environment& e)
  {
    typedef typename F::Reference FR;
    typedef typename T::Reference TR;

    return to<T>(to<TR>(to<FR>(c, e), e), e);
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_IMPL_id
# undef MCL_IMPL_wrapper



#endif /* !MCL_CONVERT_HXX_ */
