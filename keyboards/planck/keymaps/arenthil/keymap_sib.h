#pragma once

#include QMK_KEYBOARD_H
#include "keymap_aren.h"

bool process_record_sib(uint16_t keycode, keyrecord_t*);

enum sib_keycodes {
  SIB_KEYCODES_MIN = PLANCK_KEYCODES_MAX,
  SIB_MODE = PLANCK_KEYCODES_MAX,
  NOTE00,
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
  N_DOT,
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
  A_DOWN,
  A_UP,
  A_SCOOP,
  A_FALL,
  A_PLOP,
  A_DOIT,
  A_PREB,
  A_ROLL,
  A_ROLU,
  A_ROLD,
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
  REPEA2,
  REPEA4,

  TRM1,
  TRM2,
  TRM3,
  TRM4,
  TRM5,
  TRM_NXT,
  TRM_BUZ,
  FTHR_AC,
  FTHR_DE,
  SIB_KEYCODES_MAX
};

// shorthand keys
#define SIB_UNDO LCTL(KC_Z)
#define SIB_LWR MO(L_SIB_LOWER)
#define SIB_RAI MO(L_SIB_RAISE)
#define SIB_VC1 LALT(KC_1)
#define SIB_VC2 LALT(KC_2)
#define SIB_VC3 LALT(KC_3)
#define SIB_VC4 LALT(KC_4)
#define SIB_V12 LSFT(KC_V)
