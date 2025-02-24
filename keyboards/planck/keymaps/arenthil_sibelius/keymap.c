/*
 * Layout copyright 2025 Laura Chan (Laogeodritt)
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
#include "keymap.h"

extern keymap_config_t keymap_config;

void process_tapdance_dots(tap_dance_state_t *state, void *user_data);
bool process_record_sib(uint16_t keycode, keyrecord_t* record);

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_setrgb_range(0x5b, 0xce, 0xfa, 0, 9);
    rgblight_setrgb_range(0xf5, 0xa9, 0xb8, 2, 7);
    rgblight_setrgb_at(0xff, 0xff, 0xff, 4);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Sibelius base layer
    [L_BASE] = LAYOUT_ortho_4x12(
        KC_ESC,   KC_Q,    KC_X,    KC_B,    N_REST,  AC_DSHP, AC_SHRP, A_ACENT, A_STACC, A_TENUT, N_TIE,   KC_H,
        KC_DEL,   KC_K,    KC_F,    KC_G,    KC_A,    AC_NONE, AC_NAT,  NOTE4,   NOTE2,   NOTE1,   KC_S,    KC_SPC,
        KC_LSFT,  KC_T,    KC_C,    KC_D,    KC_E,    AC_DFLT, AC_FLAT, NOTE32,  NOTE16,  NOTE8,   KC_UP,   KC_L,
        KC_LCTL,  KC_LGUI, KC_LALT, SIB_UNDO,SIB_REDO,SIB_HIDA,SIB_MIGI,KC_N,TD(TD_N_DOT),KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Sibelius left layer (hidari)
    [L_HIDARI] = LAYOUT_ortho_4x12(
        _______, A_ROLLU, TREM_N,  FTHR_DE, FTHR_AC, AC_3QSH, AC_QSHP, N_CUE,   N_APPOG, N_ACCIA, N_SLIDE, KC_J,
        _______, A_ROLL,  TREM4,   TREM5,   TREM_Z,  AC_NOCA, AC_CAUT, STEM_I,  STEM_M,  STEM_E,  A_PREB,  N_PAREN,
        _______, A_ROLLD, TREM1,   TREM2,   TREM3,   AC_3QFL, AC_QFLT, STEMSEC, STEM_NO, STEMLET, KC_ENT,  KC_Z,
        _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, SIB_V12, SIB_VC1, SIB_VC2, SIB_VC3, SIB_VC4
    ),

    // Sibelius right layer (migi)
    [L_MIGI] = LAYOUT_ortho_4x12(
        _______, A_FERMA, KC_7,    KC_8,    KC_9, A_PLOP,  A_DOIT,  A_MARCO, A_STAC2, A_WEDGE, A_OPEN,  A_CLOSE,
        _______, A_FERM2, KC_4,    KC_5,    KC_6, A_SCOOP, A_FALL,  NOTE64,  NOTE0,   NOTE00,  A_DNBOW, A_UPBOW,
        _______, A_FERM3, KC_1,    KC_2,    KC_3, AC_NFLA, AC_NSHP, NOTE512, NOTE256, NOTE128, KC_O,    KC_P,
        _______, _______, _______, KC_0,    KC_0, XXXXXXX, _______, N_DOT3,  N_DOT2,  REPEAT,  REPEAT2, REPEAT4
    ),
};


tap_dance_action_t tap_dance_actions[] = {
    [TD_N_DOT] = ACTION_TAP_DANCE_FN(process_tapdance_dots),
};


/**
 * @brief Processes custom keycodes and override behaviours. This implementation dispatches to
 * private sub-functions.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_sib(keycode, record);
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
    return true;
}


/**
 * @brief Processes Sibelius layout custom keycodes.
 */
bool process_record_sib(uint16_t keycode, keyrecord_t* record) {
    if(!record->event.pressed) return true; // no key-up handler for any of these
    switch(keycode) {
    case NOTE00:
        SEND_STRING(SIB_PAD2(X_P9));
        break;
    case NOTE0:
        SEND_STRING(SIB_PAD2(X_P8));
        break;
    case NOTE1:
        SEND_STRING(SIB_PAD1(X_P6));
        break;
    case NOTE2:
        SEND_STRING(SIB_PAD1(X_P5));
        break;
    case NOTE4:
        SEND_STRING(SIB_PAD1(X_P4));
        break;
    case NOTE8:
        SEND_STRING(SIB_PAD1(X_P3));
        break;
    case NOTE16:
        SEND_STRING(SIB_PAD1(X_P2));
        break;
    case NOTE32:
        SEND_STRING(SIB_PAD1(X_P1));
        break;
    case NOTE64:
        SEND_STRING(SIB_PAD2(X_P4));
        break;
    case NOTE128:
        SEND_STRING(SIB_PAD2(X_P5));
        break;
    case NOTE256:
        SEND_STRING(SIB_PAD2(X_P6));
        break;
    case NOTE512:
        SEND_STRING(SIB_PAD2(X_P7));
        break;
    case N_DOT:
        // Generally prefer the tapdance version to these individual keys
        SEND_STRING(SIB_PAD1(X_PDOT));
        break;
    case N_DOT2:
        SEND_STRING(SIB_PAD2(X_P2));
        break;
    case N_DOT3:
        SEND_STRING(SIB_PAD2(X_P3));
        break;
    case N_TIE:
        SEND_STRING(SIB_PAD1(X_PENT));
        break;
    case N_REST:
        SEND_STRING(SIB_PAD1(X_P0));
        break;
    case N_CUE:
        SEND_STRING(SIB_PAD2(X_PENT));
        break;
    case N_APPOG:
        SEND_STRING(SIB_PAD2(X_PSLS));
        break;
    case N_ACCIA:
        SEND_STRING(SIB_PAD2(X_PAST));
        break;
    case N_PAREN:
        SEND_STRING(SIB_PAD2(X_P1));
        break;
    case N_SLIDE:
        SEND_STRING(SIB_PAD2(X_PDOT));
        break;
    case A_NONE:
        SEND_STRING(SIB_PAD4(X_P0));
        break;
    case A_ACENT:
        SEND_STRING(SIB_PAD1(X_PSLS));
        break;
    case A_STACC:
        SEND_STRING(SIB_PAD1(X_PAST));
        break;
    case A_TENUT:
        SEND_STRING(SIB_PAD1(X_PMNS));
        break;
    case A_MARCO:
        SEND_STRING(SIB_PAD4(X_P8));
        break;
    case A_STAC2:
        SEND_STRING(SIB_PAD4(X_P9));
        break;
    case A_WEDGE:
        SEND_STRING(SIB_PAD4(X_P7));
        break;
    case A_FERMA:
        SEND_STRING(SIB_PAD4(X_P1));
        break;
    case A_FERM2:
        SEND_STRING(SIB_PAD4(X_P2));
        break;
    case A_FERM3:
        SEND_STRING(SIB_PAD4(X_P3));
        break;
    case A_DNBOW:
        SEND_STRING(SIB_PAD4(X_P6));
        break;
    case A_UPBOW:
        SEND_STRING(SIB_PAD4(X_P5));
        break;
    case A_SCOOP:
        SEND_STRING(SIB_PAD5(X_P7));
        break;
    case A_FALL:
        SEND_STRING(SIB_PAD5(X_P8));
        break;
    case A_PLOP:
        SEND_STRING(SIB_PAD5(X_P5));
        break;
    case A_DOIT:
        SEND_STRING(SIB_PAD5(X_P9));
        break;
    case A_PREB:
        SEND_STRING(SIB_PAD2(X_PMNS));
        break;
    case A_ROLL:
        SEND_STRING(SIB_PAD5(X_PSLS));
        break;
    case A_ROLLU:
        SEND_STRING(SIB_PAD5(X_PAST));
        break;
    case A_ROLLD:
        SEND_STRING(SIB_PAD5(X_PMNS));
        break;
    case A_OPEN:
        SEND_STRING(SIB_PAD4(X_PDOT));
        break;
    case A_CLOSE:
        SEND_STRING(SIB_PAD4(X_P4));
        break;
    case AC_NONE:
        SEND_STRING(SIB_PAD6(X_P0));
        break;
    case AC_CAUT:
        SEND_STRING(SIB_PAD6(X_PENT));
        break;
    case AC_NOCA:
        SEND_STRING(SIB_PAD6(X_PDOT));
        break;
    case AC_FLAT:
        SEND_STRING(SIB_PAD1(X_P9));
        break;
    case AC_NAT:
        SEND_STRING(SIB_PAD1(X_P7));
        break;
    case AC_SHRP:
        SEND_STRING(SIB_PAD1(X_P8));
        break;
    case AC_DFLT:
        SEND_STRING(SIB_PAD6(X_PAST));
        break;
    case AC_DSHP:
        SEND_STRING(SIB_PAD6(X_PSLS));
        break;
    case AC_QFLT:
        SEND_STRING(SIB_PAD6(X_P6));
        break;
    case AC_QSHP:
        SEND_STRING(SIB_PAD6(X_P5));
        break;
    case AC_3QFL:
        SEND_STRING(SIB_PAD6(X_P3));
        break;
    case AC_3QSH:
        SEND_STRING(SIB_PAD6(X_P2));
        break;
    case AC_NFLA:
        SEND_STRING(SIB_PAD6(X_P1));
        break;
    case AC_NSHP:
        SEND_STRING(SIB_PAD6(X_P4));
        break;
    case STEM_I:
        SEND_STRING(SIB_PAD3(X_P7));
        break;
    case STEM_M:
        SEND_STRING(SIB_PAD3(X_P8));
        break;
    case STEM_E:
        SEND_STRING(SIB_PAD3(X_P9));
        break;
    case STEMSEC:
        SEND_STRING(SIB_PAD3(X_PSLS));
        break;
    case STEMLET:
        SEND_STRING(SIB_PAD3(X_PMNS));
        break;
    case STEM_NO:
        SEND_STRING(SIB_PAD3(X_PAST));
        break;
    case REPEAT:
        SEND_STRING(SIB_PAD5(X_P1));
        break;
    case REPEAT2:
        SEND_STRING(SIB_PAD5(X_P2));
        break;
    case REPEAT4:
        SEND_STRING(SIB_PAD5(X_P4));
        break;
    case TREM1:
        SEND_STRING(SIB_PAD3(X_P1));
        break;
    case TREM2:
        SEND_STRING(SIB_PAD3(X_P2));
        break;
    case TREM3:
        SEND_STRING(SIB_PAD3(X_P3));
        break;
    case TREM4:
        SEND_STRING(SIB_PAD3(X_P4));
        break;
    case TREM5:
        SEND_STRING(SIB_PAD3(X_P5));
        break;
    case TREM_N:
        SEND_STRING(SIB_PAD3(X_PENT));
        break;
    case TREM_Z:
        SEND_STRING(SIB_PAD3(X_P6));
        break;
    case FTHR_AC:
        SEND_STRING(SIB_PAD3(X_P0));
        break;
    case FTHR_DE:
        SEND_STRING(SIB_PAD3(X_PDOT));
        break;
    }
    return true;
}


void process_tapdance_dots(tap_dance_state_t* state, void* user_data) {
    switch(state->count) {
        case 0: // fallthrough
        case 1:
        SEND_STRING(SIB_PAD1(X_PDOT));
        break;
        case 2:
        SEND_STRING(SIB_PAD2(X_P2));
        break;
        case 3: // fallthrough
        default:
        SEND_STRING(SIB_PAD2(X_P3));
        break;
    }
}
