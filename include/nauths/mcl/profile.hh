//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_PROFILE_HH_
# define MCL_PROFILE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <algorithm>
# include <functional>
# include "nauths/mcl/spaces/xyz.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  template <typename T>
  class Profile
  {
    public:
      // types

      typedef T Space;
      typedef std::function<XYZ (const Space&)> ToXYZ;
      typedef std::function<Space (const XYZ&)> FromXYZ;
      typedef std::function<void ()> DeleteCallback;


      // constructors

      Profile(const ToXYZ&, const FromXYZ&);
      Profile(const ToXYZ&, const FromXYZ&, const DeleteCallback&);
      ~Profile();


      // static constructors

      static Profile from_icc_file(); // TODO


      // operators

      Space operator()(const XYZ&) const;
      XYZ operator()(const Space&) const;


      // getters

      const ToXYZ& to_xyz() const;
      const FromXYZ& from_xyz() const;


    private:
      // data

      ToXYZ to_;
      FromXYZ from_;
      DeleteCallback rm_;
  };

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/profile.hxx"



#endif /* !MCL_PROFILE_HH_ */
