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

# include "nauths/mcl/spaces/rgb.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define MCL_COLOR_NAMES                                                \
  ((aliceblue,            ALICE_BLUE,             240,    248,    255)) \
  ((antiquewhite,         ANTIQUE_WHITE,          250,    235,    215)) \
  ((aqua,                 AQUA,                     0,    255,    255)) \
  ((aquamarine,           AQUAMARINE,             127,    255,    212)) \
  ((azure,                AZURE,                  240,    255,    255)) \
  ((beige,                BEIGE,                  245,    245,    220)) \
  ((bisque,               BISQUE,                 255,    228,    196)) \
  ((black,                BLACK,                    0,      0,      0)) \
  ((blanchedalmond,       BLANCHED_ALMOND,        255,    235,    205)) \
  ((blue,                 BLUE,                     0,      0,    255)) \
  ((blueviolet,           BLUE_VIOLET,            138,     43,    226)) \
  ((brown,                BROWN,                  165,     42,     42)) \
  ((burlywood,            BURLY_WOOD,             222,    184,    135)) \
  ((cadetblue,            CADET_BLUE,              95,    158,    160)) \
  ((chartreuse,           CHARTREUSE,             127,    255,      0)) \
  ((chocolate,            CHOCOLATE,              210,    105,     30)) \
  ((coral,                CORAL,                  255,    127,     80)) \
  ((cornflowerblue,       CORNFLOWER_BLUE,        100,    149,    237)) \
  ((cornsilk,             CORNSILK,               255,    248,    220)) \
  ((crimson,              CRIMSON,                220,     20,     60)) \
  ((cyan,                 CYAN,                     0,    255,    255)) \
  ((darkblue,             DARK_BLUE,                0,      0,    139)) \
  ((darkcyan,             DARK_CYAN,                0,    139,    139)) \
  ((darkgoldenrod,        DARK_GOLDENROD,         184,    134,     11)) \
  ((darkgray,             DARK_GRAY,              169,    169,    169)) \
  ((darkgreen,            DARK_GREEN,               0,    100,      0)) \
  ((darkkhaki,            DARK_KHAKI,             189,    183,    107)) \
  ((darkmagenta,          DARK_MAGENTA,           139,      0,    139)) \
  ((darkolivegreen,       DARK_OLIVE_GREEN,        85,    107,     47)) \
  ((darkorange,           DARK_ORANGE,            255,    140,      0)) \
  ((darkorchid,           DARK_ORCHID,            153,     50,    204)) \
  ((darkred,              DARK_RED,               139,      0,      0)) \
  ((darksalmon,           DARK_SALMON,            233,    150,    122)) \
  ((darkseagreen,         DARK_SEA_GREEN,         143,    188,    143)) \
  ((darkslateblue,        DARK_SLATE_BLUE,         72,     61,    139)) \
  ((darkslategray,        DARK_SLATE_GRAY,         47,     79,     79)) \
  ((darkturquoise,        DARK_TURQUOISE,           0,    206,    209)) \
  ((darkviolet,           DARK_VIOLET,            148,      0,    211)) \
  ((deeppink,             DEEP_PINK,              255,     20,    147)) \
  ((deepskyblue,          DEEP_SKY_BLUE,            0,    191,    255)) \
  ((dimgray,              DIM_GRAY,               105,    105,    105)) \
  ((dodgerblue,           DODGER_BLUE,             30,    144,    255)) \
  ((firebrick,            FIRE_BRICK,             178,     34,     34)) \
  ((floralwhite,          FLORAL_WHITE,           255,    250,    240)) \
  ((forestgreen,          FOREST_GREEN,            34,    139,     34)) \
  ((fuchsia,              FUCHSIA,                255,      0,    255)) \
  ((gainsboro,            GAINSBORO,              220,    220,    220)) \
  ((ghostwhite,           GHOST_WHITE,            248,    248,    255)) \
  ((gold,                 GOLD,                   255,    215,      0)) \
  ((goldenrod,            GOLDENROD,              218,    165,     32)) \
  ((gray,                 GRAY,                   128,    128,    128)) \
  ((green,                GREEN,                    0,    128,      0)) \
  ((greenyellow,          GREEN_YELLOW,           173,    255,     47)) \
  ((honeydew,             HONEYDEW,               240,    255,    240)) \
  ((hotpink,              HOT_PINK,               255,    105,    180)) \
  ((indianred,            INDIAN_RED,             205,     92,     92)) \
  ((indigo,               INDIGO,                  75,      0,    130)) \
  ((ivory,                IVORY,                  255,    255,    240)) \
  ((khaki,                KHAKI,                  240,    230,    140)) \
  ((lavender,             LAVENDER,               230,    230,    250)) \
  ((lavenderblush,        LAVENDER_BLUSH,         255,    240,    245)) \
  ((lawngreen,            LAWN_GREEN,             124,    252,      0)) \
  ((lemonchiffon,         LEMON_CHIFFON,          255,    250,    205)) \
  ((lightblue,            LIGHT_BLUE,             173,    216,    230)) \
  ((lightcoral,           LIGHT_CORAL,            240,    128,    128)) \
  ((lightcyan,            LIGHT_CYAN,             224,    255,    255)) \
  ((lightgoldenrodyellow, LIGHT_GOLDENROD_YELLOW, 250,    250,    210)) \
  ((lightgreen,           LIGHT_GREEN,            144,    238,    144)) \
  ((lightgrey,            LIGHT_GREY,             211,    211,    211)) \
  ((lightpink,            LIGHT_PINK,             255,    182,    193)) \
  ((lightsalmon,          LIGHT_SALMON,           255,    160,    122)) \
  ((lightseagreen,        LIGHT_SEA_GREEN,         32,    178,    170)) \
  ((lightskyblue,         LIGHT_SKY_BLUE,         135,    206,    250)) \
  ((lightslategray,       LIGHT_SLATE_GRAY,       119,    136,    153)) \
  ((lightsteelblue,       LIGHT_STEEL_BLUE,       176,    196,    222)) \
  ((lightyellow,          LIGHT_YELLOW,           255,    255,    224)) \
  ((lime,                 LIME,                     0,    255,      0)) \
  ((limegreen,            LIME_GREEN,              50,    205,     50)) \
  ((linen,                LINEN,                  250,    240,    230)) \
  ((magenta,              MAGENTA,                255,      0,    255)) \
  ((maroon,               MAROON,                 128,      0,      0)) \
  ((mediumaquamarine,     MEDIUM_AQUAMARINE,      102,    205,    170)) \
  ((mediumblue,           MEDIUM_BLUE,              0,      0,    205)) \
  ((mediumorchid,         MEDIUM_ORCHID,          186,     85,    211)) \
  ((mediumpurple,         MEDIUM_PURPLE,          147,    112,    219)) \
  ((mediumseagreen,       MEDIUM_SEA_GREEN,        60,    179,    113)) \
  ((mediumslateblue,      MEDIUM_SLATE_BLUE,      123,    104,    238)) \
  ((mediumspringgreen,    MEDIUM_SPRING_GREEN,      0,    250,    154)) \
  ((mediumturquoise,      MEDIUM_TURQUOISE,        72,    209,    204)) \
  ((mediumvioletred,      MEDIUM_VIOLET_RED,      199,     21,    133)) \
  ((midnightblue,         MIDNIGHT_BLUE,           25,     25,    112)) \
  ((mintcream,            MINT_CREAM,             245,    255,    250)) \
  ((mistyrose,            MISTY_ROSE,             255,    228,    225)) \
  ((moccasin,             MOCCASIN,               255,    228,    181)) \
  ((navajowhite,          NAVAJO_WHITE,           255,    222,    173)) \
  ((navy,                 NAVY,                     0,      0,    128)) \
  ((oldlace,              OLD_LACE,               253,    245,    230)) \
  ((olive,                OLIVE,                  128,    128,      0)) \
  ((olivedrab,            OLIVE_DRAB,             107,    142,     35)) \
  ((orange,               ORANGE,                 255,    165,      0)) \
  ((orangered,            ORANGE_RED,             255,     69,      0)) \
  ((orchid,               ORCHID,                 218,    112,    214)) \
  ((palegoldenrod,        PALE_GOLDENROD,         238,    232,    170)) \
  ((palegreen,            PALE_GREEN,             152,    251,    152)) \
  ((paleturquoise,        PALE_TURQUOISE,         175,    238,    238)) \
  ((palevioletred,        PALE_VIOLET_RED,        219,    112,    147)) \
  ((papayawhip,           PAPAYA_WHIP,            255,    239,    213)) \
  ((peachpuff,            PEACH_PUFF,             255,    218,    185)) \
  ((peru,                 PERU,                   205,    133,     63)) \
  ((pink,                 PINK,                   255,    192,    203)) \
  ((plum,                 PLUM,                   221,    160,    221)) \
  ((powderblue,           POWDER_BLUE,            176,    224,    230)) \
  ((purple,               PURPLE,                 128,      0,    128)) \
  ((rebeccapurple,        REBECCA_PURPLE,         102,     51,    153)) \
  ((red,                  RED,                    255,      0,      0)) \
  ((rosybrown,            ROSY_BROWN,             188,    143,    143)) \
  ((royalblue,            ROYAL_BLUE,              65,    105,    225)) \
  ((saddlebrown,          SADDLE_BROWN,           139,     69,     19)) \
  ((salmon,               SALMON,                 250,    128,    114)) \
  ((sandybrown,           SANDY_BROWN,            244,    164,     96)) \
  ((seagreen,             SEA_GREEN,               46,    139,     87)) \
  ((seashell,             SEASHELL,               255,    245,    238)) \
  ((sienna,               SIENNA,                 160,     82,     45)) \
  ((silver,               SILVER,                 192,    192,    192)) \
  ((skyblue,              SKY_BLUE,               135,    206,    235)) \
  ((slateblue,            SLATE_BLUE,             106,     90,    205)) \
  ((slategray,            SLATE_GRAY,             112,    128,    144)) \
  ((snow,                 SNOW,                   255,    250,    250)) \
  ((springgreen,          SPRING_GREEN,             0,    255,    127)) \
  ((steelblue,            STEEL_BLUE,              70,    130,    180)) \
  ((tan,                  TAN,                    210,    180,    140)) \
  ((teal,                 TEAL,                     0,    128,    128)) \
  ((thistle,              THISTLE,                216,    191,    216)) \
  ((tomato,               TOMATO,                 255,     99,     71)) \
  ((turquoise,            TURQUOISE,               64,    224,    208)) \
  ((violet,               VIOLET,                 238,    130,    238)) \
  ((wheat,                WHEAT,                  245,    222,    179)) \
  ((white,                WHITE,                  255,    255,    255)) \
  ((whitesmoke,           WHITE_SMOKE,            245,    245,    245)) \
  ((yellow,               YELLOW,                 255,    255,      0)) \
  ((yellowgreen,          YELLOW_GREEN,           154,    205,     50)) \

# define MCL_decl(R, D, C) extern const RGBub BOOST_PP_TUPLE_ELEM(5, 1, C);



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace mcl
{

  BOOST_PP_SEQ_FOR_EACH(MCL_decl, _, MCL_COLOR_NAMES)

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# undef MCL_decl



#endif /* !MCL_CONSTANTS_HH_ */
