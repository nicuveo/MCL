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

#include "options.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  void print(const mcl::Color& c1, const mcl::Color& c2, double d, bool one, bool exact)
  {
    if (not one)
      std::cout << (exact ? c1 : c1.rounded().clamped()) <<  " "
                << (exact ? c2 : c2.rounded().clamped()) <<  " ";
    std::cout << d << std::endl;
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

int main(int argc, char const* const* argv)
{
  auto opts = Options(argc, argv);
  bool one = opts.colors().size() == 2;

  for (std::size_t i = 0; i < opts.colors().size() - 1; ++i)
  {
    const mcl::Color& c1 = opts.colors()[i];
    for (std::size_t j = i + 1; j < opts.colors().size(); ++j)
    {
      const mcl::Color& c2 = opts.colors()[j];
      print(c1, c2, mcl::delta_e(opts.function(), c1, c2), one, opts.exact());
    }
  }
}
