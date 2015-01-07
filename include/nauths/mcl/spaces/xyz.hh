//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_XYZ_HH_
# define MCL_XYZ_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/space_type.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  /// \brief x: [0..120]; y: [0..120]; z: [0..120]; a: [0..1] \n
  class XYZ : public std::array<double, 4>
  {
    public:
      // types

      typedef double Value;
      typedef XYZ Reference;
      typedef std::array<Value, 4> Super;

      enum Key
      {
        X     = 0,
        Y     = 1,
        Z     = 2,
        A     = 3,
        ALPHA = 3
      };


      // constructors

      XYZ();
      XYZ(Value l, Value c, Value h);
      XYZ(Value l, Value c, Value h, Value a);


      // getters

      static SpaceType type() { return spaces::XYZ;        }


      Value  x() const        { return std::get<X>(*this); }
      Value  y() const        { return std::get<Y>(*this); }
      Value  z() const        { return std::get<Z>(*this); }
      Value  a() const        { return std::get<A>(*this); }
      Value& x()              { return std::get<X>(*this); }
      Value& y()              { return std::get<Y>(*this); }
      Value& z()              { return std::get<Z>(*this); }
      Value& a()              { return std::get<A>(*this); }

      Value  alpha() const    { return a();                }
      Value& alpha()          { return a();                }


      // modifiers

      void x(Value n)         { x() = n;                   }
      void y(Value n)         { y() = n;                   }
      void z(Value n)         { z() = n;                   }
      void a(Value n)         { a() = n;                   }

      void alpha(Value x)     { a(x);                      }

      void clamp();
      XYZ  clamped() const;

      void round  (double to = MCL_DEFAULT_ROUND);
      XYZ  rounded(double to = MCL_DEFAULT_ROUND) const;
  };


  // operators

  MCL_IL_DECL_OPS(XYZ);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/xyz.hxx"



#endif /* !MCL_XYZ_HH_ */
