#pragma once // dont reintialize some stuff i guess
#include "tigr.h"
#include "stdint.h"
#include <stdbool.h>

#define MAX_BULLETS 2000
#define BULLET_SPEED 10.0f
#define PLAYER_DAMAGE 200

typedef struct {
    float x, y;
    float dx, dy;
    int damage;
    int size;
    uint8_t active;    
    TPixel color;
} Bullet;

void initBullets(Bullet* bullets);
void bombClear(Bullet* bullets);
void spawnPlayerBullets(Bullet* bullets,int size, float x, float y, float angle);
void spawnBossBullet(Bullet* bullets, int size, float x, float y, float angle, float speed);
void updateBullets(Bullet* bullets);
void drawBossBullets(Tigr* screen, Bullet* bullets);
void drawPlayerBullets(Tigr* screen, Bullet* bullets);
bool checkCollision(float x1, float y1, float r1, float x2, float y2, float r2);