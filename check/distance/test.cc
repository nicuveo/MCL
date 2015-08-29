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

#define BOOST_TEST_MODULE distance
#include <boost/test/included/unit_test.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_CASE(distance_1976)
{
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::RED,     mcl::colors::YELLOW),  114.030440, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::RED,     mcl::colors::LIME),    170.565250, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::RED,     mcl::colors::CYAN),    156.459940, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::RED,     mcl::colors::BLUE),    176.313880, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::RED,     mcl::colors::MAGENTA), 129.500940, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::YELLOW,  mcl::colors::LIME),     66.279822, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::YELLOW,  mcl::colors::CYAN),    111.965680, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::YELLOW,  mcl::colors::BLUE),    235.146710, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::YELLOW,  mcl::colors::MAGENTA), 199.558280, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::LIME,    mcl::colors::CYAN),    104.556160, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::LIME,    mcl::colors::BLUE),    258.682530, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::LIME,    mcl::colors::MAGENTA), 235.580500, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::CYAN,    mcl::colors::BLUE),    168.651590, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::CYAN,    mcl::colors::MAGENTA), 156.647160, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::BLUE,    mcl::colors::MAGENTA),  57.970727, 0.001);
}

BOOST_AUTO_TEST_CASE(distance_1994)
{
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::RED,     mcl::colors::YELLOW),   59.993149, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::RED,     mcl::colors::LIME),     73.430410, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::RED,     mcl::colors::CYAN),     67.601815, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::RED,     mcl::colors::BLUE),     70.580406, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::RED,     mcl::colors::MAGENTA),  50.699880, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::YELLOW,  mcl::colors::LIME),     27.107184, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::YELLOW,  mcl::colors::CYAN),     42.723379, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::YELLOW,  mcl::colors::BLUE),    111.858130, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::YELLOW,  mcl::colors::MAGENTA),  87.748199, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::LIME,    mcl::colors::CYAN),     30.102820, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::LIME,    mcl::colors::BLUE),    105.904950, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::LIME,    mcl::colors::MAGENTA),  88.030095, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::CYAN,    mcl::colors::BLUE),     99.896151, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::CYAN,    mcl::colors::MAGENTA),  87.431457, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::BLUE,    mcl::colors::MAGENTA),  32.251523, 0.001);
}

BOOST_AUTO_TEST_CASE(distance_2000)
{
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::RED,     mcl::colors::YELLOW),   64.300859, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::RED,     mcl::colors::LIME),     86.608245, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::RED,     mcl::colors::CYAN),     70.959107, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::RED,     mcl::colors::BLUE),     52.881354, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::RED,     mcl::colors::MAGENTA),  42.585671, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::YELLOW,  mcl::colors::LIME),     23.404276, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::YELLOW,  mcl::colors::CYAN),     41.973639, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::YELLOW,  mcl::colors::BLUE),    103.426970, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::YELLOW,  mcl::colors::MAGENTA),  92.808516, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::LIME,    mcl::colors::CYAN),     34.527363, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::LIME,    mcl::colors::BLUE),     83.185862, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::LIME,    mcl::colors::MAGENTA), 111.414320, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::CYAN,    mcl::colors::BLUE),     66.466912, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::CYAN,    mcl::colors::MAGENTA),  57.983482, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::BLUE,    mcl::colors::MAGENTA),  32.421232, 0.001);
}
