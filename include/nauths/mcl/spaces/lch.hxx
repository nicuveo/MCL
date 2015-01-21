//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_LCH_HXX_
# define MCL_LCH_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/lch.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline LCH
  LCH::clamped() const
  {
    LCH r = *this;
    r.clamp();
    return r;
  }

  inline void
  LCH::clamp()
  {
    *this = {
      il::clamp(l(), 0.0, 100.0),
      il::clamp(c(), 0.0, 120.0),
      il::d_mod(h()),
      il::clamp(a(), 0.0,   1.0)
    };
  }


  inline LCH
  LCH::rounded(double to) const
  {
    LCH r = *this;
    r.round(to);
    return r;
  }

  inline void
  LCH::round(double to)
  {
    *this = {
      il::round(l(), to),
      il::round(c(), to),
      il::round(h(), to),
      il::round(a(), to)
    };
  }


}



#endif /* !MCL_LCH_HXX_ */
