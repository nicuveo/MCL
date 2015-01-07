//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_RGB_HH_
# define MCL_RGB_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/misc/types.hh"
# include "nauths/mcl/spaces/space_type.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  namespace il
  {

    // predeclarations

    template <typename T> class  RGBBase;
    template <typename T> struct RGBTraits;


    // rgb class

    /*! \brief [RGB]   r: [0..1]; g: [0..1]; b: [0..1]; a: [0..1] \n \
               [RGBf]  r: [0..1]; g: [0..1]; b: [0..1]; a: [0..1] \n \
               [RGBub] r: [0..255]; g: [0..255]; b: [0..255]; a: [0..255] \n */
    template <typename T>
    class RGBBase : public std::array<T, 4>
    {
      public:
        // types

        typedef T Value;
        typedef RGBBase<T> Self;
        typedef std::array<T, 4> Super;
        typedef typename RGBTraits<Self>::Reference Reference;

        enum Key
        {
          R     = 0,
          G     = 1,
          B     = 2,
          A     = 3,
          ALPHA = 3
        };


        // constructors

        RGBBase();
        RGBBase(Value r, Value g, Value b);
        RGBBase(Value r, Value g, Value b, Value a);


        // getters

        static Value min();
        static Value max();

        static SpaceType type() { return RGBTraits<Self>::type(); }

        Value  r() const        { return std::get<R>(*this);      }
        Value  g() const        { return std::get<G>(*this);      }
        Value  b() const        { return std::get<B>(*this);      }
        Value  a() const        { return std::get<A>(*this);      }
        Value& r()              { return std::get<R>(*this);      }
        Value& g()              { return std::get<G>(*this);      }
        Value& b()              { return std::get<B>(*this);      }
        Value& a()              { return std::get<A>(*this);      }

        Value  alpha() const    { return a();                     }
        Value& alpha()          { return a();                     }


        // modifiers

        void r(Value x)         { r() = x;                        }
        void g(Value x)         { g() = x;                        }
        void b(Value x)         { b() = x;                        }
        void a(Value x)         { a() = x;                        }

        void alpha(Value x)     { a(x);                           }

        void    clamp();
        RGBBase clamped() const;

        void    round  (double to = MCL_DEFAULT_ROUND);
        RGBBase rounded(double to = MCL_DEFAULT_ROUND) const;
    };


    typedef RGBBase<double> RGB;
    typedef RGBBase<float>  RGBf;
    typedef RGBBase<byte>   RGBub;


    // rgb traits

    template <>
    struct RGBTraits<RGB>
    {
      public:
        typedef RGB Reference;
        static SpaceType type() { return spaces::RGB; }
    };

    template <>
    struct RGBTraits<RGBf>
    {
      public:
        typedef RGB Reference;
        static SpaceType type() { return spaces::RGBf; }
    };

    template <>
    struct RGBTraits<RGBub>
    {
      public:
        typedef RGB Reference;
        static SpaceType type() { return spaces::RGBub; }
    };


    // operators

    MCL_IL_DECL_OPS(RGB);
    MCL_IL_DECL_OPS(RGBf);
    MCL_IL_DECL_OPS(RGBub);

  }


  // aliases

  typedef il::RGB   RGB;
  typedef il::RGBf  RGBf;
  typedef il::RGBub RGBub;

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/spaces/rgb.hxx"



#endif /* !MCL_RGB_HH_ */
