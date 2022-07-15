#ifndef RESOURCE_H
#define RESOURCE_H
#include "gfx.h"

enum resource_id {
    RES_FONT_FIPPS,
    RES_FONT_NOTALOT35,
    RES_FONT_ORIGAMIMOMMY,
    RES_FONT_PCSENIOR,
    RES_FONT_PIXELINTV,
    RES_FONT_PRESSSTART2P,
    RES_FONT_SMWTEXTNC,
    RES_FONT_WERDNASRETURN,
    RES_FONT_PIXELZIM,
    RES_PMICON_PARTNER,
    RES_ICON_CHECK,
    RES_ICON_BUTTONS,
    RES_ICON_PAUSE,
    RES_ICON_MACRO,
    RES_ICON_MOVIE,
    RES_ICON_ARROW,
    RES_ICON_FILE,
    RES_ICON_SAVE,
    RES_ICON_OSK,
    RES_TEXTURE_CROSSHAIR,
    RES_TEXTURE_CONTROL_STICK,
    RES_MAX,
};

enum icon_global_offset {
    ICON_ARROW_LEFT = 0x0,
    ICON_ARROW_RIGHT = 0x28,
    ICON_HAND_POINTER = 0x50,
    ICON_ANIMATED_HANDPOINTER = 0x78, // animated
    ICON_FILLED_CIRCLE = 0xC0,
    ICON_EMPTY_CIRCLE = 0xE8,
    ICON_STATUS_SP_SHINE = 0x23C,
    ICON_STATUS_STAR_PIECE = 0x260,  // animated
    ICON_ASLEEP_LOOP = 0x2B8,        // animated
    ICON_ASLEEP_BEGIN = 0x314,       // animated
    ICON_ASLEEP_END = 0x4B4,         // animated
    ICON_ELECTRIFIED_LOOP = 0x60C,   // animated
    ICON_ELECTRIFIED_BEGIN = 0x6F8,  // animated
    ICON_ELECTRIFIED_END = 0x928,    // animated
    ICON_PARALYZED_LOOP = 0xA80,     // animated
    ICON_PARALYZED_BEGIN = 0xB6C,    // animated
    ICON_PARALYZED_END = 0xD9C,      // animated
    ICON_DIZZY_LOOP = 0xEF4,         // animated
    ICON_DIZZY_BEGIN = 0xF50,        // animated
    ICON_DIZZY_END = 0x10F0,         // animated
    ICON_POISONED_LOOP = 0x1248,     // animated
    ICON_POISONED_BEGIN = 0x12A4,    // animated
    ICON_POISONED_END = 0x1444,      // animated
    ICON_FROZEN_LOOP = 0x159C,       // animated
    ICON_FROZEN_BEGIN = 0x15F8,      // animated
    ICON_FROZEN_END = 0x1798,        // animated
    ICON_WEAKENED_LOOP = 0x18F0,     // animated
    ICON_WEAKENED_BEGIN = 0x192C,    // animated
    ICON_WEAKENED_END = 0x1AAC,      // animated
    ICON_STOPPED_BEGIN = 0x1C60,     // animated
    ICON_STOPPED_END = 0x1E00,       // animated
    ICON_SHRUNK_LOOP = 0x1F58,       // animated
    ICON_SHRUNK_BEGIN = 0x1FB4,      // animated
    ICON_SHRUNK_END = 0x2154,        // animated
    ICON_TRANSPARENT_LOOP = 0x22AC,  // animated
    ICON_TRANSPARENT_BEGIN = 0x2328, // animated
    ICON_TRANSPARENT_END = 0x24E8,   // animated
    ICON_BOOST_JUMP_LOOP = 0x2640,
    ICON_BOOST_JUMP_BEGIN = 0x266C, // animated
    ICON_BOOST_JUMP_END = 0x27CC,   // animated
    ICON_BOOST_HAMMER_LOOP = 0x2938,
    ICON_BOOST_HAMMER_BEGIN = 0x2964, // animated
    ICON_BOOST_HAMMER_END = 0x2AC4,   // animated
    ICON_BOOST_PARTNER = 0x2C30,
    ICON_SURPRISE = 0x2C5C,
    ICON_FP_COST = 0x2C88,
    ICON_FP_COST_REDUCED = 0x2CB4,
    ICON_FP_COST_REDUCED_TWICE = 0x2CE0,
    ICON_NOT_ENOUGH_FP = 0x2D0C,
    ICON_POW_COST = 0x2D38,
    ICON_POW_COST_REDUCED = 0x2D64,
    ICON_POW_COST_REDUCED_TWICE = 0x2D90,
    ICON_NOT_ENOUGH_POW = 0x2DBC,
    ICON_GREEN_ARROW_DOWN = 0x2DE8, // animated
    ICON_GREEN_ARROW_UP = 0x2E34,   // animated
    ICON_UNUSED_PINK_FRAME = 0x2E80,
    ICON_UNUSED_DIGIT_1 = 0x2EAC,
    ICON_UNUSED_DIGIT_2 = 0x2ED8,
    ICON_UNUSED_DIGIT_3 = 0x2F04,
    ICON_RED_BAR_1 = 0x2F30,
    ICON_EMPTY_BAR = 0x2F5C,
    ICON_RED_BAR_2 = 0x2F88,
    ICON_MARIO_HEAD = 0x2FB4,
    ICON_ELDSTAR = 0x2FE0,
    ICON_ELDSTAR_DISABLED = 0x300C,
    ICON_MAMAR = 0x3038,
    ICON_MAMAR_DISABLED = 0x3064,
    ICON_SKOLAR = 0x3090,
    ICON_SKOLAR_DISABLED = 0x30BC,
    ICON_MUSKULAR = 0x30E8,
    ICON_MUSKULAR_DISABLED = 0x3114,
    ICON_MISSTAR = 0x3140,
    ICON_MISSTAR_DISABLED = 0x316C,
    ICON_KLEVAR = 0x3198,
    ICON_KLEVAR_DISABLED = 0x31C4,
    ICON_KALMAR = 0x31F0,
    ICON_KALMAR_DISABLED = 0x321C,
    ICON_STAR_BEAM = 0x3248,
    ICON_STAR_BEAM_DISABLED = 0x3274,
    ICON_PEACH_BEAM = 0x32A0,
    ICON_PEACH_BEAM_DISABLED = 0x32CC,
    ICON_PARTNER_0 = 0x32F8,
    ICON_PARTNER_0_DISABLED = 0x3320,
    ICON_GOOMBARIO = 0x3348,
    ICON_GOOMBARIO_DISABLED = 0x3370,
    ICON_KOOPER = 0x3398,
    ICON_KOOPER_DISABLED = 0x33C0,
    ICON_BOMBETTE = 0x33E8,
    ICON_BOMBETTE_DISABLED = 0x3410,
    ICON_PARAKARRY = 0x3438,
    ICON_PARAKARRY_DISABLED = 0x3460,
    ICON_BOW = 0x3488,
    ICON_BOW_DISABLED = 0x34B0,
    ICON_WATT = 0x34D8,
    ICON_WATT_DISABLED = 0x3500,
    ICON_SUSHIE = 0x3528,
    ICON_SUSHIE_DISABLED = 0x3550,
    ICON_LAKILESTER = 0x3578,
    ICON_LAKILESTER_DISABLED = 0x35A0,
    ICON_PARTNER_9 = 0x35C8,
    ICON_PARTNER_9_DISABLED = 0x35F0,
    ICON_PARTNER_A = 0x3618,
    ICON_PARTNER_A_DISABLED = 0x3640,
    ICON_PARTNER_B = 0x3668,
    ICON_PARTNER_B_DISABLED = 0x3690,
    ICON_STATUS_TIMES = 0x36B8,
    ICON_STATUS_SLASH = 0x36E0,
    ICON_STATUS_DIGIT_0 = 0x3708,
    ICON_STATUS_DIGIT_1 = 0x3730,
    ICON_STATUS_DIGIT_2 = 0x3758,
    ICON_STATUS_DIGIT_3 = 0x3780,
    ICON_STATUS_DIGIT_4 = 0x37A8,
    ICON_STATUS_DIGIT_5 = 0x37D0,
    ICON_STATUS_DIGIT_6 = 0x37F8,
    ICON_STATUS_DIGIT_7 = 0x3820,
    ICON_STATUS_DIGIT_8 = 0x3848,
    ICON_STATUS_DIGIT_9 = 0x3870,
    ICON_STATUS_HP = 0x3898,
    ICON_STATUS_FP = 0x38C0,
    ICON_STATUS_SP_INCREMENT_1 = 0x38E8,
    ICON_STATUS_SP_INCREMENT_2 = 0x3910,
    ICON_STATUS_SP_INCREMENT_3 = 0x3938,
    ICON_STATUS_SP_INCREMENT_4 = 0x3960,
    ICON_STATUS_SP_INCREMENT_5 = 0x3988,
    ICON_STATUS_SP_INCREMENT_6 = 0x39B0,
    ICON_STATUS_SP_INCREMENT_7 = 0x39D8,
    ICON_STATUS_SP_EMPTY_INCREMENT = 0x3A00,
    ICON_STATUS_STAR_1 = 0x3A28,
    ICON_STATUS_STAR_2 = 0x3A50,
    ICON_STATUS_STAR_3 = 0x3A78,
    ICON_STATUS_STAR_4 = 0x3AA0,
    ICON_STATUS_STAR_5 = 0x3AC8,
    ICON_STATUS_STAR_6 = 0x3AF0,
    ICON_STATUS_STAR_7 = 0x3B18,
    ICON_STATUS_STAR_EMPTY = 0x3B40,
    ICON_STATUS_HEART = 0x3B68,
    ICON_STATUS_FLOWER = 0x3B88,
    ICON_STATUS_COIN = 0x3BA8,       // animated
    ICON_STATUS_STAR_POINT = 0x3CFC, // animated
    ICON_MENU_BOOTS_1 = 0x3D94,
    ICON_MENU_BOOTS_1_DISABLED = 0x3DBC,
    ICON_MENU_BOOTS_2 = 0x3DE4,
    ICON_MENU_BOOTS_2_DISABLED = 0x3E0C,
    ICON_MENU_BOOTS_3 = 0x3E34,
    ICON_MENU_BOOTS_3_DISABLED = 0x3E5C,
    ICON_MENU_HAMMER_1 = 0x3E84,
    ICON_MENU_HAMMER_1_DISABLED = 0x3EAC,
    ICON_MENU_HAMMER_2 = 0x3ED4,
    ICON_MENU_HAMMER_2_DISABLED = 0x3EFC,
    ICON_MENU_HAMMER_3 = 0x3F24,
    ICON_MENU_HAMMER_3_DISABLED = 0x3F4C,
    ICON_MENU_ITEM = 0x3F74,
    ICON_MENU_ITEM_DISABLED = 0x3F9C,
    ICON_MENU_STAR_POWER = 0x3FC4,
    ICON_MENU_STAR_POWER_DISABLED = 0x3FEC,
    ICON_PERIL = 0x4014,  // animated
    ICON_DANGER = 0x4064, // animated
    ICON_REFUND = 0x40B4, // animated
    ICON_HAPPY = 0x40FC,
    ICON_HP_DRAIN = 0x4124,
    ICON_BLUE_METER = 0x414C,
    ICON_A_BUTTON = 0x4178,
    ICON_A_BUTTON_DOWN = 0x41A4,
    ICON_MASH_A_BUTTON = 0x41D0,         // animated
    ICON_PRESS_A_BUTTON = 0x420C,        // animated
    ICON_SLOWLY_PRESS_A_BUTTON = 0x4248, // animated
    ICON_SLOWLY_MASH_A_BUTTON = 0x4284,  // animated
    ICON_START_BUTTON = 0x42C0,
    ICON_START_BUTTON_DOWN = 0x42EC,
    ICON_MASH_START_BUTTON = 0x4318,  // animated
    ICON_PRESS_START_BUTTON = 0x4354, // animated
    ICON_START_BUTTON_TEXT = 0x4390,
    ICON_ROTATE_STICK_CW = 0x43BC, // animated
    ICON_STICK_NEUTRAL = 0x446C,
    ICON_STICK_HOLD_LEFT = 0x4498,      // animated
    ICON_STICK_BACK_AND_FORTH = 0x44D0, // animated
    ICON_STICK_MASH_LEFT = 0x4580,      // animated
    ICON_STICK_TAP_LEFT = 0x45E0,       // animated
    ICON_STICK_TAP_NEUTRAL = 0x4640,    // animated
    ICON_STICK_HOLD_DOWN = 0x46DC,
    ICON_STICK_MASH_DOWN = 0x4714,       // animated
    ICON_STICK_TAP_DOWN = 0x4774,        // animated
    ICON_STICK_SLOWLY_TAP_DOWN = 0x47D4, // animated
    ICON_STICK_TAP_RIGHT = 0x4834,       // animated
    ICON_RUN_AWAY_OK = 0x4894,           // animated
    ICON_MENU_TIMES = 0x48C0,
    ICON_PARTNER_RANK_1_A = 0x48E8,
    ICON_PARTNER_RANK_1_B = 0x4910,
    ICON_PARTNER_RANK_2_A = 0x4938,
    ICON_PARTNER_RANK_2_B = 0x4960,
    ICON_MOVE_DIAMOND = 0x4988,
    ICON_MOVE_BLUE_ORB = 0x49B0,
    ICON_MOVE_GREEN_ORB = 0x49D8,
    ICON_MOVE_RED_ORB = 0x4A00,
    ICON_MOVE_DIAMOND_DISABLED = 0x4A28,
    ICON_MOVE_BLUE_ORB_DISABLED = 0x4A50,
    ICON_MOVE_GREEN_ORB_DISABLED = 0x4A78,
    ICON_MOVE_RED_ORB_DISABLED = 0x4AA0
};

void *resource_get(enum resource_id res);
void resource_free(enum resource_id res);
struct gfx_texture *resource_load_grc_texture(const char *grc_resource_name);
struct gfx_texture *resource_load_pmicon_item(Item item);
struct gfx_texture *resource_load_pmicon_global(enum icon_global_offset icon_global_offset, s8 palette_count);

#endif
