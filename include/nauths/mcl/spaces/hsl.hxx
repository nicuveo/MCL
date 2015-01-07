//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_HSL_HXX_
# define MCL_HSL_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/hsl.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline HSL
  HSL::clamped() const
  {
    HSL r = *this;
    r.clamp();
    return r;
  }

  inline void
  HSL::clamp()
  {
    *this = {
      il::d_mod(h()),
      il::clamp(s(), 0.0, 1.0),
      il::clamp(l(), 0.0, 1.0),
      il::clamp(a(), 0.0, 1.0)
    };
  }


  inline HSL
  HSL::rounded(double to) const
  {
    HSL r = *this;
    r.round(to);
    return r;
  }

  inline void
  HSL::round(double to)
  {
    *this = {
      il::round(h(), to),
      il::round(s(), to),
      il::round(l(), to),
      il::round(a(), to)
    };
  }


}



#endif /* !MCL_HSL_HXX_ */
