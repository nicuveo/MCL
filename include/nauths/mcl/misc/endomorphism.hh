//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_ENDOMORPHISM_HH_
# define MCL_ENDOMORPHISM_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/misc/monoid.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  // types

  template <typename T>
  using Endomorphism = std::function<T (T const&)>;


  // functions

  template <typename T>
  Endomorphism<T> compose(const Endomorphism<T>& f, const Endomorphism<T>& g);

  template <typename T>
  T id(T const& x);


  // impl

  template <typename T>
  struct Monoid<Endomorphism<T>>
  {
    public:
      static Endomorphism<T> empty();
      static Endomorphism<T> append(const Endomorphism<T>&, const Endomorphism<T>&);
  };


  // operators

# ifndef MCL_NO_ENDOMORPHISM_OPS

  template <typename T>
  T operator|(T const& x, const Endomorphism<T>& f);

  template <typename T>
  Endomorphism<T> operator,(const Endomorphism<T>& f, const Endomorphism<T>& g);

# endif

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/misc/endomorphism.hxx"



#endif /* !MCL_ENDOMORPHISM_HH_ */
