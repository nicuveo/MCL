//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_IO_HH_
# define MCL_IO_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <string>
# include <sstream>
# include "nauths/mcl/spaces/spaces.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_DECL_show(R, D, S)                                 \
  std::string show(               const S&);                    \
  void        show(std::ostream&, const S&);                    \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  // predeclarations

  class Color;


  // functions

  std::string show(SpaceType);
  std::string show(const Color&);
  void        show(std::ostream&, SpaceType);
  void        show(std::ostream&, const Color&);

  BOOST_PP_SEQ_FOR_EACH(MCL_DECL_show, _, MCL_SPACES)

  template <typename T> T         read(const std::string&);
  template <>           SpaceType read(const std::string&);
  template <>           Color     read(const std::string&);

  template <typename T> T         read(std::istream&);
  template <>           SpaceType read(std::istream&);
  template <>           Color     read(std::istream&);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_DECL_show



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/io.hxx"



#endif /* !MCL_IO_HH_ */
