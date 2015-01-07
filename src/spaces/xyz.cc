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

#include "nauths/mcl/spaces/xyz.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  XYZ::XYZ()
    : XYZ(100.0, 0.0, 0.0)
  {
  }

  XYZ::XYZ(Value x, Value y, Value z)
    : XYZ(x, y, z, 1.0)
  {
  }

  XYZ::XYZ(Value x, Value y, Value z, Value a)
    : Super({x, y, z, a})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(XYZ)


}
