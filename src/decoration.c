#include "global.h"
#include "asm.h"
#include "map_object_constants.h"
#include "rom4.h"
#include "sound.h"
#include "songs.h"
#include "string_util.h"
#include "menu.h"
#include "menu_helpers.h"
#include "strings.h"
#include "script.h"
#include "palette.h"
#include "field_player_avatar.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "event_data.h"
#include "field_weather.h"
#include "decoration.h"

#define DECORATION(_id, _name, _decor_field_11, _shape, _decor_field_13, _price, _description, _tiles) {\
.id = _id,\
.name = _name,\
.decor_field_11 = _decor_field_11,\
.shape = _shape,\
.decor_field_13 = _decor_field_13,\
.price = _price,\
.description = _description,\
.tiles = _tiles\
}

const u8 DecorDesc_SMALL_DESK[] = _(
    "A small desk built\n"
    "for one.");

const u8 DecorDesc_POKEMON_DESK[] = _(
    "A small desk built in\n"
    "the shape of a POKé\n"
    "BALL.");

const u8 DecorDesc_HEAVY_DESK[] = _(
    "A large desk made\n"
    "of steel. Put some\n"
    "decorations on it.");

const u8 DecorDesc_RAGGED_DESK[] = _(
    "A large desk made\n"
    "of wood. Put some\n"
    "decorations on it.");

const u8 DecorDesc_COMFORT_DESK[] = _(
    "A large desk made\n"
    "of leaves. Put some\n"
    "decorations on it.");

const u8 DecorDesc_PRETTY_DESK[] = _(
    "A huge desk made\n"
    "of glass. Holds lots\n"
    "of decorations.");

const u8 DecorDesc_BRICK_DESK[] = _(
    "A huge desk made\n"
    "of brick. Holds lots\n"
    "of decorations.");

const u8 DecorDesc_CAMP_DESK[] = _(
    "A huge desk made\n"
    "of logs. Put lots of\n"
    "decorations on it.");

const u8 DecorDesc_HARD_DESK[] = _(
    "A huge desk made\n"
    "of rocks. Holds\n"
    "many decorations.");

const u8 DecorDesc_SMALL_CHAIR[] = _(
    "A small chair made\n"
    "for one.");

const u8 DecorDesc_POKEMON_CHAIR[] = _(
    "A small chair built\n"
    "in the shape of a\n"
    "POKé BALL.");

const u8 DecorDesc_HEAVY_CHAIR[] = _(
    "A small chair made\n"
    "of steel.");

const u8 DecorDesc_PRETTY_CHAIR[] = _(
    "A small chair made\n"
    "of glass.");

const u8 DecorDesc_COMFORT_CHAIR[] = _(
    "A small chair made\n"
    "of leaves.");

const u8 DecorDesc_RAGGED_CHAIR[] = _(
    "A small chair made\n"
    "of wood.");

const u8 DecorDesc_BRICK_CHAIR[] = _(
    "A small chair made\n"
    "of brick.");

const u8 DecorDesc_CAMP_CHAIR[] = _(
    "A small chair made\n"
    "of logs.");

const u8 DecorDesc_HARD_CHAIR[] = _(
    "A small chair made\n"
    "of rock.");

const u8 DecorDesc_RED_PLANT[] = _(
    "A vivid red potted\n"
    "plant.");

const u8 DecorDesc_TROPICAL_PLANT[] = _(
    "A flowering tropical\n"
    "plant in a pot.");

const u8 DecorDesc_PRETTY_FLOWERS[] = _(
    "A pot of cute\n"
    "flowers.");

const u8 DecorDesc_COLORFUL_PLANT[] = _(
    "A large pot with\n"
    "many colorful\n"
    "flowers.");

const u8 DecorDesc_BIG_PLANT[] = _(
    "A large, umbrella-\n"
    "shaped plant in a\n"
    "big pot.");

const u8 DecorDesc_GORGEOUS_PLANT[] = _(
    "A large, impressive\n"
    "plant in a big pot.");

const u8 DecorDesc_RED_BRICK[] = _(
    "A red-colored brick.\n"
    "Decorations can be\n"
    "placed on top.");

const u8 DecorDesc_YELLOW_BRICK[] = _(
    "A yellow-colored\n"
    "brick. Put some\n"
    "decorations on top.");

const u8 DecorDesc_BLUE_BRICK[] = _(
    "A blue-colored\n"
    "brick. Put some\n"
    "decorations on top.");

const u8 DecorDesc_RED_BALLOON[] = _(
    "A red balloon filled\n"
    "with water. Bursts\n"
    "if stepped on.");

const u8 DecorDesc_BLUE_BALLOON[] = _(
    "A blue balloon filled\n"
    "with water. Bursts\n"
    "if stepped on.");

const u8 DecorDesc_YELLOW_BALLOON[] = _(
    "A yellow balloon\n"
    "filled with water.\n"
    "Pops if stepped on.");

const u8 DecorDesc_RED_TENT[] = _(
    "A large red tent.\n"
    "You can hide inside\n"
    "it.");

const u8 DecorDesc_BLUE_TENT[] = _(
    "A large blue tent.\n"
    "You can hide inside\n"
    "it.");

const u8 DecorDesc_SOLID_BOARD[] = _(
    "Place over a hole to\n"
    "cross to the other\n"
    "side.");

const u8 DecorDesc_SLIDE[] = _(
    "Use to slide down\n"
    "from the platform.");

const u8 DecorDesc_FENCE_LENGTH[] = _(
    "A small fence that\n"
    "blocks passage.");

const u8 DecorDesc_FENCE_WIDTH[] = _(
    "A small fence that\n"
    "blocks passage.");

const u8 DecorDesc_TIRE[] = _(
    "An old large tire.\n"
    "Decorations can be\n"
    "placed on top.");

const u8 DecorDesc_STAND[] = _(
    "A large pedestal\n"
    "with steps.");

const u8 DecorDesc_MUD_BALL[] = _(
    "A large ball of mud.\n"
    "Crumbles if stepped\n"
    "on.");

const u8 DecorDesc_BREAKABLE_DOOR[] = _(
    "A weird door that\n"
    "people can walk\n"
    "right through.");

const u8 DecorDesc_SAND_ORNAMENT[] = _(
    "An ornament made\n"
    "of sand. Crumbles if\n"
    "touched.");

const u8 DecorDesc_SILVER_SHIELD[] = _(
    "Awarded for 50\n"
    "straight wins at\n"
    "the BATTLE TOWER.");

const u8 DecorDesc_GOLD_SHIELD[] = _(
    "Awarded for 100\n"
    "straight wins at\n"
    "the BATTLE TOWER.");

const u8 DecorDesc_GLASS_ORNAMENT[] = _(
    "A glass replica of\n"
    "a famous sculpture\n"
    "at the ART MUSEUM.");

const u8 DecorDesc_TV[] = _(
    "A small, gray-\n"
    "colored toy TV.");

const u8 DecorDesc_ROUND_TV[] = _(
    "A toy TV modeled\n"
    "in the image of a\n"
    "SEEDOT.");

const u8 DecorDesc_CUTE_TV[] = _(
    "A toy TV modeled\n"
    "in the image of a\n"
    "SKITTY.");

const u8 DecorDesc_GLITTER_MAT[] = _(
    "An odd mat that\n"
    "glitters if stepped\n"
    "on.");

const u8 DecorDesc_JUMP_MAT[] = _(
    "A trick mat that\n"
    "jumps when it is\n"
    "stepped on.");

const u8 DecorDesc_SPIN_MAT[] = _(
    "A trick mat that\n"
    "spins around when\n"
    "stepped on.");

const u8 DecorDesc_C_LOW_NOTE_MAT[] = _(
    "A mat that plays\n"
    "a low C note when\n"
    "stepped on.");

const u8 DecorDesc_D_NOTE_MAT[] = _(
    "A mat that plays\n"
    "a D note when\n"
    "stepped on.");

const u8 DecorDesc_E_NOTE_MAT[] = _(
    "A mat that plays\n"
    "an E note when\n"
    "stepped on.");

const u8 DecorDesc_F_NOTE_MAT[] = _(
    "A mat that plays\n"
    "an F note when\n"
    "stepped on.");

const u8 DecorDesc_G_NOTE_MAT[] = _(
    "A mat that plays\n"
    "a G note when\n"
    "stepped on.");

const u8 DecorDesc_A_NOTE_MAT[] = _(
    "A mat that plays\n"
    "an A note when\n"
    "stepped on.");

const u8 DecorDesc_B_NOTE_MAT[] = _(
    "A mat that plays\n"
    "a B note when\n"
    "stepped on.");

const u8 DecorDesc_C_HIGH_NOTE_MAT[] = _(
    "A mat that plays\n"
    "a high C note when\n"
    "stepped on.");

const u8 DecorDesc_SURF_MAT[] = _(
    "A mat designed with\n"
    "a SURF image.\n"
    "Put items on top.");

const u8 DecorDesc_THUNDER_MAT[] = _(
    "A mat designed with\n"
    "a THUNDER image.\n"
    "Put items on top.");

const u8 DecorDesc_FIRE_BLAST_MAT[] = _(
    "A mat designed with\n"
    "a FIRE BLAST image.\n"
    "Put items on top.");

const u8 DecorDesc_POWDER_SNOW_MAT[] = _(
    "A mat with a POWDER\n"
    "SNOW image design.\n"
    "Put items on top.");

const u8 DecorDesc_ATTRACT_MAT[] = _(
    "A mat designed with\n"
    "an ATTRACT image.\n"
    "Put items on top.");

const u8 DecorDesc_FISSURE_MAT[] = _(
    "A mat designed with\n"
    "a FISSURE image.\n"
    "Put items on top.");

const u8 DecorDesc_SPIKES_MAT[] = _(
    "A mat designed with\n"
    "a SPIKES image.\n"
    "Put items on top.");

const u8 DecorDesc_BALL_POSTER[] = _(
    "A small poster\n"
    "printed with POKé\n"
    "BALLS.");

const u8 DecorDesc_GREEN_POSTER[] = _(
    "A small poster with\n"
    "a TREECKO print.");

const u8 DecorDesc_RED_POSTER[] = _(
    "A small poster with\n"
    "a TORCHIC print.");

const u8 DecorDesc_BLUE_POSTER[] = _(
    "A small poster with\n"
    "a MUDKIP print.");

const u8 DecorDesc_CUTE_POSTER[] = _(
    "A small poster with\n"
    "an AZURILL print.");

const u8 DecorDesc_PIKA_POSTER[] = _(
    "A large poster with\n"
    "a PIKACHU and\n"
    "PICHU print.");

const u8 DecorDesc_LONG_POSTER[] = _(
    "A large poster with\n"
    "a SEVIPER print.");

const u8 DecorDesc_SEA_POSTER[] = _(
    "A large poster with\n"
    "a RELICANTH print.");

const u8 DecorDesc_SKY_POSTER[] = _(
    "A large poster with\n"
    "a WINGULL print.");

const u8 DecorDesc_KISS_POSTER[] = _(
    "A large poster with\n"
    "a SMOOCHUM print.");

const u8 DecorDesc_PICHU_DOLL[] = _(
    "A PICHU doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_PIKACHU_DOLL[] = _(
    "A PIKACHU doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_MARILL_DOLL[] = _(
    "A MARILL doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_TOGEPI_DOLL[] = _(
#if REVISION >= 1
    "A TOGEPI doll.\n"
#else
    "A TOPGEPI doll.\n"
#endif
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_CYNDAQUIL_DOLL[] = _(
    "A CYNDAQUIL doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_CHIKORITA_DOLL[] = _(
    "A CHIKORITA doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_TOTODILE_DOLL[] = _(
    "A TOTODILE doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_JIGGLYPUFF_DOLL[] = _(
    "A JIGGLYPUFF doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_MEOWTH_DOLL[] = _(
    "A MEOWTH doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_CLEFAIRY_DOLL[] = _(
    "A CLEFAIRY doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_DITTO_DOLL[] = _(
    "A DITTO doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_SMOOCHUM_DOLL[] = _(
    "A SMOOCHUM doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_TREECKO_DOLL[] = _(
    "A TREECKO doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_TORCHIC_DOLL[] = _(
    "A TORCHIC doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_MUDKIP_DOLL[] = _(
    "A MUDKIP doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_DUSKULL_DOLL[] = _(
    "A DUSKULL doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_WYNAUT_DOLL[] = _(
    "A WYNAUT doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_BALTOY_DOLL[] = _(
    "A BALTOY doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_KECLEON_DOLL[] = _(
    "A KECLEON doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_AZURILL_DOLL[] = _(
    "An AZURILL doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_SKITTY_DOLL[] = _(
    "A SKITTY doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_SWABLU_DOLL[] = _(
    "A SWABLU doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_GULPIN_DOLL[] = _(
    "A GULPIN doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_LOTAD_DOLL[] = _(
    "A LOTAD doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_SEEDOT_DOLL[] = _(
    "A SEEDOT doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_PIKA_CUSHION[] = _(
    "A PIKACHU cushion.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_ROUND_CUSHION[] = _(
    "A MARILL cushion.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_KISS_CUSHION[] = _(
    "A SMOOCHUM\n"
    "cushion. Place it on\n"
    "a mat or a desk.");

const u8 DecorDesc_ZIGZAG_CUSHION[] = _(
    "A ZIGZAGOON\n"
    "cushion. Place it on\n"
    "a mat or a desk.");

const u8 DecorDesc_SPIN_CUSHION[] = _(
    "A SPINDA cushion.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_DIAMOND_CUSHION[] = _(
    "A SABLEYE cushion.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_BALL_CUSHION[] = _(
    "A BALL cushion.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_GRASS_CUSHION[] = _(
    "A grass-mark\n"
    "cushion. Place it on\n"
    "a mat or a desk.");

const u8 DecorDesc_FIRE_CUSHION[] = _(
    "A fire-mark\n"
    "cushion. Place it on\n"
    "a mat or a desk.");

const u8 DecorDesc_WATER_CUSHION[] = _(
    "A water-mark\n"
    "cushion. Place it on\n"
    "a mat or a desk.");

const u8 DecorDesc_SNORLAX_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_RHYDON_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_LAPRAS_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_VENUSAUR_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_CHARIZARD_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_BLASTOISE_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_WAILMER_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_REGIROCK_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_REGICE_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u8 DecorDesc_REGISTEEL_DOLL[] = _(
    "A large doll.\n"
    "Place it on a mat\n"
    "or a desk.");

const u16 DecorGfx_SMALL_DESK[] = {
    0x87
};

const u16 DecorGfx_POKEMON_DESK[] = {
    0x8F
};

const u16 DecorGfx_HEAVY_DESK[] = {
    0x90,
    0x91,
    0x92,
    0x98,
    0x99,
    0x9A
};

const u16 DecorGfx_RAGGED_DESK[] = {
    0x93,
    0x94,
    0x95,
    0x9B,
    0x9C,
    0x9D
};

const u16 DecorGfx_COMFORT_DESK[] = {
    0x96,
    0x97,
    0xA3,
    0x9E,
    0x9F,
    0xAB
};

const u16 DecorGfx_PRETTY_DESK[] = {
    0xBD,
    0xBE,
    0xBF,
    0xC5,
    0xC6,
    0xC7,
    0xCD,
    0xCE,
    0xCF
};

const u16 DecorGfx_BRICK_DESK[] = {
    0xA0,
    0xA1,
    0xA2,
    0xA8,
    0xA9,
    0xAA,
    0xB0,
    0xB1,
    0xB2
};

const u16 DecorGfx_CAMP_DESK[] = {
    0xA4,
    0xA5,
    0xA6,
    0xAC,
    0xAD,
    0xAE,
    0xB4,
    0xB5,
    0xB6
};

const u16 DecorGfx_HARD_DESK[] = {
    0xA7,
    0xBB,
    0xBC,
    0xAF,
    0xC3,
    0xC4,
    0xB7,
    0xCB,
    0xCC
};

const u16 DecorGfx_SMALL_CHAIR[] = {
    0xB8
};

const u16 DecorGfx_POKEMON_CHAIR[] = {
    0xB9
};

const u16 DecorGfx_HEAVY_CHAIR[] = {
    0xBA
};

const u16 DecorGfx_PRETTY_CHAIR[] = {
    0xC0
};

const u16 DecorGfx_COMFORT_CHAIR[] = {
    0xC1
};

const u16 DecorGfx_RAGGED_CHAIR[] = {
    0xC2
};

const u16 DecorGfx_BRICK_CHAIR[] = {
    0xC8
};

const u16 DecorGfx_CAMP_CHAIR[] = {
    0xC9
};

const u16 DecorGfx_HARD_CHAIR[] = {
    0xCA
};

const u16 DecorGfx_RED_PLANT[] = {
    0xD0,
    0xD8
};

const u16 DecorGfx_TROPICAL_PLANT[] = {
    0xD2,
    0xDA
};

const u16 DecorGfx_PRETTY_FLOWERS[] = {
    0xD4,
    0xDC
};

const u16 DecorGfx_COLORFUL_PLANT[] = {
    0xE0,
    0xE2,
    0xE8,
    0xE9
};

const u16 DecorGfx_BIG_PLANT[] = {
    0xE4,
    0xE6,
    0xEC,
    0xED
};

const u16 DecorGfx_GORGEOUS_PLANT[] = {
    0xF0,
    0xF2,
    0xF8,
    0xF9
};

const u16 DecorGfx_RED_BRICK[] = {
    0x25,
    0x2D
};

const u16 DecorGfx_YELLOW_BRICK[] = {
    0x26,
    0x2E
};

const u16 DecorGfx_BLUE_BRICK[] = {
    0x27,
    0x2F
};

const u16 DecorGfx_RED_BALLOON[] = {
    0x138
};

const u16 DecorGfx_BLUE_BALLOON[] = {
    0x13C
};

const u16 DecorGfx_YELLOW_BALLOON[] = {
    0x140
};

const u16 DecorGfx_RED_TENT[] = {
    0x30,
    0x31,
    0x32,
    0x38,
    0x39,
    0x3A,
    0x40,
    0x41,
    0x3B
};

const u16 DecorGfx_BLUE_TENT[] = {
    0x48,
    0x49,
    0x68,
    0x50,
    0x51,
    0x70,
    0x58,
    0x59,
    0x69
};

const u16 DecorGfx_SOLID_BOARD[] = {
    0x34,
    0x3C
};

const u16 DecorGfx_SLIDE[] = {
    0x35,
    0x36,
    0x3D,
    0x3E,
    0x63,
    0x64,
    0x6F,
    0x77
};

const u16 DecorGfx_FENCE_LENGTH[] = {
    0x33
};

const u16 DecorGfx_FENCE_WIDTH[] = {
    0x2C
};

const u16 DecorGfx_TIRE[] = {
    0x80,
    0x81,
    0x88,
    0x89
};

const u16 DecorGfx_STAND[] = {
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x72,
    0x73,
    0x74,
    0x75
};

const u16 DecorGfx_MUD_BALL[] = {
    0x28
};

const u16 DecorGfx_BREAKABLE_DOOR[] = {
    0x37,
    0x3F
};

const u16 DecorGfx_SAND_ORNAMENT[] = {
    0x85,
    0x8D
};

const u16 DecorGfx_SILVER_SHIELD[] = {
    0xD6,
    0xDE
};

const u16 DecorGfx_GOLD_SHIELD[] = {
    0x12E,
    0x136
};

const u16 DecorGfx_GLASS_ORNAMENT[] = {
    0x82,
    0x8A
};

const u16 DecorGfx_TV[] = {
    0xF4
};

const u16 DecorGfx_ROUND_TV[] = {
    0xF5
};

const u16 DecorGfx_CUTE_TV[] = {
    0xF6
};

const u16 DecorGfx_GLITTER_MAT[] = {
    0x60
};

const u16 DecorGfx_JUMP_MAT[] = {
    0x61
};

const u16 DecorGfx_SPIN_MAT[] = {
    0x62
};

const u16 DecorGfx_C_LOW_NOTE_MAT[] = {
    0x78
};

const u16 DecorGfx_D_NOTE_MAT[] = {
    0x79
};

const u16 DecorGfx_E_NOTE_MAT[] = {
    0x7A
};

const u16 DecorGfx_F_NOTE_MAT[] = {
    0x7B
};

const u16 DecorGfx_G_NOTE_MAT[] = {
    0x7C
};

const u16 DecorGfx_A_NOTE_MAT[] = {
    0x7D
};

const u16 DecorGfx_B_NOTE_MAT[] = {
    0x7E
};

const u16 DecorGfx_C_HIGH_NOTE_MAT[] = {
    0xB3
};

const u16 DecorGfx_SURF_MAT[] = {
    0x42,
    0x43,
    0x44,
    0x4A,
    0x4B,
    0x4C,
    0x52,
    0x53,
    0x54
};

const u16 DecorGfx_THUNDER_MAT[] = {
    0x45,
    0x46,
    0x47,
    0x4D,
    0x4E,
    0x4F,
    0x55,
    0x56,
    0x57
};

const u16 DecorGfx_FIRE_BLAST_MAT[] = {
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E,
    0x5F,
    0x65,
    0x66,
    0x67
};

const u16 DecorGfx_POWDER_SNOW_MAT[] = {
    0x100,
    0x101,
    0x102,
    0x108,
    0x109,
    0x10A,
    0x110,
    0x111,
    0x112
};

const u16 DecorGfx_ATTRACT_MAT[] = {
    0x103,
    0x104,
    0x105,
    0x10B,
    0x10C,
    0x10D,
    0x113,
    0x114,
    0x115
};

const u16 DecorGfx_FISSURE_MAT[] = {
    0x106,
    0x107,
    0x118,
    0x10E,
    0x10F,
    0x120,
    0x116,
    0x117,
    0x128
};

const u16 DecorGfx_SPIKES_MAT[] = {
    0x119,
    0x11A,
    0x11B,
    0x121,
    0x122,
    0x123,
    0x129,
    0x12A,
    0x12B
};

const u16 DecorGfx_BALL_POSTER[] = {
    0x130
};

const u16 DecorGfx_GREEN_POSTER[] = {
    0x131
};

const u16 DecorGfx_RED_POSTER[] = {
    0x132
};

const u16 DecorGfx_BLUE_POSTER[] = {
    0x133
};

const u16 DecorGfx_CUTE_POSTER[] = {
    0x134
};

const u16 DecorGfx_PIKA_POSTER[] = {
    0x11C,
    0x11D
};

const u16 DecorGfx_LONG_POSTER[] = {
    0x11E,
    0x11F
};

const u16 DecorGfx_SEA_POSTER[] = {
    0x124,
    0x125
};

const u16 DecorGfx_SKY_POSTER[] = {
    0x126,
    0x127
};

const u16 DecorGfx_KISS_POSTER[] = {
    0x12C,
    0x12D
};

const u16 DecorGfx_PICHU_DOLL[] = {
    MAP_OBJ_GFX_PICHU_DOLL
};

const u16 DecorGfx_PIKACHU_DOLL[] = {
    MAP_OBJ_GFX_PIKACHU_DOLL
};

const u16 DecorGfx_MARILL_DOLL[] = {
    MAP_OBJ_GFX_MARILL_DOLL
};

const u16 DecorGfx_TOGEPI_DOLL[] = {
    MAP_OBJ_GFX_TOGEPI_DOLL
};

const u16 DecorGfx_CYNDAQUIL_DOLL[] = {
    MAP_OBJ_GFX_CYNDAQUIL_DOLL
};

const u16 DecorGfx_CHIKORITA_DOLL[] = {
    MAP_OBJ_GFX_CHIKORITA_DOLL
};

const u16 DecorGfx_TOTODILE_DOLL[] = {
    MAP_OBJ_GFX_TOTODILE_DOLL
};

const u16 DecorGfx_JIGGLYPUFF_DOLL[] = {
    MAP_OBJ_GFX_JIGGLYPUFF_DOLL
};

const u16 DecorGfx_MEOWTH_DOLL[] = {
    MAP_OBJ_GFX_MEOWTH_DOLL
};

const u16 DecorGfx_CLEFAIRY_DOLL[] = {
    MAP_OBJ_GFX_CLEFAIRY_DOLL
};

const u16 DecorGfx_DITTO_DOLL[] = {
    MAP_OBJ_GFX_DITTO_DOLL
};

const u16 DecorGfx_SMOOCHUM_DOLL[] = {
    MAP_OBJ_GFX_SMOOCHUM_DOLL
};

const u16 DecorGfx_TREECKO_DOLL[] = {
    MAP_OBJ_GFX_TREECKO_DOLL
};

const u16 DecorGfx_TORCHIC_DOLL[] = {
    MAP_OBJ_GFX_TORCHIC_DOLL
};

const u16 DecorGfx_MUDKIP_DOLL[] = {
    MAP_OBJ_GFX_MUDKIP_DOLL
};

const u16 DecorGfx_DUSKULL_DOLL[] = {
    MAP_OBJ_GFX_DUSKULL_DOLL
};

const u16 DecorGfx_WYNAUT_DOLL[] = {
    MAP_OBJ_GFX_WYNAUT_DOLL
};

const u16 DecorGfx_BALTOY_DOLL[] = {
    MAP_OBJ_GFX_BALTOY_DOLL
};

const u16 DecorGfx_KECLEON_DOLL[] = {
    MAP_OBJ_GFX_KECLEON_DOLL
};

const u16 DecorGfx_AZURILL_DOLL[] = {
    MAP_OBJ_GFX_AZURILL_DOLL
};

const u16 DecorGfx_SKITTY_DOLL[] = {
    MAP_OBJ_GFX_SKITTY_DOLL
};

const u16 DecorGfx_SWABLU_DOLL[] = {
    MAP_OBJ_GFX_SWABLU_DOLL
};

const u16 DecorGfx_GULPIN_DOLL[] = {
    MAP_OBJ_GFX_GULPIN_DOLL
};

const u16 DecorGfx_LOTAD_DOLL[] = {
    MAP_OBJ_GFX_LOTAD_DOLL
};

const u16 DecorGfx_SEEDOT_DOLL[] = {
    MAP_OBJ_GFX_SEEDOT_DOLL
};

const u16 DecorGfx_PIKA_CUSHION[] = {
    MAP_OBJ_GFX_PIKA_CUSHION
};

const u16 DecorGfx_ROUND_CUSHION[] = {
    MAP_OBJ_GFX_ROUND_CUSHION
};

const u16 DecorGfx_KISS_CUSHION[] = {
    MAP_OBJ_GFX_KISS_CUSHION
};

const u16 DecorGfx_ZIGZAG_CUSHION[] = {
    MAP_OBJ_GFX_ZIGZAG_CUSHION
};

const u16 DecorGfx_SPIN_CUSHION[] = {
    MAP_OBJ_GFX_SPIN_CUSHION
};

const u16 DecorGfx_DIAMOND_CUSHION[] = {
    MAP_OBJ_GFX_DIAMOND_CUSHION
};

const u16 DecorGfx_BALL_CUSHION[] = {
    MAP_OBJ_GFX_BALL_CUSHION
};

const u16 DecorGfx_GRASS_CUSHION[] = {
    MAP_OBJ_GFX_GRASS_CUSHION
};

const u16 DecorGfx_FIRE_CUSHION[] = {
    MAP_OBJ_GFX_FIRE_CUSHION
};

const u16 DecorGfx_WATER_CUSHION[] = {
    MAP_OBJ_GFX_WATER_CUSHION
};

const u16 DecorGfx_SNORLAX_DOLL[] = {
    MAP_OBJ_GFX_BIG_SNORLAX_DOLL
};

const u16 DecorGfx_RHYDON_DOLL[] = {
    MAP_OBJ_GFX_BIG_RHYDON_DOLL
};

const u16 DecorGfx_LAPRAS_DOLL[] = {
    MAP_OBJ_GFX_BIG_LAPRAS_DOLL
};

const u16 DecorGfx_VENUSAUR_DOLL[] = {
    MAP_OBJ_GFX_BIG_VENUSAUR_DOLL
};

const u16 DecorGfx_CHARIZARD_DOLL[] = {
    MAP_OBJ_GFX_BIG_CHARIZARD_DOLL
};

const u16 DecorGfx_BLASTOISE_DOLL[] = {
    MAP_OBJ_GFX_BIG_BLASTOISE_DOLL
};

const u16 DecorGfx_WAILMER_DOLL[] = {
    MAP_OBJ_GFX_BIG_WAILMER_DOLL
};

const u16 DecorGfx_REGIROCK_DOLL[] = {
    MAP_OBJ_GFX_BIG_REGIROCK_DOLL
};

const u16 DecorGfx_REGICE_DOLL[] = {
    MAP_OBJ_GFX_BIG_REGICE_DOLL
};

const u16 DecorGfx_REGISTEEL_DOLL[] = {
    MAP_OBJ_GFX_BIG_REGISTEEL_DOLL
};

const struct Decoration gDecorations[] = {
    DECORATION(DECOR_NONE, _("SMALL DESK"), 0, 0, 0, 0, DecorDesc_SMALL_DESK, DecorGfx_SMALL_DESK),
    DECORATION(DECOR_SMALL_DESK, _("SMALL DESK"), 0, 0, 0, 3000, DecorDesc_SMALL_DESK, DecorGfx_SMALL_DESK),
    DECORATION(DECOR_POKEMON_DESK, _("POKéMON DESK"), 0, 0, 0, 3000, DecorDesc_POKEMON_DESK, DecorGfx_POKEMON_DESK),
    DECORATION(DECOR_HEAVY_DESK, _("HEAVY DESK"), 0, 9, 0, 6000, DecorDesc_HEAVY_DESK, DecorGfx_HEAVY_DESK),
    DECORATION(DECOR_RAGGED_DESK, _("RAGGED DESK"), 0, 9, 0, 6000, DecorDesc_RAGGED_DESK, DecorGfx_RAGGED_DESK),
    DECORATION(DECOR_COMFORT_DESK, _("COMFORT DESK"), 0, 9, 0, 6000, DecorDesc_COMFORT_DESK, DecorGfx_COMFORT_DESK),
    DECORATION(DECOR_PRETTY_DESK, _("PRETTY DESK"), 0, 8, 0, 9000, DecorDesc_PRETTY_DESK, DecorGfx_PRETTY_DESK),
    DECORATION(DECOR_BRICK_DESK, _("BRICK DESK"), 0, 8, 0, 9000, DecorDesc_BRICK_DESK, DecorGfx_BRICK_DESK),
    DECORATION(DECOR_CAMP_DESK, _("CAMP DESK"), 0, 8, 0, 9000, DecorDesc_CAMP_DESK, DecorGfx_CAMP_DESK),
    DECORATION(DECOR_HARD_DESK, _("HARD DESK"), 0, 8, 0, 9000, DecorDesc_HARD_DESK, DecorGfx_HARD_DESK),
    DECORATION(DECOR_SMALL_CHAIR, _("SMALL CHAIR"), 1, 0, 1, 2000, DecorDesc_SMALL_CHAIR, DecorGfx_SMALL_CHAIR),
    DECORATION(DECOR_POKEMON_CHAIR, _("POKéMON CHAIR"), 1, 0, 1, 2000, DecorDesc_POKEMON_CHAIR, DecorGfx_POKEMON_CHAIR),
    DECORATION(DECOR_HEAVY_CHAIR, _("HEAVY CHAIR"), 1, 0, 1, 2000, DecorDesc_HEAVY_CHAIR, DecorGfx_HEAVY_CHAIR),
    DECORATION(DECOR_PRETTY_CHAIR, _("PRETTY CHAIR"), 1, 0, 1, 2000, DecorDesc_PRETTY_CHAIR, DecorGfx_PRETTY_CHAIR),
    DECORATION(DECOR_COMFORT_CHAIR, _("COMFORT CHAIR"), 1, 0, 1, 2000, DecorDesc_COMFORT_CHAIR, DecorGfx_COMFORT_CHAIR),
    DECORATION(DECOR_RAGGED_CHAIR, _("RAGGED CHAIR"), 1, 0, 1, 2000, DecorDesc_RAGGED_CHAIR, DecorGfx_RAGGED_CHAIR),
    DECORATION(DECOR_BRICK_CHAIR, _("BRICK CHAIR"), 1, 0, 1, 2000, DecorDesc_BRICK_CHAIR, DecorGfx_BRICK_CHAIR),
    DECORATION(DECOR_CAMP_CHAIR, _("CAMP CHAIR"), 1, 0, 1, 2000, DecorDesc_CAMP_CHAIR, DecorGfx_CAMP_CHAIR),
    DECORATION(DECOR_HARD_CHAIR, _("HARD CHAIR"), 1, 0, 1, 2000, DecorDesc_HARD_CHAIR, DecorGfx_HARD_CHAIR),
    DECORATION(DECOR_RED_PLANT, _("RED PLANT"), 2, 5, 2, 3000, DecorDesc_RED_PLANT, DecorGfx_RED_PLANT),
    DECORATION(DECOR_TROPICAL_PLANT, _("TROPICAL PLANT"), 2, 5, 2, 3000, DecorDesc_TROPICAL_PLANT, DecorGfx_TROPICAL_PLANT),
    DECORATION(DECOR_PRETTY_FLOWERS, _("PRETTY FLOWERS"), 2, 5, 2, 3000, DecorDesc_PRETTY_FLOWERS, DecorGfx_PRETTY_FLOWERS),
    DECORATION(DECOR_COLORFUL_PLANT, _("COLORFUL PLANT"), 2, 4, 2, 5000, DecorDesc_COLORFUL_PLANT, DecorGfx_COLORFUL_PLANT),
    DECORATION(DECOR_BIG_PLANT, _("BIG PLANT"), 2, 4, 2, 5000, DecorDesc_BIG_PLANT, DecorGfx_BIG_PLANT),
    DECORATION(DECOR_GORGEOUS_PLANT, _("GORGEOUS PLANT"), 2, 4, 2, 5000, DecorDesc_GORGEOUS_PLANT, DecorGfx_GORGEOUS_PLANT),
    DECORATION(DECOR_RED_BRICK, _("RED BRICK"), 0, 5, 3, 500, DecorDesc_RED_BRICK, DecorGfx_RED_BRICK),
    DECORATION(DECOR_YELLOW_BRICK, _("YELLOW BRICK"), 0, 5, 3, 500, DecorDesc_YELLOW_BRICK, DecorGfx_YELLOW_BRICK),
    DECORATION(DECOR_BLUE_BRICK, _("BLUE BRICK"), 0, 5, 3, 500, DecorDesc_BLUE_BRICK, DecorGfx_BLUE_BRICK),
    DECORATION(DECOR_RED_BALLOON, _("RED BALLOON"), 1, 0, 3, 500, DecorDesc_RED_BALLOON, DecorGfx_RED_BALLOON),
    DECORATION(DECOR_BLUE_BALLOON, _("BLUE BALLOON"), 1, 0, 3, 500, DecorDesc_BLUE_BALLOON, DecorGfx_BLUE_BALLOON),
    DECORATION(DECOR_YELLOW_BALLOON, _("YELLOW BALLOON"), 1, 0, 3, 500, DecorDesc_YELLOW_BALLOON, DecorGfx_YELLOW_BALLOON),
    DECORATION(DECOR_RED_TENT, _("RED TENT"), 1, 8, 3, 10000, DecorDesc_RED_TENT, DecorGfx_RED_TENT),
    DECORATION(DECOR_BLUE_TENT, _("BLUE TENT"), 1, 8, 3, 10000, DecorDesc_BLUE_TENT, DecorGfx_BLUE_TENT),
    DECORATION(DECOR_SOLID_BOARD, _("SOLID BOARD"), 1, 5, 3, 3000, DecorDesc_SOLID_BOARD, DecorGfx_SOLID_BOARD),
    DECORATION(DECOR_SLIDE, _("SLIDE"), 1, 7, 3, 8000, DecorDesc_SLIDE, DecorGfx_SLIDE),
    DECORATION(DECOR_FENCE_LENGTH, _("FENCE LENGTH"), 0, 0, 3, 500, DecorDesc_FENCE_LENGTH, DecorGfx_FENCE_LENGTH),
    DECORATION(DECOR_FENCE_WIDTH, _("FENCE WIDTH"), 0, 0, 3, 500, DecorDesc_FENCE_WIDTH, DecorGfx_FENCE_WIDTH),
    DECORATION(DECOR_TIRE, _("TIRE"), 0, 4, 3, 800, DecorDesc_TIRE, DecorGfx_TIRE),
    DECORATION(DECOR_STAND, _("STAND"), 1, 3, 3, 7000, DecorDesc_STAND, DecorGfx_STAND),
    DECORATION(DECOR_MUD_BALL, _("MUD BALL"), 1, 0, 3, 200, DecorDesc_MUD_BALL, DecorGfx_MUD_BALL),
    DECORATION(DECOR_BREAKABLE_DOOR, _("BREAKABLE DOOR"), 1, 5, 3, 3000, DecorDesc_BREAKABLE_DOOR, DecorGfx_BREAKABLE_DOOR),
    DECORATION(DECOR_SAND_ORNAMENT, _("SAND ORNAMENT"), 2, 5, 3, 3000, DecorDesc_SAND_ORNAMENT, DecorGfx_SAND_ORNAMENT),
    DECORATION(DECOR_SILVER_SHIELD, _("SILVER SHIELD"), 2, 5, 3, 0, DecorDesc_SILVER_SHIELD, DecorGfx_SILVER_SHIELD),
    DECORATION(DECOR_GOLD_SHIELD, _("GOLD SHIELD"), 2, 5, 3, 0, DecorDesc_GOLD_SHIELD, DecorGfx_GOLD_SHIELD),
    DECORATION(DECOR_GLASS_ORNAMENT, _("GLASS ORNAMENT"), 2, 5, 3, 0, DecorDesc_GLASS_ORNAMENT, DecorGfx_GLASS_ORNAMENT),
    DECORATION(DECOR_TV, _("TV"), 0, 0, 3, 3000, DecorDesc_TV, DecorGfx_TV),
    DECORATION(DECOR_ROUND_TV, _("ROUND TV"), 0, 0, 3, 4000, DecorDesc_ROUND_TV, DecorGfx_ROUND_TV),
    DECORATION(DECOR_CUTE_TV, _("CUTE TV"), 0, 0, 3, 4000, DecorDesc_CUTE_TV, DecorGfx_CUTE_TV),
    DECORATION(DECOR_GLITTER_MAT, _("GLITTER MAT"), 1, 0, 4, 2000, DecorDesc_GLITTER_MAT, DecorGfx_GLITTER_MAT),
    DECORATION(DECOR_JUMP_MAT, _("JUMP MAT"), 1, 0, 4, 2000, DecorDesc_JUMP_MAT, DecorGfx_JUMP_MAT),
    DECORATION(DECOR_SPIN_MAT, _("SPIN MAT"), 1, 0, 4, 2000, DecorDesc_SPIN_MAT, DecorGfx_SPIN_MAT),
    DECORATION(DECOR_C_LOW_NOTE_MAT, _("C Low NOTE MAT"), 1, 0, 4, 500, DecorDesc_C_LOW_NOTE_MAT, DecorGfx_C_LOW_NOTE_MAT),
    DECORATION(DECOR_D_NOTE_MAT, _("D NOTE MAT"), 1, 0, 4, 500, DecorDesc_D_NOTE_MAT, DecorGfx_D_NOTE_MAT),
    DECORATION(DECOR_E_NOTE_MAT, _("E NOTE MAT"), 1, 0, 4, 500, DecorDesc_E_NOTE_MAT, DecorGfx_E_NOTE_MAT),
    DECORATION(DECOR_F_NOTE_MAT, _("F NOTE MAT"), 1, 0, 4, 500, DecorDesc_F_NOTE_MAT, DecorGfx_F_NOTE_MAT),
    DECORATION(DECOR_G_NOTE_MAT, _("G NOTE MAT"), 1, 0, 4, 500, DecorDesc_G_NOTE_MAT, DecorGfx_G_NOTE_MAT),
    DECORATION(DECOR_A_NOTE_MAT, _("A NOTE MAT"), 1, 0, 4, 500, DecorDesc_A_NOTE_MAT, DecorGfx_A_NOTE_MAT),
    DECORATION(DECOR_B_NOTE_MAT, _("B NOTE MAT"), 1, 0, 4, 500, DecorDesc_B_NOTE_MAT, DecorGfx_B_NOTE_MAT),
    DECORATION(DECOR_C_HIGH_NOTE_MAT, _("C High NOTE MAT"), 1, 0, 4, 500, DecorDesc_C_HIGH_NOTE_MAT, DecorGfx_C_HIGH_NOTE_MAT),
    DECORATION(DECOR_SURF_MAT, _("SURF MAT"), 1, 8, 4, 4000, DecorDesc_SURF_MAT, DecorGfx_SURF_MAT),
    DECORATION(DECOR_THUNDER_MAT, _("THUNDER MAT"), 1, 8, 4, 4000, DecorDesc_THUNDER_MAT, DecorGfx_THUNDER_MAT),
    DECORATION(DECOR_FIRE_BLAST_MAT, _("FIRE BLAST MAT"), 1, 8, 4, 4000, DecorDesc_FIRE_BLAST_MAT, DecorGfx_FIRE_BLAST_MAT),
    DECORATION(DECOR_POWDER_SNOW_MAT, _("POWDER SNOW MAT"), 1, 8, 4, 4000, DecorDesc_POWDER_SNOW_MAT, DecorGfx_POWDER_SNOW_MAT),
    DECORATION(DECOR_ATTRACT_MAT, _("ATTRACT MAT"), 1, 8, 4, 4000, DecorDesc_ATTRACT_MAT, DecorGfx_ATTRACT_MAT),
    DECORATION(DECOR_FISSURE_MAT, _("FISSURE MAT"), 1, 8, 4, 4000, DecorDesc_FISSURE_MAT, DecorGfx_FISSURE_MAT),
    DECORATION(DECOR_SPIKES_MAT, _("SPIKES MAT"), 1, 8, 4, 4000, DecorDesc_SPIKES_MAT, DecorGfx_SPIKES_MAT),
    DECORATION(DECOR_BALL_POSTER, _("BALL POSTER"), 3, 0, 5, 1000, DecorDesc_BALL_POSTER, DecorGfx_BALL_POSTER),
    DECORATION(DECOR_GREEN_POSTER, _("GREEN POSTER"), 3, 0, 5, 1000, DecorDesc_GREEN_POSTER, DecorGfx_GREEN_POSTER),
    DECORATION(DECOR_RED_POSTER, _("RED POSTER"), 3, 0, 5, 1000, DecorDesc_RED_POSTER, DecorGfx_RED_POSTER),
    DECORATION(DECOR_BLUE_POSTER, _("BLUE POSTER"), 3, 0, 5, 1000, DecorDesc_BLUE_POSTER, DecorGfx_BLUE_POSTER),
    DECORATION(DECOR_CUTE_POSTER, _("CUTE POSTER"), 3, 0, 5, 1000, DecorDesc_CUTE_POSTER, DecorGfx_CUTE_POSTER),
    DECORATION(DECOR_PIKA_POSTER, _("PIKA POSTER"), 3, 1, 5, 1500, DecorDesc_PIKA_POSTER, DecorGfx_PIKA_POSTER),
    DECORATION(DECOR_LONG_POSTER, _("LONG POSTER"), 3, 1, 5, 1500, DecorDesc_LONG_POSTER, DecorGfx_LONG_POSTER),
    DECORATION(DECOR_SEA_POSTER, _("SEA POSTER"), 3, 1, 5, 1500, DecorDesc_SEA_POSTER, DecorGfx_SEA_POSTER),
    DECORATION(DECOR_SKY_POSTER, _("SKY POSTER"), 3, 1, 5, 1500, DecorDesc_SKY_POSTER, DecorGfx_SKY_POSTER),
    DECORATION(DECOR_KISS_POSTER, _("KISS POSTER"), 3, 1, 5, 1500, DecorDesc_KISS_POSTER, DecorGfx_KISS_POSTER),
    DECORATION(DECOR_PICHU_DOLL, _("PICHU DOLL"), 4, 0, 6, 3000, DecorDesc_PICHU_DOLL, DecorGfx_PICHU_DOLL),
    DECORATION(DECOR_PIKACHU_DOLL, _("PIKACHU DOLL"), 4, 0, 6, 3000, DecorDesc_PIKACHU_DOLL, DecorGfx_PIKACHU_DOLL),
    DECORATION(DECOR_MARILL_DOLL, _("MARILL DOLL"), 4, 0, 6, 3000, DecorDesc_MARILL_DOLL, DecorGfx_MARILL_DOLL),
    DECORATION(DECOR_TOGEPI_DOLL, _("TOGEPI DOLL"), 4, 0, 6, 3000, DecorDesc_TOGEPI_DOLL, DecorGfx_TOGEPI_DOLL),
    DECORATION(DECOR_CYNDAQUIL_DOLL, _("CYNDAQUIL DOLL"), 4, 0, 6, 3000, DecorDesc_CYNDAQUIL_DOLL, DecorGfx_CYNDAQUIL_DOLL),
    DECORATION(DECOR_CHIKORITA_DOLL, _("CHIKORITA DOLL"), 4, 0, 6, 3000, DecorDesc_CHIKORITA_DOLL, DecorGfx_CHIKORITA_DOLL),
    DECORATION(DECOR_TOTODILE_DOLL, _("TOTODILE DOLL"), 4, 0, 6, 3000, DecorDesc_TOTODILE_DOLL, DecorGfx_TOTODILE_DOLL),
    DECORATION(DECOR_JIGGLYPUFF_DOLL, _("JIGGLYPUFF DOLL"), 4, 0, 6, 3000, DecorDesc_JIGGLYPUFF_DOLL, DecorGfx_JIGGLYPUFF_DOLL),
    DECORATION(DECOR_MEOWTH_DOLL, _("MEOWTH DOLL"), 4, 0, 6, 3000, DecorDesc_MEOWTH_DOLL, DecorGfx_MEOWTH_DOLL),
    DECORATION(DECOR_CLEFAIRY_DOLL, _("CLEFAIRY DOLL"), 4, 0, 6, 3000, DecorDesc_CLEFAIRY_DOLL, DecorGfx_CLEFAIRY_DOLL),
    DECORATION(DECOR_DITTO_DOLL, _("DITTO DOLL"), 4, 0, 6, 3000, DecorDesc_DITTO_DOLL, DecorGfx_DITTO_DOLL),
    DECORATION(DECOR_SMOOCHUM_DOLL, _("SMOOCHUM DOLL"), 4, 0, 6, 3000, DecorDesc_SMOOCHUM_DOLL, DecorGfx_SMOOCHUM_DOLL),
    DECORATION(DECOR_TREECKO_DOLL, _("TREECKO DOLL"), 4, 0, 6, 3000, DecorDesc_TREECKO_DOLL, DecorGfx_TREECKO_DOLL),
    DECORATION(DECOR_TORCHIC_DOLL, _("TORCHIC DOLL"), 4, 0, 6, 3000, DecorDesc_TORCHIC_DOLL, DecorGfx_TORCHIC_DOLL),
    DECORATION(DECOR_MUDKIP_DOLL, _("MUDKIP DOLL"), 4, 0, 6, 3000, DecorDesc_MUDKIP_DOLL, DecorGfx_MUDKIP_DOLL),
    DECORATION(DECOR_DUSKULL_DOLL, _("DUSKULL DOLL"), 4, 0, 6, 3000, DecorDesc_DUSKULL_DOLL, DecorGfx_DUSKULL_DOLL),
    DECORATION(DECOR_WYNAUT_DOLL, _("WYNAUT DOLL"), 4, 0, 6, 3000, DecorDesc_WYNAUT_DOLL, DecorGfx_WYNAUT_DOLL),
    DECORATION(DECOR_BALTOY_DOLL, _("BALTOY DOLL"), 4, 0, 6, 3000, DecorDesc_BALTOY_DOLL, DecorGfx_BALTOY_DOLL),
    DECORATION(DECOR_KECLEON_DOLL, _("KECLEON DOLL"), 4, 0, 6, 3000, DecorDesc_KECLEON_DOLL, DecorGfx_KECLEON_DOLL),
    DECORATION(DECOR_AZURILL_DOLL, _("AZURILL DOLL"), 4, 0, 6, 3000, DecorDesc_AZURILL_DOLL, DecorGfx_AZURILL_DOLL),
    DECORATION(DECOR_SKITTY_DOLL, _("SKITTY DOLL"), 4, 0, 6, 3000, DecorDesc_SKITTY_DOLL, DecorGfx_SKITTY_DOLL),
    DECORATION(DECOR_SWABLU_DOLL, _("SWABLU DOLL"), 4, 0, 6, 3000, DecorDesc_SWABLU_DOLL, DecorGfx_SWABLU_DOLL),
    DECORATION(DECOR_GULPIN_DOLL, _("GULPIN DOLL"), 4, 0, 6, 3000, DecorDesc_GULPIN_DOLL, DecorGfx_GULPIN_DOLL),
    DECORATION(DECOR_LOTAD_DOLL, _("LOTAD DOLL"), 4, 0, 6, 3000, DecorDesc_LOTAD_DOLL, DecorGfx_LOTAD_DOLL),
    DECORATION(DECOR_SEEDOT_DOLL, _("SEEDOT DOLL"), 4, 0, 6, 3000, DecorDesc_SEEDOT_DOLL, DecorGfx_SEEDOT_DOLL),
    DECORATION(DECOR_PIKA_CUSHION, _("PIKA CUSHION"), 4, 0, 7, 2000, DecorDesc_PIKA_CUSHION, DecorGfx_PIKA_CUSHION),
    DECORATION(DECOR_ROUND_CUSHION, _("ROUND CUSHION"), 4, 0, 7, 2000, DecorDesc_ROUND_CUSHION, DecorGfx_ROUND_CUSHION),
    DECORATION(DECOR_KISS_CUSHION, _("KISS CUSHION"), 4, 0, 7, 2000, DecorDesc_KISS_CUSHION, DecorGfx_KISS_CUSHION),
    DECORATION(DECOR_ZIGZAG_CUSHION, _("ZIGZAG CUSHION"), 4, 0, 7, 2000, DecorDesc_ZIGZAG_CUSHION, DecorGfx_ZIGZAG_CUSHION),
    DECORATION(DECOR_SPIN_CUSHION, _("SPIN CUSHION"), 4, 0, 7, 2000, DecorDesc_SPIN_CUSHION, DecorGfx_SPIN_CUSHION),
    DECORATION(DECOR_DIAMOND_CUSHION, _("DIAMOND CUSHION"), 4, 0, 7, 2000, DecorDesc_DIAMOND_CUSHION, DecorGfx_DIAMOND_CUSHION),
    DECORATION(DECOR_BALL_CUSHION, _("BALL CUSHION"), 4, 0, 7, 2000, DecorDesc_BALL_CUSHION, DecorGfx_BALL_CUSHION),
    DECORATION(DECOR_GRASS_CUSHION, _("GRASS CUSHION"), 4, 0, 7, 2000, DecorDesc_GRASS_CUSHION, DecorGfx_GRASS_CUSHION),
    DECORATION(DECOR_FIRE_CUSHION, _("FIRE CUSHION"), 4, 0, 7, 2000, DecorDesc_FIRE_CUSHION, DecorGfx_FIRE_CUSHION),
    DECORATION(DECOR_WATER_CUSHION, _("WATER CUSHION"), 4, 0, 7, 2000, DecorDesc_WATER_CUSHION, DecorGfx_WATER_CUSHION),
    DECORATION(DECOR_SNORLAX_DOLL, _("SNORLAX DOLL"), 4, 5, 6, 10000, DecorDesc_SNORLAX_DOLL, DecorGfx_SNORLAX_DOLL),
    DECORATION(DECOR_RHYDON_DOLL, _("RHYDON DOLL"), 4, 5, 6, 10000, DecorDesc_RHYDON_DOLL, DecorGfx_RHYDON_DOLL),
    DECORATION(DECOR_LAPRAS_DOLL, _("LAPRAS DOLL"), 4, 5, 6, 10000, DecorDesc_LAPRAS_DOLL, DecorGfx_LAPRAS_DOLL),
    DECORATION(DECOR_VENUSAUR_DOLL, _("VENUSAUR DOLL"), 4, 5, 6, 10000, DecorDesc_VENUSAUR_DOLL, DecorGfx_VENUSAUR_DOLL),
    DECORATION(DECOR_CHARIZARD_DOLL, _("CHARIZARD DOLL"), 4, 5, 6, 10000, DecorDesc_CHARIZARD_DOLL, DecorGfx_CHARIZARD_DOLL),
    DECORATION(DECOR_BLASTOISE_DOLL, _("BLASTOISE DOLL"), 4, 5, 6, 10000, DecorDesc_BLASTOISE_DOLL, DecorGfx_BLASTOISE_DOLL),
    DECORATION(DECOR_WAILMER_DOLL, _("WAILMER DOLL"), 4, 5, 6, 10000, DecorDesc_WAILMER_DOLL, DecorGfx_WAILMER_DOLL),
    DECORATION(DECOR_REGIROCK_DOLL, _("REGIROCK DOLL"), 4, 5, 6, 10000, DecorDesc_REGIROCK_DOLL, DecorGfx_REGIROCK_DOLL),
    DECORATION(DECOR_REGICE_DOLL, _("REGICE DOLL"), 4, 5, 6, 10000, DecorDesc_REGICE_DOLL, DecorGfx_REGICE_DOLL),
    DECORATION(DECOR_REGISTEEL_DOLL, _("REGISTEEL DOLL"), 4, 5, 6, 10000, DecorDesc_REGISTEEL_DOLL, DecorGfx_REGISTEEL_DOLL)
};

extern u8 gUnknown_0815F399[];

void sub_80FE1DC(void)
{
    sub_80FE2B4();
    MenuDrawTextWindow(0, 0, 10, 9);
    PrintMenuItems(1, 1, 4, (const struct MenuAction *)gUnknown_083EC604);
    InitMenu(0, 1, 1, 4, gUnknown_020388D4, 9);
}

void sub_80FE220(void)
{
    gUnknown_020388D4 = 0;
    ScriptContext2_Enable();
    sub_80FE1DC();
    sub_80FE394();
}

void DecorationPC(u8 taskId)
{
    sub_80FE220();
    gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
}

void Task_SecretBasePC_Decoration(u8 taskId)
{
    DecorationPC(taskId);
    ewram_1f000.items = gSaveBlock1.secretBases[0].decorations;
    ewram_1f000.pos = gSaveBlock1.secretBases[0].decorationPos;
    ewram_1f000.size = sizeof gSaveBlock1.secretBases[0].decorations;
    ewram_1f000.isPlayerRoom = 0;
}

void DoPlayerPCDecoration(u8 taskId)
{
    DecorationPC(taskId);
    ewram_1f000.items = gSaveBlock1.playerRoomDecor;
    ewram_1f000.pos = gSaveBlock1.playerRoomDecorPos;
    ewram_1f000.size = sizeof gSaveBlock1.playerRoomDecor;
    ewram_1f000.isPlayerRoom = 1;
}

void sub_80FE2B4(void)
{
    u16 palettes[3];
    memcpy(palettes, gUnknown_083EC654, sizeof gUnknown_083EC654);
    LoadPalette(&palettes[2], 0xdf, 2);
    LoadPalette(&palettes[1], 0xd1, 2);
    LoadPalette(&palettes[0], 0xd8, 2);
}

void Task_DecorationPCProcessMenuInput(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            gUnknown_020388D4 = MoveMenuCursor(-1);
            sub_80FE394();
        }
        if (gMain.newKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            gUnknown_020388D4 = MoveMenuCursor(1);
            sub_80FE394();
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_083EC604[gUnknown_020388D4].func(taskId);
        } else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gpu_pal_decompress_alloc_tag_and_upload(taskId);
        }
    }
}

void sub_80FE394(void)
{
    MenuFillWindowRectWithBlankTile(2, 15, 27, 18);
    MenuPrint(gUnknown_083EC624[gUnknown_020388D4], 2, 15);
}

void gpu_pal_decompress_alloc_tag_and_upload(u8 taskId)
{
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 10, 9);
    MenuFillWindowRectWithBlankTile(2, 15, 27, 18);
    FreeSpritePaletteByTag(6);
    if (ewram_1f000.isPlayerRoom == 0)
    {
        ScriptContext1_SetupScript(gUnknown_0815F399);
        DestroyTask(taskId);
    } else
    {
        ReshowPlayerPC(taskId);
    }
}

void sub_80FE418(u8 taskId)
{
    sub_80FE5AC(taskId);
}

void sub_80FE428(u8 taskId)
{
    InitMenu(0, 1, 1, 4, gUnknown_020388D4, 9);
    sub_80FE394();
    gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
}

void sub_80FE470(u8 decoCat, u8 a1, u8 a2, u8 palIdx)
{
    u8 *strptr;
    u8 v0;
    v0 = sub_8072CBC();
    // PALETTE {palIdx}
    strptr = gStringVar4;
    strptr[0] = EXT_CTRL_CODE_BEGIN;
    strptr[1] = 5;
    strptr[2] = palIdx;
    strptr += 3;
    strptr = StringCopy(strptr, gUnknown_083EC5E4[decoCat]);
    strptr = sub_8072C14(strptr, sub_8134194(decoCat), 0x56, 1);
    *strptr++ = 0xba;
    strptr = sub_8072C14(strptr, gDecorationInventories[decoCat].size, 0x68, 1);
    strptr[0] = EXT_CTRL_CODE_BEGIN;
    strptr[1] = 5;
    strptr[2] = v0;
    strptr[3] = EOS;
    MenuPrint(gStringVar4, a1, a2);
}

void sub_80FE528(u8 taskId)
{
    u8 decoCat;
    MenuDrawTextWindow(0, 0, 14, 19);
    for (decoCat=0; decoCat<8; decoCat++)
    {
        if (ewram_1f000.isPlayerRoom == 1 && gTasks[taskId].data[11] == 0 && decoCat != DECOCAT_DOLL && decoCat != DECOCAT_CUSHION)
        {
            sub_80FE470(decoCat, 1, 2 * decoCat + 1, 13);
        } else
        {
            sub_80FE470(decoCat, 1, 2 * decoCat + 1, 255);
        }
    }
    MenuPrint(gUnknownText_Exit, 1, 17);
}

void sub_80FE5AC(u8 taskId)
{
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 29, 19);
    sub_80FE528(taskId);
    InitMenu(0, 1, 1, 9, gUnknown_020388F6, 13);
    gTasks[taskId].func = sub_80FE604;
}

void sub_80FE604(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            MoveMenuCursor(-1);
        } else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            MoveMenuCursor(1);
        } else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_020388F6 = GetMenuCursorPos();
            if (gUnknown_020388F6 != 8)
            {
                gUnknown_020388D5 = sub_8134194(gUnknown_020388F6);
                if (gUnknown_020388D5)
                {
                    sub_8134104(gUnknown_020388F6);
                    gUnknown_020388D0 = gDecorationInventories[gUnknown_020388F6].items;
                    sub_80FEF50(taskId);
                    sub_80F944C();
                    sub_80F9480(gUnknown_020388F7, 8);
                    LoadScrollIndicatorPalette();
                    gTasks[taskId].func = sub_80FE868;
                } else
                {
                    sub_8072DEC();
                    MenuZeroFillWindowRect(0, 0, 14, 19);
                    DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE418, 0);
                }
            } else
            {
                sub_80FE728(taskId);
            }
        } else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_80FE728(taskId);
        }
    }
}

void sub_80FE728(u8 taskId)
{
    if (gTasks[taskId].data[11] != 3)
    {
        sub_80FE758(taskId);
    } else
    {
        sub_8109DAC(taskId);
    }
}

void sub_80FE758(u8 taskId)
{
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 14, 19);
    if (gTasks[taskId].data[11] != 2)
    {
        sub_80FE1DC();
        MenuDisplayMessageBox();
        sub_80FE394();
        gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
    } else
    {
        sub_80B3068(taskId);
    }
}

void sub_80FE7A8(u8 taskId)
{
    gTasks[taskId].data[11] = 3;
    gUnknown_020388F6 = 0;
    sub_80FE5AC(taskId);
}

void sub_80FE7D4(u8 *dest, u8 decClass)
{
    StringCopy(dest, gUnknown_083EC5E4[decClass]);
}

void sub_80FE7EC(u8 taskId)
{
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 29, 19);

    sub_80FEC94(taskId);
    sub_80FECB8(gUnknown_020388F6);

    MenuDrawTextWindow(15, 12, 29, 19);

    sub_80FECE0(gUnknown_020388F2 + gUnknown_020388F4);
    InitMenu(0, 1, 2, gUnknown_020388F3 + 1, gUnknown_020388F2, 13);
}

void sub_80FE868(u8 taskId)
{
    sub_80FE7EC(taskId);
    gTasks[taskId].func = sub_80FE948;
}

void sub_80FE894(u8 taskId /*r8*/, s8 cursorVector /*r5*/, s8 bgVector /*r7*/)
{
    int v0 /*r10*/;
    u8 v1;
    v0 = gUnknown_020388F2 + gUnknown_020388F4 == gUnknown_020388D5;
    PlaySE(SE_SELECT);
    if (cursorVector != 0)
    {
        gUnknown_020388F2 = MoveMenuCursor(cursorVector);
    }
    if (bgVector != 0)
    {
        v1 = gUnknown_020388F4;
        gUnknown_020388F4 = v1 + bgVector;
        sub_80FEABC(taskId, 1);
    }
    if (gUnknown_020388F2 + gUnknown_020388F4 != gUnknown_020388D5)
    {
        if (v0)
        {
            MenuDrawTextWindow(15, 12, 29, 19);
        }
        sub_80FECE0(gUnknown_020388F2 + gUnknown_020388F4);
    } else
    {
        MenuZeroFillWindowRect(15, 12, 29, 19);
    }
}

void sub_80FE948(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
        {
            if (gUnknown_020388F2 != 0)
            {
                sub_80FE894(taskId, -1, 0);
            } else if (gUnknown_020388F4 != 0)
            {
                sub_80FE894(taskId, 0, -1);
            }
        }
        if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
        {
            if (gUnknown_020388F2 != gUnknown_020388F3)
            {
                sub_80FE894(taskId, 1, 0);
            } else if (gUnknown_020388F4 + gUnknown_020388F2 != gUnknown_020388D5)
            {
                sub_80FE894(taskId, 0, 1);
            }
        }
        if (gMain.newKeys & A_BUTTON)
        {
            sub_8072DEC();
            PlaySE(SE_SELECT);
            gUnknown_020388F5 = gUnknown_020388F2 + gUnknown_020388F4;
            if (gUnknown_020388F5 == gUnknown_020388D5)
            {
                gUnknown_083EC634[gTasks[taskId].data[11]].func2(taskId);
            } else
            {
                gUnknown_083EC634[gTasks[taskId].data[11]].func1(taskId);
            }
        } else if (gMain.newKeys & B_BUTTON)
        {
            sub_8072DEC();
            PlaySE(SE_SELECT);
            gUnknown_083EC634[gTasks[taskId].data[11]].func2(taskId);
        }
    }
}

void sub_80FEABC(u8 taskId, u8 dummy1)
{
    u16 i;
    u16 j;
    u8 ni;
    if (gUnknown_020388F4 != 0 || (DestroyVerticalScrollIndicator(0), gUnknown_020388F4 != 0))
    {
        CreateVerticalScrollIndicators(0, 0x3c, 0x08);
    }
    if (gUnknown_020388F4 + 7 == gUnknown_020388D5)
    {
        DestroyVerticalScrollIndicator(1);
    }
    if (gUnknown_020388F4 + 7 < gUnknown_020388D5)
    {
        CreateVerticalScrollIndicators(1, 0x3c, 0x98);
    }
    for (i=gUnknown_020388F4; i<gUnknown_020388F4+8; i++)
    {
        ni = 2 * (i - gUnknown_020388F4) + 2;
        if (gUnknown_020388F7[i - gUnknown_020388F4])
        {
            sub_80F94F8(&gUnknown_020388F7[i - gUnknown_020388F4]);
        }
        if (i == gUnknown_020388D5)
        {
            sub_8072A18(gUnknownText_Exit, 0x08, 8 * ni, 0x68, 1);
            break;
        }
        if (gUnknown_020388D0[i])
        {
            if (ewram_1f000.isPlayerRoom == 1 && gUnknown_020388F6 != DECOCAT_DOLL && gUnknown_020388F6 != DECOCAT_CUSHION && gTasks[taskId].data[11] == 0)
            {
                StringCopy(gStringVar1, gDecorations[gUnknown_020388D0[i]].name);
                sub_8072A18(gUnknown_083EC65A, 0x08, 8 * ni, 0x68, 1);
            } else
            {
                sub_8072A18(gDecorations[gUnknown_020388D0[i]].name, 0x08, 8 * ni, 0x68, 1);
            }
            for (j=0; j<16; j++)
            {
                if (gUnknown_020388D6[j] - 1 == i)
                {
                    sub_80F94A4(4, &gUnknown_020388F7[i - gUnknown_020388F4], 0x6c, (i - gUnknown_020388F4) * 16 + 24);
                    break;
                }
            }
            for (j=0; j<12; j++)
            {
                if (gUnknown_020388E6[j] - 1 == i)
                {
                    sub_80F94A4(5, &gUnknown_020388F7[i - gUnknown_020388F4], 0x6c, (i - gUnknown_020388F4) * 16 + 24);
                    break;
                }
            }
        }
    }
}

void sub_80FEC94(u8 taskId)
{
    MenuDrawTextWindow(0, 0, 14, 19);
    sub_80FEABC(taskId, 0);
}

void sub_80FECB8(u8 decoCat)
{
    MenuDrawTextWindow(15, 0, 29, 3);
    sub_80FE470(decoCat, 16, 1, 0xff);
}

void sub_80FECE0(u8 decoCat)
{
    sub_8072AB0(gDecorations[gUnknown_020388D0[decoCat]].description, 0x80, 0x68, 0x68, 0x30, 0x1);
}

void sub_80FED1C(void)
{
    MenuZeroFillWindowRect(15, 0, 29, 3);
    MenuZeroFillWindowRect(15, 12, 29, 19);
}

void sub_80FED3C(u8 taskId)
{
    LoadScrollIndicatorPalette();
    gTasks[taskId].func = sub_80FE868;
}

bool8 sub_80FED64(u8 a0)
{
    u8 i;
    for (i=0; i<16; i++)
    {
        if (gUnknown_020388D6[i] == a0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_80FED90(u8 taskId)
{
    u16 i;
    u16 j;
    u16 k;
    u16 cnt;
    cnt = 0;
    for (i=0; i<16; i++)
    {
        gUnknown_020388D6[i] = 0;
        if (i < 12)
        {
            gUnknown_020388E6[i] = 0;
        }
    }
    for (i=0; i<16; i++)
    {
        if (gSaveBlock1.secretBases[0].decorations[i] != 0)
        {
            for (j=0; j<gDecorationInventories[gUnknown_020388F6].size; j++)
            {
                if (gUnknown_020388D0[j] == gSaveBlock1.secretBases[0].decorations[i])
                {
                    for (k=0; k<cnt && gUnknown_020388D6[k]!=j+1; k++);
                    if (k == cnt)
                    {
                        gUnknown_020388D6[cnt] = j+1;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cnt = 0;
    for (i=0; i<12; i++)
    {
        if (gSaveBlock1.playerRoomDecor[i] != 0)
        {
            for (j=0; j<gDecorationInventories[gUnknown_020388F6].size; j++)
            {
                if (gUnknown_020388D0[j] == gSaveBlock1.playerRoomDecor[i] && !sub_80FED64(j + 1))
                {
                    for (k=0; k<cnt && gUnknown_020388E6[k]!=j+1; k++);
                    if (k == cnt)
                    {
                        gUnknown_020388E6[cnt] = j+1;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
}

void sub_80FEF28(void)
{
    if (gUnknown_020388D5 <= 7)
    {
        gUnknown_020388F3 = gUnknown_020388D5;
    } else
    {
        gUnknown_020388F3 = 7;
    }
}

void sub_80FEF50(u8 taskId)
{
    sub_80FED90(taskId);
    sub_80FEF28();
    gUnknown_020388F2 = 0;
    gUnknown_020388F4 = 0;
}

void sub_80FEF74(void)
{
    sub_80F9520(gUnknown_020388F7, 8);
    DestroyVerticalScrollIndicator(0);
    DestroyVerticalScrollIndicator(1);
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 14, 19);
}

bool8 sub_80FEFA4(void)
{
    u16 i;
    int v0;
    for (i=0; i<16; i++)
    {
        v0 = gUnknown_020388F4 + gUnknown_020388F2 + 1;
        if (gUnknown_020388D6[i] == v0 || (i < 12 && gUnknown_020388E6[i] == v0))
        {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_80FEFF4(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        LoadScrollIndicatorPalette();
        gTasks[taskId].func = sub_80FE868;
    }
}

void sub_80FF034(u8 taskId)
{
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 14, 19);
    sub_80FE5AC(taskId);
}

void sub_80FF058(u8 taskId)
{
    sub_80F9520(gUnknown_020388F7, 8);
    DestroyVerticalScrollIndicator(0);
    DestroyVerticalScrollIndicator(1);
    BuyMenuFreeMemory();
    gTasks[taskId].func = sub_80FF034;
}

void sub_80FF098(u8 taskId)
{
    gUnknown_020388D5--;
    if (gUnknown_020388F4 + 7 > gUnknown_020388D5 && gUnknown_020388F4 != 0)
    {
        gUnknown_020388F4--;
    }
    sub_8134104(gUnknown_020388F6);
    sub_80FED90(taskId);
    sub_80FEF28();
}

void sub_80FF0E0(u8 taskId)
{
    gTasks[taskId].data[3] = gSaveBlock1.pos.x;
    gTasks[taskId].data[4] = gSaveBlock1.pos.y;
    PlayerGetDestCoords(&gTasks[taskId].data[0], &gTasks[taskId].data[1]);
}

void sub_80FF114(u8 taskId)
{
    DrawWholeMapView();
    warp1_set(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum, -1, gTasks[taskId].data[3], gTasks[taskId].data[4]);
    warp_in();
}
void sub_80FF160(u8 taskId)
{
    if (!sub_81341D4())
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE428, 0);
    } else
    {
        gTasks[taskId].data[11] = 0;
        gUnknown_020388F6 = 0;
        sub_80FE5AC(taskId);
    }
}

u16 sub_80FF1B0(u8 decoId, u8 a1)
{
    u16 retval;
    retval = 0xffff;

    switch (decoId)
    {
        case DECOR_STAND:
            retval = gUnknown_083EC97C[a1] << 12;
            return retval;
        case DECOR_SLIDE:
            retval = gUnknown_083EC984[a1] << 12;
            return retval;
        default:
            return retval;
    }
}

void sub_80FF1EC(u16 mapX, u16 mapY, u8 decWidth, u8 decHeight, u16 decIdx)
{
    u16 i;
    u16 j; // r10
    u16 behavior;
    u16 flags; // r8
    u16 v0;
    u16 v1;
    s16 x;
    s16 decBottom;

    for (i=0; i<decHeight; i++)
    {
        decBottom = mapY - decHeight + 1 + i;
        for (j=0; j<decWidth; j++)
        {
            x = mapX + j;
            behavior = GetBehaviorByMetatileId(0x200 + gDecorations[decIdx].tiles[i * decWidth + j]);
            if (sub_8057288(behavior) == 1 || (gDecorations[decIdx].decor_field_11 != 1 && (behavior >> 12)))
            {
                flags = 0xc00;
            } else
            {
                flags = 0x000;
            }
            if (gDecorations[decIdx].decor_field_11 != 3 && sub_80572B0(MapGridGetMetatileBehaviorAt(x, decBottom)) == 1)
            {
                v0 = 1;
            } else
            {
                v0 = 0;
            }
            v1 = sub_80FF1B0(gDecorations[decIdx].id, i * decWidth + j);
            if (v1 != 0xffff)
            {
                MapGridSetMetatileEntryAt(x, decBottom, (gDecorations[decIdx].tiles[i * decWidth + j] + (0x200 | v0)) | flags | v1);
            } else
            {
                MapGridSetMetatileIdAt(x, decBottom, (gDecorations[decIdx].tiles[i * decWidth + j] + (0x200 | v0)) | flags);
            }
        }
    }
}

void sub_80FF394(u16 mapX, u16 mapY, u16 decIdx)
{
    switch (gDecorations[decIdx].shape)
    {
        case 0:
            sub_80FF1EC(mapX, mapY, 1, 1, decIdx);
            break;
        case 1:
            sub_80FF1EC(mapX, mapY, 2, 1, decIdx);
            break;
        case 2:
            sub_80FF1EC(mapX, mapY, 3, 1, decIdx);
            break;
        case 3:
            sub_80FF1EC(mapX, mapY, 4, 2, decIdx);
            break;
        case 4:
            sub_80FF1EC(mapX, mapY, 2, 2, decIdx);
            break;
        case 5:
            sub_80FF1EC(mapX, mapY, 1, 2, decIdx);
            break;
        case 6:
            sub_80FF1EC(mapX, mapY, 1, 3, decIdx);
            break;
        case 7:
            sub_80FF1EC(mapX, mapY, 2, 4, decIdx);
            break;
        case 8:
            sub_80FF1EC(mapX, mapY, 3, 3, decIdx);
            break;
        case 9:
            sub_80FF1EC(mapX, mapY, 3, 2, decIdx);
            break;
    }
}

void sub_80FF474(void)
{
    u8 i;
    u8 j;
    for (i=0; i<14; i++)
    {
        if (FlagGet(i + 0xae) == 1)
        {
            FlagReset(i + 0xae);
            for (j=0; j<gMapHeader.events->mapObjectCount; j++)
            {
                if (gMapHeader.events->mapObjects[j].flagId == i + 0xae)
                {
                    break;
                }
            }
            VarSet(0x3f20 + gMapHeader.events->mapObjects[j].graphicsId, gUnknown_02038900.decoration->tiles[0]);
            gSpecialVar_0x8005 = gMapHeader.events->mapObjects[j].localId;
            gSpecialVar_0x8006 = gUnknown_020391A4;
            gSpecialVar_0x8007 = gUnknown_020391A6;
            show_sprite(gSpecialVar_0x8005, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
            sub_805C0F8(gSpecialVar_0x8005, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
            sub_805C78C(gSpecialVar_0x8005, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
            break;
        }
    }
}

bool8 sub_80FF58C/*IsThereRoomForMoreDecorations*/(void)
{
    u16 i;
    for (i=0; i<ewram_1f000.size; i++)
    {
        if (ewram_1f000.items[i] == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_80FF5BC(u8 taskId)
{
    if (ewram_1f000.isPlayerRoom == 1 && gUnknown_020388F6 != DECOCAT_DOLL && gUnknown_020388F6 != DECOCAT_CUSHION)
    {
        sub_80FEF74();
        sub_80FED1C();
        DisplayItemMessageOnField(taskId, gSecretBaseText_DecorCantPlace, sub_80FEFF4, 0);
    } else if (sub_80FEFA4() == TRUE)
    {
        if (sub_80FF58C() == TRUE)
        {
            fade_screen(1, 0);
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].func = sub_80FF6AC;
        } else
        {
            sub_80FEF74();
            sub_80FED1C();
            ConvertIntToDecimalStringN(gStringVar1, ewram_1f000.size, STR_CONV_MODE_RIGHT_ALIGN, 2);
            if (!ewram_1f000.isPlayerRoom)
            {
                StringExpandPlaceholders(gStringVar4, gSecretBaseText_NoMoreDecor);
            } else
            {
                StringExpandPlaceholders(gStringVar4, gSecretBaseText_NoMoreDecor2);
            }
            DisplayItemMessageOnField(taskId, gStringVar4, sub_80FEFF4, 0);
        }
    } else
    {
        sub_80FEF74();
        sub_80FED1C();
        DisplayItemMessageOnField(taskId, gSecretBaseText_InUseAlready, sub_80FEFF4, 0);
    }
}

void sub_80FF6AC(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_80FF0E0(taskId);
                DestroyVerticalScrollIndicator(0);
                DestroyVerticalScrollIndicator(1);
                sub_80F9520(gUnknown_020388F7, 8);
                BuyMenuFreeMemory();
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            gPaletteFade.bufferTransferDisabled = 1;
            AddDecorationIconObjectFromFieldObject(&gUnknown_02038900, gUnknown_020388D0[gUnknown_020388F5]);
            sub_80FF960(taskId);
            SetUpPlacingDecorationPlayerAvatar(taskId, &gUnknown_02038900);
            pal_fill_black();
            gPaletteFade.bufferTransferDisabled = 0;
            gTasks[taskId].data[2] = 2;
            break;
        case 2:
            if (sub_807D770() == 1)
            {
                gTasks[taskId].data[12] = 0;
                sub_810065C(taskId);
            }
            break;
    }
}

void AddDecorationIconObjectFromFieldObject(struct UnkStruct_02038900 * unk_02038900, u8 decoIdx)
{
    sub_80FEF74();
    sub_80FED1C();
    sub_81006D0(unk_02038900);
    unk_02038900->decoration = &gDecorations[decoIdx];
    if (gDecorations[decoIdx].decor_field_11 != 4)
    {
        sub_81008BC(unk_02038900);
        sub_8100930(unk_02038900->decoration->shape);
        sub_8100874(unk_02038900);
        sub_810070C(unk_02038900->unk_884, ((u16 *)gMapHeader.mapData->secondaryTileset->metatiles + 8 * unk_02038900->decoration->tiles[0])[7] >> 12);
        LoadSpritePalette(&gUnknown_083EC954);
        gUnknown_020391A8 = gSprites[gUnknown_03004880.unk4].data0;
        gUnknown_03004880.unk4 = CreateSprite(&gSpriteTemplate_83EC93C, gUnknown_083EC900[unk_02038900->decoration->shape].unk_2,  gUnknown_083EC900[unk_02038900->decoration->shape].unk_3, 0);
    } else
    {
        gUnknown_020391A8 = gSprites[gUnknown_03004880.unk4].data0;
        gUnknown_03004880.unk4 = AddPseudoFieldObject(unk_02038900->decoration->tiles[0], sub_81009A8, gUnknown_083EC900[unk_02038900->decoration->shape].unk_2,  gUnknown_083EC900[unk_02038900->decoration->shape].unk_3, 1);
        gSprites[gUnknown_03004880.unk4].oam.priority = 1;
    }
}

void SetUpPlacingDecorationPlayerAvatar(u8 taskId, struct UnkStruct_02038900 *unk_02038900)
{
    u8 v0;
    v0 = 16 * (u8)gTasks[taskId].data[5] + gUnknown_083EC900[unk_02038900->decoration->shape].unk_2 - 8 * ((u8)gTasks[taskId].data[5] - 1);
    if (unk_02038900->decoration->shape == 2 || unk_02038900->decoration->shape == 8 || unk_02038900->decoration->shape == 9)
    {
        v0 -= 8;
    }
    if (gSaveBlock2.playerGender == MALE)
    {
        gUnknown_020391A9 = AddPseudoFieldObject(0xc1, SpriteCallbackDummy, v0, 0x48, 0);
    } else
    {
        gUnknown_020391A9 = AddPseudoFieldObject(0xc2, SpriteCallbackDummy, v0, 0x48, 0);
    }
    gSprites[gUnknown_020391A9].oam.priority = 1;
    DestroySprite(&gSprites[gUnknown_020391A8]);
    gUnknown_020391A8 = gUnknown_03004880.unk4;
}

void sub_80FF960(u8 taskId)
{
    switch (gDecorations[gUnknown_020388D0[gUnknown_020388F5]].shape)
    {
        case 0:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 1;
            break;
        case 1:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 1;
            break;
        case 2:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 1;
            break;
        case 3:
            gTasks[taskId].data[5] = 4;
            gTasks[taskId].data[6] = 2;
            break;
        case 4:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 2;
            break;
        case 5:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 2;
            break;
        case 6:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 3;
            gTasks[taskId].data[1]++;
            break;
        case 7:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 4;
            break;
        case 8:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 3;
            break;
        case 9:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 2;
            break;
    }
}

void sub_80FFAB0(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[gUnknown_020391A8].data7 = 1;
    gSprites[gUnknown_020391A9].data7 = 1;
    sub_810045C();
    sub_8100038(taskId);
}

void sub_80FFB08(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[gUnknown_020391A8].data7 = 1;
    gSprites[gUnknown_020391A9].data7 = 1;
    sub_810045C();
    DisplayItemMessageOnField(taskId, gSecretBaseText_CancelDecorating, sub_8100248, 0);
}

bool8 sub_80FFB6C(u8 a0, u16 a1)
{
    if (sub_8057274(a0) != 1 || a1 != 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_80FFB94(u8 taskId, s16 x, s16 y, u16 decoId)
{
    if (x == gTasks[taskId].data[3] + 7 && y == gTasks[taskId].data[4] + 7 && decoId != 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_80FFBDC(u16 a0, struct Decoration *decoration)
{
    if (sub_8057274(a0) != 1)
    {
        if (decoration->id == DECOR_SOLID_BOARD && sub_8057300(a0) == 1)
        {
            return TRUE;
        }
        if (sub_805729C(a0))
        {
            return TRUE;
        }
    }
    return FALSE;
}

#ifdef NONMATCHING
bool8 sub_80FFC24(u8 taskId, const struct Decoration *decoration)
{
    u8 i;
    u8 j;
    u8 behaviorAt;
    u16 behaviorBy;
    u8 fieldObjectId;
    u8 mapY;
    u8 mapX;
    s16 curY;
    s16 curX;
    mapY = gTasks[taskId].data[6];
    mapX = gTasks[taskId].data[5];
    switch (decoration->decor_field_11)
    {
        case 0:
        case 1:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    behaviorBy = 0xf000 & GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]);
                    if (!sub_80FFBDC(behaviorAt, decoration))
                    {
                        return FALSE;
                    }
                    if (!sub_80FFB94(taskId, curX, curY, behaviorBy))
                    {
                        return FALSE;
                    }
                    fieldObjectId = GetFieldObjectIdByXYZ(curX, curY, 0);
                    if (fieldObjectId != 0 && fieldObjectId != 16)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case 2:
            for (i=0; i<mapY-1; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    behaviorBy = 0xf000 & GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - i) * mapX + j]);
                    if (!sub_805729C(behaviorAt) && !sub_80FFB6C(behaviorAt, behaviorBy))
                    {
                        return FALSE;
                    }
                    if (!sub_80FFB94(taskId, curX, curY, behaviorBy))
                    {
                        return FALSE;
                    }
                    fieldObjectId = GetFieldObjectIdByXYZ(curX, curY, 0);
                    if (fieldObjectId != 16)
                    {
                        return FALSE;
                    }
                }
            }
            curY = gTasks[taskId].data[1] - mapY + 1;
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                behaviorBy = 0xf000 & GetBehaviorByMetatileId(0x200 + decoration->tiles[j]);
                if (!sub_805729C(behaviorAt) && !sub_80572B0(behaviorAt))
                {
                    return FALSE;
                }
                if (!sub_80FFB94(taskId, curX, curY, behaviorBy))
                {
                    return FALSE;
                }
                fieldObjectId = GetFieldObjectIdByXYZ(curX, curY, 0);
                if (fieldObjectId != 0 && fieldObjectId != 16)
                {
                    return FALSE;
                }
            }
            break;
        case 3:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    if (!sub_80572B0(MapGridGetMetatileBehaviorAt(curX, curY)) || MapGridGetMetatileIdAt(curX, curY) == 0x28c)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case 4:
            curY = gTasks[taskId].data[1];
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                if (decoration->shape == 5)
                {
                    if (!sub_80572EC(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                else if (!sub_80572D8(behaviorAt))
                {
                    if (!sub_80572EC(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                fieldObjectId = GetFieldObjectIdByXYZ(curX, curY, 0);
                if (fieldObjectId != 16)
                {
                    return FALSE;
                }
            }
            break;
    }
    return TRUE;
}
#else
__attribute__((naked))
bool8 sub_80FFC24(u8 taskId, const struct Decoration *decoration)
{
    asm(".syntax unified\n"
    "\tpush {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x24\n"
    "\tstr r1, [sp]\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tmov r10, r0\n"
    "\tldr r1, _080FFC60 @ =gTasks\n"
    "\tlsls r0, 2\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tadds r0, r1\n"
    "\tldrb r2, [r0, 0x14]\n"
    "\tstr r2, [sp, 0x4]\n"
    "\tldrb r0, [r0, 0x12]\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tldr r3, [sp]\n"
    "\tldrb r0, [r3, 0x11]\n"
    "\tadds r2, r1, 0\n"
    "\tcmp r0, 0x4\n"
    "\tbls _080FFC56\n"
    "\tb _08100024\n"
    "_080FFC56:\n"
    "\tlsls r0, 2\n"
    "\tldr r1, _080FFC64 @ =_080FFC68\n"
    "\tadds r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    "_080FFC60: .4byte gTasks\n"
    "_080FFC64: .4byte _080FFC68\n"
    "\t.align 2, 0\n"
    "_080FFC68:\n"
    "\t.4byte _080FFC7C\n"
    "\t.4byte _080FFC7C\n"
    "\t.4byte _080FFD68\n"
    "\t.4byte _080FFF1C\n"
    "\t.4byte _080FFFA0\n"
    "_080FFC7C:\n"
    "\tmovs r6, 0\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tcmp r6, r0\n"
    "\tbcc _080FFC86\n"
    "\tb _08100024\n"
    "_080FFC86:\n"
    "\tmov r1, r10\n"
    "\tlsls r1, 2\n"
    "\tstr r1, [sp, 0x1C]\n"
    "_080FFC8C:\n"
    "\tmov r2, r10\n"
    "\tlsls r0, r2, 2\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tldr r3, _080FFD64 @ =gTasks\n"
    "\tadds r0, r3\n"
    "\tldrh r0, [r0, 0xA]\n"
    "\tsubs r0, r6\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tmov r9, r0\n"
    "\tmovs r7, 0\n"
    "\tadds r6, 0x1\n"
    "\tstr r6, [sp, 0x14]\n"
    "\tldr r0, [sp, 0x8]\n"
    "\tcmp r7, r0\n"
    "\tbcs _080FFD56\n"
    "\tmov r1, r9\n"
    "\tlsls r1, 16\n"
    "\tstr r1, [sp, 0xC]\n"
    "\tasrs r1, 16\n"
    "\tmov r9, r1\n"
    "_080FFCB8:\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tldr r2, _080FFD64 @ =gTasks\n"
    "\tadds r0, r2\n"
    "\tldrh r0, [r0, 0x8]\n"
    "\tadds r0, r7\n"
    "\tlsls r0, 16\n"
    "\tmov r8, r0\n"
    "\tasrs r6, r0, 16\n"
    "\tadds r0, r6, 0\n"
    "\tmov r1, r9\n"
    "\tbl MapGridGetMetatileBehaviorAt\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tldr r3, [sp, 0x4]\n"
    "\tldr r1, [sp, 0x14]\n"
    "\tsubs r0, r3, r1\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tadds r1, r0, 0\n"
    "\tmuls r1, r2\n"
    "\tadds r1, r7\n"
    "\tldr r3, [sp]\n"
    "\tldr r0, [r3, 0x1C]\n"
    "\tlsls r1, 1\n"
    "\tadds r1, r0\n"
    "\tmovs r2, 0x80\n"
    "\tlsls r2, 2\n"
    "\tadds r0, r2, 0\n"
    "\tldrh r1, [r1]\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tbl GetBehaviorByMetatileId\n"
    "\tmovs r3, 0xF0\n"
    "\tlsls r3, 8\n"
    "\tadds r1, r3, 0\n"
    "\tadds r5, r1, 0\n"
    "\tands r5, r0\n"
    "\tadds r0, r4, 0\n"
    "\tldr r1, [sp]\n"
    "\tbl sub_80FFBDC\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFD1A\n"
    "\tb _080FFFF4\n"
    "_080FFD1A:\n"
    "\tmov r0, r10\n"
    "\tadds r1, r6, 0\n"
    "\tmov r2, r9\n"
    "\tadds r3, r5, 0\n"
    "\tbl sub_80FFB94\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFD2E\n"
    "\tb _080FFFF4\n"
    "_080FFD2E:\n"
    "\tmov r1, r8\n"
    "\tlsrs r0, r1, 16\n"
    "\tldr r2, [sp, 0xC]\n"
    "\tlsrs r1, r2, 16\n"
    "\tmovs r2, 0\n"
    "\tbl GetFieldObjectIdByXYZ\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tcmp r4, 0\n"
    "\tbeq _080FFD4A\n"
    "\tcmp r4, 0x10\n"
    "\tbeq _080FFD4A\n"
    "\tb _080FFFF4\n"
    "_080FFD4A:\n"
    "\tadds r0, r7, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r7, r0, 24\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcc _080FFCB8\n"
    "_080FFD56:\n"
    "\tldr r1, [sp, 0x14]\n"
    "\tlsls r0, r1, 24\n"
    "\tlsrs r6, r0, 24\n"
    "\tldr r2, [sp, 0x4]\n"
    "\tcmp r6, r2\n"
    "\tbcc _080FFC8C\n"
    "\tb _08100024\n"
    "\t.align 2, 0\n"
    "_080FFD64: .4byte gTasks\n"
    "_080FFD68:\n"
    "\tmovs r6, 0\n"
    "\tmov r3, r10\n"
    "\tlsls r3, 2\n"
    "\tstr r3, [sp, 0x1C]\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tsubs r0, 0x1\n"
    "\tstr r0, [sp, 0x18]\n"
    "\tcmp r6, r0\n"
    "\tbge _080FFE54\n"
    "\tadds r0, r3, 0\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tstr r0, [sp, 0x10]\n"
    "_080FFD82:\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tadds r0, r1, r2\n"
    "\tldrh r0, [r0, 0xA]\n"
    "\tsubs r0, r6\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tmov r9, r0\n"
    "\tmovs r7, 0\n"
    "\tadds r6, 0x1\n"
    "\tstr r6, [sp, 0x14]\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcs _080FFE48\n"
    "\tlsls r0, 16\n"
    "\tstr r0, [sp, 0x20]\n"
    "_080FFDA0:\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tadds r0, r1, r2\n"
    "\tldrh r0, [r0, 0x8]\n"
    "\tadds r0, r7\n"
    "\tlsls r0, 16\n"
    "\tmov r8, r0\n"
    "\tasrs r6, r0, 16\n"
    "\tmov r2, r9\n"
    "\tlsls r1, r2, 16\n"
    "\tadds r0, r6, 0\n"
    "\tasrs r1, 16\n"
    "\tbl MapGridGetMetatileBehaviorAt\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tldr r3, [sp, 0x4]\n"
    "\tldr r1, [sp, 0x14]\n"
    "\tsubs r0, r3, r1\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tadds r1, r0, 0\n"
    "\tmuls r1, r2\n"
    "\tadds r1, r7\n"
    "\tldr r3, [sp]\n"
    "\tldr r0, [r3, 0x1C]\n"
    "\tlsls r1, 1\n"
    "\tadds r1, r0\n"
    "\tmovs r2, 0x80\n"
    "\tlsls r2, 2\n"
    "\tadds r0, r2, 0\n"
    "\tldrh r1, [r1]\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tbl GetBehaviorByMetatileId\n"
    "\tmovs r3, 0xF0\n"
    "\tlsls r3, 8\n"
    "\tadds r1, r3, 0\n"
    "\tadds r5, r1, 0\n"
    "\tands r5, r0\n"
    "\tadds r0, r4, 0\n"
    "\tbl sub_805729C\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFE0C\n"
    "\tadds r0, r4, 0\n"
    "\tadds r1, r5, 0\n"
    "\tbl sub_80FFB6C\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFE0C\n"
    "\tb _080FFFF4\n"
    "_080FFE0C:\n"
    "\tmov r0, r10\n"
    "\tadds r1, r6, 0\n"
    "\tldr r3, [sp, 0x20]\n"
    "\tasrs r2, r3, 16\n"
    "\tadds r3, r5, 0\n"
    "\tbl sub_80FFB94\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFE22\n"
    "\tb _080FFFF4\n"
    "_080FFE22:\n"
    "\tmov r1, r8\n"
    "\tlsrs r0, r1, 16\n"
    "\tldr r2, [sp, 0x20]\n"
    "\tlsrs r1, r2, 16\n"
    "\tmovs r2, 0\n"
    "\tbl GetFieldObjectIdByXYZ\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tcmp r0, 0x10\n"
    "\tbeq _080FFE3A\n"
    "\tb _080FFFF4\n"
    "_080FFE3A:\n"
    "\tadds r0, r7, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r7, r0, 24\n"
    "\tldr r2, _080FFF18 @ =gTasks\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcc _080FFDA0\n"
    "_080FFE48:\n"
    "\tldr r1, [sp, 0x14]\n"
    "\tlsls r0, r1, 24\n"
    "\tlsrs r6, r0, 24\n"
    "\tldr r3, [sp, 0x18]\n"
    "\tcmp r6, r3\n"
    "\tblt _080FFD82\n"
    "_080FFE54:\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tadds r0, r2\n"
    "\tldrh r0, [r0, 0xA]\n"
    "\tldr r1, [sp, 0x4]\n"
    "\tsubs r0, r1\n"
    "\tadds r0, 0x1\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tmov r9, r0\n"
    "\tmovs r7, 0\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcc _080FFE74\n"
    "\tb _08100024\n"
    "_080FFE74:\n"
    "\tlsls r0, 16\n"
    "\tstr r0, [sp, 0x20]\n"
    "_080FFE78:\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tldr r1, _080FFF18 @ =gTasks\n"
    "\tadds r0, r1\n"
    "\tldrh r0, [r0, 0x8]\n"
    "\tadds r0, r7\n"
    "\tlsls r0, 16\n"
    "\tmov r8, r0\n"
    "\tasrs r6, r0, 16\n"
    "\tmov r2, r9\n"
    "\tlsls r1, r2, 16\n"
    "\tadds r0, r6, 0\n"
    "\tasrs r1, 16\n"
    "\tbl MapGridGetMetatileBehaviorAt\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tldr r3, [sp]\n"
    "\tldr r0, [r3, 0x1C]\n"
    "\tlsls r1, r7, 1\n"
    "\tadds r1, r0\n"
    "\tmovs r2, 0x80\n"
    "\tlsls r2, 2\n"
    "\tadds r0, r2, 0\n"
    "\tldrh r1, [r1]\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tbl GetBehaviorByMetatileId\n"
    "\tmovs r3, 0xF0\n"
    "\tlsls r3, 8\n"
    "\tadds r1, r3, 0\n"
    "\tadds r5, r1, 0\n"
    "\tands r5, r0\n"
    "\tadds r0, r4, 0\n"
    "\tbl sub_805729C\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFEDA\n"
    "\tadds r0, r4, 0\n"
    "\tbl sub_80572B0\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFEDA\n"
    "\tb _080FFFF4\n"
    "_080FFEDA:\n"
    "\tmov r0, r10\n"
    "\tadds r1, r6, 0\n"
    "\tldr r3, [sp, 0x20]\n"
    "\tasrs r2, r3, 16\n"
    "\tadds r3, r5, 0\n"
    "\tbl sub_80FFB94\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _080FFEF0\n"
    "\tb _080FFFF4\n"
    "_080FFEF0:\n"
    "\tmov r1, r8\n"
    "\tlsrs r0, r1, 16\n"
    "\tldr r2, [sp, 0x20]\n"
    "\tlsrs r1, r2, 16\n"
    "\tmovs r2, 0\n"
    "\tbl GetFieldObjectIdByXYZ\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tcmp r4, 0\n"
    "\tbeq _080FFF0A\n"
    "\tcmp r4, 0x10\n"
    "\tbne _080FFFF4\n"
    "_080FFF0A:\n"
    "\tadds r0, r7, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r7, r0, 24\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcc _080FFE78\n"
    "\tb _08100024\n"
    "\t.align 2, 0\n"
    "_080FFF18: .4byte gTasks\n"
    "_080FFF1C:\n"
    "\tmovs r6, 0\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tcmp r6, r0\n"
    "\tbcc _080FFF26\n"
    "\tb _08100024\n"
    "_080FFF26:\n"
    "\tmov r1, r10\n"
    "\tlsls r0, r1, 2\n"
    "\tadd r0, r10\n"
    "\tlsls r1, r0, 3\n"
    "\tldr r2, _080FFF9C @ =gTasks\n"
    "\tadds r0, r1, r2\n"
    "\tldrh r0, [r0, 0xA]\n"
    "\tsubs r0, r6\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tmov r9, r0\n"
    "\tmovs r7, 0\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcs _080FFF8C\n"
    "\tadds r0, r2, 0\n"
    "\tadds r1, r0\n"
    "\tmov r8, r1\n"
    "\tmov r1, r9\n"
    "\tlsls r0, r1, 16\n"
    "\tasrs r5, r0, 16\n"
    "_080FFF50:\n"
    "\tmov r2, r8\n"
    "\tldrh r0, [r2, 0x8]\n"
    "\tadds r0, r7\n"
    "\tlsls r0, 16\n"
    "\tasrs r4, r0, 16\n"
    "\tadds r0, r4, 0\n"
    "\tadds r1, r5, 0\n"
    "\tbl MapGridGetMetatileBehaviorAt\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tbl sub_80572B0\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbeq _080FFFF4\n"
    "\tadds r0, r4, 0\n"
    "\tadds r1, r5, 0x1\n"
    "\tbl MapGridGetMetatileIdAt\n"
    "\tmovs r1, 0xA3\n"
    "\tlsls r1, 2\n"
    "\tcmp r0, r1\n"
    "\tbeq _080FFFF4\n"
    "\tadds r0, r7, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r7, r0, 24\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcc _080FFF50\n"
    "_080FFF8C:\n"
    "\tadds r0, r6, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r6, r0, 24\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tcmp r6, r0\n"
    "\tbcc _080FFF26\n"
    "\tb _08100024\n"
    "\t.align 2, 0\n"
    "_080FFF9C: .4byte gTasks\n"
    "_080FFFA0:\n"
    "\tmov r3, r10\n"
    "\tlsls r1, r3, 2\n"
    "\tadds r0, r1, r3\n"
    "\tlsls r0, 3\n"
    "\tadds r0, r2\n"
    "\tldrh r0, [r0, 0xA]\n"
    "\tmov r9, r0\n"
    "\tmovs r7, 0\n"
    "\tstr r1, [sp, 0x1C]\n"
    "\tldr r0, [sp, 0x8]\n"
    "\tcmp r7, r0\n"
    "\tbcs _08100024\n"
    "\tadds r6, r2, 0\n"
    "\tmov r1, r9\n"
    "\tlsls r1, 16\n"
    "\tstr r1, [sp, 0x20]\n"
    "_080FFFC0:\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\tadd r0, r10\n"
    "\tlsls r0, 3\n"
    "\tadds r0, r6\n"
    "\tldrh r0, [r0, 0x8]\n"
    "\tadds r0, r7\n"
    "\tlsls r0, 16\n"
    "\tlsrs r5, r0, 16\n"
    "\tasrs r0, 16\n"
    "\tmov r2, r9\n"
    "\tlsls r1, r2, 16\n"
    "\tasrs r1, 16\n"
    "\tbl MapGridGetMetatileBehaviorAt\n"
    "\tlsls r0, 24\n"
    "\tlsrs r4, r0, 24\n"
    "\tldr r3, [sp]\n"
    "\tldrb r0, [r3, 0x12]\n"
    "\tcmp r0, 0x5\n"
    "\tbne _080FFFF8\n"
    "_080FFFE8:\n"
    "\tadds r0, r4, 0\n"
    "\tbl sub_80572EC\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbne _08100004\n"
    "_080FFFF4:\n"
    "\tmovs r0, 0\n"
    "\tb _08100026\n"
    "_080FFFF8:\n"
    "\tadds r0, r4, 0\n"
    "\tbl sub_80572D8\n"
    "\tlsls r0, 24\n"
    "\tcmp r0, 0\n"
    "\tbeq _080FFFE8\n"
    "_08100004:\n"
    "\tadds r0, r5, 0\n"
    "\tldr r2, [sp, 0x20]\n"
    "\tlsrs r1, r2, 16\n"
    "\tmovs r2, 0\n"
    "\tbl GetFieldObjectIdByXYZ\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tcmp r0, 0x10\n"
    "\tbne _080FFFF4\n"
    "\tadds r0, r7, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r7, r0, 24\n"
    "\tldr r3, [sp, 0x8]\n"
    "\tcmp r7, r3\n"
    "\tbcc _080FFFC0\n"
    "_08100024:\n"
    "\tmovs r0, 0x1\n"
    "_08100026:\n"
    "\tadd sp, 0x24\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    ".syntax divided\n");
}
#endif

void sub_8100038(u8 taskId)
{
    if (sub_80FFC24(taskId, &gDecorations[gUnknown_020388D0[gUnknown_020388F5]]) == 1)
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_PlaceItHere, sub_81000A0, 0);
    } else
    {
        PlaySE(SE_HAZURE);
        DisplayItemMessageOnField(taskId, gSecretBaseText_CantBePlacedHere, sub_81006A8, 0);
    }
}

void sub_81000A0(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    sub_80F914C(taskId, &gUnknown_083EC95C);
}

void sub_81000C4(u8 taskId)
{
    MenuZeroFillWindowRect(0, 0, 29, 19);
    sub_8100174(taskId);
    if (gDecorations[gUnknown_020388D0[gUnknown_020388F5]].decor_field_11 != 4)
    {
        sub_80FF394(gTasks[taskId].data[0], gTasks[taskId].data[1], gUnknown_020388D0[gUnknown_020388F5]);
    } else
    {
        gUnknown_020391A4 = gTasks[taskId].data[0] - 7;
        gUnknown_020391A6 = gTasks[taskId].data[1] - 7;
        ScriptContext1_SetupScript(gUnknown_081A2F7B);
    }
    gSprites[gUnknown_020391A8].pos1.y += 2;
    sub_810028C(taskId);
}

void sub_8100174(u8 taskId)
{
    u16 i;
    for (i=0; i<ewram_1f000.size; i++)
    {
        if (ewram_1f000.items[i] == 0)
        {
            ewram_1f000.items[i] = gUnknown_020388D0[gUnknown_020388F5];
            ewram_1f000.pos[i] = ((gTasks[taskId].data[0] - 7) << 4) + (gTasks[taskId].data[1] - 7);
            break;
        }
    }
    if (!ewram_1f000.isPlayerRoom)
    {
        for (i=0; i<16; i++)
        {
            if (gUnknown_020388D6[i] == 0)
            {
                gUnknown_020388D6[i] = gUnknown_020388F5 + 1;
                break;
            }
        }
    } else
    {
        for (i=0; i<12; i++)
        {
            if (gUnknown_020388E6[i] == 0)
            {
                gUnknown_020388E6[i] = gUnknown_020388F5 + 1;
                break;
            }
        }
    }
}

void sub_8100248(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    sub_80F914C(taskId, &gUnknown_083EC964);
}

void sub_810026C(u8 taskId)
{
    MenuZeroFillWindowRect(0, 0, 29, 19);
    sub_810028C(taskId);
}

void sub_810028C(u8 taskId)
{
    fade_screen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = c1_overworld_prev_quest;
}

void c1_overworld_prev_quest(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            ScriptContext2_Enable();
            if (!gPaletteFade.active)
            {
                sub_80FF114(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_81016F4();
            FreeSpritePaletteByTag(0xbb8);
            gUnknown_0300485C = &sub_8100364;
            SetMainCallback2(c2_exit_to_overworld_2_switch);
            DestroyTask(taskId);
            break;
    }
}

void sub_8100334(u8 taskId)
{
    if (sub_807D770() == 1)
    {
        gTasks[taskId].func = sub_80FE948;
    }
}

void sub_8100364(void)
{
    ScriptContext2_Enable();
    LoadScrollIndicatorPalette();
    pal_fill_black();
    sub_80FE7EC(CreateTask(sub_8100334, 8));
}

bool8 sub_810038C(u8 taskId)
{
    s16 *data;
    data = gTasks[taskId].data;
    if (gUnknown_020391AA == DIR_SOUTH && data[1] - data[6] - 6 < 0)
    {
        data[1]++;
        return FALSE;
    } else if (gUnknown_020391AA == DIR_NORTH && data[1] - 7 >= gMapHeader.mapData->height)
    {
        data[1]--;
        return FALSE;
    } else if (gUnknown_020391AA == DIR_WEST && data[0] - 7 < 0)
    {
        data[0]++;
        return FALSE;
    } else if (gUnknown_020391AA == DIR_EAST && data[0] + data[5] - 8 >= gMapHeader.mapData->width)
    {
        data[0]--;
        return FALSE;
    }
    return TRUE;
}

bool8 sub_8100430(void)
{
    if ((gMain.heldKeys & DPAD_ANY) != DPAD_UP && (gMain.heldKeys & DPAD_ANY) != DPAD_DOWN && (gMain.heldKeys & DPAD_ANY) != DPAD_LEFT && (gMain.heldKeys & DPAD_ANY) != DPAD_RIGHT)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_810045C(void)
{
    gUnknown_020391AA = 0;
    gSprites[gUnknown_020391A8].data2 = 0;
    gSprites[gUnknown_020391A8].data3 = 0;
}

void sub_8100494(u8 taskId)
{
    if (!gSprites[gUnknown_020391A8].data4)
    {
        if (gTasks[taskId].data[10] == 1)
        {
            gUnknown_083EC96C[gTasks[taskId].data[12]][0](taskId);
            return;
        } else if (gTasks[taskId].data[10] == 2)
        {
            gUnknown_083EC96C[gTasks[taskId].data[12]][1](taskId);
            return;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_UP)
        {
            gUnknown_020391AA = DIR_SOUTH;
            gSprites[gUnknown_020391A8].data2 =  0;
            gSprites[gUnknown_020391A8].data3 = -2;
            gTasks[taskId].data[1]--;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_DOWN)
        {
            gUnknown_020391AA = DIR_NORTH;
            gSprites[gUnknown_020391A8].data2 =  0;
            gSprites[gUnknown_020391A8].data3 =  2;
            gTasks[taskId].data[1]++;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_LEFT)
        {
            gUnknown_020391AA = DIR_WEST;
            gSprites[gUnknown_020391A8].data2 = -2;
            gSprites[gUnknown_020391A8].data3 =  0;
            gTasks[taskId].data[0]--;
        }
        if ((gMain.heldKeys & DPAD_ANY) == DPAD_RIGHT)
        {
            gUnknown_020391AA = DIR_EAST;
            gSprites[gUnknown_020391A8].data2 =  2;
            gSprites[gUnknown_020391A8].data3 =  0;
            gTasks[taskId].data[0]++;
        }
        if (!sub_8100430() || !sub_810038C(taskId))
        {
            sub_810045C();
        }
    }
    if (gUnknown_020391AA)
    {
        gSprites[gUnknown_020391A8].data4++;
        gSprites[gUnknown_020391A8].data4 &= 7;
    }
    if (!gTasks[taskId].data[10])
    {
        if (gMain.newKeys & A_BUTTON)
        {
            gTasks[taskId].data[10] = A_BUTTON;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            gTasks[taskId].data[10] = B_BUTTON;
        }
    }
}

void sub_810065C(u8 taskId)
{
    MenuZeroFillWindowRect(0, 0, 29, 19);
    gSprites[gUnknown_020391A8].data7 = 0;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8100494;
}

void sub_81006A8(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        sub_810065C(taskId);
    }
}

void sub_81006D0(struct UnkStruct_02038900 *unk_02038900)
{
    u16 i;
    for (i=0; i<0x800; i++)
    {
        unk_02038900->unk_084[i] = 0;
    }
    for (i=0; i<0x40; i++)
    {
        unk_02038900->unk_004[i] = 0;
    }
}

void sub_810070C(u16 *a0, u16 a1)
{
    u16 i;
    for (i=0; i<16; i++)
    {
        a0[i] = ((u16 *)gMapHeader.mapData->primaryTileset->palettes)[16 * a1 + i];
    }
}

void sub_8100740(u8 *dest, u16 flags)
{
    u8 buffer[32];
    u16 mode;
    u16 i;
    mode = flags >> 10;
    if (flags != 0)
    {
        flags &= 0x3ff;
    }
    for (i=0; i<32; i++)
    {
        buffer[i] = ((u8 *)gMapHeader.mapData->primaryTileset->tiles)[flags * 32 + i];
    }
    switch (mode)
    {
        case 0:
            for (i=0; i<32; i++)
            {
                dest[i] = buffer[i];
            }
            break;
        case 1:
            for (i=0; i<8; i++)
            {
                dest[4*i] = (buffer[4*(i+1) - 1] >> 4) + ((buffer[4*(i+1) - 1] & 0xf) << 4);
                dest[4*i + 1] = (buffer[4*(i+1) - 2] >> 4) + ((buffer[4*(i+1) - 2] & 0xf) << 4);
                dest[4*i + 2] = (buffer[4*(i+1) - 3] >> 4) + ((buffer[4*(i+1) - 3] & 0xf) << 4);
                dest[4*i + 3] = (buffer[4*(i+1) - 4] >> 4) + ((buffer[4*(i+1) - 4] & 0xf) << 4);
            }
            break;
        case 2:
            for (i=0; i<8; i++)
            {
                dest[4*i] = buffer[4*(7-i)];
                dest[4*i + 1] = buffer[4*(7-i) + 1];
                dest[4*i + 2] = buffer[4*(7-i) + 2];
                dest[4*i + 3] = buffer[4*(7-i) + 3];
            }
            break;
        case 3:
            for (i=0; i<32; i++)
            {
                dest[i] = (buffer[31-i] >> 4) + ((buffer[31-i] & 0xf) << 4);
            }
            break;
    }
}

void sub_8100874(struct UnkStruct_02038900 *unk_02038900)
{
    u16 i;
    for (i=0; i<0x40; i++)
        sub_8100740(&unk_02038900->unk_084[i * 32], unk_02038900->unk_004[i]);
}

u16 sub_810089C(u16 a0)
{
    return ((u16 *)gMapHeader.mapData->secondaryTileset->metatiles)[a0] & 0xfff;
}

void sub_81008BC(struct UnkStruct_02038900 *unk_02038900)
{
    u8 i;
    u8 idx;
    idx = unk_02038900->decoration->shape;
    for (i=0; i<gUnknown_083EC860[idx].size; i++)
    {
        unk_02038900->unk_004[gUnknown_083EC860[idx].var0[i]] = sub_810089C(unk_02038900->decoration->tiles[gUnknown_083EC860[idx].var4[i]] * 8 + gUnknown_083EC860[idx].var8[i]);
    }
}

void sub_8100930(u8 unk12)
/*
 * This function sets an OAM object not directly referenced anywhere else
 * in the source.
 */
{
    gUnknown_020391AC.y = 0;
    gUnknown_020391AC.affineMode = 0;
    gUnknown_020391AC.objMode = 0;
    gUnknown_020391AC.mosaic = 0;
    gUnknown_020391AC.bpp = 0;
    gUnknown_020391AC.shape = gUnknown_083EC900[unk12].unk_0;
    gUnknown_020391AC.x = 0;
    gUnknown_020391AC.matrixNum = 0;
    gUnknown_020391AC.size = gUnknown_083EC900[unk12].unk_1;
    gUnknown_020391AC.tileNum = 0;
    gUnknown_020391AC.priority = 1;
    gUnknown_020391AC.paletteNum = 0;
}

void sub_81009A8(struct Sprite *sprite)
{
    sprite->data2 = 0;
    sprite->data3 = 0;
    sprite->data4 = 0;
    sprite->data5 = 0;
    sprite->data6 = 0;
    sprite->data7 = 0;
    sprite->callback = sub_81009C0;
}

void sub_81009C0(struct Sprite *sprite)
{
    if (sprite->data7 == 0)
    {
        if (sprite->data6 < 15)
        {
            sprite->invisible = 0;
        } else
        {
            sprite->invisible = 1;
        }
        sprite->data6 = (sprite->data6 + 1) & 0x1f;
    } else
    {
        sprite->invisible = 0;
    }
}

void sub_8100A0C(u8 taskId)
{
    if (sub_8100D38(taskId) == 1)
    {
        fade_screen(1, 0);
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_8100E70;
    } else
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecorInUse, sub_80FE428, 0);
    }
}

void sub_8100A60(u8 a0)
{
    ewram_1f000.items[a0] = 0;
    ewram_1f000.pos[a0] = 0;
}

void sub_8100A7C(void)
{
    u16 i;
    gSpecialVar_0x8005 = 0;
    gScriptResult = 0;
    if (gSpecialVar_0x8004 == gUnknown_02039234)
    {
        gScriptResult = 1;
    } else if (gDecorations[ewram_1f000.items[gUnknown_020391B4[gSpecialVar_0x8004].var00]].decor_field_11 == 4)
    {
        gSpecialVar_0x8005 = gUnknown_020391B4[gSpecialVar_0x8004].var04;
        sub_8100A60(gUnknown_020391B4[gSpecialVar_0x8004].var00);
        for (i=0; i<gMapHeader.events->mapObjectCount; i++)
        {
            if (gMapHeader.events->mapObjects[i].flagId == gSpecialVar_0x8005)
            {
                gSpecialVar_0x8006 = gMapHeader.events->mapObjects[i].localId;
                break;
            }
        }
    }
}

void sub_8100B20(void)
{
    u8 i;
    for (i=0; i<gMapHeader.events->mapObjectCount; i++)
    {
        if (gMapHeader.events->mapObjects[i].flagId == gSpecialVar_0x8004)
        {
            gSpecialVar_0x8005 = gMapHeader.events->mapObjects[i].localId;
            break;
        }
    }
}

void sub_8100B6C(void)
{
    u8 i;
    u8 j;
    u8 k;
    u8 x;
    u8 y;
    u8 unk11;
    for (i=0; i<gUnknown_02039234; i++)
    {
        unk11 = gDecorations[ewram_1f000.items[gUnknown_020391B4[i].var00]].decor_field_11;
        x = ewram_1f000.pos[gUnknown_020391B4[i].var00] >> 4;
        y = ewram_1f000.pos[gUnknown_020391B4[i].var00] & 0xf;
        if (unk11 != 4)
        {
            if (ewram_1f000.items[gUnknown_020391B4[i].var00] == DECOR_SAND_ORNAMENT && MapGridGetMetatileIdAt(x + 7, y + 7) == 0x28c)
            {
                gUnknown_020391B4[i].height++;
            }
            for (j=0; j<gUnknown_020391B4[i].height; j++)
            {
                for (k=0; k<gUnknown_020391B4[i].width; k++)
                {
                    MapGridSetMetatileEntryAt(x + 7 + k, y + 7 - j, ((u16 *)gMapHeader.mapData->map)[(x + k) + gMapHeader.mapData->width * (y - j)] | 0x3000);
                }
            }
            sub_8100A60(gUnknown_020391B4[i].var00);
        }
    }
}

void sub_8100C88(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            sub_8100B6C();
            gTasks[taskId].data[2] = 1;
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                DrawWholeMapView();
                ScriptContext1_SetupScript(gUnknown_081A2F8A);
                MenuZeroFillWindowRect(0, 0, 29, 19);
                gTasks[taskId].data[2] = 2;
            }
            break;
        case 2:
            ScriptContext2_Enable();
            sub_80FED90(taskId);
            pal_fill_black();
            gTasks[taskId].data[2] = 3;
            break;
        case 3:
            if (sub_807D770() == 1)
            {
                gTasks[taskId].data[13] = -1;
                DisplayItemMessageOnField(taskId, gSecretBaseText_DecorReturned, sub_81010F0, 0);
            }
            break;
    }
}

bool8 sub_8100D38(u8 taskId)
{
    u16 i;
    for (i=0; i<ewram_1f000.size; i++)
    {
        if (ewram_1f000.items[i] != 0)
        {
            gTasks[taskId].data[13] = i;
            return TRUE;
        }
    }
    return FALSE;
}

void SetUpPuttingAwayDecorationPlayerAvatar(void)
{
    player_get_direction_lower_nybble();
    MenuZeroFillWindowRect(0, 0, 29, 19);
    gUnknown_020391A8 = gSprites[gUnknown_03004880.unk4].data0;
    sub_81016C8();
    gUnknown_03004880.unk4 = CreateSprite(&gSpriteTemplate_83ECA88, 0x78, 0x50, 0);
    if (gSaveBlock2.playerGender == MALE)
    {
        gUnknown_020391A9 = AddPseudoFieldObject(0xc1, SpriteCallbackDummy, 0x88, 0x48, 0);
    } else
    {
        gUnknown_020391A9 = AddPseudoFieldObject(0xc2, SpriteCallbackDummy, 0x88, 0x48, 0);
    }
    gSprites[gUnknown_020391A9].oam.priority = 1;
    DestroySprite(&gSprites[gUnknown_020391A8]);
    gUnknown_020391A8 = gUnknown_03004880.unk4;
    gSprites[gUnknown_020391A8].oam.priority = 1;
}

void sub_8100E70(u8 taskId)
{
    s16 *data;
    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_80FF0E0(taskId);
                data[2] = 1;
                data[6] = 1;
                data[5] = 1;
                sub_8072DEC();
            }
            break;
        case 1:
            SetUpPuttingAwayDecorationPlayerAvatar();
            pal_fill_black();
            data[2] = 2;
            break;
        case 2:
            if (sub_807D770() == TRUE)
            {
                data[12] = 1;
                sub_8100EEC(taskId);
            }
            break;
    }
}

void sub_8100EEC(u8 taskId)
{
    MenuZeroFillWindowRect(0, 0, 29, 19);
    gSprites[gUnknown_020391A8].data7 = 0;
    gSprites[gUnknown_020391A8].invisible = 0;
    gSprites[gUnknown_020391A8].callback = sub_8101698;
    gSprites[gUnknown_020391A9].pos1.x = 0x88;
    gSprites[gUnknown_020391A9].pos1.y = 0x48;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8100494;
}

void sub_8100F88(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_810045C();
    sub_8101024(taskId);
}

void sub_8100FB4(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_810045C();
    gSprites[gUnknown_020391A8].invisible = 0;
    gSprites[gUnknown_020391A8].callback = SpriteCallbackDummy;
    DisplayItemMessageOnField(taskId, gSecretBaseText_StopPuttingAwayDecor, sub_810156C, 0);
}

void sub_8101024(u8 taskId)
{
    u8 mtBehavior;
    s16 *data;
    sub_8101460(taskId);
    if (gUnknown_02039234 != 0)
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_ReturnDecor, sub_8101518, 0);
    } else
    {
        data = gTasks[taskId].data;
        mtBehavior = MapGridGetMetatileBehaviorAt(data[0], data[1]);
        if (MetatileBehavior_IsSecretBasePC(mtBehavior) == TRUE || sub_805738C(mtBehavior) == TRUE)
        {
            gSprites[gUnknown_020391A8].invisible = 0;
            gSprites[gUnknown_020391A8].callback = SpriteCallbackDummy;
            DisplayItemMessageOnField(taskId, gSecretBaseText_StopPuttingAwayDecor, sub_810156C, 0);
        } else
        {
            DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecor, sub_81010F0, 0);
        }
    }
}

void sub_81010F0(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        sub_8100EEC(taskId);
    }
}

void sub_8101118(u8 decorIdx, struct UnkStruct_020391B4 *unk_020391B4)
{
    if (gDecorations[decorIdx].shape == 0)
    {
        unk_020391B4->width = 1;
        unk_020391B4->height = 1;
    } else if (gDecorations[decorIdx].shape == 1)
    {
        unk_020391B4->width = 2;
        unk_020391B4->height = 1;
    } else if (gDecorations[decorIdx].shape == 2)
    {
        unk_020391B4->width = 3;
        unk_020391B4->height = 1;
    } else if (gDecorations[decorIdx].shape == 3)
    {
        unk_020391B4->width = 4;
        unk_020391B4->height = 2;
    } else if (gDecorations[decorIdx].shape == 4)
    {
        unk_020391B4->width = 2;
        unk_020391B4->height = 2;
    } else if (gDecorations[decorIdx].shape == 5)
    {
        unk_020391B4->width = 1;
        unk_020391B4->height = 2;
    } else if (gDecorations[decorIdx].shape == 6)
    {
        unk_020391B4->width = 1;
        unk_020391B4->height = 3;
    } else if (gDecorations[decorIdx].shape == 7)
    {
        unk_020391B4->width = 2;
        unk_020391B4->height = 4;
    } else if (gDecorations[decorIdx].shape == 8)
    {
        unk_020391B4->width = 3;
        unk_020391B4->height = 3;
    } else if (gDecorations[decorIdx].shape == 9)
    {
        unk_020391B4->width = 3;
        unk_020391B4->height = 2;
    }
}

void sub_8101198(u8 x, u8 y)
{
    gSprites[gUnknown_020391A8].invisible = 1;
    gSprites[gUnknown_020391A8].callback = SpriteCallbackDummy;
    gSprites[gUnknown_020391A9].pos1.x = 0x88 + x * 16;
    gSprites[gUnknown_020391A9].pos1.y = 0x48 + y * 16;
}

bool8 sub_8101200(u8 taskId, u8 decorIdx, struct UnkStruct_020391B4 *unk_020391B4)
{
    u8 x;
    u8 y;
    u8 xOff;
    u8 yOff;
    x = gTasks[taskId].data[0] - 7;
    y = gTasks[taskId].data[1] - 7;
    xOff = ewram_1f000.pos[decorIdx] >> 4;
    yOff = ewram_1f000.pos[decorIdx] & 0xf;
    if (ewram_1f000.items[decorIdx] == DECOR_SAND_ORNAMENT && MapGridGetMetatileIdAt(xOff + 7, yOff + 7) == 0x28c)
    {
        unk_020391B4->height--;
    }
    if (x >= xOff && x < xOff + unk_020391B4->width && y > yOff - unk_020391B4->height && y <= yOff)
    {
        sub_8101198(unk_020391B4->width - (x - xOff + 1), yOff - y);
        return TRUE;
    }
    return FALSE;
}

void sub_81012A0(void)
{
    u8 xOff;
    u8 yOff;
    u16 i;
    xOff = ewram_1f000.pos[gUnknown_020391B4[gUnknown_02039234].var00] >> 4;
    yOff = ewram_1f000.pos[gUnknown_020391B4[gUnknown_02039234].var00] & 0xf;
    for (i=0; i<0x40; i++)
    {
        if (gSaveBlock1.mapObjectTemplates[i].x == xOff && gSaveBlock1.mapObjectTemplates[i].y == yOff && !FlagGet(gSaveBlock1.mapObjectTemplates[i].flagId))
        {
            gUnknown_020391B4[gUnknown_02039234].var04 = gSaveBlock1.mapObjectTemplates[i].flagId;
            break;
        }
    }
}

bool8 sub_8101340(u8 taskId)
{
    u16 i;
    for (i=0; i<ewram_1f000.size; i++)
    {
        if (ewram_1f000.items[i] != 0)
        {
            if (gDecorations[ewram_1f000.items[i]].decor_field_11 == 4)
            {
                sub_8101118(ewram_1f000.items[i], gUnknown_020391B4);
                if (sub_8101200(taskId, i, gUnknown_020391B4) == TRUE)
                {
                    gUnknown_020391B4->var00 = i;
                    sub_81012A0();
                    gUnknown_02039234 = 1;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void sub_81013B8(u8 a0, u8 a1, u8 a2, u8 a3)
{
    u8 i;
    u8 xOff;
    u8 yOff;
    u8 decorIdx;
    for (i=0; i<ewram_1f000.size; i++)
    {
        decorIdx = ewram_1f000.items[i];
        xOff = ewram_1f000.pos[i] >> 4;
        yOff = ewram_1f000.pos[i] & 0xf;
        if (decorIdx != 0 && gDecorations[decorIdx].decor_field_11 == 4 && a0 <= xOff && a1 <= yOff && a2 >= xOff && a3 >= yOff)
        {
            gUnknown_020391B4[gUnknown_02039234].var00 = i;
            sub_81012A0();
            gUnknown_02039234++;
        }
    }
}

#ifdef NONMATCHING
void sub_8101460(u8 taskId)
{
    u8 i;
    u8 xOff;
    u8 yOff;
    gUnknown_02039234 = 0;
    if (sub_8101340(taskId) != TRUE)
    {
        for (i=0; i<ewram_1f000.size; i++)
        {
            if (ewram_1f000.items[i] != 0) // This is using the wrong register!
            {
                sub_8101118(ewram_1f000.items[i], gUnknown_020391B4);
                if (sub_8101200(taskId, i, gUnknown_020391B4) == TRUE)
                {
                    gUnknown_020391B4[0].var00 = i;
                    gUnknown_02039234++;
                    break;
                }
            }
        }
        if (gUnknown_02039234 != 0)
        {
            xOff = ewram_1f000.pos[gUnknown_020391B4[0].var00] >> 4;
            yOff = ewram_1f000.pos[gUnknown_020391B4[0].var00] & 0xf;
            sub_81013B8(xOff, yOff - gUnknown_020391B4[0].var02 + 1, xOff + gUnknown_020391B4[0].var01 - 1, yOff);
        }
    }
}
#else
__attribute__((naked))

void sub_8101460(u8 taskId)
{
    asm(".syntax unified\n"
    "\tpush {r4-r7,lr}\n"
    "\tlsls r0, 24\n"
    "\tlsrs r6, r0, 24\n"
    "\tldr r4, _081014B8 @ =gUnknown_02039234\n"
    "\tmovs r0, 0\n"
    "\tstrb r0, [r4]\n"
    "\tadds r0, r6, 0\n"
    "\tbl sub_8101340\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tcmp r0, 0x1\n"
    "\tbeq _08101504\n"
    "\tmovs r5, 0\n"
    "\tldr r0, _081014BC @ =ewram_1f000\n"
    "\tldrb r1, [r0, 0x8]\n"
    "\tcmp r5, r1\n"
    "\tbcs _081014D2\n"
    "\tadds r7, r4, 0\n"
    "_08101486:\n"
    "\tldr r0, [r0]\n"
    "\tadds r0, r5\n"
    "\tldrb r1, [r0] @ compiler incorrectly uses r0 for this and the next instruction\n"
    "\tcmp r1, 0\n"
    "\tbeq _081014C4\n"
    "\tldr r4, _081014C0 @ =gUnknown_020391B4\n"
    "\tadds r0, r1, 0\n"
    "\tadds r1, r4, 0\n"
    "\tbl sub_8101118\n"
    "\tadds r0, r6, 0\n"
    "\tadds r1, r5, 0\n"
    "\tadds r2, r4, 0\n"
    "\tbl sub_8101200\n"
    "\tlsls r0, 24\n"
    "\tlsrs r0, 24\n"
    "\tcmp r0, 0x1\n"
    "\tbne _081014C4\n"
    "\tstrb r5, [r4]\n"
    "\tldrb r0, [r7]\n"
    "\tadds r0, 0x1\n"
    "\tstrb r0, [r7]\n"
    "\tb _081014D2\n"
    "\t.align 2, 0\n"
    "_081014B8: .4byte gUnknown_02039234\n"
    "_081014BC: .4byte 0x201f000\n"
    "_081014C0: .4byte gUnknown_020391B4\n"
    "_081014C4:\n"
    "\tadds r0, r5, 0x1\n"
    "\tlsls r0, 24\n"
    "\tlsrs r5, r0, 24\n"
    "\tldr r0, _0810150C @ =ewram_1f000\n"
    "\tldrb r1, [r0, 0x8]\n"
    "\tcmp r5, r1\n"
    "\tbcc _08101486\n"
    "_081014D2:\n"
    "\tldr r0, _08101510 @ =gUnknown_02039234\n"
    "\tldrb r0, [r0]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08101504\n"
    "\tldr r0, _0810150C @ =ewram_1f000\n"
    "\tldr r2, _08101514 @ =gUnknown_020391B4\n"
    "\tldrb r1, [r2]\n"
    "\tldr r0, [r0, 0x4]\n"
    "\tadds r0, r1\n"
    "\tldrb r1, [r0]\n"
    "\tlsrs r0, r1, 4\n"
    "\tmovs r3, 0xF\n"
    "\tands r3, r1\n"
    "\tldrb r1, [r2, 0x2]\n"
    "\tsubs r1, r3, r1\n"
    "\tadds r1, 0x1\n"
    "\tlsls r1, 24\n"
    "\tlsrs r1, 24\n"
    "\tldrb r2, [r2, 0x1]\n"
    "\tadds r2, r0\n"
    "\tsubs r2, 0x1\n"
    "\tlsls r2, 24\n"
    "\tlsrs r2, 24\n"
    "\tbl sub_81013B8\n"
    "_08101504:\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    "_0810150C: .4byte 0x201f000\n"
    "_08101510: .4byte gUnknown_02039234\n"
    "_08101514: .4byte gUnknown_020391B4\n"
    ".syntax divided\n");
}
#endif

void sub_8101518(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    sub_80F914C(taskId, &gUnknown_083EC9CC);
}

void sub_810153C(u8 taskId)
{
    fade_screen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_8100C88;
}

void sub_810156C(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    sub_80F914C(taskId, &gUnknown_083EC9D4);
}

void sub_8101590(u8 taskId)
{
    MenuZeroFillWindowRect(0, 0, 29, 19);
    sub_81015B0(taskId);
}

void sub_81015B0(u8 taskId)
{
    fade_screen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_81015E0;
}

void sub_81015E0(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_80FF114(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_81016F4();
            gUnknown_0300485C = sub_8101678;
            SetMainCallback2(c2_exit_to_overworld_2_switch);
            DestroyTask(taskId);
            break;
    }
}

void sub_8101648(u8 taskId)
{
    if (sub_807D770() == TRUE)
    {
        gTasks[taskId].func = Task_DecorationPCProcessMenuInput;
    }
}

void sub_8101678(void)
{
    pal_fill_black();
    MenuDisplayMessageBox();
    sub_80FE220();
    CreateTask(sub_8101648, 8);
}

void sub_8101698(struct Sprite *sprite)
{
    sprite->data0 = (sprite->data0 + 1) & 0x1f;
    if (sprite->data0 >= 16)
    {
        sprite->invisible = TRUE;
    } else
    {
        sprite->invisible = FALSE;
    }
}

void sub_81016C8(void)
{
    if (gSaveBlock2.playerGender == MALE)
    {
        LoadSpritePalette(&gUnknown_083ECA5C);
    } else
    {
        LoadSpritePalette(&gUnknown_083ECA64);
    }
}

void sub_81016F4(void)
{
    FreeSpritePaletteByTag(8);
}

void sub_8101700(u8 taskId)
{
    if (!sub_81341D4())
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE428, 0);
    } else
    {
        gTasks[taskId].data[11] = 1;
        gUnknown_020388F6 = 0;
        sub_80FE5AC(taskId);
    }
}

void sub_8101750(u8 taskId)
{
    if (!sub_81341D4())
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_NoDecors, sub_80FE428, 0);
    } else
    {
        gTasks[taskId].data[11] = 2;
        gUnknown_020388F6 = 0;
        sub_80FE5AC(taskId);
    }
}

void sub_81017A0(u8 taskId)
{
    sub_80FEF74();
    sub_80FED1C();
    if (sub_80FEFA4() == TRUE)
    {
        StringCopy(gStringVar1, gDecorations[gUnknown_020388D0[gUnknown_020388F5]].name);
        StringExpandPlaceholders(gStringVar4, gSecretBaseText_WillBeDiscarded);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8101824, 0);
    } else
    {
        DisplayItemMessageOnField(taskId, gSecretBaseText_DecorInUse, sub_80FEFF4, 0);
    }
}

void sub_8101824(u8 taskId)
{
    DisplayYesNoMenu(20, 8, 1);
    sub_80F914C(taskId, &gUnknown_083ECAA0);
}

void sub_8101848(u8 taskId)
{
    MenuZeroFillWindowRect(20, 8, 26, 14);
    sub_8109A30(gUnknown_020388D0[gUnknown_020388F5]);
    gUnknown_020388D0[gUnknown_020388F5] = DECOR_NONE;
    sub_80FF098(taskId);
    DisplayItemMessageOnField(taskId, gSecretBaseText_DecorThrownAway, sub_80FEFF4, 0);
}
