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

#include "nauths/mcl/spaces/lch.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  LCH::LCH()
    : LCH(100.0, 100.0, 0.0)
  {
  }

  LCH::LCH(Value l, Value c, Value h)
    : LCH(l, c, h, 1.0)
  {
  }

  LCH::LCH(Value l, Value c, Value h, Value a)
    : Super({l, c, h, a})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(LCH)


}
