//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_INTERPOLATION_HH_
# define MCL_INTERPOLATION_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_DECL_itp(R, D, S)                                       \
  template <>                                                        \
  S interpolate(S const&, S const&, double);                         \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  // types

  template <typename T>
  using Interpolation = std::function<T (T const&, T const&, double)>;


  // interpolation functions

  template <typename T>
  T interpolate(T const&, T const&, double);

  BOOST_PP_SEQ_FOR_EACH(MCL_DECL_itp, _, MCL_SPACES)

  template <typename T>
  Color interpolate(             const Color&, const Color&, double);
  Color interpolate(SpaceType s, const Color&, const Color&, double);
  template <typename T>
  Color interpolate(             const Color&, const Color&, double, const Environment&);
  Color interpolate(SpaceType s, const Color&, const Color&, double, const Environment&);


  // interpolation binders

  template <typename T>
  Interpolation<Color> interpolation();
  Interpolation<Color> interpolation(SpaceType);
  template <typename T>
  Interpolation<Color> interpolation(const Environment&);
  Interpolation<Color> interpolation(SpaceType, const Environment&);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/interpolation.hxx"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_DECL_itp



#endif /* !MCL_INTERPOLATION_HH_ */
