#pragma once

#ifdef AUDIO_ENABLE
    /*
     * Composer: Jean Sibelius
     * Title: Violin Concerto in D minor, Op. 47
     * Status: Public Domain (US, Canada)
     */
    #define STARTUP_SONG SONG( \
        MUSICAL_NOTE(_G5, 32+16+8), Q__NOTE(_A5), MUSICAL_NOTE(_D5, 32+32+8), S__NOTE(_REST), \
        Q__NOTE(_D5), HD_NOTE(_F5), MUSICAL_NOTE(_E5, 5), MUSICAL_NOTE(_F5, 5), MUSICAL_NOTE(_E5, 6), \
        MUSICAL_NOTE(_D5, 32+32+8) \
    );
    // #define STARTUP_SONG SONG(CAMPANELLA)
    // #define STARTUP_SONG SONG(NO_SOUND)
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define TAPPING_TERM 200

// Default 120BPM seems more like 200+ BPM... quick fix here
#define TEMPO_DEFAULT 60

/*
 * Original indices:
 * -----------------
 * | 6   5   4   3 |
 * |       0       |
 * | 7   8   1   2 |
 * -----------------
 *
 * Mapped indices:
 * -----------------
 * | 0   2   5   7 |
 * |       4       |
 * | 1   3   6   8 |
 * -----------------
 */
#define RGBLIGHT_LED_MAP { 6, 7, 5, 8, 0, 4, 1, 3, 2 }
