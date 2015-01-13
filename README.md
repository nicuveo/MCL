[![Build Status](https://travis-ci.org/nicuveo/MCL.svg?branch=master)](https://travis-ci.org/nicuveo/MCL)

*MCL*: a Minimalistic Color Library
===================================

The *MCL* is a small collection of color related tools. It features:
  * lightweight color classes (*RGB*, *HSV*, *XYZ*...),
  * color spaces conversion algorithms,
  * color distance computations (delta e),
  * color interpolation functions,
  * command line utilities,
  * a (limited) C API...


Install
-------

``` bash
./configure  # -a "PREFIX=/usr/local"
make
make install
```

Headers will be installed in `$PREFIX/include/nauths/mcl/`.  
To use, simply include `<nauths/mcl/mcl.hh>` and add `-l mcl` to your link flags.
