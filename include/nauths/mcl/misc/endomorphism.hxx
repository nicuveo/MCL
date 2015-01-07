//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_ENDOMORPHISM_HXX_
# define MCL_ENDOMORPHISM_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/misc/endomorphism.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // functions

  template <typename T>
  inline Endomorphism<T>
  compose(const Endomorphism<T>& f, const Endomorphism<T>& g)
  {
    using namespace std::placeholders;
    return std::bind(f, std::bind(g, _1));
  }

  template <typename T>
  inline T
  id(T const& x)
  {
    return x;
  }


  // impl

  template <typename T>
  inline Endomorphism<T>
  Monoid<Endomorphism<T>>::empty()
  {
    return id<T>;
  }

  template <typename T>
  inline Endomorphism<T>
  Monoid<Endomorphism<T>>::append(const Endomorphism<T>& f, const Endomorphism<T>& g)
  {
    return compose(f, g);
  }



  // operators

# ifndef MCL_NO_ENDOMORPHISM_OPS

  template <typename T>
  T operator|(T const& x, const Endomorphism<T>& f)
  {
    return f(x);
  }

  template <typename T>
  inline Endomorphism<T>
  operator,(const Endomorphism<T>& f, const Endomorphism<T>& g)
  {
    return compose(f, g);
  }

# endif


}



#endif /* !MCL_ENDOMORPHISM_HXX_ */
