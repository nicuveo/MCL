//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_IO_HXX_
# define MCL_IO_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/convert.hh"
# include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_IMPL_show(R, D, S)                   \
  inline std::string                              \
  show(const S& c)                                \
  {                                               \
    std::stringstream ss;                         \
    show(ss, c);                                  \
    return ss.str();                              \
  }                                               \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // functions

  inline std::string
  show(const Color& c)
  {
    std::stringstream ss;
    show(ss, c);
    return ss.str();
  }


  BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_show, _, MCL_SPACES)


  template <typename T>
  inline T
  read(const std::string& s)
  {
    return to<T>(read<Color>(s));
  }

  template <typename T>
  inline T
  read(std::istream& i)
  {
    return to<T>(read<Color>(i));
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_IMPL_show_o
# undef MCL_IMPL_show_s



#endif /* !MCL_IO_HXX_ */
