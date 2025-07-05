#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "tigr.h"
#define HIGH_SCORE_FILE "assets/high_score.txt"
 
typedef struct{
    int high_score;
 } Highscore;

int getHighScore(Highscore* highScore );
void saveHighScore(Highscore* highScore, int newScore);


#endif