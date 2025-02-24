#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MIDI_BASIC

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// Default 120BPM seems more like 200+ BPM... quick fix here
#define TEMPO_DEFAULT 60

// Enable sibelius mode
// TODO: enable once arenthil_sibelius is ported over
//#define AREN_EN_SIB
