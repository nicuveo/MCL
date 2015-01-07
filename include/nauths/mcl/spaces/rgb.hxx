//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_RGB_HXX_
# define MCL_RGB_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/rgb.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{

  namespace il
  {


    // getters

    template <> inline RGBub::Value RGBub::min() { return   0; }
    template <> inline RGBub::Value RGBub::max() { return 255; }
    template <> inline RGBf::Value  RGBf::min()  { return 0.f; }
    template <> inline RGBf::Value  RGBf::max()  { return 1.f; }
    template <> inline RGB::Value   RGB::min()   { return 0.0; }
    template <> inline RGB::Value   RGB::max()   { return 1.0; }



    // modifiers

    template <typename T>
    inline RGBBase<T>
    RGBBase<T>::clamped() const
    {
      RGBBase<T> r = *this;
      r.clamp();
      return r;
    }

    template <typename T>
    inline void
    RGBBase<T>::clamp()
    {
      *this = {
        il::clamp(r(), min(), max()),
        il::clamp(g(), min(), max()),
        il::clamp(b(), min(), max()),
        il::clamp(a(), min(), max())
      };
    }


    template <typename T>
    inline RGBBase<T>
    RGBBase<T>::rounded(double to) const
    {
      RGBBase<T> r = *this;
      r.round(to);
      return r;
    }

    template <>
    inline void
    RGB::round(double to)
    {
      *this = {
        il::round(r(), to),
        il::round(g(), to),
        il::round(b(), to),
        il::round(a(), to)
      };
    }

    template <>
    inline void
    RGBf::round(double to)
    {
      *this = {
        static_cast<float>(il::round(r(), to)),
        static_cast<float>(il::round(g(), to)),
        static_cast<float>(il::round(b(), to)),
        static_cast<float>(il::round(a(), to))
      };
    }

    template <>
    inline void
    RGBub::round(double)
    {
    }


  }

}



#endif /* !MCL_RGB_HXX_ */
