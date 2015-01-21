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

To build, *MCL* currently requires g++ 4.8 and boost 1.54.

``` bash
make
make install # PREFIX=/usr/local
```

* Headers will be installed in `$PREFIX/include/nauths/mcl/`.
* Binaries (*clcc*, *clcd*, *clct*) will be installed in `$PREFIX/bin/`.
* The .a file (*libmcl.a*) will be installed in  `$PREFIX/lib/`.

To use, simply include `<nauths/mcl/mcl.hh>`, add `-std=c++11` to your
compilation flags, and add `-l mcl` to your link flags.


Library
-------

Here's a file named `test.cc` that uses and demonstrates some of the mentioned features.

``` c++
#include <nauths/mcl/mcl.hh>
#include <iostream>

using namespace mcl;

int main(int argc, char const* const* argv)
{
  typedef Endomorphism<Color> ColorTransform; // Color -> Color

  ColorTransform t1 = opaque<Color>();        // sets alpha to maximum
  ColorTransform t2 = grey<Color>();          // converts to grayscale
  ColorTransform t3 = to<RGBub>();            // converts to unsigned byte RGB
  ColorTransform tr = (t3 , t2 , t1);         // (,) composes endomorphisms

  for (int i = 1; i < argc; ++i)
  {
    Color c = read<Color>(argv[i]);
    std::cout << tr(c) << std::endl;          // equivalent to t3(t2(t1(c)))
  }
}

```

Simply compile it with `g++ -std=c++11 test.cc -lmcl -o test`.  This
program expects colors as arguments, and outputs an opaque, greyscaled,
*RGBified* version of them. For instance:

``` bash
$ ./test red
RGBub(127,127,127)

$ ./test "HSV(30, 0.1, 0.6, 0.1)"
RGBub(146,146,146)
```


Tools
-----

The *MCL* builds and installs three small binaries: *clcc*, *clcd*, and
*clct*. Run any of each with "-h" to display a summary of options and
usage.

##### *CLCC*: Command Line Color Convert

``` bash
$ clcc -f "red" -t XYZ
XYZ(41.246,21.267,1.933)
```

##### *CLCD*: Command Line Color Distance

``` bash
clcd --cie94 "RGB(1.0, 0.4, 1.0)" "RGB(1.0, 0.5, 1.0)"
4.79934
```

##### *CLCT*: Command Line Color Transform

``` bash
echo red | clct grey | clct "to xyz"
XYZ(20.214,21.267,23.156)
```


Documentation
-------------

All the documentation can be found on the [Wiki](https://github.com/nicuveo/MCL/wiki).
