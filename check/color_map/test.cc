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

#define BOOST_TEST_MODULE color_map
#include <boost/test/included/unit_test.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define CREATE(R, D, S)                         \
  case mcl::spaces::S:                          \
  {                                             \
   mcl::S color;                                \
   fill(color);                                 \
   return color;                                \
   }                                            \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{


  template <typename T>
  T random()
  {
    return T((rand() % 10000 + 1) / 10000.);
  }

  template <>
  mcl::byte random()
  {
    return (rand() >> 8) % 256;
  }

  template <typename T, std::size_t N>
  void fill(std::array<T, N>& color)
  {
    for (auto& x : color)
      x = random<T>();
  }

  template <typename T>
  T make()
  {
    T color;
    fill(color);
    return color;
  }

  mcl::Color make(mcl::SpaceType s)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(CREATE, _, MCL_SPACES)
    }

    return mcl::Color();
  }

  mcl::Color make()
  {
    return make((mcl::SpaceType) (rand() % (mcl::spaces::XYZ + 1)));
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_CASE(color_map_1)
{
  mcl::ColorMap m = mcl::ColorMap::strict(mcl::interpolation<mcl::RGBub>());

  m[0.0] = mcl::colors::red();
  m[1.0] = mcl::colors::lime();

  BOOST_CHECK_EQUAL(m.get(0.00), mcl::Color(mcl::colors::red()));
  BOOST_CHECK_EQUAL(m.get(0.50), mcl::Color(mcl::colors::olive()));
  BOOST_CHECK_EQUAL(m.get(1.00), mcl::Color(mcl::colors::lime()));
}

BOOST_AUTO_TEST_CASE(color_map_2)
{
  mcl::ColorMap m = mcl::ColorMap::strict(mcl::interpolation<mcl::RGBub>());

  m[0.0] = mcl::colors::red();
  m[1.0] = mcl::colors::lime();

  mcl::Color c1 = m.get(0.25);
  mcl::Color c2 = m.compute(0.25);
  mcl::Color c3 = m.compute(0.75);
  mcl::Color c4 = m.get(0.75);

  BOOST_REQUIRE_EQUAL(c1, c2);
  BOOST_REQUIRE_EQUAL(c3, c4);
}

BOOST_AUTO_TEST_CASE(color_map_3)
{
  const auto& i = mcl::interpolation<mcl::RGBub>();
  mcl::ColorMap m = mcl::ColorMap::strict(i);

  m[0.0] = mcl::colors::red();
  m[1.0] = mcl::colors::lime();

  mcl::Color c1 = m.get(0.3);
  mcl::Color c2 = m.get(0.7);

  BOOST_REQUIRE_EQUAL(i(mcl::colors::red(), mcl::colors::lime(), 0.3), c1);
  BOOST_REQUIRE_EQUAL(i(mcl::colors::red(), mcl::colors::lime(), 0.7), c2);
}

BOOST_AUTO_TEST_CASE(color_map_strict)
{
  srand(42);

  mcl::ColorMap m = mcl::ColorMap::strict(mcl::interpolation<mcl::RGBub>());
  mcl::Color c1 = make();
  mcl::Color c2 = make();
  double i1 = 1. + (rand() % 101) / 100.;
  double i2 = 1. + (rand() % 101) / 100.;

  m[i1] = c1;
  m[i2] = c2;

  BOOST_REQUIRE_THROW(m.get(std::min(i1, i2) - 0.1), std::domain_error);
  BOOST_REQUIRE_THROW(m.get(std::max(i1, i2) + 0.1), std::domain_error);
}

BOOST_AUTO_TEST_CASE(color_map_fallback)
{
  srand(42);

  mcl::Color cd = make();
  mcl::ColorMap m = mcl::ColorMap::fallback(mcl::interpolation<mcl::RGBub>(), cd);
  mcl::Color c1 = make();
  mcl::Color c2 = make();
  double i1 = 1. + (rand() % 101) / 100.;
  double i2 = 1. + (rand() % 101) / 100.;

  m[i1] = c1;
  m[i2] = c2;

  BOOST_REQUIRE_EQUAL(cd, m.get(std::min(i1, i2) - 0.1));
  BOOST_REQUIRE_EQUAL(cd, m.get(std::max(i1, i2) + 0.1));
}

BOOST_AUTO_TEST_CASE(color_map_clamp)
{
  srand(42);

  mcl::ColorMap m = mcl::ColorMap::clamp(mcl::interpolation<mcl::RGBub>());
  mcl::Color c1 = make();
  mcl::Color c2 = make();
  double i1 = 1. + (rand() % 101) / 100.;
  double i2 = 1. + (rand() % 101) / 100.;

  m[std::min(i1, i2)] = c1;
  m[std::max(i1, i2)] = c2;

  BOOST_REQUIRE_EQUAL(c1, m.get(std::min(i1, i2) - 0.5));
  BOOST_REQUIRE_EQUAL(c2, m.get(std::max(i1, i2) + 0.5));
}

BOOST_AUTO_TEST_CASE(interpolation_bonus)
{
  srand(42);

  for (mcl::SpaceType s : mcl::COLOR_SPACES)
  {
    const mcl::Color c1 = make(s);
    const mcl::Color c2 = make(s);

    BOOST_CHECK_EQUAL(mcl::interpolate(s, c1, c2, 0.0), c1);
    BOOST_CHECK_EQUAL(mcl::interpolate(s, c1, c2, 1.0), c2);
  }
}
