//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_XYZ_HXX_
# define MCL_XYZ_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/xyz.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline XYZ
  XYZ::clamped() const
  {
    XYZ r = *this;
    r.clamp();
    return r;
  }

  inline void
  XYZ::clamp()
  {
    *this = {
      il::clamp(x(),    0.0, 100.0),
      il::clamp(y(), -120.0, 120.0),
      il::clamp(z(), -120.0, 120.0),
      il::clamp(a(),    0.0,   1.0)
    };
  }


  inline XYZ
  XYZ::rounded(double to) const
  {
    XYZ r = *this;
    r.round(to);
    return r;
  }

  inline void
  XYZ::round(double to)
  {
    *this = {
      il::round(x(), to),
      il::round(y(), to),
      il::round(z(), to),
      il::round(a(), to)
    };
  }


}



#endif /* !MCL_XYZ_HXX_ */
