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

#include <iomanip>
#include "options.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Local code

namespace
{

  void print(const mcl::Color& c1, const mcl::Color& c2, bool one, bool exact)
  {
    if (not one) std::cout << (exact ? c1 : c1.rounded().clamped()) <<  " ";
                 std::cout << (exact ? c2 : c2.rounded().clamped()) << std::endl;
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

int main(int argc, char const* const* argv)
{
  auto opts = Options(argc, argv);
  bool one = opts.input().size() == 1 and opts.output().size() == 1;

  for (const auto& color : opts.input())
    for (auto space : opts.output())
      print(color, color.to(space), one, opts.exact());
}
