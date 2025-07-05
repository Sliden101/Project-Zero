#include <stdio.h>
#include "tigr.h"
#include "screen.h"
#include "highscore.h"

void menu(Tigr* screen, GameState* game){
    Tigr* picture = tigrLoadImage("assets/menu.png");

    int playRectX, quitRectX, rectY, rectW, rectH;

    playRectX = SCREEN_WIDTH/2 - 200;
    quitRectX = SCREEN_WIDTH/2 + 100;

    rectY = SCREEN_HEIGHT/2;
    rectW = 100;
    rectH = 50;

    int x = (screen->w - picture->w) / 2;
    int y = (screen->h - picture->h) / 2;

    tigrBlit(screen, picture, x, y, 0, 0, picture->w, picture->h);

    tigrRect(screen, playRectX, rectY, rectW, rectH, tigrRGB(0,255,255));
    tigrRect(screen, quitRectX, rectY, rectW, rectH, tigrRGB(255,0,255));
    
    tigrPrint(screen,tfont,SCREEN_WIDTH/2 - 165,SCREEN_HEIGHT/2+20, tigrRGB(0,255,255),"PLAY");
    tigrPrint(screen,tfont,SCREEN_WIDTH/2 + 135,SCREEN_HEIGHT/2+18, tigrRGB(0,255,255),"QUIT");

    int mouseX, mouseY, buttons;

    tigrMouse(screen, &mouseX, &mouseY, &buttons);

    int isOverPlay = mouseX >= playRectX && mouseX < playRectX + rectW && mouseY >= rectY && mouseY < rectY + rectH;
    if(isOverPlay && (buttons & 1)){
        game->gameState=1;
    }

    int isOverQuit = mouseX >= quitRectX && mouseX < quitRectX + rectW && mouseY >= rectY && mouseY < rectY + rectH;

    if(isOverQuit && (buttons & 1)){
        cleanUpGame(game);
        tigrFree(screen); 
    }

    tigrFree(picture);    
}


void playing(Tigr* screen, GameState* game){

    //Screen
    getHighScore(&game->highScore);
    tigrClear(screen, tigrRGB(0, 0, 0));
    tigrRect(screen, 0, 0, GAME_WIDTH, SCREEN_HEIGHT, tigrRGB(0,255,255));
    //Show Stats
    char score[50];
    char lives[50];
    char bomb[50];
    char highScore[50];
    sprintf(score,"SCORE %d",game->score);
    sprintf(lives,"Lives Left: %d",game->player.lives);
    sprintf(bomb,"Bombs Left: %d",game->player.bombs);
    sprintf(highScore,"High Score  %d",game->highScore);
    tigrPrint(screen,tfont,SCREEN_WIDTH/2+90,SCREEN_HEIGHT/2-220,tigrRGB(0,0,255),score);
    tigrPrint(screen,tfont,SCREEN_WIDTH/2+90,SCREEN_HEIGHT/2-200,tigrRGB(0,0,255),lives); 
    tigrPrint(screen,tfont,SCREEN_WIDTH/2+90,SCREEN_HEIGHT/2-180,tigrRGB(0,0,255),bomb); 
    tigrPrint(screen,tfont,SCREEN_WIDTH/2+90,SCREEN_HEIGHT/2-160,tigrRGB(0,255,255),highScore);
    //Player
    drawPlayer(screen,&game->player);
    movePlayer(screen, &game->player);

    //Boss

    shootAtBoss(screen, &game->player, game->bullets, game->boss.x , game->boss.y);
    updateBullets(game->bullets);
    drawBullets(screen, game->bullets);
    

    updateBoss(&game->boss, game->bossBullets, game->player.x, game->player.y);
    updateBullets(game->bossBullets);

    drawBullets(screen, game->bossBullets);
    drawBoss(screen, &game->boss);

    saveHighScore(&game->highScore,game->score);


    if(tigrKeyDown(screen, 'X')&&game->player.bombs>0){
        bombClear(game->bossBullets);
        game->player.bombs--;
    }

    for(int i = 0; i <MAX_BULLETS; i++){
        if(game->bullets[i].active&&checkCollision(game->bullets[i].x, game->bullets[i].y, 3, game->boss.x, game->boss.y, game->boss.hitboxRadius)){
            game->boss.health -= game->bullets[i].damage;
            game->bullets[i].active = 0;
            printf("Player bullet hit boss! Health: %d\n", game->boss.health);
            game->score += 10;
        }
        if(game->bossBullets[i].active&&checkCollision(game->bossBullets[i].x, game->bossBullets[i].y, game->bossBullets[i].size, game->player.x, game->player.y, game->player.hitboxRadius)){
            game->player.lives--;
            game->bossBullets[i].active=0;
            printf("Boss bullet hit Player! Lives: %d\n", game->player.lives);
        }
    }
    
    //Gameover
    if(game->player.lives<=0){
        game->gameState=3;
    }

    //Win Condition
    if(game->boss.health<=0){
        game->gameState=4;
    }


    //Return to menu
    if(tigrKeyDown(screen, 'B')){
        game->gameState=0;
    }
    if(tigrKeyDown(screen,'P')){
        game->gameState=2;
    }
}

void paused(Tigr* screen, GameState* game){
    if(tigrKeyDown(screen,'P')){
        game->gameState=1;
    }
    tigrFill(screen, 0, 0, GAME_WIDTH+10, SCREEN_HEIGHT, tigrRGB(20,20,20));
    tigrFill(screen, 0, 0, GAME_WIDTH+10, SCREEN_HEIGHT, tigrRGB(50,50,50));

    tigrPrint(screen,tfont,SCREEN_WIDTH/2-120,SCREEN_HEIGHT/2-45,tigrRGB(0,255,255),"PAUSED");

}
void gameOver(Tigr* screen, GameState* game){
    Tigr* picture = tigrLoadImage("assets/gameover.png");

    int x = (screen->w - picture->w) / 2;
    int y = (screen->h - picture->h) / 2;

    tigrBlit(screen, picture, x, y, 0, 0, picture->w, picture->h);
    saveHighScore(&game->highScore,game->score);
    tigrFree(picture);
}

void win(Tigr* screen, GameState* game){
    Tigr* picture = tigrLoadImage("assets/win.png");

    int x = (screen->w - picture->w) / 2;
    int y = (screen->h - picture->h) / 2;

    tigrBlit(screen, picture, x, y, 0, 0, picture->w, picture->h);

    //Stage Clear
    tigrPrint(screen,tfont,SCREEN_WIDTH/4+90,SCREEN_HEIGHT/2-220,tigrRGB(252,163,17),"STAGE CLEAR");

    char score[50];
    sprintf(score,"SCORE %d",game->score);
    tigrPrint(screen,tfont,SCREEN_WIDTH/2+90,SCREEN_HEIGHT/2-220,tigrRGB(0,0,255),score);
    saveHighScore(&game->highScore,game->score);


    tigrFree(picture);

}

void cleanUpGame(GameState* game){
    shutdown_audio(&game->audio);
}
