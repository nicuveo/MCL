//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CMY_HH_
# define MCL_CMY_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/cmyk.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief c: [0..1]; m: [0..1]; y: [0..1]; a: [0..1] \n
  class CMY : public std::array<double, 4>
  {
    public:
      // types

      typedef double Value;
      typedef CMYK Reference;
      typedef std::array<Value, 4> Super;

      enum Key
      {
        C     = 0,
        M     = 1,
        Y     = 2,
        A     = 3,
        ALPHA = 3
      };


      // constructors

      CMY();
      CMY(Value c, Value m, Value y);
      CMY(Value c, Value m, Value y, Value a);


      // getters

      static SpaceType type() { return spaces::CMY;        }

      Value  c() const        { return std::get<C>(*this); }
      Value  m() const        { return std::get<M>(*this); }
      Value  y() const        { return std::get<Y>(*this); }
      Value  a() const        { return std::get<A>(*this); }
      Value& c()              { return std::get<C>(*this); }
      Value& m()              { return std::get<M>(*this); }
      Value& y()              { return std::get<Y>(*this); }
      Value& a()              { return std::get<A>(*this); }

      Value  alpha() const    { return a();                }
      Value& alpha()          { return a();                }


      // modifiers

      void c(Value x)         { c() = x;                   }
      void m(Value x)         { m() = x;                   }
      void y(Value x)         { y() = x;                   }
      void a(Value x)         { a() = x;                   }

      void alpha(Value x)     { a(x);                      }

      void clamp();
      CMY  clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      CMY  rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(CMY);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/cmy.hxx"



#endif /* !MCL_CMY_HH_ */
