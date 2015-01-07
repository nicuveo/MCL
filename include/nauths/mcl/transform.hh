//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_TRANSFORM_HH_
# define MCL_TRANSFORM_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/misc/endomorphism.hh"
# include "nauths/mcl/color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  // transform functions

  template <typename T> T greyed(T const&);
  template <typename T> T grayed(T const&);
  template <typename T> T greyed(T const&, const Environment&);
  template <typename T> T grayed(T const&, const Environment&);

  template <typename T> T to_opaque(T const&);
  template <typename T> T to_transparent(T const&);
  template <typename T> T with_alpha(T const&, double);

  template <typename T> T with_lightness(T const&, double);
  template <typename T> T with_lightness(T const&, double, const Environment&);

  template <typename T> T rounded(T const&, double to = MCL_DEFAULT_ROUND);
  template <typename T> T clamped(T const&);


  // endomorphism functions

  template <typename T> Endomorphism<T> grey();
  template <typename T> Endomorphism<T> gray();
  template <typename T> Endomorphism<T> grey(const Environment&);
  template <typename T> Endomorphism<T> gray(const Environment&);

  template <typename T> Endomorphism<T> opaque();
  template <typename T> Endomorphism<T> transparent();
  template <typename T> Endomorphism<T> alpha(double);

  template <typename T> Endomorphism<T> lightness(double);
  template <typename T> Endomorphism<T> lightness(double, const Environment&);

  template <typename T> Endomorphism<T> round(double to = MCL_DEFAULT_ROUND);
  template <typename T> Endomorphism<T> clamp();


  // color endomorphism functions

  template <typename T> Endomorphism<Color> to();
  template <typename T> Endomorphism<Color> to(const Environment&);
                        Endomorphism<Color> to(SpaceType s);
                        Endomorphism<Color> to(SpaceType s, const Environment&);
}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/transform.hxx"



#endif /* !MCL_TRANSFORM_HH_ */
