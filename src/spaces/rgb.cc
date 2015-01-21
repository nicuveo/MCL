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

#include "nauths/mcl/spaces/rgb.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{

  namespace il
  {


    // constructors

    template <typename T>
    RGBBase<T>::RGBBase()
      : RGBBase(max(), max(), max())
    {
    }

    template <typename T>
    RGBBase<T>::RGBBase(Value r, Value g, Value b)
      : RGBBase(r, g, b, max())
    {
    }

    template <typename T>
    RGBBase<T>::RGBBase(Value r, Value g, Value b, Value a)
      : Super({{r, g, b, a}})
    {
    }



    // operators

    MCL_IL_IMPL_OPS(RGB)
    MCL_IL_IMPL_OPS(RGBf)
    MCL_IL_IMPL_OPS(RGBub)


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Instantiation

namespace mcl
{

  namespace il
  {


    template class RGBBase<byte>;
    template class RGBBase<float>;
    template class RGBBase<double>;


  }

}
