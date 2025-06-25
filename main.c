#define MINIAUDIO_IMPLEMENTATION
#include "tigr.h"
#include "player.h"
#include "boss.h"
#include "bullet.h"
#include "audio.h"
#include "miniaudio.h"

#define MAX_BULLETS 2000

typedef struct {
    Player player;
    Boss boss;
    Bullet bullets[MAX_BULLETS];

    int score;
    int highScore;
    int phase;
    int frameCount;
    float gameTime;

    int gameState; //0 = Menu, 1 = Playing, 2 = Paused, 3 = GameOver, 4 = Win
    
    Tigr* playerSprite;
    Tigr* bossSprite;
    Tigr* bulletSprites[3];

    AudioSystem audio;

} GameState;

void initGame(Tigr* screen, GameState* game){
    init_audio(&game->audio);
    play_bgm(&game->audio, "assets/music.mp3");

    game->score = 0;
    game->gameState = 0;

    //Player Init
    game->player.x = 100;
    game->player.y = 100;

    game->player.hitboxRadius = 5;
    game->player.lives = 10;
    game->player.bombs = 3;
    
    game->player.invincibleFrames = 0;
    game->player.focusMode = 0;
    game->player.color = tigrRGB(0,255,255);

}

void cleanUpGame(GameState* game){
    shutdown_audio(&game->audio);
}

void menu(Tigr* screen, GameState* game){

}

void playing(Tigr* screen, GameState* game){
    tigrClear(screen, tigrRGB(255, 0, 0));
    
    drawPlayer(screen,&game->player);
    movePlayer(screen, &game->player);
    tigrRect(screen, 0, 0, 300, 480, tigrRGB(0,255,255));

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

int main() {
    Tigr* screen = tigrWindow(500, 480, "Project Zero", 0);
    GameState game;

    initGame(screen, &game);
    
    while (!tigrClosed(screen)) {

        if(game.gameState==1){
            playing(screen, &game);
        } else if(game.gameState==2){
            paused(screen, &game);
        } else if(game.gameState==3){
            gameOver(screen,&game);
        } else{
            playing(screen, &game);
        }

        tigrUpdate(screen);
    }
    
    // Cleanup
    cleanUpGame(&game);
    tigrFree(screen);
    return 0;
}
