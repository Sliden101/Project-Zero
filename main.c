#define MINIAUDIO_IMPLEMENTATION
#include "tigr.h"
#include "audio.h"
#include "miniaudio.h"
#include "screen.h"

void initGame(Tigr* screen, GameState* game){

    init_audio(&game->audio);
    play_bgm(&game->audio, "assets/badapple.mp3");

    game->score = 0;
    game->gameState = 0;

    game->phase = 1;
    game->frameCount = 0;
    game->gameTime = 0;
    
    //Player Init
    game->player.x = GAME_WIDTH/2;
    game->player.y = SCREEN_HEIGHT-50;

    game->player.hitboxRadius = 3;
    game->player.lives = 10;
    game->player.bombs = 3;
    
    game->player.invincibleFrames = 0;
    game->player.focusMode = 0;
    game->player.color = tigrRGB(0,255,255);

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
            playing(screen, &game);
        }
        tigrUpdate(screen);
    }
    
    // Cleanup
    cleanUpGame(&game);
    tigrFree(screen);
    return 0;
}
