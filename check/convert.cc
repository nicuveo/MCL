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

  typedef std::map<mcl::SpaceType, mcl::Color> Colors;


  std::map<std::string, Colors> DATA = {
    { "red", {
        {mcl::spaces::CMYK,  mcl::CMYK(  0.000000,   1.000000,   1.000000,   0.000000)},
        {mcl::spaces::CMY,   mcl::CMY (  0.000000,   1.000000,   1.000000)},
        {mcl::spaces::HSL,   mcl::HSL (  0.000000,   1.000000,   0.500000)},
        {mcl::spaces::HSV,   mcl::HSV (  0.000000,   1.000000,   1.000000)},
        {mcl::spaces::LAB,   mcl::LAB ( 53.240800,  80.092500,  67.203200)},
        {mcl::spaces::LCH,   mcl::LCH ( 53.240800, 104.551800,  39.999000)},
        {mcl::spaces::RGB,   mcl::RGB (  1.000000,   0.000000,   0.000000)},
        {mcl::spaces::XYZ,   mcl::XYZ ( 41.245600,  21.267300,   1.933400)}
      }
    },
    { "pale green", {
        {mcl::spaces::CMYK,  mcl::CMYK(  0.394422,   0.000000,   0.394422,   0.015686)},
        {mcl::spaces::CMY,   mcl::CMY (  0.403922,   0.015686,   0.403922)},
        {mcl::spaces::HSL,   mcl::HSL (120.000000,   0.925234,   0.790196)},
        {mcl::spaces::HSV,   mcl::HSV (120.000000,   0.394422,   0.984314)},
        {mcl::spaces::LAB,   mcl::LAB ( 90.749600, -48.296800,  38.527700)},
        {mcl::spaces::LCH,   mcl::LCH ( 90.749600,  61.781600, 141.419600)},
        {mcl::spaces::RGB,   mcl::RGB (  0.596078,   0.984314,   0.596078)},
        {mcl::spaces::XYZ,   mcl::XYZ ( 53.111100,  77.933700,  41.943800)}
      }
    }
  };

  std::vector<mcl::SpaceType> SPACES = {
    mcl::spaces::CMYK,
    mcl::spaces::CMY,
    mcl::spaces::HSL,
    mcl::spaces::HSV,
    mcl::spaces::LAB,
    mcl::spaces::LCH,
    mcl::spaces::RGB,
    mcl::spaces::XYZ
  };


  template <std::size_t N>
  double check(const std::array<double, N>& c1, const std::array<double, N>& c2)
  {
    double d = 0;
    for (std::size_t i = 0; i < N; ++i)
      d += std::abs(c1[i] - c2[i]);
    return d;
  }

  double check(mcl::SpaceType s, const mcl::Color& c1, const mcl::Color& c2)
  {
    switch (s)
    {
      case mcl::spaces::CMYK: return check(c1.get<mcl::CMYK>(), c2.get<mcl::CMYK>());
      case mcl::spaces::CMY:  return check(c1.get<mcl::CMY> (), c2.get<mcl::CMY> ());
      case mcl::spaces::HSL:  return check(c1.get<mcl::HSL> (), c2.get<mcl::HSL> ());
      case mcl::spaces::HSV:  return check(c1.get<mcl::HSV> (), c2.get<mcl::HSV> ());
      case mcl::spaces::LAB:  return check(c1.get<mcl::LAB> (), c2.get<mcl::LAB> ());
      case mcl::spaces::LCH:  return check(c1.get<mcl::LCH> (), c2.get<mcl::LCH> ());
      case mcl::spaces::RGB:  return check(c1.get<mcl::RGB> (), c2.get<mcl::RGB> ());
      case mcl::spaces::XYZ:  return check(c1.get<mcl::XYZ> (), c2.get<mcl::XYZ> ());
      default: return false;
    }
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_SUITE(convert)

BOOST_AUTO_TEST_CASE(convert_00)
{
  for (const auto& d : DATA)
    for (const auto& s : SPACES)
    {
      const auto& c0 = d.second.find(s)->second.rounded();
      for (const auto& p : d.second)
      {
        const auto& c1 = d.second.find(s)->second.to(p.first);
        const auto& c2 = p.second;
        double e = check(s, c1, c2);

        BOOST_CHECK_MESSAGE(e <= 0.0005, d.first << ":\t"   << c0
                                                 << "\t-> " << c1.rounded()
                                                 << "\t!= " << c2.rounded()
                                                 << "\t("   << e << ")");
      }
    }
}

BOOST_AUTO_TEST_SUITE_END()
