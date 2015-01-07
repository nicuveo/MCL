//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_LAB_HH_
# define MCL_LAB_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/xyz.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief l: [0..100]; a: [-120..120]; b: [-120..120]; alpha: [0..1] \n
  class LAB : public std::array<double, 4>
  {
    public:
      // types

      typedef double Value;
      typedef XYZ Reference;
      typedef std::array<Value, 4> Super;

      enum Key
      {
        L     = 0,
        A     = 1,
        B     = 2,
        ALPHA = 3
      };


      // constructors

      LAB();
      LAB(Value l, Value a, Value b);
      LAB(Value l, Value a, Value b, Value alpha);


      // getters

      static SpaceType type() { return spaces::LAB;            }

      Value  l() const        { return std::get<L>(*this);     }
      Value  a() const        { return std::get<A>(*this);     }
      Value  b() const        { return std::get<B>(*this);     }
      Value& l()              { return std::get<L>(*this);     }
      Value& a()              { return std::get<A>(*this);     }
      Value& b()              { return std::get<B>(*this);     }

      Value  alpha() const    { return std::get<ALPHA>(*this); }
      Value& alpha()          { return std::get<ALPHA>(*this); }


      // modifiers

      void l(Value x)         { l() = x;                       }
      void a(Value x)         { a() = x;                       }
      void b(Value x)         { b() = x;                       }

      void alpha(Value x)     { alpha() = x;                   }

      void clamp();
      LAB  clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      LAB  rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(LAB);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/lab.hxx"



#endif /* !MCL_LAB_HH_ */
