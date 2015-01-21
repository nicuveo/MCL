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

#include "nauths/mcl/spaces/hsl.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  HSL::HSL()
    : HSL(0.0, 1.0, 1.0)
  {
  }

  HSL::HSL(Value h, Value s, Value l)
    : HSL(h, s, l, 1.0)
  {
  }

  HSL::HSL(Value h, Value s, Value l, Value a)
    : Super({{h, s, l, a}})
  {
  }



  // operators

  MCL_IL_IMPL_OPS(HSL)


}
