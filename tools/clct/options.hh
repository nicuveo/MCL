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

    typedef char const* const*        SysArgv;
    typedef mcl::Color                Color;
    typedef mcl::Endomorphism<Color>  Endomorphism;
    typedef std::vector<Endomorphism> Endomorphisms;


    // constructor

    Options(int argc, SysArgv argv);


    // accessors

    const Endomorphism& function() const { return fun_; }


  private:
    // internals

    void init(int argc, SysArgv argv);
    void usage(std::ostream& ostr, const char* arg, int err);


    // data

    Endomorphism fun_;
    po::options_description hidden_;
    po::options_description options_;
    po::positional_options_description pos_;
    std::vector<std::string> raw_;
};



#endif /* !MCL_OPTIONS_HH_ */
