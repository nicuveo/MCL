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
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::red(),     mcl::colors::yellow()),  114.030440, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::red(),     mcl::colors::lime()),    170.565250, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::red(),     mcl::colors::cyan()),    156.459940, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::red(),     mcl::colors::blue()),    176.313880, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::red(),     mcl::colors::magenta()), 129.500940, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::yellow(),  mcl::colors::lime()),     66.279822, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::yellow(),  mcl::colors::cyan()),    111.965680, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::yellow(),  mcl::colors::blue()),    235.146710, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::yellow(),  mcl::colors::magenta()), 199.558280, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::lime(),    mcl::colors::cyan()),    104.556160, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::lime(),    mcl::colors::blue()),    258.682530, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::lime(),    mcl::colors::magenta()), 235.580500, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::cyan(),    mcl::colors::blue()),    168.651590, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::cyan(),    mcl::colors::magenta()), 156.647160, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1976(mcl::colors::blue(),    mcl::colors::magenta()),  57.970727, 0.001);
}

BOOST_AUTO_TEST_CASE(distance_1994)
{
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::red(),     mcl::colors::yellow()),   59.993149, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::red(),     mcl::colors::lime()),     73.430410, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::red(),     mcl::colors::cyan()),     67.601815, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::red(),     mcl::colors::blue()),     70.580406, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::red(),     mcl::colors::magenta()),  50.699880, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::yellow(),  mcl::colors::lime()),     27.107184, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::yellow(),  mcl::colors::cyan()),     42.723379, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::yellow(),  mcl::colors::blue()),    111.858130, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::yellow(),  mcl::colors::magenta()),  87.748199, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::lime(),    mcl::colors::cyan()),     30.102820, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::lime(),    mcl::colors::blue()),    105.904950, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::lime(),    mcl::colors::magenta()),  88.030095, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::cyan(),    mcl::colors::blue()),     99.896151, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::cyan(),    mcl::colors::magenta()),  87.431457, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_1994(mcl::colors::blue(),    mcl::colors::magenta()),  32.251523, 0.001);
}

BOOST_AUTO_TEST_CASE(distance_2000)
{
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::red(),     mcl::colors::yellow()),   64.300859, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::red(),     mcl::colors::lime()),     86.608245, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::red(),     mcl::colors::cyan()),     70.959107, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::red(),     mcl::colors::blue()),     52.881354, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::red(),     mcl::colors::magenta()),  42.585671, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::yellow(),  mcl::colors::lime()),     23.404276, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::yellow(),  mcl::colors::cyan()),     41.973639, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::yellow(),  mcl::colors::blue()),    103.426970, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::yellow(),  mcl::colors::magenta()),  92.808516, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::lime(),    mcl::colors::cyan()),     34.527363, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::lime(),    mcl::colors::blue()),     83.185862, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::lime(),    mcl::colors::magenta()), 111.414320, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::cyan(),    mcl::colors::blue()),     66.466912, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::cyan(),    mcl::colors::magenta()),  57.983482, 0.001);
  BOOST_CHECK_CLOSE(mcl::cie_2000(mcl::colors::blue(),    mcl::colors::magenta()),  32.421232, 0.001);
}
