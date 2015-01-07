//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_SPACE_MACROS_HH_
# define MCL_SPACE_MACROS_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_DEFAULT_ROUND 0.001

# ifndef MCL_NO_IOSTREAM_OPS

#  define MCL_IL_DECL_OPS(S)                                    \
  std::ostream& operator<< (std::ostream&, const S&);           \
  std::istream& operator>> (std::istream&,       S&)            \

#  define MCL_IL_IMPL_OPS(S)                    \
  std::ostream&                                 \
  operator<<(std::ostream& ostr, const S& s)    \
  {                                             \
    show(ostr, s);                              \
    return ostr;                                \
  }                                             \
                                                \
  std::istream&                                 \
  operator>>(std::istream& istr, S& s)          \
  {                                             \
    s = read<S>(istr);                          \
    return istr;                                \
  }                                             \

# else

#  define MCL_IL_DECL_OPS(S)
#  define MCL_IL_IMPL_OPS(S)

# endif



#endif /* !MCL_SPACE_MACROS_HH_ */
