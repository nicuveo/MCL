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

#include <cstring>
#include "nauths/mcl/mcl.hh"

extern "C" {
#include "nauths/mcl/cmcl.h"
}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_impl(S1, S2)                                             \
  std::memcpy(t,                                                     \
              mcl::to<S2>(*reinterpret_cast<const S1*>(f)).begin(),  \
              sizeof (double) * (1 + S2::ALPHA))                     \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

void mcl_cmy_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::CMYK);
}

void mcl_cmy_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::HSL);
}

void mcl_cmy_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::HSV);
}

void mcl_cmy_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::LAB);
}

void mcl_cmy_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::LCH);
}

void mcl_cmy_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::RGB);
}

void mcl_cmy_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::CMY, mcl::XYZ);
}

void mcl_cmyk_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::CMY);
}

void mcl_cmyk_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::HSL);
}

void mcl_cmyk_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::HSV);
}

void mcl_cmyk_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::LAB);
}

void mcl_cmyk_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::LCH);
}

void mcl_cmyk_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::RGB);
}

void mcl_cmyk_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::CMYK, mcl::XYZ);
}

void mcl_hsl_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::CMY);
}

void mcl_hsl_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::CMYK);
}

void mcl_hsl_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::HSV);
}

void mcl_hsl_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::LAB);
}

void mcl_hsl_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::LCH);
}

void mcl_hsl_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::RGB);
}

void mcl_hsl_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::HSL, mcl::XYZ);
}

void mcl_hsv_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::CMY);
}

void mcl_hsv_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::CMYK);
}

void mcl_hsv_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::HSL);
}

void mcl_hsv_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::LAB);
}

void mcl_hsv_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::LCH);
}

void mcl_hsv_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::RGB);
}

void mcl_hsv_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::HSV, mcl::XYZ);
}

void mcl_lab_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::CMY);
}

void mcl_lab_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::CMYK);
}

void mcl_lab_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::HSL);
}

void mcl_lab_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::HSV);
}

void mcl_lab_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::LCH);
}

void mcl_lab_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::RGB);
}

void mcl_lab_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::LAB, mcl::XYZ);
}

void mcl_lch_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::CMY);
}

void mcl_lch_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::CMYK);
}

void mcl_lch_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::HSL);
}

void mcl_lch_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::HSV);
}

void mcl_lch_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::LAB);
}

void mcl_lch_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::RGB);
}

void mcl_lch_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::LCH, mcl::XYZ);
}

void mcl_rgb_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::CMY);
}

void mcl_rgb_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::CMYK);
}

void mcl_rgb_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::HSL);
}

void mcl_rgb_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::HSV);
}

void mcl_rgb_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::LAB);
}

void mcl_rgb_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::LCH);
}

void mcl_rgb_to_xyz(const double* f, double* t)
{
  MCL_impl(mcl::RGB, mcl::XYZ);
}

void mcl_xyz_to_cmy(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::CMY);
}

void mcl_xyz_to_cmyk(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::CMYK);
}

void mcl_xyz_to_hsl(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::HSL);
}

void mcl_xyz_to_hsv(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::HSV);
}

void mcl_xyz_to_lab(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::LAB);
}

void mcl_xyz_to_lch(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::LCH);
}

void mcl_xyz_to_rgb(const double* f, double* t)
{
  MCL_impl(mcl::XYZ, mcl::RGB);
}


double mcl_cie_1976(const double* lab1, const double* lab2)
{
  auto l1 = reinterpret_cast<const mcl::LAB*>(lab1);
  auto l2 = reinterpret_cast<const mcl::LAB*>(lab2);
  return mcl::cie_1976(*l1, *l2);
}

double mcl_cie_1994(const double* lab1, const double* lab2)
{
  auto l1 = reinterpret_cast<const mcl::LAB*>(lab1);
  auto l2 = reinterpret_cast<const mcl::LAB*>(lab2);
  return mcl::cie_1994(*l1, *l2);
}

double mcl_cie_2000(const double* lab1, const double* lab2)
{
  auto l1 = reinterpret_cast<const mcl::LAB*>(lab1);
  auto l2 = reinterpret_cast<const mcl::LAB*>(lab2);
  return mcl::cie_2000(*l1, *l2);
}
