#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "tigr.h"
#define HIGH_SCORE_FILE "assets/high_score.txt"
 
typedef struct{
    int high_score;
 } HIGHSCORE;

int getHighScore(HIGHSCORE* highScore );
void saveHighScore(HIGHSCORE* highScore, int newScore);


#endif