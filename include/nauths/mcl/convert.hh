//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CONVERT_HH_
# define MCL_CONVERT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/environment.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_DECL_ref(S1, S2)                              \
  template <> S1 to(const S2& c, const Environment&);      \
  template <> S2 to(const S1& c, const Environment&);      \

# define MCL_DECL_ref1(R, D, S) MCL_DECL_ref(S, S::Reference)
# define MCL_DECL_ref2(R,    S) MCL_DECL_ref(BOOST_PP_SEQ_ELEM(0, S)::Reference, \
                                             BOOST_PP_SEQ_ELEM(1, S)::Reference) \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  // general declaration

  template <typename T, typename F>
  T to(const F&);

  template <typename T, typename F>
  T to(const F&, const Environment&);


  // reference declaration

  BOOST_PP_SEQ_FOR_EACH(MCL_DECL_ref1, _, MCL_SPACES)
  BOOST_PP_SEQ_FOR_EACH_PRODUCT(MCL_DECL_ref2, (MCL_SPACES) (MCL_SPACES))

  template <> CMYK to(const RGB&,    const Environment&);
  template <> CMYK to(const XYZ&,    const Environment&);
  template <> RGB  to(const XYZ&,    const Environment&);
  template <> RGB  to(const CMYK&,   const Environment&);
  template <> XYZ  to(const CMYK&,   const Environment&);
  template <> XYZ  to(const RGB&,    const Environment&);


  // special cases

  template <> HSL   to(const HSV&,   const Environment&);
  template <> HSV   to(const HSL&,   const Environment&);
  template <> LAB   to(const LCH&,   const Environment&);
  template <> LCH   to(const LAB&,   const Environment&);
  template <> RGBf  to(const RGBub&, const Environment&);
  template <> RGBub to(const RGBf&,  const Environment&);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_DECL_ref
# undef MCL_DECL_ref1
# undef MCL_DECL_ref2



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/convert.hxx"



#endif /* !MCL_CONVERT_HH_ */
