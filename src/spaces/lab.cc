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

#include "nauths/mcl/spaces/lab.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  LAB::LAB()
    : LAB(100.0, 0.0, 0.0)
  {
  }

  LAB::LAB(Value l, Value a, Value b)
    : LAB(l, a, b, 1.0)
  {
  }

  LAB::LAB(Value l, Value a, Value b, Value alpha)
    : Super({{l, a, b, alpha}})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(LAB)


}
