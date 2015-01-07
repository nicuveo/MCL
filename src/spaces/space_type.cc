//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "nauths/mcl/spaces/space_type.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_ENUM(S, D, E) spaces::E



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{

  namespace spaces
  {


    // operators

    MCL_IL_IMPL_OPS(Type)


  }



  // constants

  const SpaceType COLOR_SPACES[] = {BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(MCL_ENUM, _, MCL_SPACES))};


}
