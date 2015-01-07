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
// Local code

namespace
{

  Options::Endomorphism translate(std::stringstream& ss)
  {
    std::vector<Options::Endomorphism> endos;
    std::string t;

    while (ss >> t)
    {
      if (t == "g" or t == "gray" or t == "grey")
      {
        endos.push_back(mcl::grey<mcl::Color>());
      }
      else if (t == "l" or t == "lightness")
      {
        double arg;
        ss >> arg;
        endos.push_back(mcl::lightness<mcl::Color>(arg));
      }
      else if (t == "t" or t == "to"  or t == "convert")
      {
        mcl::SpaceType arg;
        ss >> arg;
        endos.push_back(mcl::to(arg));
      }
      else
      {
        throw std::runtime_error("unexpected transform \"" + t + "\"");
      }
    }

    return mcl::fold<Options::Endomorphism>(endos.rbegin(), endos.rend());
  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

Options::Options(int argc, SysArgv argv)
  : fun_(0), options_(po::options_description("Options"))
{
  options_.add_options()
    ("help,h",    "print this help");
  hidden_.add_options()
    ("transform", po::value<std::vector<std::string>>(&raw_), "");
  pos_.add("transform", -1);

  init(argc, argv);
}


void
Options::init(int argc, SysArgv argv)
{
  po::variables_map map;

  try
  {
    po::options_description parsed;
    std::stringstream ss;

    parsed.add(options_).add(hidden_);
    po::store(po::command_line_parser(argc, argv).options(parsed).positional(pos_).run(), map);
    po::notify(map);

    for (const auto& s : raw_)
      ss << " " << s;
    fun_ = translate(ss);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl << std::endl;
    usage(std::cerr, *argv, 1);
  }

  if (map.count("help"))
    usage(std::cout, argv[0], 0);
}

void
Options::usage(std::ostream& ostr, const char* arg, int err)
{
  ostr << "Usage:"                                                          << std::endl
       << "  " << arg << ": transform [transform...]"                       << std::endl
       << "  " << arg << ": -h"                                             << std::endl
                                                                            << std::endl
       << options_                                                          << std::endl
       << "Tranforms:"                                                      << std::endl
       << "  g [grey] [gray]       converts to true greyscale"              << std::endl
       << "  l [lightness]    arg  sets lightness to given value [0..100]"  << std::endl
       << "  t [to] [convert] arg  converts to given color space"           << std::endl
                                                                            << std::endl
       << "Format:"                                                         << std::endl
       << "  color spaces: " << BOOST_PP_STRINGIZE((MCL_SPACES_ENUM))       << std::endl
       << "  colors:       \"SPACE(v1, v2, v3..)\" or any svg color name"   << std::endl
                                                                            << std::endl
       << "About:"                                                          << std::endl
       << "  " << arg << " reads colors from the standard input and prints" << std::endl
       << "  the transformed colors on the standard output."                << std::endl
       << "  See also: clcc, clcd."                                         << std::endl;

  exit(err);
}
