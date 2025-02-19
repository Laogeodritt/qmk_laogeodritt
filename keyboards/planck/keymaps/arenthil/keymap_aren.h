#pragma once

/*
 * This keyboard only has QWERTY implemented.
 * 
 * If you want Colemak/Dvorak/Plover, you can define these macros in config.h:
 *
 * - AREN_EN_COLEMAK
 * - AREN_EN_DVORAK
 * - AREN_EN_PLOVER
 *
 * You could alternatively replace the L_QWERTY layer wholesale with your
 * preferred layout.
 *
 * Note that I haven't tested the Colemak/Dvorak/Plover layers at all.
 */
enum planck_layers {
    L_QWERTY = 0,
    #ifdef AREN_EN_COLEMAK
        L_COLEMAK,
    #endif
    #ifdef AREN_EN_DVORAK
        L_DVORAK,
    #endif
    L_LOWER,
    L_RAISE,
    L_FN_NUM,
    L_SPACE_FN,
    L_ARROW_OVERLAY,
    #ifdef AREN_EN_SIB
        L_SIB_BASE,
        L_SIB_LOWER,
        L_SIB_RAISE,
    #endif // AREN_EN_SIB
    #ifdef AREN_EN_PLOVER
        L_PLOVER,
    #endif
    L_ADJUST,
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    BACKLIT,
    EXT_PLV,
    PLANCK_KEYCODES_MAX
};
