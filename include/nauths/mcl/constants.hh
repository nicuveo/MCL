//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef MCL_CONSTANTS_HH_
# define MCL_CONSTANTS_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/mcl/convert.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_COLOR_NAMES                                                \
  ((alice_blue,             ALICE_BLUE,             240,    248,    255)) \
  ((antique_white,          ANTIQUE_WHITE,          250,    235,    215)) \
  ((aqua,                   AQUA,                     0,    255,    255)) \
  ((aquamarine,             AQUAMARINE,             127,    255,    212)) \
  ((azure,                  AZURE,                  240,    255,    255)) \
  ((beige,                  BEIGE,                  245,    245,    220)) \
  ((bisque,                 BISQUE,                 255,    228,    196)) \
  ((black,                  BLACK,                    0,      0,      0)) \
  ((blanched_almond,        BLANCHED_ALMOND,        255,    235,    205)) \
  ((blue,                   BLUE,                     0,      0,    255)) \
  ((blue_violet,            BLUE_VIOLET,            138,     43,    226)) \
  ((brown,                  BROWN,                  165,     42,     42)) \
  ((burly_wood,             BURLY_WOOD,             222,    184,    135)) \
  ((cadet_blue,             CADET_BLUE,              95,    158,    160)) \
  ((chartreuse,             CHARTREUSE,             127,    255,      0)) \
  ((chocolate,              CHOCOLATE,              210,    105,     30)) \
  ((coral,                  CORAL,                  255,    127,     80)) \
  ((cornflower_blue,        CORNFLOWER_BLUE,        100,    149,    237)) \
  ((cornsilk,               CORNSILK,               255,    248,    220)) \
  ((crimson,                CRIMSON,                220,     20,     60)) \
  ((cyan,                   CYAN,                     0,    255,    255)) \
  ((dark_blue,              DARK_BLUE,                0,      0,    139)) \
  ((dark_cyan,              DARK_CYAN,                0,    139,    139)) \
  ((dark_goldenrod,         DARK_GOLDENROD,         184,    134,     11)) \
  ((dark_gray,              DARK_GRAY,              169,    169,    169)) \
  ((dark_green,             DARK_GREEN,               0,    100,      0)) \
  ((dark_khaki,             DARK_KHAKI,             189,    183,    107)) \
  ((dark_magenta,           DARK_MAGENTA,           139,      0,    139)) \
  ((dark_olive_green,       DARK_OLIVE_GREEN,        85,    107,     47)) \
  ((dark_orange,            DARK_ORANGE,            255,    140,      0)) \
  ((dark_orchid,            DARK_ORCHID,            153,     50,    204)) \
  ((dark_red,               DARK_RED,               139,      0,      0)) \
  ((dark_salmon,            DARK_SALMON,            233,    150,    122)) \
  ((dark_sea_green,         DARK_SEA_GREEN,         143,    188,    143)) \
  ((dark_slate_blue,        DARK_SLATE_BLUE,         72,     61,    139)) \
  ((dark_slate_gray,        DARK_SLATE_GRAY,         47,     79,     79)) \
  ((dark_turquoise,         DARK_TURQUOISE,           0,    206,    209)) \
  ((dark_violet,            DARK_VIOLET,            148,      0,    211)) \
  ((deep_pink,              DEEP_PINK,              255,     20,    147)) \
  ((deep_sky_blue,          DEEP_SKY_BLUE,            0,    191,    255)) \
  ((dim_gray,               DIM_GRAY,               105,    105,    105)) \
  ((dodger_blue,            DODGER_BLUE,             30,    144,    255)) \
  ((fire_brick,             FIRE_BRICK,             178,     34,     34)) \
  ((floral_white,           FLORAL_WHITE,           255,    250,    240)) \
  ((forest_green,           FOREST_GREEN,            34,    139,     34)) \
  ((fuchsia,                FUCHSIA,                255,      0,    255)) \
  ((gainsboro,              GAINSBORO,              220,    220,    220)) \
  ((ghost_white,            GHOST_WHITE,            248,    248,    255)) \
  ((gold,                   GOLD,                   255,    215,      0)) \
  ((goldenrod,              GOLDENROD,              218,    165,     32)) \
  ((gray,                   GRAY,                   128,    128,    128)) \
  ((green,                  GREEN,                    0,    128,      0)) \
  ((green_yellow,           GREEN_YELLOW,           173,    255,     47)) \
  ((honeydew,               HONEYDEW,               240,    255,    240)) \
  ((hot_pink,               HOT_PINK,               255,    105,    180)) \
  ((indian_red,             INDIAN_RED,             205,     92,     92)) \
  ((indigo,                 INDIGO,                  75,      0,    130)) \
  ((ivory,                  IVORY,                  255,    255,    240)) \
  ((khaki,                  KHAKI,                  240,    230,    140)) \
  ((lavender,               LAVENDER,               230,    230,    250)) \
  ((lavender_blush,         LAVENDER_BLUSH,         255,    240,    245)) \
  ((lawn_green,             LAWN_GREEN,             124,    252,      0)) \
  ((lemon_chiffon,          LEMON_CHIFFON,          255,    250,    205)) \
  ((light_blue,             LIGHT_BLUE,             173,    216,    230)) \
  ((light_coral,            LIGHT_CORAL,            240,    128,    128)) \
  ((light_cyan,             LIGHT_CYAN,             224,    255,    255)) \
  ((light_goldenrod_yellow, LIGHT_GOLDENROD_YELLOW, 250,    250,    210)) \
  ((light_green,            LIGHT_GREEN,            144,    238,    144)) \
  ((light_grey,             LIGHT_GREY,             211,    211,    211)) \
  ((light_pink,             LIGHT_PINK,             255,    182,    193)) \
  ((light_salmon,           LIGHT_SALMON,           255,    160,    122)) \
  ((light_sea_green,        LIGHT_SEA_GREEN,         32,    178,    170)) \
  ((light_sky_blue,         LIGHT_SKY_BLUE,         135,    206,    250)) \
  ((light_slate_gray,       LIGHT_SLATE_GRAY,       119,    136,    153)) \
  ((light_steel_blue,       LIGHT_STEEL_BLUE,       176,    196,    222)) \
  ((light_yellow,           LIGHT_YELLOW,           255,    255,    224)) \
  ((lime,                   LIME,                     0,    255,      0)) \
  ((lime_green,             LIME_GREEN,              50,    205,     50)) \
  ((linen,                  LINEN,                  250,    240,    230)) \
  ((magenta,                MAGENTA,                255,      0,    255)) \
  ((maroon,                 MAROON,                 128,      0,      0)) \
  ((medium_aquamarine,      MEDIUM_AQUAMARINE,      102,    205,    170)) \
  ((medium_blue,            MEDIUM_BLUE,              0,      0,    205)) \
  ((medium_orchid,          MEDIUM_ORCHID,          186,     85,    211)) \
  ((medium_purple,          MEDIUM_PURPLE,          147,    112,    219)) \
  ((medium_sea_green,       MEDIUM_SEA_GREEN,        60,    179,    113)) \
  ((medium_slate_blue,      MEDIUM_SLATE_BLUE,      123,    104,    238)) \
  ((medium_spring_green,    MEDIUM_SPRING_GREEN,      0,    250,    154)) \
  ((medium_turquoise,       MEDIUM_TURQUOISE,        72,    209,    204)) \
  ((medium_violet_red,      MEDIUM_VIOLET_RED,      199,     21,    133)) \
  ((midnight_blue,          MIDNIGHT_BLUE,           25,     25,    112)) \
  ((mint_cream,             MINT_CREAM,             245,    255,    250)) \
  ((misty_rose,             MISTY_ROSE,             255,    228,    225)) \
  ((moccasin,               MOCCASIN,               255,    228,    181)) \
  ((navajo_white,           NAVAJO_WHITE,           255,    222,    173)) \
  ((navy,                   NAVY,                     0,      0,    128)) \
  ((old_lace,               OLD_LACE,               253,    245,    230)) \
  ((olive,                  OLIVE,                  128,    128,      0)) \
  ((olive_drab,             OLIVE_DRAB,             107,    142,     35)) \
  ((orange,                 ORANGE,                 255,    165,      0)) \
  ((orange_red,             ORANGE_RED,             255,     69,      0)) \
  ((orchid,                 ORCHID,                 218,    112,    214)) \
  ((pale_goldenrod,         PALE_GOLDENROD,         238,    232,    170)) \
  ((pale_green,             PALE_GREEN,             152,    251,    152)) \
  ((pale_turquoise,         PALE_TURQUOISE,         175,    238,    238)) \
  ((pale_violet_red,        PALE_VIOLET_RED,        219,    112,    147)) \
  ((papaya_whip,            PAPAYA_WHIP,            255,    239,    213)) \
  ((peach_puff,             PEACH_PUFF,             255,    218,    185)) \
  ((peru,                   PERU,                   205,    133,     63)) \
  ((pink,                   PINK,                   255,    192,    203)) \
  ((plum,                   PLUM,                   221,    160,    221)) \
  ((powder_blue,            POWDER_BLUE,            176,    224,    230)) \
  ((purple,                 PURPLE,                 128,      0,    128)) \
  ((rebecca_purple,         REBECCA_PURPLE,         102,     51,    153)) \
  ((red,                    RED,                    255,      0,      0)) \
  ((rosy_brown,             ROSY_BROWN,             188,    143,    143)) \
  ((royal_blue,             ROYAL_BLUE,              65,    105,    225)) \
  ((saddle_brown,           SADDLE_BROWN,           139,     69,     19)) \
  ((salmon,                 SALMON,                 250,    128,    114)) \
  ((sandy_brown,            SANDY_BROWN,            244,    164,     96)) \
  ((sea_green,              SEA_GREEN,               46,    139,     87)) \
  ((seashell,               SEASHELL,               255,    245,    238)) \
  ((sienna,                 SIENNA,                 160,     82,     45)) \
  ((silver,                 SILVER,                 192,    192,    192)) \
  ((sky_blue,               SKY_BLUE,               135,    206,    235)) \
  ((slate_blue,             SLATE_BLUE,             106,     90,    205)) \
  ((slate_gray,             SLATE_GRAY,             112,    128,    144)) \
  ((snow,                   SNOW,                   255,    250,    250)) \
  ((spring_green,           SPRING_GREEN,             0,    255,    127)) \
  ((steel_blue,             STEEL_BLUE,              70,    130,    180)) \
  ((tan,                    TAN,                    210,    180,    140)) \
  ((teal,                   TEAL,                     0,    128,    128)) \
  ((thistle,                THISTLE,                216,    191,    216)) \
  ((tomato,                 TOMATO,                 255,     99,     71)) \
  ((turquoise,              TURQUOISE,               64,    224,    208)) \
  ((violet,                 VIOLET,                 238,    130,    238)) \
  ((wheat,                  WHEAT,                  245,    222,    179)) \
  ((white,                  WHITE,                  255,    255,    255)) \
  ((white_smoke,            WHITE_SMOKE,            245,    245,    245)) \
  ((yellow,                 YELLOW,                 255,    255,      0)) \
  ((yellow_green,           YELLOW_GREEN,           154,    205,     50)) \

# define MCL_decl(R, D, C)                         \
  extern const RGBub BOOST_PP_TUPLE_ELEM(5, 1, C); \
  template <typename T>                            \
  inline T BOOST_PP_TUPLE_ELEM(5, 0, C)()          \
  {                                                \
    return to<T>(BOOST_PP_TUPLE_ELEM(5, 1, C));    \
  }                                                \



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  namespace colors
  {

    BOOST_PP_SEQ_FOR_EACH(MCL_decl, _, MCL_COLOR_NAMES)

  }

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_decl



#endif /* !MCL_CONSTANTS_HH_ */
