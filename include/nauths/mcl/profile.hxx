//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_PROFILE_HXX_
# define MCL_PROFILE_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/profile.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  template <typename T>
  Profile<T>::Profile(const ToXYZ& to, const FromXYZ& from)
    : to_(to), from_(from)
  {
  }

  template <typename T>
  Profile<T>::Profile(const ToXYZ& to, const FromXYZ& from, const DeleteCallback& rm)
    : to_(to), from_(from), rm_(rm)
  {
  }

  template <typename T>
  Profile<T>::~Profile()
  {
    if (rm_)
      rm_();
  }



  // operators

  template <typename T>
  inline typename Profile<T>::Space
  Profile<T>::operator()(const XYZ& c) const
  {
    return from_(c);
  }

  template <typename T>
  inline XYZ
  Profile<T>::operator()(const Space& c) const
  {
    return to_(c);
  }



  // getters

  template <typename T>
  inline const typename Profile<T>::ToXYZ&
  Profile<T>::to_xyz() const
  {
    return to_;
  }

  template <typename T>
  inline const typename Profile<T>::FromXYZ&
  Profile<T>::from_xyz() const
  {
    return from_;
  }


}



#endif /* !MCL_PROFILE_HXX_ */
