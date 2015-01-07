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

#include "nauths/mcl/interpolation.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_IMPL_sitp(R, D, S) case spaces::S: return interpolate<S>(c1, c2, f, e);
#define MCL_IMPL_ditp(R, D, S)                          \
  template <>                                           \
  S                                                     \
  interpolate(S const& c1, S const& c2, double f)       \
  {                                                     \
    S res;                                              \
    interpolate(res, c1, c2, f);                        \
    return res;                                         \
  }                                                     \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace mcl
{

  namespace
  {

    template <typename T> T    round(double x) { return x;       }
    template <>           byte round(double x) { return x + 0.5; }

    template <typename T, std::size_t N>
    void interpolate(std::array<T, N>& out,
                     std::array<T, N> const& in1,
                     std::array<T, N> const& in2,
                     double f)
    {
      for (std::size_t i = 0; i < N; ++i)
        out[i] = round<T>(in1[i] * (1.0 - f) + in2[i] * f);
    }


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  Color
  interpolate(SpaceType s, const Color& c1, const Color& c2, double f, const Environment& e)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_sitp, _, MCL_SPACES)
    }

    return Color();
  }

  BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_ditp, _, MCL_SPACES)


}
