//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_COLOR_MAP_HH_
# define MCL_COLOR_MAP_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <map>
# include "nauths/mcl/interpolation.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  class ColorMap : public std::map<double, Color>
  {
    public:
      // types

      typedef double                                 Key;
      typedef Color                                  Value;
      typedef std::map<double, Color>                Super;
      typedef Interpolation<Color>                   InterpolationFunction;
      typedef std::function<Color (const ColorMap&)> DomainFunction;


      // constructors

      ColorMap(const InterpolationFunction& interpolation,
               const DomainFunction&        underflow,
               const DomainFunction&        overflow);

      static ColorMap fallback(const InterpolationFunction&, const Color&);
      static ColorMap strict  (const InterpolationFunction&);
      static ColorMap clamp   (const InterpolationFunction&);


      // getters

      Value get(Key k) const;
      Value compute(Key k);

      Key min() const;
      Key max() const;
      const Value& min_value() const;
      const Value& max_value() const;


    private:

      // helpers

      static Color d_fallback   (const ColorMap&, const Color&);
      static Color d_clamp_under(const ColorMap&);
      static Color d_clamp_over (const ColorMap&);
      static Color d_strict     (const ColorMap&);


      // data

      InterpolationFunction i_;
      DomainFunction u_;
      DomainFunction o_;
  };

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/color_map.hxx"



#endif /* !MCL_COLOR_MAP_HH_ */
