//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MATH_HH_
# define MATH_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <cmath>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  namespace il
  {

    template <typename T>
    inline constexpr T clamp(T value, T min, T max)
    {
      return value <= min ? min : value >= max ? max : value;
    }

    inline constexpr double clean(double value)
    {
      return value == 0.0 ? 0.0 : value;
    }

    inline double round(double value, double to)
    {
      return clean(std::round(value / to) * to);
    }

    inline double d_mod(double value)
    {
      return std::fmod(std::fmod(value, 360.0) + 360.0, 360.0);
    }

  }

}



#endif /* !MATH_HH_ */
