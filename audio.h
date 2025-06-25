#pragma once
#include "miniaudio.h"

typedef struct {
    ma_engine engine;
    ma_sound bgm;
} AudioSystem;

void init_audio(AudioSystem* audio);
void play_bgm(AudioSystem* audio, const char* filepath);
void stop_bgm(AudioSystem* audio);
void shutdown_audio(AudioSystem* audio);