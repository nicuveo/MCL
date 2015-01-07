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

#include <cstdlib>
#include <iostream>
#include <nauths/mcl/mcl.hh>

#define BOOST_TEST_MODULE color
#include <boost/test/included/unit_test.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

#define CREATE(R, D, S)                         \
  case mcl::spaces::S:                          \
  {                                             \
    mcl::S color;                               \
    fill(color, alpha);                         \
    return color;                               \
  }                                             \


  void init()
  {
    srand(42);
  }

  template <typename T>
  T random()
  {
    return T((rand() % 10000) / 10000.);
  }

  template <>
  mcl::byte random()
  {
    return (rand() >> 8) % 256;
  }

  template <typename T>
  T normalize(double x)
  {
    return x;
  }

  template <>
  mcl::byte normalize(double x)
  {
    return x * 255;
  }

  template <typename T, std::size_t N>
  void fill(std::array<T, N>& color, double alpha, double factor = 1.0)
  {
    for (int i = 0; i < N - 1; ++i)
      color[i] = random<T>() * factor;
    color[N - 1] = normalize<T>(alpha);
  }

  mcl::Color make(mcl::SpaceType s, double alpha)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(CREATE, _, MCL_SPACES)
    }

    return mcl::Color();
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_CASE(color_00)
{
  init();

  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    const double a = random<double>();
    const mcl::Color c1 = make(s1, a);

    switch (s1)
    {
      case MCL_RGBub: BOOST_CHECK_EQUAL(c1.alpha(), (mcl::byte(a * 255)) / 255.0); break;
      case MCL_RGBf:  BOOST_CHECK_EQUAL(c1.alpha(), (float) a);                    break;
      default:        BOOST_CHECK_EQUAL(c1.alpha(), a);                            break;
    }

    BOOST_CHECK_EQUAL(c1.type(), s1);
  }
}

BOOST_AUTO_TEST_CASE(clamp_cmy)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::CMY c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.c() >=    0.0 and c.c() <=   1.0);
    BOOST_REQUIRE(c.m() >=    0.0 and c.m() <=   1.0);
    BOOST_REQUIRE(c.y() >=    0.0 and c.y() <=   1.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_cmyk)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::CMYK c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.c() >=    0.0 and c.c() <=   1.0);
    BOOST_REQUIRE(c.m() >=    0.0 and c.m() <=   1.0);
    BOOST_REQUIRE(c.y() >=    0.0 and c.y() <=   1.0);
    BOOST_REQUIRE(c.k() >=    0.0 and c.k() <=   1.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_rgb)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::RGB c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.r() >=    0.0 and c.r() <=   1.0);
    BOOST_REQUIRE(c.g() >=    0.0 and c.g() <=   1.0);
    BOOST_REQUIRE(c.b() >=    0.0 and c.b() <=   1.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_rgbf)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::RGBf c;

    fill(c, random<float>(), 10.f);
    c.clamp();

    BOOST_REQUIRE(c.r() >=    0.f and c.r() <=   1.f);
    BOOST_REQUIRE(c.g() >=    0.f and c.g() <=   1.f);
    BOOST_REQUIRE(c.b() >=    0.f and c.b() <=   1.f);
  }
}

BOOST_AUTO_TEST_CASE(clamp_hsl)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::HSL c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.h() >=    0.0 and c.h() <= 360.0);
    BOOST_REQUIRE(c.s() >=    0.0 and c.s() <=   1.0);
    BOOST_REQUIRE(c.l() >=    0.0 and c.l() <=   1.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_hsv)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::HSV c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.h() >=    0.0 and c.h() <= 360.0);
    BOOST_REQUIRE(c.s() >=    0.0 and c.s() <=   1.0);
    BOOST_REQUIRE(c.v() >=    0.0 and c.v() <=   1.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_lab)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::LAB c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.l() >=    0.0 and c.l() <= 100.0);
    BOOST_REQUIRE(c.a() >= -120.0 and c.a() <= 120.0);
    BOOST_REQUIRE(c.b() >= -120.0 and c.b() <= 120.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_lch)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::LCH c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.l() >=    0.0 and c.l() <= 100.0);
    BOOST_REQUIRE(c.c() >= -120.0 and c.c() <= 120.0);
    BOOST_REQUIRE(c.h() >=    0.0 and c.h() <= 360.0);
  }
}

BOOST_AUTO_TEST_CASE(clamp_xyz)
{
  init();

  for (int i = 0; i < 100; ++i)
  {
    mcl::XYZ c;

    fill(c, random<double>(), 10.0);
    c.clamp();

    BOOST_REQUIRE(c.x() >=    0.0 and c.x() <= 120.0);
    BOOST_REQUIRE(c.y() >=    0.0 and c.y() <= 120.0);
    BOOST_REQUIRE(c.z() >=    0.0 and c.z() <= 120.0);
  }
}
