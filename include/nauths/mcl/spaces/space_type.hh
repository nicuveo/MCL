//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_SPACE_TYPE_HH_
# define MCL_SPACE_TYPE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <array>
# include <iostream>
# include <boost/preprocessor.hpp>
# include "nauths/mcl/spaces/space_macros.hh"
# include "nauths/mcl/misc/math.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_CMY   0
# define MCL_CMYK  1
# define MCL_HSL   2
# define MCL_HSV   3
# define MCL_LAB   4
# define MCL_LCH   5
# define MCL_RGB   6
# define MCL_RGBf  7
# define MCL_RGBub 8
# define MCL_XYZ   9

# define MCL_SPACES (CMY) (CMYK) (HSL) (HSV) (LAB) (LCH) (RGB) (RGBf) (RGBub) (XYZ)
# define MCL_SPACES_ENUM BOOST_PP_SEQ_ENUM(MCL_SPACES)
# define MCL_SPACES_CARD BOOST_PP_SEQ_SIZE(MCL_SPACES)

# define MCL_DECL_enum(Z, I, D) BOOST_PP_SEQ_ELEM(I, MCL_SPACES) = I



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  namespace spaces
  {

    // enum

    enum Type
    {
      BOOST_PP_ENUM(MCL_SPACES_CARD, MCL_DECL_enum, _)
    };


    // operators

    MCL_IL_DECL_OPS(Type);

  }


  // alias

  typedef spaces::Type SpaceType;


  // constants

  extern const SpaceType COLOR_SPACES[MCL_SPACES_CARD];

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_DECL_enum



#endif /* !MCL_SPACE_TYPE_HH_ */
