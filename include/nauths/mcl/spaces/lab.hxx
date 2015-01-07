//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_LAB_HXX_
# define MCL_LAB_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/lab.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline LAB
  LAB::clamped() const
  {
    LAB r = *this;
    r.clamp();
    return r;
  }

  inline void
  LAB::clamp()
  {
    *this = {
      il::clamp(l(),        0.0, 100.0),
      il::clamp(a(),     -120.0, 120.0),
      il::clamp(b(),     -120.0, 120.0),
      il::clamp(alpha(),    0.0,   1.0)
    };
  }


  inline LAB
  LAB::rounded(double to) const
  {
    LAB r = *this;
    r.round(to);
    return r;
  }

  inline void
  LAB::round(double to)
  {
    *this = {
      il::round(l(),     to),
      il::round(a(),     to),
      il::round(b(),     to),
      il::round(alpha(), to)
    };
  }


}



#endif /* !MCL_LAB_HXX_ */
