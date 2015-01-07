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

#include "nauths/mcl/spaces/cmy.hh"
#include "nauths/mcl/convert.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace mcl
{

  namespace
  {


    // helpers

    XYZ srgb_to_xyz(const RGB& from)
    {
      RGB tmp = from;
      XYZ res;

      tmp.r() = tmp.r() > 0.04045 ? std::pow((tmp.r() + 0.055) / 1.055, 2.4) : tmp.r() / 12.92;
      tmp.g() = tmp.g() > 0.04045 ? std::pow((tmp.g() + 0.055) / 1.055, 2.4) : tmp.g() / 12.92;
      tmp.b() = tmp.b() > 0.04045 ? std::pow((tmp.b() + 0.055) / 1.055, 2.4) : tmp.b() / 12.92;

      tmp.r() *= 100.0;
      tmp.g() *= 100.0;
      tmp.b() *= 100.0;

      res.x() = tmp.r() * 0.4124564 + tmp.g() * 0.3575761 + tmp.b() * 0.1804375;
      res.y() = tmp.r() * 0.2126729 + tmp.g() * 0.7151522 + tmp.b() * 0.0721750;
      res.z() = tmp.r() * 0.0193339 + tmp.g() * 0.1191920 + tmp.b() * 0.9503041;

      res.a()  = from.a();

      return res;
    }

    RGB xyz_to_srgb(const XYZ& from)
    {
      XYZ tmp = from;
      RGB res;

      tmp.x() /= 100.0;
      tmp.y() /= 100.0;
      tmp.z() /= 100.0;

      res.r() = tmp.x() *  3.2404542 + tmp.y() * -1.5371385 + tmp.z() * -0.4985314;
      res.g() = tmp.x() * -0.9692660 + tmp.y() *  1.8760108 + tmp.z() *  0.0415560;
      res.b() = tmp.x() *  0.0556434 + tmp.y() * -0.2040259 + tmp.z() *  1.0572252;

      res.r() = res.r() > 0.0031308 ? 1.055 * std::pow(res.r(), (1.0 / 2.4)) - 0.055 : 12.92 * res.r();
      res.g() = res.g() > 0.0031308 ? 1.055 * std::pow(res.g(), (1.0 / 2.4)) - 0.055 : 12.92 * res.g();
      res.b() = res.b() > 0.0031308 ? 1.055 * std::pow(res.b(), (1.0 / 2.4)) - 0.055 : 12.92 * res.b();

      res.a() = from.a();

      return res;
    }

    XYZ cmyk_to_xyz(const CMYK& from)
    {
      const CMY& tmp = to<CMY>(from);
      return srgb_to_xyz(RGB(1.0 - tmp.c(), 1.0 - tmp.m(), 1.0 - tmp.y(), tmp.a()));
    }

    CMYK xyz_to_cmyk(const XYZ& from)
    {
      const RGB& tmp = xyz_to_srgb(from);
      return to<CMYK>(CMY(1.0 - tmp.r(), 1.0 - tmp.g(), 1.0 - tmp.b(), tmp.a()));
    }


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  Environment::Environment(const RGBProfile& r, const CMYKProfile& c, const WhitePoint& wp)
    : wp_(wp), rgb_(r), cmyk_(c)
  {
  }



  // constants

  const Environment::WhitePoint  Environment::D65       = WhitePoint(95.047, 100.000, 108.883);
  const Environment::RGBProfile  Environment::SRGB      = RGBProfile (srgb_to_xyz, xyz_to_srgb);
  const Environment::CMYKProfile Environment::SRGB_CMYK = CMYKProfile(cmyk_to_xyz, xyz_to_cmyk);

  Environment                    Environment::DEFAULT   = Environment(SRGB, SRGB_CMYK, D65);


}
