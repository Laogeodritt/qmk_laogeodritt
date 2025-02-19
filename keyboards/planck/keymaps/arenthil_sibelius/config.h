#pragma once

#ifdef AUDIO_ENABLE
    /*
     * Composer: Jean Sibelius
     * Title: Violin Concerto in D minor, Op. 47
     * Status: Public Domain (US, Canada)
     */
    #define STARTUP_SONG SONG( \
        MUSICAL_NOTE(_G5, 32+16+8), E__NOTE(_A5), MUSICAL_NOTE(_D5, 32+32+8), S__NOTE(_REST), \
        Q__NOTE(_D5), QD_NOTE(_F5), MUSICAL_NOTE(_E5, 3), MUSICAL_NOTE(_F5, 3), MUSICAL_NOTE(_E5, 2), \
        MUSICAL_NOTE(_D5, 32+32+8), \
    );
    // #define STARTUP_SONG SONG(CAMPANELLA)
    // #define STARTUP_SONG SONG(NO_SOUND)
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define TAPPING_TERM 200
