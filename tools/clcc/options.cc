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

#include "nauths/mcl/io.hh"
#include "options.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

#define MCL_namespace(D, E, S) mcl::spaces::S



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Options::Options(int argc, SysArgv argv)
  : options_(po::options_description("Options")),
    output_({BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(MCL_namespace, _, MCL_SPACES))})
{
  options_.add_options()
    ("help,h",  "print this help")
    ("exact,e", "do not round output")
    ("from,f",  po::value<std::vector<std::string>>(&raw_), "input color")
    ("to,t",    po::value<SpaceTypes>(&output_), "output colorspace");

  init(argc, argv);
}


void
Options::init(int argc, SysArgv argv)
{
  po::variables_map map;

  try
  {
    po::store(po::command_line_parser(argc, argv).options(options_).run(), map);
    po::notify(map);

    for (const auto& desc : raw_)
      input_.push_back(mcl::read<mcl::Color>(desc));

    exact_ = map.count("exact");
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl << std::endl;
    usage(std::cerr, *argv, 1);
  }

  if (map.count("help") or input_.empty())
    usage(std::cout, argv[0], 0);
}

void
Options::usage(std::ostream& ostr, const char* arg, int err)
{
  ostr << "Usage:"                                                                 << std::endl
       << "  " << arg << ": -f color1 [-f color2...] [-t space1 [-t space2...]]"   << std::endl
       << "  " << arg << ": -h"                                                    << std::endl
                                                                                   << std::endl
       << options_                                                                 << std::endl
       << "Format:"                                                                << std::endl
       << "  color spaces: " << BOOST_PP_STRINGIZE((MCL_SPACES_ENUM))              << std::endl
       << "  colors:       \"SPACE(v1, v2, v3..)\" or any svg color name"          << std::endl
                                                                                   << std::endl
       << "Examples"                                                               << std::endl
       << "  " << arg << " -f \"RGB(1, 0, 0)\" -t HSV -t HSL # RGB to HSL and HSV" << std::endl
       << "  " << arg << " -f \"green\"                      # RGB to all spaces"  << std::endl;

  exit(err);
}
