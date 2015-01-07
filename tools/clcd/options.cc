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
// Implementation

Options::Options(int argc, SysArgv argv)
  : fun_(0), options_(po::options_description("Options"))
{
  options_.add_options()
    ("help,h",  "print this help")
    ("exact,e", "do not round output")
    ("cie76",   "use CIE1976 delta E")
    ("cie94",   "use CIE1994 delta E")
    ("cie00",   "use CIE2000 delta E (default)");
  hidden_.add_options()
    ("color",  po::value<std::vector<std::string>>(&raw_), "");
  pos_.add("color", -1);

  init(argc, argv);
}


void
Options::init(int argc, SysArgv argv)
{
  po::variables_map map;

  try
  {
    po::options_description parsed;

    parsed.add(options_).add(hidden_);
    po::store(po::command_line_parser(argc, argv).options(parsed).positional(pos_).run(), map);
    po::notify(map);

    if (raw_.empty())
    {
      std::cerr << "Error: expecting at least two colors" << std::endl << std::endl;
      usage(std::cerr, *argv, 2);
    }

    for (const auto& desc : raw_)
      colors_.push_back(mcl::read<mcl::Color>(desc));

    update(map, *argv, "cie76", mcl::CIE_1976);
    update(map, *argv, "cie94", mcl::CIE_1994);
    update(map, *argv, "cie00", mcl::CIE_2000);

    if (not fun_)
      fun_ = mcl::CIE_2000;

    exact_ = map.count("exact");
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl << std::endl;
    usage(std::cerr, *argv, 1);
  }

  if (map.count("help"))  usage(std::cout, argv[0], 0);
  if (colors_.size() < 2) usage(std::cout, argv[0], 4);
}

void
Options::usage(std::ostream& ostr, const char* arg, int err)
{
  ostr << "Usage:"                                                        << std::endl
       << "  " << arg << ": [options] color1 color2 [color3...]"          << std::endl
       << "  " << arg << ": -h"                                           << std::endl
                                                                          << std::endl
       << options_                                                        << std::endl
       << "Format:"                                                       << std::endl
       << "  color spaces: " << BOOST_PP_STRINGIZE((MCL_SPACES_ENUM))     << std::endl
       << "  colors:       \"SPACE(v1, v2, v3..)\" or any svg color name" << std::endl
                                                                          << std::endl
       << "Examples"                                                      << std::endl
       << "  " << arg << " \"RGB(1, 0.5, 0)\" \"HSL(0, 1, 0)\""           << std::endl
       << "  " << arg << " black red --cie94"                             << std::endl;

  exit(err);
}

void
Options::update(const po::variables_map& map, const char* arg, const char* opt, mcl::DistanceFunction ref)
{
  if (map.count(opt))
  {
    if (fun_)
    {
      std::cerr << "Error: unexpected \"" << opt << "\": expecting at most one distance function" << std::endl << std::endl;
      usage(std::cerr, arg, 3);
    }
    fun_ = ref;
  }
}
