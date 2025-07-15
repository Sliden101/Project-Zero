#include "audio.h"
#include <stdio.h>

void initAudio(AudioSystem* audio) {
    ma_result result;
    
    result = ma_engine_init(NULL, &audio->engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine\n");
        return;
    }
}

void playBgm(AudioSystem* audio, const char* filepath) {
    ma_result result;
    
    // Load and start BGM (loops automatically)
    result = ma_sound_init_from_file(
        &audio->engine,
        filepath,
        0,
        NULL,  
        NULL,  
        &audio->bgm
    );
    
    if (result != MA_SUCCESS) {
        printf("Failed to load BGM: %s\n", filepath);
        return;
    }
    
    ma_sound_start(&audio->bgm);
}

void stopBgm(AudioSystem* audio) {
    ma_sound_stop(&audio->bgm);
    ma_sound_uninit(&audio->bgm);
}

void shutdownAudio(AudioSystem* audio) {
    ma_engine_uninit(&audio->engine);
}