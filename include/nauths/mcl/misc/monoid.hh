//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_MONOID_HH_
# define MCL_MONOID_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <functional>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{


  // typeclass

  template <typename T>
  struct Monoid
  {
    public:
      static T empty();
      static T append(T const&, T const&);
  };


  // functions

  template <typename T, typename I>
  T fold(I first, I last);

  template <typename T, typename C>
  T fold(C const& container);


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/misc/monoid.hxx"



#endif /* !MCL_MONOID_HH_ */
