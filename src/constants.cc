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

#include "nauths/mcl/constants.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_impl(R, D, C) const RGBub BOOST_PP_TUPLE_ELEM(5, 1, C) =   \
    RGBub(BOOST_PP_TUPLE_ELEM(5, 2, C),                                 \
          BOOST_PP_TUPLE_ELEM(5, 3, C),                                 \
          BOOST_PP_TUPLE_ELEM(5, 4, C));                                \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  BOOST_PP_SEQ_FOR_EACH(MCL_impl, _, MCL_COLOR_NAMES)


}
