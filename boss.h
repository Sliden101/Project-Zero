#pragma once
#include "tigr.h"
#include "bullet.h"
#include "math.h"

#define BOSS_HEALTH 3000
#define BOSS_HITBOX_RADIUS 4
#define PHASE_ONE_SPEED 3.0f
#define PHASE_TWO_SPEED 5.0f

typedef struct {
    float x, y;
    int health;
    int maxHealth;
    float hitboxRadius;
    int phase;
    int patternTimer;
    TPixel color;
} Boss;

void initBoss(Boss* boss);
void updateBoss(Boss* boss, Bullet* bullets, float playerX, float playerY);
void drawBoss(Tigr* screen, Boss* boss);
void spawnBossBullet(Bullet* bullets, int size, float x, float y, float angle, float speed);