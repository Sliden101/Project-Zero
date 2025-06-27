#pragma once
#include "tigr.h"
#include "stdint.h"

#define MAX_BULLETS 2000
#define BULLET_SPEED 8.0f

typedef struct {
    float x, y;
    float dx, dy;
    int damage;
    uint8_t active;      
} Bullet;

void initBullets(Bullet* bullets);
void spawnBullets(Bullet* bullets, float x, float y, float angle);
void updateBullets(Bullet* bullets);
void drawBullets(Tigr* screen, Bullet* bullets);