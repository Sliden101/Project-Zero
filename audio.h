#pragma once
#include "miniaudio.h"

typedef struct {
    ma_engine engine;
    ma_sound bgm;
} AudioSystem;

void initAudio(AudioSystem* audio);
void playBgm(AudioSystem* audio, const char* filepath);
void stopBgm(AudioSystem* audio);
void shutdownAudio(AudioSystem* audio);