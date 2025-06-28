#define MINIAUDIO_IMPLEMENTATION
#include "tigr.h"
#include "audio.h"
#include "miniaudio.h"
#include "screen.h"

void initGame(Tigr* screen, GameState* game){

    init_audio(&game->audio);
    play_bgm(&game->audio, "assets/projectzero.mp3");

    game->score = 0;
    game->gameState = 0;

    game->phase = 1;
    game->frameCount = 0;
    game->gameTime = 0;
    
    //Player Init
    initPlayer(&game->player);
    initBullets(game->bullets);

    //Boss Init
    initBoss(&game->boss);
    initBullets(game->bossBullets);

}

int main() {
    Tigr* screen = tigrWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Zero", 0);
    GameState game;

    initGame(screen, &game);
    
    while (!tigrClosed(screen)) {

        if(game.gameState==1){
            playing(screen, &game);
        } else if(game.gameState==2){
            paused(screen, &game);
        } else if(game.gameState==3){
            gameOver(screen,&game);
        } else if (game.gameState==0){
            menu(screen, &game);
        }
        tigrUpdate(screen);
    }
    
    // Cleanup
    cleanUpGame(&game);
    tigrFree(screen);
    return 0;
}
