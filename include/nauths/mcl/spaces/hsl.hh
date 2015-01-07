//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_HSL_HH_
# define MCL_HSL_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/rgb.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief h: [0..360]; s: [0..1]; l: [0..1]; a: [0..1] \n
  class HSL : public std::array<double, 4>
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
        L     = 2,
        A     = 3,
        ALPHA = 3
      };


      // constructors

      HSL();
      HSL(Value h, Value s, Value l);
      HSL(Value h, Value s, Value l, Value a);


      // getters

      static SpaceType type() { return spaces::HSL;        }

      Value  h() const        { return std::get<H>(*this); }
      Value  s() const        { return std::get<S>(*this); }
      Value  l() const        { return std::get<L>(*this); }
      Value  a() const        { return std::get<A>(*this); }
      Value& h()              { return std::get<H>(*this); }
      Value& s()              { return std::get<S>(*this); }
      Value& l()              { return std::get<L>(*this); }
      Value& a()              { return std::get<A>(*this); }

      Value  alpha() const    { return a();                }
      Value& alpha()          { return a();                }


      // modifiers

      void h(Value x)         { h() = x;                   }
      void s(Value x)         { s() = x;                   }
      void l(Value x)         { l() = x;                   }
      void a(Value x)         { a() = x;                   }

      void alpha(Value x)     { a(x);                      }

      void clamp();
      HSL  clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      HSL  rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(HSL);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/hsl.hxx"



#endif /* !MCL_HSL_HH_ */
