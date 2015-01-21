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

#include "nauths/mcl/distance.hh"



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



    // helpers

    inline constexpr double d2r(double d)
    {
      return d * D2R;
    }

    inline double r2d(double d)
    {
      return il::d_mod(d * R2D);
    }

    inline constexpr double sqr(double x)
    {
      return x * x;
    }

    inline double tmp1(double x)
    {
      return std::sqrt(std::pow(x, 7.0) / (std::pow(x, 7.0) + 6103515625)); // 25^7
    }

    inline double tmp2(double x1, double x2)
    {
      return std::abs(x1 - x2) <= 180.0
        ? (x2 - x1)
        : (x2 <= x1
           ? (x2 - x1 + 360.0)
           : (x2 - x1 - 360.0));
    }

    inline double tmp3(double x1, double x2)
    {
      return 0.5 * (x1 + x2 + (std::abs(x2 - x1) <= 180.0
                               ? 0.0
                               : (x1 + x2 < 360.0
                                  ?  360.0
                                  : -360.0)));
    }

    inline double tmp4(double x)
    {
      return sqr(x - 50.0) / std::sqrt(20.0 + sqr(x - 50.0));
    }

    inline double tmp5(double x)
    {
      return d2r(60.0 * std::exp(-sqr((x - 275) / 25)));
    }


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constants

  const DistanceFunction CIE_1976 = &cie_1976<Color, Color>;
  const DistanceFunction CIE_1994 = &cie_1994<Color, Color>;
  const DistanceFunction CIE_2000 = &cie_2000<Color, Color>;



  // functions

  double
  cie_1976(LAB const& x1, LAB const& x2)
  {
    const double dl = x2.l() - x1.l();
    const double da = x2.a() - x1.a();
    const double db = x2.b() - x1.b();

    return std::sqrt(dl * dl + da * da + db * db);
  }

  double
  cie_1994(LAB const& x1, LAB const& x2)
  {
    constexpr double kl = 1.0;
    constexpr double kc = 1.0;
    constexpr double kh = 1.0;
    constexpr double k1 = 0.045;
    constexpr double k2 = 0.015;
    const double c1 = std::hypot(x1.a(), x1.b());
    const double c2 = std::hypot(x2.a(), x2.b());
    const double dl = x1.l() - x2.l();
    const double da = x1.a() - x2.a();
    const double db = x1.b() - x2.b();
    const double dc = c1 - c2;
    const double dh = std::sqrt(da * da + db * db - dc * dc);
    const double sl = 1.0;
    const double sc = 1.0 + k1 * c1;
    const double sh = 1.0 + k2 * c1;

    return std::sqrt(sqr(dl / (kl * sl)) +
                     sqr(dc / (kc * sc)) +
                     sqr(dh / (kh * sh)));
  }

  double
  cie_2000(LAB const& x1, LAB const& x2)
  {
    constexpr double kl = 1.0;
    constexpr double kc = 1.0;
    constexpr double kh = 1.0;
    constexpr double k1 = 0.045;
    constexpr double k2 = 0.015;
    const double c1 = std::hypot(x1.a(), x1.b());
    const double c2 = std::hypot(x2.a(), x2.b());
    const double dl = x2.l() - x1.l();
    const double ml = (x1.l() + x2.l()) / 2.0;
    const double mc = (c1 + c2) / 2.0;
    const double z1 = x1.a() * (1.5 - tmp1(mc) / 2.0);
    const double z2 = x2.a() * (1.5 - tmp1(mc) / 2.0);
    const double v1 = std::hypot(z1, x1.b());
    const double v2 = std::hypot(z2, x2.b());
    const double dv = v2 - v1;
    const double mv = (v1 + v2) / 2.0;
    const double j1 = r2d(std::atan2(x1.b(), z1));
    const double j2 = r2d(std::atan2(x2.b(), z2));
    const double dj = 2.0 * std::sqrt(v1 * v2) * std::sin(d2r(tmp2(j1, j2) / 2.0));
    const double mj = tmp3(j1, j2);
    const double t  = 1.0 - 0.17 * std::cos(d2r(mj       - 30.0))
                          + 0.24 * std::cos(d2r(mj * 2.0       ))
                          + 0.32 * std::cos(d2r(mj * 3.0 +  6.0))
                          - 0.20 * std::cos(d2r(mj * 4.0 - 63.0));
    const double sl = 1 + k2 * tmp4(ml);
    const double sc = 1.0 + k1 * mv;
    const double sh = 1.0 + k2 * mv * t;
    const double rt = -2.0 * tmp1(mv) * std::sin(tmp5(mj));

    return std::sqrt(sqr(dl / (kl * sl)) +
                     sqr(dv / (kc * sc)) +
                     sqr(dj / (kh * sh)) +
                     rt * (dv / (kc * sc)) * dj / (kh * sh));
  }


}
