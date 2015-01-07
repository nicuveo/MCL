//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CMYK_HH_
# define MCL_CMYK_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/space_type.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief c: [0..1]; m: [0..1]; y: [0..1]; k: [0..1]; a: [0..1] \n
  class CMYK : public std::array<double, 5>
  {
    public:
      // types

      typedef double Value;
      typedef CMYK Reference;
      typedef std::array<Value, 5> Super;

      enum Key
      {
        C     = 0,
        M     = 1,
        Y     = 2,
        K     = 3,
        A     = 4,
        ALPHA = 4
      };


      // constructors

      CMYK();
      CMYK(Value c, Value m, Value y, Value k);
      CMYK(Value c, Value m, Value y, Value k, Value a);


      // getters

      static SpaceType type() { return spaces::CMYK;       }

      Value  c() const        { return std::get<C>(*this); }
      Value  m() const        { return std::get<M>(*this); }
      Value  y() const        { return std::get<Y>(*this); }
      Value  k() const        { return std::get<K>(*this); }
      Value  a() const        { return std::get<A>(*this); }
      Value& c()              { return std::get<C>(*this); }
      Value& m()              { return std::get<M>(*this); }
      Value& y()              { return std::get<Y>(*this); }
      Value& k()              { return std::get<K>(*this); }
      Value& a()              { return std::get<A>(*this); }

      Value  alpha() const    { return a();                }
      Value& alpha()          { return a();                }


      // modifiers

      void c(Value x)         { c() = x;                   }
      void m(Value x)         { m() = x;                   }
      void y(Value x)         { y() = x;                   }
      void k(Value x)         { k() = x;                   }
      void a(Value x)         { a() = x;                   }

      void alpha(Value x)     { a(x);                      }

      void clamp();
      CMYK clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      CMYK rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(CMYK);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/cmyk.hxx"



#endif /* !MCL_CMYK_HH_ */
