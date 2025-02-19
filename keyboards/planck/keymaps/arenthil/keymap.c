/*
 * Layout copyright 2021-2025 Laura Chan (Laogeodritt)
 *
 * Source file copyright 2015-2025 Jack Humbert, Laura Chan (Laogeodritt)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_aren.h"
#include "keymap_sib.h"

extern keymap_config_t keymap_config;

bool process_record_base(uint16_t keycode, keyrecord_t*);

// shorthand keys
#define LOWER MO(L_LOWER)
#define RAISE MO(L_RAISE)
#define FN MO(L_FN_NUM)
#define SPACE_FN LT(L_SPACE_FN, KC_SPC)
#define ADJUST MO(L_ADJUST)
#define POLY_MTH RALT(KC_GRV)
#define POLY_GRK RALT(KC_TILD)
#define POLY_SYM RALT(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | GUI  | Alt  |  FN  |Lower |    Space    |Raise | RAlt | GRK  | MATH | SYM  |
  * `-----------------------------------------------------------------------------------'
  */
  [L_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,  KC_T,     KC_Y,     KC_U,  KC_I,    KC_O,    KC_P,      KC_BSPC,
      KC_ESC,  KC_A,    KC_S,    KC_D, KC_F,  KC_G,     KC_H,     KC_J,  KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V,  KC_B,     KC_N,     KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   SC_SENT,
      KC_LCTL, KC_LGUI, KC_LALT, FN,   LOWER, SPACE_FN, SPACE_FN, RAISE, KC_RALT, POLY_GRK, POLY_MTH, POLY_SYM
  ),

#ifdef AREN_EN_COLEMAK
  /* Colemak
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SftEnt|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | GUI  | Alt  |  FN  |Lower |    Space    |Raise | RAlt | GRK  | MATH | SYM  |
  * `-----------------------------------------------------------------------------------'
  */
  [L_COLEMAK] = LAYOUT_planck_grid(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,     KC_J,     KC_L,    KC_U,    KC_Y,     KC_SCLN,  KC_BSPC,
      KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,     KC_H,     KC_N,    KC_E,    KC_I,     KC_O,     KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_K,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  SC_SENT,
      KC_LCTL, KC_LGUI, KC_LALT, FN,      LOWER,   SPACE_FN, SPACE_FN, RAISE,   KC_RALT, POLY_GRK, POLY_MTH, POLY_SYM
  ),
#endif

#ifdef AREN_EN_DVORAK
  /* Dvorak
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |SftEnt|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | GUI  | Alt  |  FN  |Lower |    Space    |Raise | RAlt | GRK  | MATH | SYM  |
  * `-----------------------------------------------------------------------------------'
  */
  [L_DVORAK] = LAYOUT_planck_grid(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,     KC_F,     KC_G,    KC_C,    KC_R,     KC_L,     KC_BSPC,
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,     KC_D,     KC_H,    KC_T,    KC_N,     KC_S,     KC_SLSH,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,     KC_B,     KC_M,    KC_W,    KC_V,     KC_Z,     SC_SENT,
      KC_LCTL, KC_LGUI, KC_LALT, FN,      LOWER,   SPACE_FN, SPACE_FN, RAISE,   KC_RALT, POLY_GRK, POLY_MTH, POLY_SYM
  ),
#endif

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  DEL |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | ____ |      |      |   [  |   ]  |   +  |   =  |   -  |   _  |   {  |   }  |  |   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | ____ |S+NUBS|      |      |      |      |      |      |      |      |   \  | Home |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ____ | ____ | ____ | ____ |//////|    Space    | ____ | RAlt | PgDn | PgUp | End  |
  * `-----------------------------------------------------------------------------------'
  */
  [L_LOWER] = LAYOUT_ortho_4x12(
      KC_TILD, KC_EXLM,       KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
      _______, XXXXXXX,       XXXXXXX, KC_LBRC, KC_RBRC, KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE,
      _______, RSFT(KC_NUBS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_HOME,
      _______, _______,       _______, _______, _______, KC_INS,  KC_INS,  _______,  _______, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | ____ |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   -  |   .  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | NUBS |      |      |      |      |   /  |   1  |   2  |   3  |   +  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ____ | ____ | ____ | ____ | ____ |    Space    |//////| ____ | ____ | ____ | ____ |
  * `-----------------------------------------------------------------------------------'
  */
  [L_RAISE] = LAYOUT_ortho_4x12(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PDOT,
      _______, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PENT,
      _______, _______, _______, _______, _______,  KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
  ),

  /* Function and numpad (right-side keys are all numpad keycodes)
  * ,-----------------------------------------------------------------------------------.
  * | ____ |  F1  |  F2  |  F3  |  F4  |      |   6  |   7  |   8  |   9  |   0  | ____ |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  OFF |  F5  |  F6  |  F7  |  F8  |      |   *  |   4  |   5  |   6  |   -  |   .  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | ____ |  F9  |  F10 |  F11 |  F12 |      |   /  |   1  |   2  |   3  |   +  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ____ | ____ | ____ |//////|      |    Space    |      | ____ | ____ | ____ | ____ |
  * `-----------------------------------------------------------------------------------'
  */
  [L_FN_NUM] = LAYOUT_ortho_4x12(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_PEQL, KC_P7,   KC_P8, KC_P9,   KC_P0,   _______,
TG(L_FN_NUM),KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_PAST, KC_P4,   KC_P5, KC_P6,   KC_PMNS, KC_PDOT,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PSLS, KC_P1,   KC_P2, KC_P3,   KC_PPLS, KC_PENT,
    _______, _______, _______, _______, XXXXXXX, KC_SPC,  KC_SPC,  XXXXXXX, KC_P0, KC_PDOT, XXXXXXX, XXXXXXX
),

  /* Space function
  * ,-----------------------------------------------------------------------------------.
  * |PRTSC |      |  UP  |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  OFF | LEFT | DOWN | RIGHT|      |      |      | LEFT | DOWN |  UP  | RIGHT|      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |/////////////|      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [L_SPACE_FN] = LAYOUT_ortho_4x12(
      KC_PSCR, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
TG(L_SPACE_FN), KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Arrow overlay
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  OFF |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      | LEFT | DOWN |  UP  | RGHT |
  * `-----------------------------------------------------------------------------------'
  */
  [L_ARROW_OVERLAY] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TG(L_ARROW_OVERLAY), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

  #ifdef AREN_EN_SIB
    #warning "Sibelius layout needs to be updated for parity with arenthil_sibelius keymap"
  /* Sibelius base layer
  * ,-----------------------------------------------------------------------------------.
  * | UNDO |   >  |    b |  nat |   #  |./../…| NO > |   C  |   D  |   E  | REST | BKSP |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  ESC |   .  |  1/4 | half | whole| slur |  < > |   F  |   G  |   A  |   B  |   N  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | SHFT |   -  | 1/32 | 1/16 |  1/8 |  tie | line |  sym | clef |  key | time | ENTER|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | CTRL |  OS  |  ALT | EXIT | RAISE|             | LOWER| LEFT | DOWN |  UP  | RGHT |
  * `-----------------------------------------------------------------------------------'
  */
  [L_SIB_BASE] = LAYOUT_ortho_4x12(
    SIB_UNDO, A_ACENT, AC_FLAT, AC_NAT,  AC_SHRP, N_DOT,   A_NONE,  KC_C,    KC_D,    KC_E,    N_REST,  KC_BSPC,
    KC_ESC,   A_STACC, NOTE4,   NOTE2,   NOTE1,   KC_S,    KC_H,    KC_F,    KC_G,    KC_A,    KC_B,    KC_N,
    KC_LSFT,  A_TENUT, NOTE32,  NOTE16,  NOTE8,   N_TIE,   KC_L,    KC_Z,    KC_Q,    KC_K,    KC_T,    SC_SENT,
    KC_LCTL,  KC_LGUI, KC_LALT, SIB_MODE,SIB_LWR, KC_SPC,  KC_SPC,  SIB_RAI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Sibelius lower layer
  * ,-----------------------------------------------------------------------------------.
  * | ____ | rol^ |   d  | no(#)|  q#  | scoop| doit | stem2|nostem|stmlet|      | upbow|
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | ____ | roll |  db  |  (#) |  ##  | plop | fall | stem_|_stem_| _stem| swap | dnbow|
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | ____ | rolv |   Nb |  (n) |  N#  |  (.) | bend |  cue | appog| accia| slide| v1-2 |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ____ | ____ | ____ | ____ |//////|             |ADJUST|voice1|voice2|voice3|voice4|
  * `-----------------------------------------------------------------------------------'
  */
  [L_SIB_LOWER] = LAYOUT_ortho_4x12(
    _______, A_ROLU,  AC_QFLT, AC_NOCA, AC_QSHP, A_SCOOP, A_DOIT,  STEMSEC, STEM_NO, STEMLET, XXXXXXX, A_UP,
    _______, A_ROLL,  AC_3QFL, AC_CAUT, AC_3QSH, A_PLOP,  A_FALL,  STEM_I,  STEM_M,  STEM_E,  KC_X,    A_DOWN,
    _______, A_ROLD,  AC_NFLA, N_PAREN, AC_NSHP, A_PREB,  KC_J,    N_CUE,   N_APPOG, N_ACCIA, N_SLIDE, SIB_V12,
    _______, _______, _______, _______, _______, _______, _______, _______, SIB_VC1, SIB_VC2, SIB_VC3, SIB_VC4
  ),

  /* Sibelius raise layer
  * ,-----------------------------------------------------------------------------------.
  * |   o  |   ^  |  bb  | no#  |   x  |fermat| rept |   7  |   8  |   9  | trem5| tremz|
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |   +  | stcss| 1/64 | breve| long | ferm2| rept2|   4  |   5  |   6  | trem3| trem4|
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | ____ | wedge| 1/512| 1/256| 1/128| ferm3| rept4|   1  |   2  |   3  | trem1| trem2|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ____ | ____ | ____ | ____ |ADJUST|             |//////|      | ntrem|fthrac|fthrde|
  * `-----------------------------------------------------------------------------------'
  */
  [L_SIB_RAISE] = LAYOUT_ortho_4x12(
    A_OPEN,  A_MARCO,  AC_DFLT, AC_NONE, AC_DSHP, A_FERMA, REPEAT, KC_7,    KC_8,    KC_9,    TRM5,    TRM_BUZ,
    A_CLOSE, A_STAC2,  NOTE64,  NOTE0,   NOTE00,  A_FERM2, REPEA2, KC_4,    KC_5,    KC_6,    TRM3,    TRM4,
    _______, A_WEDGE,  NOTE512, NOTE256, NOTE128, A_FERM3, REPEA4, KC_1,    KC_2,    KC_3,    TRM1,    TRM2,
    _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, TRM_NXT, FTHR_AC, FTHR_DE
  ),

  #endif

  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * | RESET|QWERTY|      |      |      |      |      |      |      | AU_ON|AU_OFF|      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | DEBUG|      |      |DVORAK|      |      |      |      |      | MU_ON|MU_OFF|MU_MOD|
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |CAPSLK|  SIB |      |COLEMK|      |      |      |      |      |MID_ON|MIDOFF|      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |PLOVER|      |      |      |      |             |      |      |Voice-|Voice+|      |
  * `-----------------------------------------------------------------------------------'
  */
  [L_ADJUST] = LAYOUT_ortho_4x12(
      RESET,   QWERTY,              BL_TOGG,        BL_STEP, BL_UP,        BL_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  XXXXXXX,
      DB_TOGG, TG(L_ARROW_OVERLAY), TG(L_SPACE_FN), DVORAK,  TG(L_FN_NUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MU_ON,   MU_OFF,  MU_NEXT,
      KC_CAPS, SIB_MODE,            XXXXXXX,        COLEMAK, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MI_ON,   MI_OFF,  XXXXXXX,
      XXXXXXX, XXXXXXX,             XXXXXXX,        XXXXXXX, _______,      XXXXXXX, XXXXXXX, _______, XXXXXXX, AU_PREV, AU_NEXT, XXXXXXX
  ),

#ifdef AREN_EN_PLOVER
  /* Plover layer (http://opensteno.org)
  * ,-----------------------------------------------------------------------------------.
  * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [L_PLOVER] = LAYOUT_planck_grid(
      KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
      XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
      XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
  ),
#endif
};

#if defined(AUDIO_ENABLE)
  float qwerty_song[][2]     = SONG(QWERTY_SOUND);
  #if defined(AREN_EN_PLOVER)
    float plover_song[][2]     = SONG(PLOVER_SOUND);
    float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  #endif
  #if defined(AREN_EN_DVORAK)
    float qwerty_song[][2]     = SONG(DVORAK_SOUND);
  #endif
  #if defined(AREN_EN_COLEMAK)
    float colemak_song[][2] = SONG(COLEMAK_SOUND);
  #endif
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, L_LOWER, L_RAISE, L_ADJUST);
}

/**
 * @brief Processes custom keycodes and override behaviours. This implementation dispatches to
 * private sub-functions.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef AREN_EN_SIB
    if(SIB_KEYCODES_MIN <= keycode && keycode < SIB_KEYCODES_MAX) {
      return process_record_sib(keycode, record);
    }
    else {
      return process_record_base(keycode, record);
    }
  #else
    return process_record_base(keycode, record);
  #endif
}

/**
 * @brief Processes base layout custom keycodes.
 */
bool process_record_base(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(qwerty_song);
        #endif
        set_single_persistent_default_layer(L_QWERTY);
      }
      return true;

    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return true;

    #ifdef AREN_EN_COLEMAK
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(colemak_song);
        #endif
        set_single_persistent_default_layer(L_COLEMAK);
      }
      return true;
    #endif

    #ifdef AREN_EN_DVORAK
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(dvorak_song);
        #endif
        set_single_persistent_default_layer(L_DVORAK);
      }
      return true;
    #endif

    #ifdef AREN_EN_PLOVER
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(L_RAISE);
        layer_off(L_LOWER);
        layer_off(L_FN);
        layer_off(L_SPACE_FN);
        layer_off(L_ADJUST);
        layer_on(L_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return true;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(L_PLOVER);
      }
      return true;
    #endif

  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_PGDN);
  } else {
    tap_code(KC_PGUP);
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
