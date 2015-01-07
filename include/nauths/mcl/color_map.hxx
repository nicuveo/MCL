//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_COLOR_MAP_HXX_
# define MCL_COLOR_MAP_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color_map.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  inline ColorMap
  ColorMap::fallback(const InterpolationFunction& i, const Color& c)
  {
    using namespace std::placeholders;
    const auto& f = std::bind(d_fallback, _1, c);
    return ColorMap(i, f, f);
  }

  inline ColorMap
  ColorMap::strict(const InterpolationFunction& i)
  {
    return ColorMap(i, d_strict, d_strict);
  }

  inline ColorMap
  ColorMap::clamp(const InterpolationFunction& i)
  {
    return ColorMap(i, d_clamp_under, d_clamp_over);
  }



  // getters

  inline ColorMap::Key
  ColorMap::min() const
  {
    return begin()->first;
  }

  inline ColorMap::Key
  ColorMap::max() const
  {
    return rbegin()->first;
  }

  inline const ColorMap::Value&
  ColorMap::min_value() const
  {
    return begin()->second;
  }

  inline const ColorMap::Value&
  ColorMap::max_value() const
  {
    return rbegin()->second;
  }


}



#endif /* !MCL_COLOR_MAP_HXX_ */
