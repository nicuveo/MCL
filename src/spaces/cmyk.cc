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

#include "nauths/mcl/spaces/cmyk.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  CMYK::CMYK()
    : CMYK(1.0, 1.0, 1.0, 1.0)
  {
  }

  CMYK::CMYK(Value c, Value m, Value y, Value k)
    : CMYK(c, m, y, k, 1.0)
  {
  }

  CMYK::CMYK(Value c, Value m, Value y, Value k, Value a)
    : Super({c, m, y, k, a})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(CMYK)


}
