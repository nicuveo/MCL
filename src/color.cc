//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include "nauths/mcl/transform.hh"
#include "nauths/mcl/color.hh"
#include "nauths/mcl/io.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_IMPL_constructor(R, D, S) Color::Color(const S& s) : Data(s) {}
#define MCL_INST(R, D, S)                                 \
  template Color& Color::to<S>();                         \
  template Color& Color::to<S>(const Environment&);       \
  template Color  Color::to<S>()                   const; \
  template Color  Color::to<S>(const Environment&) const; \

#define MCL_SWITCH(R, E, S) case BOOST_PP_CAT(MCL_, S): return to<S>(E);
#define MCL_APPLY(X, E)     boost::apply_visitor(ConvertVisitor<T>(X, E), X)



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace mcl
{

  namespace
  {


    // type visitor

    struct TypeVisitor : public boost::static_visitor<SpaceType>
    {
      public:
        template <typename T>
        inline SpaceType
        operator()(const T&) const
        {
          return T::type();
        }
    };



    // alpha visitor

    struct AlphaGetVisitor : public boost::static_visitor<double>
    {
      public:
        template <typename T>
        inline double
        operator()(const T& space) const
        {
          return space.alpha();
        }

        inline double
        operator()(const RGBub& space) const
        {
          return space.alpha() / 255.0;
        }
    };

    struct AlphaSetVisitor : public boost::static_visitor<>
    {
      public:
        AlphaSetVisitor(double a)
          : a_(a)
        {
        }

        template <typename T>
        inline void
        operator()(T& space) const
        {
          space.alpha() = a_;
        }

        inline void
        operator()(RGBub& space) const
        {
          space.alpha() = a_ * 255.0;
        }

      private:
        double a_;
    };



    // grey visitor

    struct GreyVisitor : public boost::static_visitor<>
    {
      public:
        GreyVisitor(const Environment& env)
          : env_(env)
        {
        }

        template <typename T>
        inline void
        operator()(T& space) const
        {
          space = greyed<T>(space, env_);
        }

      private:
        const Environment& env_;
    };



    // convert visitor

    template <typename T>
    struct ConvertVisitor : public boost::static_visitor<>
    {
      public:
        ConvertVisitor(il::ColorData& data, const Environment& env)
          : data_(data), env_(env)
        {
        }

        template <typename U>
        inline void
        operator()(const U& space) const
        {
          data_ = to<T>(space, env_);
        }

        inline void
        operator()(const T&) const
        {
        }

      private:
        il::ColorData& data_;
        const Environment& env_;
    };



    // clamp visitor

    struct ClampVisitor : public boost::static_visitor<>
    {
      public:
        template <typename T>
        inline void
        operator()(T& s) const
        {
          s.clamp();
        }
    };



    // round visitor

    struct RoundVisitor : public boost::static_visitor<>
    {
      public:
        RoundVisitor(double to)
          : to_(to)
        {
        }

        template <typename T>
        inline void
        operator()(T& s) const
        {
          s.round(to_);
        }

      private:
        double to_;
    };


  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace mcl
{


  // constructors

  Color::Color()
    : Data(RGB())
  {
  }

  BOOST_PP_SEQ_FOR_EACH(MCL_IMPL_constructor, _, MCL_SPACES)



  // operators

  MCL_IL_IMPL_OPS(Color)



  // getters

  SpaceType
  Color::type() const
  {
    return boost::apply_visitor(TypeVisitor(), *this);
  }

  double
  Color::alpha() const
  {
    return boost::apply_visitor(AlphaGetVisitor(), *this);
  }


  template <typename T>
  Color&
  Color::to()
  {
    MCL_APPLY(*this, Environment::DEFAULT);
    return *this;
  }

  template <typename T>
  Color&
  Color::to(const Environment& e)
  {
    MCL_APPLY(*this, e);
    return *this;
  }

  template <typename T>
  Color
  Color::to() const
  {
    Color res = *this;
    MCL_APPLY(res, Environment::DEFAULT);
    return res;
  }

  template <typename T>
  Color
  Color::to(const Environment& e) const
  {
    Color res = *this;
    MCL_APPLY(res, e);
    return res;
  }

  Color&
  Color::to(SpaceType s)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(MCL_SWITCH, Environment::DEFAULT, MCL_SPACES);
    }
    return *this;
  }

  Color&
  Color::to(SpaceType s, const Environment& e)
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(MCL_SWITCH, e, MCL_SPACES);
    }
    return *this;
  }

  Color
  Color::to(SpaceType s) const
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(MCL_SWITCH, Environment::DEFAULT, MCL_SPACES);
    }
    return *this;
  }

  Color
  Color::to(SpaceType s, const Environment& e) const
  {
    switch (s)
    {
      BOOST_PP_SEQ_FOR_EACH(MCL_SWITCH, e, MCL_SPACES);
    }
    return *this;
  }



  // modifiers

  void
  Color::gray(const Environment& e)
  {
    boost::apply_visitor(GreyVisitor(e), *this);
  }

  void
  Color::grey(const Environment& e)
  {
    boost::apply_visitor(GreyVisitor(e), *this);
  }


  void
  Color::alpha(double a)
  {
    return boost::apply_visitor(AlphaSetVisitor(a), *this);
  }


  void
  Color::clamp()
  {
    boost::apply_visitor(ClampVisitor(), *this);
  }

  void
  Color::round(double to)
  {
    boost::apply_visitor(RoundVisitor(to), *this);
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Instantiation

namespace mcl
{


  BOOST_PP_SEQ_FOR_EACH(MCL_INST, _, MCL_SPACES)


}
