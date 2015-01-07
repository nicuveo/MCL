//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_TRANSFORM_HXX_
# define MCL_TRANSFORM_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color.hh"
# include "nauths/mcl/transform.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // transform functions

  template <typename T>
  inline T
  greyed(T const& c)
  {
    return Color::greyed(c);
  }

  template <typename T>
  inline T
  grayed(T const& c)
  {
    return Color::grayed(c);
  }

  template <typename T>
  inline T
  greyed(T const& c, const Environment& e)
  {
    return Color::greyed(c, e);
  }

  template <typename T>
  inline T
  grayed(T const& c, const Environment& e)
  {
    return Color::grayed(c, e);
  }


  template <typename T>
  inline T
  to_opaque(T const& c)
  {
    return Color::to_opaque(c);
  }

  template <typename T>
  inline T
  to_transparent(T const& c)
  {
    return Color::to_transparent(c);
  }

  template <typename T>
  inline T
  with_alpha(T const& c, double a)
  {
    return Color::with_alpha(c, a);
  }


  template <typename T>
  inline T
  with_lightness(T const& c, double l)
  {
    return Color::with_lightness(c, l);
  }

  template <typename T>
  inline T
  with_lightness(T const& c, double l, const Environment& e)
  {
    return Color::with_lightness(c, l, e);
  }


  template <typename T>
  inline T
  rounded(T const& c, double to = MCL_DEFAULT_ROUND)
  {
    return Color::rounded(c, to);
  }

  template <typename T>
  inline T
  clamped(T const& c)
  {
    return Color::clamped(c);
  }



  // endomorphism functions

  template <typename T>
  Endomorphism<T>
  grey()
  {
    static const Endomorphism<T> e = static_cast<T (*)(T const&)>(greyed<T>);
    return e;
  }

  template <typename T>
  Endomorphism<T>
  gray()
  {
    static const Endomorphism<T> e = static_cast<T (*)(T const&)>(grayed<T>);
    return e;
  }

  template <typename T>
  Endomorphism<T>
  grey(const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<T (*)(T const&, const Environment&)>(greyed<T>), _1, e);
  }

  template <typename T>
  Endomorphism<T>
  gray(const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<T (*)(T const&, const Environment&)>(grayed<T>), _1, e);
  }


  template <typename T>
  Endomorphism<T>
  opaque()
  {
    static const Endomorphism<T> e = static_cast<T (*)(T const&)>(to_opaque<T>);
    return e;
  }

  template <typename T>
  Endomorphism<T>
  transparent()
  {
    static const Endomorphism<T> e = static_cast<T (*)(T const&)>(to_transparent<T>);
    return e;
  }

  template <typename T>
  Endomorphism<T>
  alpha(double a)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<T (*)(T const&, double)>(with_alpha<T>), _1, a);
  }


  template <typename T>
  Endomorphism<T>
  lightness(double l)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<T (*)(T const&, double)>(with_lightness<T>), _1, l);
  }

  template <typename T>
  Endomorphism<T>
  lightness(double l, const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<T (*)(T const&, double, const Environment&)>(with_lightness<T>), _1, l, e);
  }


  template <typename T>
  Endomorphism<T>
  round(double to)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<T (*)(T const&, double)>(rounded<T>), _1, to);
  }

  template <typename T>
  Endomorphism<T>
  clamp()
  {
    static const Endomorphism<T> e = static_cast<T (*)(T const&)>(clamped<T>);
    return e;
  }



  // color endomorphism functions

  template <typename T>
  inline Endomorphism<Color>
  to()
  {
    using namespace std::placeholders;
    return std::bind(static_cast<Color (Color::*)() const>(&Color::to<T>), _1);
  }

  template <typename T>
  inline Endomorphism<Color>
  to(const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<Color (Color::*)(const Environment&) const>(&Color::to<T>), _1, e);
  }

  inline Endomorphism<Color>
  to(SpaceType s)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<Color (Color::*)(SpaceType) const>(&Color::to), _1, s);
  }

  inline Endomorphism<Color>
  to(SpaceType s, const Environment& e)
  {
    using namespace std::placeholders;
    return std::bind(static_cast<Color (Color::*)(SpaceType, const Environment&) const>(&Color::to), _1, s, e);
  }



}



#endif /* !MCL_TRANSFORM_HXX_ */
