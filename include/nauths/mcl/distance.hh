//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_DISTANCE_HH_
# define MCL_DISTANCE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color.hh"
# include "nauths/mcl/convert.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  // typedef

  typedef double (*DistanceFunction)(const Color&, const Color&, const Environment&);


  // constants

  extern const DistanceFunction CIE_1976;
  extern const DistanceFunction CIE_1994;
  extern const DistanceFunction CIE_2000;


  // functions

  template <typename C1, typename C2> double cie_1976(C1  const& c1, C2  const& c2, const Environment&);
  template <typename C1, typename C2> double cie_1976(C1  const& c1, C2  const& c2);
                                      double cie_1976(LAB const& c1, LAB const& c2);

  template <typename C1, typename C2> double cie_1994(C1  const& c1, C2  const& c2, const Environment&);
  template <typename C1, typename C2> double cie_1994(C1  const& c1, C2  const& c2);
                                      double cie_1994(LAB const& c1, LAB const& c2);

  template <typename C1, typename C2> double cie_2000(C1  const& c1, C2  const& c2, const Environment&);
  template <typename C1, typename C2> double cie_2000(C1  const& c1, C2  const& c2);
                                      double cie_2000(LAB const& c1, LAB const& c2);


  // wrapper

  double delta_e(const DistanceFunction& f, const Color& c1, const Color& c2, const Environment& e);
  double delta_e(const DistanceFunction& f, const Color& c1, const Color& c2);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/distance.hxx"



#endif /* !MCL_DISTANCE_HH_ */
