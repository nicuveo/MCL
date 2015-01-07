//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_COLOR_HXX_
# define MCL_COLOR_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/convert.hh"
# include "nauths/mcl/color.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // operators

  inline bool
  operator==(const Color& c1, const Color& c2)
  {
    return c1.data() == c2.data();
  }

  inline bool
  operator!=(const Color& c1, const Color& c2)
  {
    return not (c1.data() == c2.data());
  }



  // getters

  inline Color::Data&
  Color::data()
  {
    return *this;
  }

  inline const Color::Data&
  Color::data() const
  {
    return *this;
  }


  inline double
  Color::lightness() const
  {
    return get<LAB>().l();
  }


  template <typename T>
  inline const T&
  Color::get()
  {
    return boost::get<T>(to<T>());
  }

  template <typename T>
  inline const T&
  Color::get(const Environment& e)
  {
    return boost::get<T>(to<T>(e));
  }


  template <typename T>
  inline T
  Color::get() const
  {
    return boost::get<T>(to<T>());
  }

  template <typename T>
  inline T
  Color::get(const Environment& e) const
  {
    return boost::get<T>(to<T>(e));
  }



  // modifiers

  inline void
  Color::gray()
  {
    gray(Environment::DEFAULT);
  }

  inline void
  Color::grey()
  {
    grey(Environment::DEFAULT);
  }

  inline Color
  Color::grayed() const
  {
    return grayed(*this, Environment::DEFAULT);
  }

  inline Color
  Color::greyed() const
  {
    return greyed(*this, Environment::DEFAULT);
  }

  inline Color
  Color::grayed(const Environment& e) const
  {
    return grayed(*this, e);
  }

  inline Color
  Color::greyed(const Environment& e) const
  {
    return greyed(*this, e);
  }

  template <typename T>
  inline T
  Color::grayed(T const& c)
  {
    return grayed(c, Environment::DEFAULT);
  }

  template <typename T>
  inline T
  Color::greyed(T const& c)
  {
    return greyed(c, Environment::DEFAULT);
  }

  template <typename T>
  inline T
  Color::grayed(T const& c, const Environment& e)
  {
    return mcl::to<T>(grayed(mcl::to<LAB>(c, e)), e);
  }

  template <typename T>
  inline T
  Color::greyed(T const& c, const Environment& e)
  {
    return mcl::to<T>(greyed(mcl::to<LAB>(c, e)), e);
  }

  template <>
  inline LAB
  Color::grayed(LAB const& c, const Environment&)
  {
    return LAB(c.l(), 0.0, 0.0, c.alpha());
  }

  template <>
  inline LAB
  Color::greyed(LAB const& c, const Environment&)
  {
    return LAB(c.l(), 0.0, 0.0, c.alpha());
  }


  inline void
  Color::opaque()
  {
    alpha(1.0);
  }

  inline void
  Color::transparent()
  {
    alpha(0.0);
  }

  inline Color
  Color::to_opaque() const
  {
    return with_alpha(*this, 1.0);
  }

  inline Color
  Color::to_transparent() const
  {
    return with_alpha(*this, 0.0);
  }

  inline Color
  Color::with_alpha(double a) const
  {
    return with_alpha(*this, a);
  }

  template <typename T>
  inline T
  Color::to_opaque(T const& c)
  {
    return with_alpha(c, 1.0);
  }

  template <typename T>
  inline T
  Color::to_transparent(T const& c)
  {
    return with_alpha(c, 0.0);
  }

  template <typename T>
  inline T
  Color::with_alpha(T const& c, double a)
  {
    T r = c;
    r.alpha(a);
    return r;
  }


  inline void
  Color::lightness(double l)
  {
    lightness(l, Environment::DEFAULT);
  }

  inline Color
  Color::with_lightness(double l) const
  {
    return with_lightness(*this, l, Environment::DEFAULT);
  }

  inline Color
  Color::with_lightness(double l, const Environment& e) const
  {
    return with_lightness(*this, l, e);
  }

  template <typename T>
  inline T
  Color::with_lightness(T const& c, double l)
  {
    return with_lightness(c, l, Environment::DEFAULT);
  }

  template <typename T>
  inline T
  Color::with_lightness(T const& c, double l, const Environment& e)
  {
    return mcl::to<T>(with_lightness(mcl::to<LAB>(c, e), l), e);
  }

  template <>
  inline LAB
  Color::with_lightness(LAB const& c, double l, const Environment&)
  {
    return LAB(l, c.a(), c.b(), c.alpha());
  }


  inline Color
  Color::clamped() const
  {
    return clamped(*this);
  }

  inline Color
  Color::rounded(double to) const
  {
    return rounded(*this, to);

  }

  template <typename T>
  inline T
  Color::clamped(T const& c)
  {
    T r = c;
    r.clamp();
    return r;
  }

  template <typename T>
  inline T
  Color::rounded(T const& c, double to)
  {
    T r = c;
    r.round(to);
    return r;
  }



}



#endif /* !MCL_COLOR_HXX_ */
