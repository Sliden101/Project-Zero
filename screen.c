#include "tigr.h"
#include "screen.h"

void menu(Tigr* screen, GameState* game){
    Tigr* picture = tigrLoadImage("assets/menu.png");

    int playRectX, quitRectX, rectY, rectW, rectH;

    playRectX = SCREEN_WIDTH/2 - 200;
    quitRectX = SCREEN_WIDTH/2 + 100;

    rectY = SCREEN_HEIGHT/2;
    rectW = 100;
    rectH = 50;

    rectY = SCREEN_HEIGHT/2;

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
    tigrClear(screen, tigrRGB(255, 0, 0));


    drawPlayer(screen,&game->player);
    movePlayer(screen, &game->player);
    tigrRect(screen, 0, 0, GAME_WIDTH, SCREEN_HEIGHT, tigrRGB(0,255,255));

    //Return to menu
    if(tigrKeyDown(screen, 'B')){
        game->gameState=0;
    }
}

void paused(Tigr* screen, GameState* game){

}
void gameOver(Tigr* screen, GameState* game){
    Tigr* picture = tigrLoadImage("assets/gameover.png");

    int x = (screen->w - picture->w) / 2;
    int y = (screen->h - picture->h) / 2;

    tigrBlit(screen, picture, x, y, 0, 0, picture->w, picture->h);
    tigrFree(picture);
}

void win(Tigr* screen, GameState* game);

void cleanUpGame(GameState* game){
    shutdown_audio(&game->audio);
}
