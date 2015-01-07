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

#include "nauths/mcl/spaces/hsv.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  HSV::HSV()
    : HSV(0.0, 1.0, 1.0)
  {
  }

  HSV::HSV(Value h, Value s, Value v)
    : HSV(h, s, v, 1.0)
  {
  }

  HSV::HSV(Value h, Value s, Value v, Value a)
    : Super({h, s, v, a})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(HSV)


}
