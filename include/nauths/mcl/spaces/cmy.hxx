//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CMY_HXX_
# define MCL_CMY_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/cmy.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline CMY
  CMY::clamped() const
  {
    CMY r = *this;
    r.clamp();
    return r;
  }

  inline void
  CMY::clamp()
  {
    *this = {
      il::clamp(c(), 0.0, 1.0),
      il::clamp(m(), 0.0, 1.0),
      il::clamp(y(), 0.0, 1.0),
      il::clamp(a(), 0.0, 1.0)
    };
  }


  inline CMY
  CMY::rounded(double to) const
  {
    CMY r = *this;
    r.round(to);
    return r;
  }

  inline void
  CMY::round(double to)
  {
    *this = {
      il::round(c(), to),
      il::round(m(), to),
      il::round(y(), to),
      il::round(a(), to)
    };
  }


}



#endif /* !MCL_CMY_HXX_ */
