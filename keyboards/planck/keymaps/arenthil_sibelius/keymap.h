#pragma once

// shorthand modifier keys
#define SIB_UNDO LCTL(KC_Z)
#define SIB_REDO LCTL(KC_Y)
#define SIB_HIDA MO(L_HIDARI)
#define SIB_MIGI MO(L_MIGI)
#define SIB_VC1 LALT(KC_1)
#define SIB_VC2 LALT(KC_2)
#define SIB_VC3 LALT(KC_3)
#define SIB_VC4 LALT(KC_4)
#define SIB_V12 LSFT(KC_V)

#define SIB_PAD1(KEY) (SS_TAP(X_F7) SS_TAP(KEY))
#define SIB_PAD2(KEY) (SS_TAP(X_F8) SS_TAP(KEY))
#define SIB_PAD3(KEY) (SS_TAP(X_F9) SS_TAP(KEY))
#define SIB_PAD4(KEY) (SS_TAP(X_F10) SS_TAP(KEY))
#define SIB_PAD5(KEY) (SS_TAP(X_F11) SS_TAP(KEY))
#define SIB_PAD6(KEY) (SS_TAP(X_F12) SS_TAP(KEY))

enum planck_layers {
    L_BASE = 0,
    L_HIDARI,
    L_MIGI
};

enum sib_keycodes {
    NOTE00 = SAFE_RANGE,
    NOTE0,
    NOTE1,
    NOTE2,
    NOTE4,
    NOTE8,
    NOTE16,
    NOTE32,
    NOTE64,
    NOTE128,
    NOTE256,
    NOTE512,
    N_DOT, // --> N_DOT_TD for tapdance version
    N_DOT2,
    N_DOT3,
    N_TIE,
    N_REST,
    N_CUE,
    N_APPOG,
    N_ACCIA,
    N_PAREN,
    N_SLIDE,

    A_NONE,
    A_ACENT,
    A_STACC,
    A_TENUT,
    A_MARCO,
    A_STAC2,
    A_WEDGE,
    A_FERMA,
    A_FERM2,
    A_FERM3,
    A_DNBOW,
    A_UPBOW,
    A_SCOOP,
    A_FALL,
    A_PLOP,
    A_DOIT,
    A_PREB,
    A_ROLL,
    A_ROLLU,
    A_ROLLD,
    A_OPEN,
    A_CLOSE,

    AC_NONE,
    AC_CAUT,
    AC_NOCA,
    AC_FLAT,
    AC_NAT,
    AC_SHRP,
    AC_DFLT,
    AC_DSHP,
    AC_QFLT,
    AC_QSHP,
    AC_3QFL,
    AC_3QSH,
    AC_NFLA,
    AC_NSHP,

    STEM_I,
    STEM_M,
    STEM_E,
    STEMSEC,
    STEMLET,
    STEM_NO,

    REPEAT,
    REPEAT2,
    REPEAT4,

    TREM1,
    TREM2,
    TREM3,
    TREM4,
    TREM5,
    TREM_N,
    TREM_Z,
    FTHR_AC,
    FTHR_DE,
    SIB_KEYCODES_MAX
};

enum sib_tapdance {
    TD_N_DOT,
    SIB_TAPDANCE_MAX
};
