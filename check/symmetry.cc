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

#define CREATE(R, D, S)                                       \
  case mcl::spaces::S:                                        \
  {                                                           \
    mcl::S color;                                             \
    fill(color);                                              \
    return color;                                             \
  }                                                           \

#define CONVERT_(F, T)                                        \
  if (f == mcl::spaces::F and t == mcl::spaces::T)            \
  {                                                           \
    return mcl::to<mcl::F>(mcl::to<mcl::T>(c.get<mcl::F>())); \
  }                                                           \

#define CONVERT(R, S) CONVERT_(BOOST_PP_SEQ_ELEM(0,S), BOOST_PP_SEQ_ELEM(1,S))


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

  template <typename T, std::size_t N>
  void fill(std::array<T, N>& color)
  {
    for (int i = 0; i < N; ++i)
      color[i] = random<T>();
  }

  mcl::Color make(mcl::SpaceType s)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(CREATE, _, MCL_SPACES)
    }

    return mcl::Color();
  }

  mcl::Color convert(const mcl::Color& c, mcl::SpaceType f, mcl::SpaceType t)
  {
    BOOST_PP_SEQ_FOR_EACH_PRODUCT(CONVERT, (MCL_SPACES)(MCL_SPACES))
    return mcl::Color();
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_SUITE(symmetry)

BOOST_AUTO_TEST_CASE(symmetry_00)
{
  init();
  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    if (s1 != MCL_CMYK)
    {
      const mcl::Color c1 = make(s1).rounded();
      for (mcl::SpaceType s2 : mcl::COLOR_SPACES)
      {
        if (s2 != MCL_RGBub)
        {
          const mcl::Color c2 = c1.to(s2).to(s1).rounded();
          BOOST_CHECK_MESSAGE(c1 == c2, s1 << " -> " << s2 << ":\t" << c1 << " != " << c2);
        }
      }
    }
  }
}

BOOST_AUTO_TEST_CASE(symmetry_01)
{
  init();
  for (mcl::SpaceType s1 : mcl::COLOR_SPACES)
  {
    if (s1 != MCL_CMYK)
    {
      const mcl::Color c1 = make(s1).rounded();
      for (mcl::SpaceType s2 : mcl::COLOR_SPACES)
      {
        if (s2 != MCL_RGBub)
        {
          const mcl::Color c2 = convert(c1, s1, s2).rounded();
          BOOST_CHECK_MESSAGE(c1 == c2, s1 << " -> " << s2 << ":\t" << c1 << " != " << c2);
        }
      }
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
