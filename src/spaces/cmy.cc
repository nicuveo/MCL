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

#include "nauths/mcl/spaces/cmy.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  CMY::CMY()
    : CMY(1.0, 1.0, 1.0)
  {
  }

  CMY::CMY(Value c, Value m, Value y)
    : CMY(c, m, y, 1.0)
  {
  }

  CMY::CMY(Value c, Value m, Value y, Value a)
    : Super({c, m, y, a})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(CMY)


}
