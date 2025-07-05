#include "highscore.h"
#include <stdlib.h>
#include <stdio.h>

int getHighScore(Highscore* highScore){
    FILE *file=fopen(HIGH_SCORE_FILE,"r");
    if(file!=NULL){
       fscanf(file,"%d",&highScore->high_score);
       fclose(file);
    }
    else{
       highScore->high_score=0;
    }
    if(file==NULL){
      printf("Error opening");
    }
    return highScore->high_score;
}

void saveHighScore(Highscore* highScore,int newScore){
    getHighScore(highScore);
   if(newScore>highScore->high_score){
         FILE *file=fopen(HIGH_SCORE_FILE,"w");
      if(file!=NULL){
         fprintf(file,"%d",newScore);
         fclose(file);
         highScore->high_score=newScore;
      }
      else {
         printf("Failed to open high score file ");
      }
   }
}