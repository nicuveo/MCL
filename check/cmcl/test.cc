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

extern "C" {
#include <nauths/mcl/cmcl.h>
}

#define BOOST_TEST_MODULE cmcl
#include <boost/test/included/unit_test.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define CMCL_TEST(S1, S2, F)                    \
  srand(42);                                    \
  mcl::S1 c1 = make<mcl::S1>();                 \
  mcl::S2 c2a = mcl::to<mcl::S2>(c1);           \
  mcl::S2 c2b;                                  \
  F(c1.begin(), c2b.begin());                   \
  BOOST_REQUIRE_EQUAL(c2a, c2b)                 \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  template <typename T>
  T random();

  template <>
  double random()
  {
    return double((rand() % 10000 + 1) / 10000.);
  }

  template <typename T, std::size_t N>
  void fill(std::array<T, N>& color)
  {
    for (int i = 0; i < N; ++i)
      color[i] = random<T>();
  }

  template <typename T>
  T make()
  {
    T res;
    fill(res);
    return res;
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_CASE(cmcl_cmy_to_cmyk) { CMCL_TEST(CMY , CMYK, mcl_cmy_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_cmy_to_hsl ) { CMCL_TEST(CMY , HSL , mcl_cmy_to_hsl ); }
BOOST_AUTO_TEST_CASE(cmcl_cmy_to_hsv ) { CMCL_TEST(CMY , HSV , mcl_cmy_to_hsv ); }
BOOST_AUTO_TEST_CASE(cmcl_cmy_to_lab ) { CMCL_TEST(CMY , LAB , mcl_cmy_to_lab ); }
BOOST_AUTO_TEST_CASE(cmcl_cmy_to_lch ) { CMCL_TEST(CMY , LCH , mcl_cmy_to_lch ); }
BOOST_AUTO_TEST_CASE(cmcl_cmy_to_rgb ) { CMCL_TEST(CMY , RGB , mcl_cmy_to_rgb ); }
BOOST_AUTO_TEST_CASE(cmcl_cmy_to_xyz ) { CMCL_TEST(CMY , XYZ , mcl_cmy_to_xyz ); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_cmy) { CMCL_TEST(CMYK, CMY , mcl_cmyk_to_cmy); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_hsl) { CMCL_TEST(CMYK, HSL , mcl_cmyk_to_hsl); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_hsv) { CMCL_TEST(CMYK, HSV , mcl_cmyk_to_hsv); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_lab) { CMCL_TEST(CMYK, LAB , mcl_cmyk_to_lab); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_lch) { CMCL_TEST(CMYK, LCH , mcl_cmyk_to_lch); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_rgb) { CMCL_TEST(CMYK, RGB , mcl_cmyk_to_rgb); }
BOOST_AUTO_TEST_CASE(cmcl_cmyk_to_xyz) { CMCL_TEST(CMYK, XYZ , mcl_cmyk_to_xyz); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_cmy ) { CMCL_TEST(HSL , CMY , mcl_hsl_to_cmy ); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_cmyk) { CMCL_TEST(HSL , CMYK, mcl_hsl_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_hsv ) { CMCL_TEST(HSL , HSV , mcl_hsl_to_hsv ); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_lab ) { CMCL_TEST(HSL , LAB , mcl_hsl_to_lab ); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_lch ) { CMCL_TEST(HSL , LCH , mcl_hsl_to_lch ); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_rgb ) { CMCL_TEST(HSL , RGB , mcl_hsl_to_rgb ); }
BOOST_AUTO_TEST_CASE(cmcl_hsl_to_xyz ) { CMCL_TEST(HSL , XYZ , mcl_hsl_to_xyz ); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_cmy ) { CMCL_TEST(HSV , CMY , mcl_hsv_to_cmy ); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_cmyk) { CMCL_TEST(HSV , CMYK, mcl_hsv_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_hsl ) { CMCL_TEST(HSV , HSL , mcl_hsv_to_hsl ); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_lab ) { CMCL_TEST(HSV , LAB , mcl_hsv_to_lab ); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_lch ) { CMCL_TEST(HSV , LCH , mcl_hsv_to_lch ); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_rgb ) { CMCL_TEST(HSV , RGB , mcl_hsv_to_rgb ); }
BOOST_AUTO_TEST_CASE(cmcl_hsv_to_xyz ) { CMCL_TEST(HSV , XYZ , mcl_hsv_to_xyz ); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_cmy ) { CMCL_TEST(LAB , CMY , mcl_lab_to_cmy ); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_cmyk) { CMCL_TEST(LAB , CMYK, mcl_lab_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_hsl ) { CMCL_TEST(LAB , HSL , mcl_lab_to_hsl ); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_hsv ) { CMCL_TEST(LAB , HSV , mcl_lab_to_hsv ); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_lch ) { CMCL_TEST(LAB , LCH , mcl_lab_to_lch ); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_rgb ) { CMCL_TEST(LAB , RGB , mcl_lab_to_rgb ); }
BOOST_AUTO_TEST_CASE(cmcl_lab_to_xyz ) { CMCL_TEST(LAB , XYZ , mcl_lab_to_xyz ); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_cmy ) { CMCL_TEST(LCH , CMY , mcl_lch_to_cmy ); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_cmyk) { CMCL_TEST(LCH , CMYK, mcl_lch_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_hsl ) { CMCL_TEST(LCH , HSL , mcl_lch_to_hsl ); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_hsv ) { CMCL_TEST(LCH , HSV , mcl_lch_to_hsv ); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_lab ) { CMCL_TEST(LCH , LAB , mcl_lch_to_lab ); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_rgb ) { CMCL_TEST(LCH , RGB , mcl_lch_to_rgb ); }
BOOST_AUTO_TEST_CASE(cmcl_lch_to_xyz ) { CMCL_TEST(LCH , XYZ , mcl_lch_to_xyz ); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_cmy ) { CMCL_TEST(RGB , CMY , mcl_rgb_to_cmy ); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_cmyk) { CMCL_TEST(RGB , CMYK, mcl_rgb_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_hsl ) { CMCL_TEST(RGB , HSL , mcl_rgb_to_hsl ); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_hsv ) { CMCL_TEST(RGB , HSV , mcl_rgb_to_hsv ); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_lab ) { CMCL_TEST(RGB , LAB , mcl_rgb_to_lab ); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_lch ) { CMCL_TEST(RGB , LCH , mcl_rgb_to_lch ); }
BOOST_AUTO_TEST_CASE(cmcl_rgb_to_xyz ) { CMCL_TEST(RGB , XYZ , mcl_rgb_to_xyz ); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_cmy ) { CMCL_TEST(XYZ , CMY , mcl_xyz_to_cmy ); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_cmyk) { CMCL_TEST(XYZ , CMYK, mcl_xyz_to_cmyk); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_hsl ) { CMCL_TEST(XYZ , HSL , mcl_xyz_to_hsl ); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_hsv ) { CMCL_TEST(XYZ , HSV , mcl_xyz_to_hsv ); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_lab ) { CMCL_TEST(XYZ , LAB , mcl_xyz_to_lab ); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_lch ) { CMCL_TEST(XYZ , LCH , mcl_xyz_to_lch ); }
BOOST_AUTO_TEST_CASE(cmcl_xyz_to_rgb ) { CMCL_TEST(XYZ , RGB , mcl_xyz_to_rgb ); }

BOOST_AUTO_TEST_CASE(cmcl_cie_1976)
{
  srand(42);
  mcl::LAB l1 = make<mcl::LAB>();
  mcl::LAB l2 = make<mcl::LAB>();
  BOOST_REQUIRE_EQUAL(mcl_cie_1976(l1.begin(), l2.begin()), mcl::cie_1976(l1, l2));
}

BOOST_AUTO_TEST_CASE(cmcl_cie_1994)
{
  srand(42);
  mcl::LAB l1 = make<mcl::LAB>();
  mcl::LAB l2 = make<mcl::LAB>();
  BOOST_REQUIRE_EQUAL(mcl_cie_1994(l1.begin(), l2.begin()), mcl::cie_1994(l1, l2));
}

BOOST_AUTO_TEST_CASE(cmcl_cie_2000)
{
  srand(42);
  mcl::LAB l1 = make<mcl::LAB>();
  mcl::LAB l2 = make<mcl::LAB>();
  BOOST_REQUIRE_EQUAL(mcl_cie_2000(l1.begin(), l2.begin()), mcl::cie_2000(l1, l2));
}
