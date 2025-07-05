#include "boss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initBoss(Boss* boss) {
    *boss = (Boss){
        .x = 150.0f,
        .y = 100.0f,
        .health = BOSS_HEALTH,
        .maxHealth = BOSS_HEALTH,
        .hitboxRadius = BOSS_HITBOX_RADIUS,
        .phase = 1,
        .patternTimer = 0,
        .movementTimer = 0,
        .moveXDirection = 1,
        .moveYDirection = 1,
        .color = tigrRGB(200, 50, 50)
    };
}

void updateBoss(Boss* boss, Bullet* bullets, float playerX, float playerY) {
    boss->patternTimer++;
    boss->movementTimer++;

    //Movement
    if (boss->movementTimer % 10 == 0) {
        if (rand() % 2 == 0 || boss->x < 50) {
            boss->moveXDirection = 1; // Right
        } else if (boss->x > 200) {
            boss->moveXDirection = -1; // Left
        }
    }
    
    boss->x += boss->moveXDirection * 1.5f;

    if (boss->x < 20) boss->x = 20;
    if (boss->x > 280) boss->x = 280;


    //Implement rectangle

    //Attack Patterns
    
    switch (boss->phase) {
        case 1: 
            //Spiral
            if (boss->patternTimer % 5 == 0) {
                float angle = boss->patternTimer * 0.1f;
                for (int i = 0; i < 3; i++) {
                    spawnBossBullet(bullets, 10, boss->x, boss->y, angle + i * (2*M_PI/3), PHASE_ONE_SPEED);
                }
            }
            //Burst shotgun
            if(boss->patternTimer % 90 == 0){
                float aimAngle = atan2f(playerY - boss->y, playerX - boss->x);
                for(int i = -2; i<=2;i++){
                    spawnBossBullet(bullets, 12, boss->x, boss->y, aimAngle + i * 0.2f, PHASE_ONE_SPEED * 1.5f);
                }
            }
            break;
        
        case 2:
            //Aimed Circle    
            if (boss->patternTimer % 30 == 0) {
                float aimAngle = atan2f(playerY - boss->y, playerX - boss->x);
                spawnBossBullet(bullets, 15, boss->x, boss->y, aimAngle, PHASE_TWO_SPEED);
                for (int i = 0; i < 8; i++) {
                    spawnBossBullet(bullets,15, boss->x, boss->y, i * (2*M_PI/8), PHASE_TWO_SPEED);
                }
            }
            break;
        case 3:
            if (boss->patternTimer % 3 == 0) {
                float angle = -boss->patternTimer * 0.2f;
                float radius = 5 + (boss->patternTimer % 30) * 0.5f;
                for (int i = 0; i < 4; i++) {
                    spawnBossBullet(bullets, 8, 
                                   boss->x + cosf(angle + i*M_PI/2) * radius,
                                   boss->y + sinf(angle + i*M_PI/2) * radius,
                                   angle + i*M_PI/2, PHASE_THREE_SPEED);
                }
            }

    }
    
    if (boss->health < boss->maxHealth * 0.75f && boss->phase == 1) {
        boss->phase = 2;
        boss->color = tigrRGB(255, 100, 100);
        boss->patternTimer = 0;
    }
    else if (boss->health < boss->maxHealth * 0.5f && boss->phase == 2) {
        boss->phase = 3;
        boss->color = tigrRGB(255, 50, 150);
        boss->patternTimer = 0;
    }

}

void drawBoss(Tigr* screen, Boss* boss) {
    tigrFillCircle(screen, boss->x, boss->y, boss->hitboxRadius, boss->color);
    
    float healthPercent = (float)boss->health / boss->maxHealth;
    tigrFillRect(screen, boss->x - 50, boss->y - 40, 100 * healthPercent, 5, 
                tigrRGB(255 * (1-healthPercent), 255 * healthPercent, 0));
}

void spawnBossBullet(Bullet* bullets, int size, float x, float y, float angle, float speed) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            bullets[i] = (Bullet){
                .x = x,
                .y = y,
                .dx = cosf(angle) * speed,
                .dy = sinf(angle) * speed,
                .size = size,
                .active = 1,
                .damage = 1,
                .color = tigrRGB(255, 100, 100)
            };
            return;
        }
    }
}