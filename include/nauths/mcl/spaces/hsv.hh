//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_HSV_HH_
# define MCL_HSV_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/rgb.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief h: [0..360]; s: [0..1]; v: [0..1]; a: [0..1] \n
  class HSV : public std::array<double, 4>
  {
    public:
      // types

      typedef double Value;
      typedef RGB Reference;
      typedef std::array<Value, 4> Super;

      enum Key
      {
        H     = 0,
        S     = 1,
        V     = 2,
        A     = 3,
        ALPHA = 3
      };


      // constructors

      HSV();
      HSV(Value h, Value s, Value v);
      HSV(Value h, Value s, Value v, Value a);


      // getters

      static SpaceType type() { return spaces::HSV;        }

      Value  h() const        { return std::get<H>(*this); }
      Value  s() const        { return std::get<S>(*this); }
      Value  v() const        { return std::get<V>(*this); }
      Value  a() const        { return std::get<A>(*this); }
      Value& h()              { return std::get<H>(*this); }
      Value& s()              { return std::get<S>(*this); }
      Value& v()              { return std::get<V>(*this); }
      Value& a()              { return std::get<A>(*this); }

      Value  alpha() const    { return a();                }
      Value& alpha()          { return a();                }


      // modifiers

      void h(Value x)         { h() = x;                   }
      void s(Value x)         { s() = x;                   }
      void v(Value x)         { v() = x;                   }
      void a(Value x)         { a() = x;                   }

      void alpha(Value x)     { a(x);                      }

      void clamp();
      HSV  clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      HSV  rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(HSV);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/hsv.hxx"



#endif /* !MCL_HSV_HH_ */
