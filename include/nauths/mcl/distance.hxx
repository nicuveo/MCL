//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_DISTANCE_HXX_
# define MCL_DISTANCE_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/distance.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // functions

  template <typename C1, typename C2>
  inline double
  cie_1976(C1 const& c1, C2 const& c2, const Environment& e)
  {
    return cie_1976(to<LAB>(c1, e), to<LAB>(c2, e));
  }

  template <typename C1, typename C2>
  inline double
  cie_1994(C1 const& c1, C2 const& c2, const Environment& e)
  {
    return cie_1994(to<LAB>(c1, e), to<LAB>(c2, e));
  }

  template <typename C1, typename C2>
  inline double
  cie_2000(C1 const& c1, C2 const& c2, const Environment& e)
  {
    return cie_2000(to<LAB>(c1, e), to<LAB>(c2, e));
  }

  template <typename C1, typename C2>
  inline double
  cie_1976(C1 const& c1, C2 const& c2)
  {
    return cie_1976(c1, c2, Environment::DEFAULT);
  }

  template <typename C1, typename C2>
  inline double
  cie_1994(C1 const& c1, C2 const& c2)
  {
    return cie_1994(c1, c2, Environment::DEFAULT);
  }

  template <typename C1, typename C2>
  inline double
  cie_2000(C1 const& c1, C2 const& c2)
  {
    return cie_2000(c1, c2, Environment::DEFAULT);
  }



  // wrapper

  inline double
  delta_e(const DistanceFunction& f, const Color& c1, const Color& c2, const Environment& e)
  {
    return f(c1, c2, e);
  }

  inline double
  delta_e(const DistanceFunction& f, const Color& c1, const Color& c2)
  {
    return delta_e(f, c1, c2, Environment::DEFAULT);
  }


}



#endif /* !MCL_DISTANCE_HXX_ */
