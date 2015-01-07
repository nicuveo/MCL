//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CMYK_HXX_
# define MCL_CMYK_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/cmyk.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // modifiers

  inline CMYK
  CMYK::clamped() const
  {
    CMYK r = *this;
    r.clamp();
    return r;
  }

  inline void
  CMYK::clamp()
  {
    *this = {
      il::clamp(c(), 0.0, 1.0),
      il::clamp(m(), 0.0, 1.0),
      il::clamp(y(), 0.0, 1.0),
      il::clamp(k(), 0.0, 1.0),
      il::clamp(a(), 0.0, 1.0)
    };
  }


  inline CMYK
  CMYK::rounded(double to) const
  {
    CMYK r = *this;
    r.round(to);
    return r;
  }

  inline void
  CMYK::round(double to)
  {
    *this = {
      il::round(c(), to),
      il::round(m(), to),
      il::round(y(), to),
      il::round(k(), to),
      il::round(a(), to)
    };
  }


}



#endif /* !MCL_CMYKK_HXX_ */
