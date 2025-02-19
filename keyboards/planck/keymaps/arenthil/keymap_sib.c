#include "keymap_sib.h"

#define SIB_PAD1(KEY) (SS_TAP(X_F7) SS_TAP(KEY))
#define SIB_PAD2(KEY) (SS_TAP(X_F8) SS_TAP(KEY))
#define SIB_PAD3(KEY) (SS_TAP(X_F9) SS_TAP(KEY))
#define SIB_PAD4(KEY) (SS_TAP(X_F10) SS_TAP(KEY))
#define SIB_PAD5(KEY) (SS_TAP(X_F11) SS_TAP(KEY))
#define SIB_PAD6(KEY) (SS_TAP(X_F12) SS_TAP(KEY))

#ifdef AUDIO_ENABLE
  /*
   * Composer: Jean Sibelius
   * Title: Violin Concerto in D minor, Op. 47
   * Status: Public Domain (US, Canada)
   */
  float sib_song[][2]     = SONG(
    MUSICAL_NOTE(_G5, 32+16+8), E__NOTE(_A5), MUSICAL_NOTE(_D5, 32+32+8), S__NOTE(_REST),
    Q__NOTE(_D5), QD_NOTE(_F5), MUSICAL_NOTE(_E5, 3), MUSICAL_NOTE(_F5, 3), MUSICAL_NOTE(_E5, 2),
    MUSICAL_NOTE(_D5, 32+32+8),
  );
  float sib_off_song[][2] = SONG(QWERTY_SOUND);
#endif

/**
 * @brief Processes Sibelius layout custom keycodes.
 */
bool process_record_sib(uint16_t keycode, keyrecord_t* record) {
  if(!record->event.pressed) return true; // not handling key-up for any of the below
  switch(keycode) {
  case SIB_MODE:
    #ifdef AREN_EN_SIB
        #ifdef AUDIO_ENABLE
        stop_all_notes();
        if(IS_LAYER_OFF(L_SIB_BASE))
            PLAY_SONG(sib_song);
        else
            PLAY_SONG(sib_off_song);
        #endif
        layer_invert(L_SIB_BASE);
    #endif // AREN_EN_SIB
    break;
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
    // TODO: figure out tapdancing for this
    SEND_STRING(SIB_PAD1(X_PDOT));
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
  case A_DOWN:
    SEND_STRING(SIB_PAD4(X_P6));
    break;
  case A_UP:
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
  case A_ROLU:
    SEND_STRING(SIB_PAD5(X_PAST));
    break;
  case A_ROLD:
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
  case REPEA2:
    SEND_STRING(SIB_PAD5(X_P2));
    break;
  case REPEA4:
    SEND_STRING(SIB_PAD5(X_P4));
    break;
  case N_SLIDE:
    SEND_STRING(SIB_PAD2(X_PDOT));
    break;
  case TRM1:
    SEND_STRING(SIB_PAD3(X_P1));
    break;
  case TRM2:
    SEND_STRING(SIB_PAD3(X_P2));
    break;
  case TRM3:
    SEND_STRING(SIB_PAD3(X_P3));
    break;
  case TRM4:
    SEND_STRING(SIB_PAD3(X_P4));
    break;
  case TRM5:
    SEND_STRING(SIB_PAD3(X_P5));
    break;
  case TRM_NXT:
    SEND_STRING(SIB_PAD3(X_PENT));
    break;
  case TRM_BUZ:
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
