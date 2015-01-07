//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_HSV_HXX_
# define MCL_HSV_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/hsv.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline HSV
  HSV::clamped() const
  {
    HSV r = *this;
    r.clamp();
    return r;
  }

  inline void
  HSV::clamp()
  {
    *this = {
      il::d_mod(h()),
      il::clamp(s(), 0.0, 1.0),
      il::clamp(v(), 0.0, 1.0),
      il::clamp(a(), 0.0, 1.0)
    };
  }


  inline HSV
  HSV::rounded(double to) const
  {
    HSV r = *this;
    r.round(to);
    return r;
  }

  inline void
  HSV::round(double to)
  {
    *this = {
      il::round(h(), to),
      il::round(s(), to),
      il::round(v(), to),
      il::round(a(), to)
    };
  }


}



#endif /* !MCL_HSV_HXX_ */
