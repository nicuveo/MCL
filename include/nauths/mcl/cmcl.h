//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef CMCL_H
# define CMCL_H



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

void mcl_cmy_to_cmyk(const double* from, double* to);
void mcl_cmy_to_hsl (const double* from, double* to);
void mcl_cmy_to_hsv (const double* from, double* to);
void mcl_cmy_to_lab (const double* from, double* to);
void mcl_cmy_to_lch (const double* from, double* to);
void mcl_cmy_to_rgb (const double* from, double* to);
void mcl_cmy_to_xyz (const double* from, double* to);
void mcl_cmyk_to_cmy(const double* from, double* to);
void mcl_cmyk_to_hsl(const double* from, double* to);
void mcl_cmyk_to_hsv(const double* from, double* to);
void mcl_cmyk_to_lab(const double* from, double* to);
void mcl_cmyk_to_lch(const double* from, double* to);
void mcl_cmyk_to_rgb(const double* from, double* to);
void mcl_cmyk_to_xyz(const double* from, double* to);
void mcl_hsl_to_cmy (const double* from, double* to);
void mcl_hsl_to_cmyk(const double* from, double* to);
void mcl_hsl_to_hsv (const double* from, double* to);
void mcl_hsl_to_lab (const double* from, double* to);
void mcl_hsl_to_lch (const double* from, double* to);
void mcl_hsl_to_rgb (const double* from, double* to);
void mcl_hsl_to_xyz (const double* from, double* to);
void mcl_hsv_to_cmy (const double* from, double* to);
void mcl_hsv_to_cmyk(const double* from, double* to);
void mcl_hsv_to_hsl (const double* from, double* to);
void mcl_hsv_to_lab (const double* from, double* to);
void mcl_hsv_to_lch (const double* from, double* to);
void mcl_hsv_to_rgb (const double* from, double* to);
void mcl_hsv_to_xyz (const double* from, double* to);
void mcl_lab_to_cmy (const double* from, double* to);
void mcl_lab_to_cmyk(const double* from, double* to);
void mcl_lab_to_hsl (const double* from, double* to);
void mcl_lab_to_hsv (const double* from, double* to);
void mcl_lab_to_lch (const double* from, double* to);
void mcl_lab_to_rgb (const double* from, double* to);
void mcl_lab_to_xyz (const double* from, double* to);
void mcl_lch_to_cmy (const double* from, double* to);
void mcl_lch_to_cmyk(const double* from, double* to);
void mcl_lch_to_hsl (const double* from, double* to);
void mcl_lch_to_hsv (const double* from, double* to);
void mcl_lch_to_lab (const double* from, double* to);
void mcl_lch_to_rgb (const double* from, double* to);
void mcl_lch_to_xyz (const double* from, double* to);
void mcl_rgb_to_cmy (const double* from, double* to);
void mcl_rgb_to_cmyk(const double* from, double* to);
void mcl_rgb_to_hsl (const double* from, double* to);
void mcl_rgb_to_hsv (const double* from, double* to);
void mcl_rgb_to_lab (const double* from, double* to);
void mcl_rgb_to_lch (const double* from, double* to);
void mcl_rgb_to_xyz (const double* from, double* to);
void mcl_xyz_to_cmy (const double* from, double* to);
void mcl_xyz_to_cmyk(const double* from, double* to);
void mcl_xyz_to_hsl (const double* from, double* to);
void mcl_xyz_to_hsv (const double* from, double* to);
void mcl_xyz_to_lab (const double* from, double* to);
void mcl_xyz_to_lch (const double* from, double* to);
void mcl_xyz_to_rgb (const double* from, double* to);

double mcl_cie_1976(const double* lab1, const double* lab2);
double mcl_cie_1994(const double* lab1, const double* lab2);
double mcl_cie_2000(const double* lab1, const double* lab2);



#endif /* !CMLC_H */
