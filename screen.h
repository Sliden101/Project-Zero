#ifndef SCREEN_H
#define SCREEN_H
#include "tigr.h"
#include "player.h"
#include "boss.h"
#include "bullet.h"
#include "audio.h"
#include "highscore.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 480

#define GAME_WIDTH 300

typedef struct {
    Player player;
    Bullet bullets[MAX_BULLETS];
    Boss boss;
    Bullet bossBullets[MAX_BULLETS];
    Highscore highScore;

    int score;
    int phase;
    int frameCount;
    float gameTime;
    int bgScrollY;
    int gameState; //0 = Menu, 1 = Playing, 2 = Paused, 3 = GameOver, 4 = Win

    Tigr* playerSprite;
    Tigr* bossSprite;
    Tigr* bulletSprites[3];
    Tigr* background;
    AudioSystem audio;
} GameState;

void menu(Tigr* screen, GameState* game);
void playing(Tigr* screen, GameState* game);
void paused(Tigr* screen, GameState* game);
void gameOver(Tigr* screen, GameState* game);
void win(Tigr* screen, GameState* game);
void cleanUpGame(GameState* game);
void drawGame(Tigr* screen, GameState* game);
#endif