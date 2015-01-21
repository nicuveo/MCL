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

#include <cmath>
#include "nauths/mcl/convert.hh"
#include "nauths/mcl/color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace mcl
{

  namespace
  {


    // constants

    constexpr double PI = 3.141592653589793238462643383279502884L;

    constexpr double D2R = PI / 180.0;
    constexpr double R2D = 180.0 / PI;

    constexpr double EPSILON =   216.0 / 24389.0;
    constexpr double KAPPA   = 24389.0 /    27.0;



    // helpers

    template <typename T>
    inline T max3(T v1, T v2, T v3)
    {
      return v2 > v3
        ? (v1 > v2 ? v1 : v2)
        : (v1 > v3 ? v1 : v3);
    }

    template <typename T>
    inline T min3(T v1, T v2, T v3)
    {
      return v2 < v3
        ? (v1 < v2 ? v1 : v2)
        : (v1 < v3 ? v1 : v3);
    }

    inline double d2r(double d)
    {
      return d * D2R;
    }

    inline double r2d(double d)
    {
      return d * R2D;
    }


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // CMY

  template <>
  CMY
  to(const CMYK& c, const Environment&)
  {
    double t = 1.0 - c.k();

    return CMY(c.c() * t + c.k(),
               c.m() * t + c.k(),
               c.y() * t + c.k(),
               c.a());
  }

  template <>
  CMYK
  to(const CMY& c, const Environment&)
  {
    double k = min3(c.c(), c.m(), c.y());
    double t = 1.0 - k;

    if (t <= 0)
      return CMYK(0.0, 0.0, 0.0, 1.0);

    return CMYK((c.c() - k) / t,
                (c.m() - k) / t,
                (c.y() - k) / t,
                k,
                c.a());
  }



  // HSL

  template <>
  HSL
  to(const RGB& c, const Environment&)
  {
    const double u = max3(c.r(), c.g(), c.b());
    const double m = min3(c.r(), c.g(), c.b());
    const double d = u - m;
    const double l = (u + m) / 2.0;
    double h = 0;
    double s = 0;

    if (d != 0)
    {
      s = d / (1.0 - std::abs(2.0 * l - 1.0));

           if (c.r() == u) h =   0.0 + 60.0 * (c.g() - c.b()) / d;
      else if (c.g() == u) h = 120.0 + 60.0 * (c.b() - c.r()) / d;
      else                 h = 240.0 + 60.0 * (c.r() - c.g()) / d;

      h = il::d_mod(h);
    }

    return HSL(h, s, l, c.a());
  }

  template <>
  RGB
  to(const HSL& f, const Environment&)
  {
    double c = f.s() * (1.0 - std::abs(2.0 * f.l() - 1.0));
    double m = f.l() - c / 2.0;
    double k = f.h() / 60.0;
    int    i = int(k) % 6;
    double x = c * (1.0 - std::abs(std::fmod(k, 2.0) - 1.0));

    c += m;
    x += m;

    switch (i)
    {
      case 0: return RGB(c, x, m, f.a());
      case 1: return RGB(x, c, m, f.a());
      case 2: return RGB(m, c, x, f.a());
      case 3: return RGB(m, x, c, f.a());
      case 4: return RGB(x, m, c, f.a());
      case 5: return RGB(c, m, x, f.a());
    }

    return RGB();
  }



  // HSV

  template <>
  HSV
  to(const RGB& c, const Environment&)
  {
    const double v = max3(c.r(), c.g(), c.b());
    const double l = min3(c.r(), c.g(), c.b());
    const double d = v - l;
    double h = 0;
    double s = 0;

    if (v != 0)
      s = d / v;

    if (d != 0)
    {      if (c.r() == v) h =   0.0 + 60.0 * (c.g() - c.b()) / d;
      else if (c.g() == v) h = 120.0 + 60.0 * (c.b() - c.r()) / d;
      else                 h = 240.0 + 60.0 * (c.r() - c.g()) / d;

      h = il::d_mod(h);
    }

    return HSV(h, s, v, c.a());
  }

  template <>
  RGB
  to(const HSV& f, const Environment&)
  {
    double c = f.s() * f.v();
    double m = f.v() - c;
    double k = f.h() / 60.0;
    int    i = int(k) % 6;
    double x = c * (1.0 - std::abs(std::fmod(k, 2.0) - 1.0));

    c += m;
    x += m;

    switch (i)
    {
      case 0: return RGB(c, x, m, f.a());
      case 1: return RGB(x, c, m, f.a());
      case 2: return RGB(m, c, x, f.a());
      case 3: return RGB(m, x, c, f.a());
      case 4: return RGB(x, m, c, f.a());
      case 5: return RGB(c, m, x, f.a());
    }

    return RGB();
  }



  // LAB

  template <>
  LAB
  to(const XYZ& c, const Environment& e)
  {
    const XYZ& wp = e.white_point();
    const double x2 = c.x() / wp.x();
    const double y2 = c.y() / wp.y();
    const double z2 = c.z() / wp.z();
    const double x3 = x2 > EPSILON ? std::cbrt(x2) : (KAPPA * x2 + 16.0) / 116.0;
    const double y3 = y2 > EPSILON ? std::cbrt(y2) : (KAPPA * y2 + 16.0) / 116.0;
    const double z3 = z2 > EPSILON ? std::cbrt(z2) : (KAPPA * z2 + 16.0) / 116.0;

    return LAB(116 * y3 - 16.0, 500.0 * (x3 - y3), 200.0 * (y3 - z3), c.a());
  }

  template <>
  XYZ
  to(const LAB& c, const Environment& e)
  {
    const XYZ& wp = e.white_point();
    const double y1 = (c.l() + 16.0) / 116.0;
    const double x1 = c.a() / 500.0 + y1;
    const double z1 = y1 - c.b() / 200.0;
    const double x2 = std::pow(x1, 3.0) > EPSILON ? std::pow(x1, 3.0) : (116.0 * x1 - 16.0) / KAPPA;
    const double y2 = std::pow(y1, 3.0) > EPSILON ? std::pow(y1, 3.0) : (116.0 * y1 - 16.0) / KAPPA;
    const double z2 = std::pow(z1, 3.0) > EPSILON ? std::pow(z1, 3.0) : (116.0 * z1 - 16.0) / KAPPA;

    return XYZ(wp.x() * x2, wp.y() * y2, wp.z() * z2, c.alpha());
  }



  // RGBub

  template <>
  RGBub
  to(const RGB& c, const Environment&)
  {
    return RGBub(std::round(il::clamp(c.r(), 0.0, 1.0) * RGBub::max()),
                 std::round(il::clamp(c.g(), 0.0, 1.0) * RGBub::max()),
                 std::round(il::clamp(c.b(), 0.0, 1.0) * RGBub::max()),
                 std::round(il::clamp(c.a(), 0.0, 1.0) * RGBub::max()));
  }

  template <>
  RGB
  to(const RGBub& c, const Environment&)
  {
    return RGB(c.r() / double(RGBub::max()),
               c.g() / double(RGBub::max()),
               c.b() / double(RGBub::max()),
               c.a() / double(RGBub::max()));
  }



  // RGBf

  template <>
  RGBf
  to(const RGB& c, const Environment&)
  {
    return RGBf(float(c.r()),
                float(c.g()),
                float(c.b()),
                float(c.a()));
  }

  template <>
  RGB
  to(const RGBf& c, const Environment&)
  {
    return RGB(double(c.r()),
               double(c.g()),
               double(c.b()),
               double(c.a()));
  }



  // special cases

  template <>
  HSL
  to(const HSV& c, const Environment&)
  {
    float x = (2 - c.s()) * c.v();
    float y = c.s() * c.v();
    float z = x <= 1.f ? x : 2.f - x;

    return HSL(c.h(), y / z, x / 2.f, c.a());
  }

  template <>
  HSV
  to(const HSL& c, const Environment&)
  {
    float x = c.l() * 2;
    float y = c.s() * (x <= 1.f ? x : 2.f - x);

    return HSV(c.h(), (y + y) / (x + y), (x + y) / 2.f, c.a());
  }

  template <>
  LAB
  to(const LCH& c, const Environment&)
  {
    return LAB(c.l(),
               c.c() * std::cos(d2r(c.h())),
               c.c() * std::sin(d2r(c.h())),
               c.a());
  }

  template <>
  LCH
  to(const LAB& c, const Environment&)
  {
    return LCH(c.l(),
               std::sqrt(std::pow(c.a(), 2.0) + std::pow(c.b(), 2.0)),
               il::d_mod(r2d(std::atan2(c.b(), c.a()))),
               c.alpha());
  }

  template <>
  RGBf
  to(const RGBub& c, const Environment&)
  {
    return RGBf(c.r() / float(RGBub::max()),
                c.g() / float(RGBub::max()),
                c.b() / float(RGBub::max()),
                c.a() / float(RGBub::max()));
  }

  template <>
  RGBub
  to(const RGBf& c, const Environment&)
  {
    return RGBub(std::round(c.r() * RGBub::max()),
                 std::round(c.g() * RGBub::max()),
                 std::round(c.b() * RGBub::max()),
                 std::round(c.a() * RGBub::max()));
  }


}
