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
#include <boost/test/unit_test.hpp>
#include "nauths/mcl/mcl.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

#define CREATE(R, D, S)                                              \
  case mcl::spaces::S:                                               \
  {                                                                  \
    mcl::S color;                                                    \
    fill(color, alpha);                                              \
    return color;                                                    \
  }                                                                  \

#define READ(R, D, S)                                                \
  case mcl::spaces::S:                                               \
  {                                                                  \
    mcl::S color;                                                    \
    istr >> color;                                                   \
    return color;                                                    \
}                                                                    \

#define WRITE(R, D, S)                                               \
  case mcl::spaces::S:                                               \
  {                                                                  \
    ostr << c.get<mcl::S>();                                         \
  }                                                                  \

#define NAME_TEST(R, D, C)                                           \
  NAME_TEST_(BOOST_PP_STRINGIZE(BOOST_PP_TUPLE_ELEM(4, 0, C)),       \
             mcl::colors::BOOST_PP_TUPLE_ELEM(4, 0, C)())
#define NAME_TEST_(N, C)                                             \
  check(C,           mcl::read<mcl::Color>(N));                      \
  check(C.rounded(), mcl::read<mcl::Color>(mcl::show(C)).rounded()); \


  void init()
  {
    srand(42);
  }

  void check(const mcl::Color& c1, const mcl::Color& c2)
  {
    BOOST_CHECK_EQUAL(c1, c2);
  }

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
  void fill(std::array<T, N>& color, bool alpha)
  {
    for (std::size_t i = 0; i < (alpha ? N : N - 1); ++i)
      color[i] = random<T>();
  }

  mcl::Color make(mcl::SpaceType s, bool alpha)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(CREATE, _, MCL_SPACES)
    }

    return mcl::Color();
  }

  mcl::Color read(mcl::SpaceType s, std::istream& istr)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(READ, _, MCL_SPACES)
    }

    return mcl::Color();
  }

  void write(mcl::Color c, std::ostream& ostr)
  {
    switch (c.type())
    {
      BOOST_PP_SEQ_FOR_EACH(WRITE, _, MCL_SPACES)
    }
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_SUITE(io)

BOOST_AUTO_TEST_CASE(io_00)
{
  init();

  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    const mcl::Color c1 = make(s1, true).rounded(0.00001);
    try
    {
      const mcl::Color c2 = mcl::read<mcl::Color>(mcl::show(c1)).rounded(0.00001);
      BOOST_CHECK_EQUAL(c1, c2);
    }
    catch (const std::exception& e)
    {
      BOOST_ERROR("failed for " << c1 << " with message: " << e.what());
    }
  }
}

BOOST_AUTO_TEST_CASE(io_01)
{
  init();

  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    const mcl::Color c1 = make(s1, false).rounded(0.00001);
    try
    {
      const mcl::Color c2 = mcl::read<mcl::Color>(mcl::show(c1)).rounded(0.00001);
      BOOST_CHECK_EQUAL(c1, c2);
    }
    catch (const std::exception& e)
    {
      BOOST_ERROR("failed for " << c1 << " with message: " << e.what());
    }
  }
}

BOOST_AUTO_TEST_CASE(io_02)
{
  init();

  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    try
    {
      const mcl::SpaceType s2 = mcl::read<mcl::SpaceType>(mcl::show(s1));
      BOOST_CHECK_EQUAL(s1, s2);
    }
    catch (const std::exception& e)
    {
      BOOST_ERROR("failed for " << s1 << " with message: " << e.what());
    }
  }
}

BOOST_AUTO_TEST_CASE(io_03)
{
  init();

  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>(""),           std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>("CYM"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>(" RGB"),       std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>("RGB "),       std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>("ARGB"),       std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>("RGBA"),       std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::SpaceType>("RGB(1,1,1)"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(io_04)
{
  init();

  BOOST_CHECK_THROW(mcl::read<mcl::Color>(""),                   std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CYM"),                std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB"),                std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>(" RGB"),               std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB "),               std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("ARGB"),               std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBA"),               std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB()"),              std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1"),              std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1, 1)"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1, 1, 1, 1, 1)"), std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1 1)"),           std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(,,)"),            std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1,1,1"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1,1,1,"),         std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1,1,1) "),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>(" RGB(1,1,1)"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(1,1,1)1"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("1RGB(1,1,1)"),        std::runtime_error);
}

BOOST_AUTO_TEST_CASE(io_05)
{
  init();

  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CMY(0,0,0_"),    std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CMYK(0,0,0,0_"), std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("HSL(0,0,0_"),    std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("HSV(0,0,0_"),    std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("LAB(0,0,0_"),    std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("LCH(0,0,0_"),    std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(0,0,0_"),    std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBf(0,0,0_"),   std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBub(0,0,0_"),  std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("XYZ(0,0,0_"),    std::runtime_error);

  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CMY(a,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CMYK(a,"),       std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("HSL(a,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("HSV(a,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("LAB(a,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("LCH(a,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB(a,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBf(a,"),       std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBub(a,"),      std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("XYZ(a,"),        std::runtime_error);

  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CMY,"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("CMYK,"),         std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("HSL,"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("HSV,"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("LAB,"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("LCH,"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGB,"),          std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBf,"),         std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("RGBub,"),        std::runtime_error);
  BOOST_CHECK_THROW(mcl::read<mcl::Color>("XYZ,"),          std::runtime_error);
}

BOOST_AUTO_TEST_CASE(io_06)
{
  init();

  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    const mcl::Color c1 = make(s1, false).rounded(0.00001);
    try
    {
      std::stringstream ss;
      ss << c1;
      write(c1, ss);
      const mcl::Color c2 = read(s1, ss).rounded(0.00001);
      mcl::Color c3;
      ss >> c3;

      BOOST_CHECK_EQUAL(c1, c2);
      BOOST_CHECK_EQUAL(c1, c3.rounded(0.00001));
    }
    catch (const std::exception& e)
    {
      BOOST_ERROR("failed for " << c1 << " with message: " << e.what());
    }
  }
}

BOOST_AUTO_TEST_CASE(io_07)
{
  init();

  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    try
    {
      std::stringstream ss;
      ss << s1;
      mcl::SpaceType s2;
      ss >> s2;
      BOOST_CHECK_EQUAL(s1, s2);
    }
    catch (const std::exception& e)
    {
      BOOST_ERROR("failed for " << s1 << " with message: " << e.what());
    }
  }
}

BOOST_AUTO_TEST_CASE(io_08)
{
  BOOST_PP_SEQ_FOR_EACH(NAME_TEST, _, MCL_COLOR_NAMES);
}

BOOST_AUTO_TEST_SUITE_END()
