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
// Macros

#define CREATE(R, D, S)                         \
  case mcl::spaces::S:                          \
  {                                             \
    mcl::S color;                               \
    fill(color);                                \
    return color;                               \
  }                                             \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{


  typedef mcl::Endomorphism<mcl::Color> Endo;



  const Endo grey        = mcl::grey<mcl::Color>();
  const Endo gray        = mcl::gray<mcl::Color>();
  const Endo opaque      = mcl::opaque<mcl::Color>();
  const Endo transparent = mcl::transparent<mcl::Color>();
  const Endo alpha25     = mcl::alpha<mcl::Color>(0.25);
  const Endo alpha50     = mcl::alpha<mcl::Color>(0.50);
  const Endo alpha75     = mcl::alpha<mcl::Color>(0.75);
  const Endo light25     = mcl::lightness<mcl::Color>(25);
  const Endo light50     = mcl::lightness<mcl::Color>(50);
  const Endo light75     = mcl::lightness<mcl::Color>(75);
  const Endo cround      = mcl::round<mcl::Color>();
  const Endo clamp       = mcl::clamp<mcl::Color>();



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

BOOST_AUTO_TEST_SUITE(transform)

BOOST_AUTO_TEST_CASE(gray_equal_grey)
{
  srand(42);
  for (int i = 0; i < 100; ++i)
  {
    mcl::Color c = make();
    BOOST_REQUIRE_EQUAL(grey(c), gray(c));
  }
}

BOOST_AUTO_TEST_CASE(endos)
{
  srand(42);

  for (int i = 0; i < 100; ++i)
  {
    mcl::Color c0 = make();
    mcl::Color c1 = c0 | clamp | grey | cround | transparent | gray | opaque | light25 | alpha25 | light50 | alpha50 | light75 | alpha75;
    mcl::Color c2 = (alpha75, light75, alpha50, light50, alpha25, light25, opaque, gray, transparent, cround, grey, clamp)(c0);
    mcl::Color c3 = alpha75(light75(alpha50(light50(alpha25(light25(opaque(gray(transparent(cround(grey(clamp(c0))))))))))));
    BOOST_REQUIRE_EQUAL(c1, c2);
    BOOST_REQUIRE_EQUAL(c2, c3);
    BOOST_REQUIRE_EQUAL(c1, c3);
  }
}

BOOST_AUTO_TEST_CASE(endos_2)
{
  srand(42);

  std::vector<Endo> endos = {alpha75, light75, alpha50, light50};
  Endo e1 = (endos[0], endos[1], endos[2], endos[3]);
  Endo e2 = mcl::concat<Endo>(endos);

  for (int i = 0; i < 100; ++i)
  {
    mcl::Color c0 = make();
    mcl::Color c1 = e1(c0);
    mcl::Color c2 = e2(c0);
    BOOST_REQUIRE_EQUAL(c1, c2);
  }
}

BOOST_AUTO_TEST_SUITE_END()
