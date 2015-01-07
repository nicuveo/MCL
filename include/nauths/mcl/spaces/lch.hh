//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_LCH_HH_
# define MCL_LCH_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/xyz.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief l: [0..100]; c: [-120..120]; h: [0..360]; a: [0..1] \n
  class LCH : public std::array<double, 4>
  {
    public:
      // types

      typedef double Value;
      typedef XYZ Reference;
      typedef std::array<Value, 4> Super;

      enum Key
      {
        L     = 0,
        C     = 1,
        H     = 2,
        A     = 3,
        ALPHA = 3
      };


      // constructors

      LCH();
      LCH(Value l, Value c, Value h);
      LCH(Value l, Value c, Value h, Value a);


      // getters

      static SpaceType type() { return spaces::LCH;        }

      Value  l() const        { return std::get<L>(*this); }
      Value  c() const        { return std::get<C>(*this); }
      Value  h() const        { return std::get<H>(*this); }
      Value  a() const        { return std::get<A>(*this); }
      Value& l()              { return std::get<L>(*this); }
      Value& c()              { return std::get<C>(*this); }
      Value& h()              { return std::get<H>(*this); }
      Value& a()              { return std::get<A>(*this); }

      Value  alpha() const    { return a();                }
      Value& alpha()          { return a();                }


      // modifiers

      void l(Value x)         { l() = x;                   }
      void c(Value x)         { c() = x;                   }
      void h(Value x)         { h() = x;                   }
      void a(Value x)         { a() = x;                   }

      void alpha(Value x)     { a(x);                      }

      void clamp();
      LCH  clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      LCH  rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(LCH);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/lch.hxx"



#endif /* !MCL_LCH_HH_ */
