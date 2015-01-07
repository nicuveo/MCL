//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_INTERPOLATION_HXX_
# define MCL_INTERPOLATION_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/interpolation.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // interpolation functions

  template <typename T>
  inline T
  interpolate(T const& c1, T const& c2, double f)
  {
    return interpolate<T>(c1, c2, f, Environment::DEFAULT);
  }


  template <typename T>
  inline Color
  interpolate(const Color& c1, const Color& c2, double f)
  {
    return interpolate<T>(c1, c2, f, Environment::DEFAULT);
  }

  inline Color
  interpolate(SpaceType s, const Color& c1, const Color& c2, double f)
  {
    return interpolate(s, c1, c2, f, Environment::DEFAULT);
  }

  template <typename T>
  inline Color
  interpolate(const Color& c1, const Color& c2, double f, const Environment& e)
  {
    return interpolate(c1.get<T>(e), c2.get<T>(e), f);
  }



  // interpolation binders

  template <typename T>
  inline Interpolation<Color>
  interpolation()
  {
    return interpolation<T>(Environment::DEFAULT);
  }

  inline Interpolation<Color>
  interpolation(SpaceType s)
  {
    return interpolation(s, Environment::DEFAULT);
  }

  template <typename T>
  inline Interpolation<Color>
  interpolation(const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<Color (*)(const Color&,
                                           const Color&,
                                           double,
                                           const Environment&)>(interpolate<T>), _1, _2, _3, e);
  }

  inline Interpolation<Color>
  interpolation(SpaceType s, const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<Color (*)(SpaceType s,
                                           const Color&,
                                           const Color&,
                                           double,
                                           const Environment&)>(interpolate), s, _1, _2, _3, e);
  }


}



#endif /* !MCL_INTERPOLATION_HXX_ */
