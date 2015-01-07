//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef TOOLS_ONCE_HH_
# define TOOLS_ONCE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define DO_ONCE(code)                                  \
do                                                      \
{                                                       \
  static bool first = true;                             \
  if (first)                                            \
  {                                                     \
    code;                                               \
  }                                                     \
  first = false;                                        \
}                                                       \
while (false)                                           \

# define DO_ONCE_AT_LAUNCH()                            \
  class ToolsOnceAtLaunch                               \
  {                                                     \
    private:                                            \
      ToolsOnceAtLaunch();                              \
      static ToolsOnceAtLaunch instance_;               \
  };                                                    \
                                                        \
  ToolsOnceAtLaunch ToolsOnceAtLaunch::instance_;       \
                                                        \
  ToolsOnceAtLaunch::ToolsOnceAtLaunch()                \



#endif /* !TOOLS_ONCE_HH_ */
