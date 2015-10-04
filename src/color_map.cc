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

#include "nauths/mcl/color_map.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  ColorMap::ColorMap(const InterpolationFunction& i,
                     const DomainFunction& u,
                     const DomainFunction& o)
    : i_(i), u_(u), o_(o)
  {
  }



  // getters

  ColorMap::Value
  ColorMap::get(Key key) const
  {
    auto it1 = lower_bound(key);

    if (it1 == end())      return o_(*this);
    if (key == it1->first) return it1->second;
    if (it1 == begin())    return u_(*this);

    auto it2 = it1--;

    return i_(it1->second,
              it2->second,
              il::clamp((key - it1->first) / (it2->first - it1->first),
                        0.0,
                        1.0));
  }

  ColorMap::Value
  ColorMap::compute(Key k)
  {
    auto it = find(k);
    if (it != end())
      return it->second;
    auto c = get(k);
    (*this)[k] = c;
    return c;
  }



  // helpers

  Color
  ColorMap::d_fallback(const ColorMap&, const Color& c)
  {
    return c;
  }

  Color
  ColorMap::d_clamp_under(const ColorMap& c)
  {
    return c.min_value();
  }

  Color
  ColorMap::d_clamp_over(const ColorMap& c)
  {
    return c.max_value();
  }

  Color
  ColorMap::d_strict(const ColorMap&)
  {
    throw std::domain_error("mcl::ColorMap::strict: key out of bounds");
  }


}
