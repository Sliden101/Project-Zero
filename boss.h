#pragma once
#include "tigr.h"
#include "bullet.h"
#include "math.h"

#define BOSS_HEALTH 6000
#define BOSS_HITBOX_RADIUS 10

#define PHASE_ONE_SPEED 2.0f
#define PHASE_TWO_SPEED 2.5f
#define PHASE_THREE_SPEED 3.0f


#define PHASE_ONE_SIZE 10
#define PHASE_TWO_SIZE 6
#define PHASE_THREE_SIZE_SPREAD 10
#define PHASE_THREE_SIZE_SHOTGUN 12


typedef struct {
    float x, y;
    int health;
    int maxHealth;
    float hitboxRadius;
    int phase;
    int patternTimer;
    int movementTimer;
    int moveXDirection;    
    int moveYDirection;
    TPixel color;
} Boss;

void initBoss(Boss* boss);
void updateBoss(Boss* boss, Bullet* bullets, float playerX, float playerY);
void drawBoss(Tigr* screen, Boss* boss);
void spawnBossBullet(Bullet* bullets, int size, float x, float y, float angle, float speed);