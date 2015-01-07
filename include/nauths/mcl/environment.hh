//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_ENVIRONMENT_HH_
# define MCL_ENVIRONMENT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/spaces.hh"
# include "nauths/mcl/profile.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  class Environment
  {
    public:
      // types

      typedef XYZ           WhitePoint;
      typedef Profile<RGB>  RGBProfile;
      typedef Profile<CMYK> CMYKProfile;


      // constructors

      Environment(const RGBProfile&, const CMYKProfile&, const WhitePoint&);


      // constants

      static const WhitePoint  D65;
      static const RGBProfile  SRGB;
      static const CMYKProfile SRGB_CMYK;

      static Environment DEFAULT;


      // getters

      const WhitePoint&  white_point()  const;
      const RGBProfile&  rgb_profile()  const;
      const CMYKProfile& cmyk_profile() const;


    private:
      // data

      WhitePoint  wp_;
      RGBProfile  rgb_;
      CMYKProfile cmyk_;
  };

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/environment.hxx"



#endif /* !MCL_ENVIRONMENT_HH_ */
