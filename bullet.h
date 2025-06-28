#pragma once // dont reintialize some stuff i guess
#include "tigr.h"
#include "stdint.h"

#define MAX_BULLETS 2000
#define BULLET_SPEED 8.0f

typedef struct {
    float x, y;
    float dx, dy;
    int damage;
    uint8_t active;    
    TPixel color;
} Bullet;

void initBullets(Bullet* bullets);
void spawnBullets(Bullet* bullets, float x, float y, float angle);
void updateBullets(Bullet* bullets);
void drawBullets(Tigr* screen, Bullet* bullets);
int checkCollision(float x1, float y1, float r1, float x2, float y2, float r2);