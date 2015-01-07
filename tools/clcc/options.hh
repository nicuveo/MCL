//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_OPTIONS_HH_
# define MCL_OPTIONS_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <vector>
# include <iostream>
# include <boost/program_options.hpp>
# include "nauths/mcl/mcl.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Namespaces

namespace po = boost::program_options;



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

class Options
{
  public:
    // types

    typedef char const* const*          SysArgv;
    typedef std::vector<mcl::SpaceType> SpaceTypes;
    typedef std::vector<mcl::Color>     Colors;


    // constructor

    Options(int argc, SysArgv argv);


    // accessors

    const Colors&     input()  const { return input_;  }
    const SpaceTypes& output() const { return output_; }
    bool              exact()  const { return exact_;  }


  private:
    // internals

    void init(int argc, SysArgv argv);
    void usage(std::ostream& ostr, const char* arg, int err);


    // data

    po::options_description options_;

    bool exact_;
    Colors input_;
    SpaceTypes output_;
    std::vector<std::string> raw_;
};



#endif /* !MCL_OPTIONS_HH_ */
