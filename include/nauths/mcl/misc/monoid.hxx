//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_MONOID_HXX_
# define MCL_MONOID_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <numeric>
# include "nauths/mcl/misc/monoid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // functions

  template <typename T, typename I>
  inline T
  concat(I first, I last)
  {
    return std::accumulate(first,
                           last,
                           Monoid<T>::empty(),
                           Monoid<T>::append);
  }

  template <typename T, typename C>
  inline T
  concat(C const& c)
  {
    return concat<T>(c.begin(), c.end());
  }


}



#endif /* !MCL_MONOID_HXX_ */
