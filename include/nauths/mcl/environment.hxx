//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_ENVIRONMENT_HXX_
# define MCL_ENVIRONMENT_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/environment.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // getters

  inline const Environment::WhitePoint&
  Environment::white_point() const
  {
    return wp_;
  }

  inline const Environment::RGBProfile&
  Environment::rgb_profile() const
  {
    return rgb_;
  }

  inline const Environment::CMYKProfile&
  Environment::cmyk_profile() const
  {
    return cmyk_;
  }


}



#endif /* !MCL_ENVIRONMENT_HXX_ */
