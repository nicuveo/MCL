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
// Implementation

BOOST_AUTO_TEST_SUITE(size)

BOOST_AUTO_TEST_CASE(size_00)
{

  BOOST_CHECK_EQUAL(sizeof(mcl::RGBub), 4);
  BOOST_CHECK_EQUAL(sizeof(mcl::RGBf),  4 * sizeof(float));
  BOOST_CHECK_EQUAL(sizeof(mcl::RGB),   4 * sizeof(double));

  BOOST_CHECK_EQUAL(sizeof(mcl::HSV),   4 * sizeof(double));
  BOOST_CHECK_EQUAL(sizeof(mcl::HSL),   4 * sizeof(double));
  BOOST_CHECK_EQUAL(sizeof(mcl::LAB),   4 * sizeof(double));
  BOOST_CHECK_EQUAL(sizeof(mcl::LCH),   4 * sizeof(double));
  BOOST_CHECK_EQUAL(sizeof(mcl::XYZ),   4 * sizeof(double));
  BOOST_CHECK_EQUAL(sizeof(mcl::CMY),   4 * sizeof(double));
  BOOST_CHECK_EQUAL(sizeof(mcl::CMYK),  5 * sizeof(double));
}

BOOST_AUTO_TEST_SUITE_END()
