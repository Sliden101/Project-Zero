#include "boss.h"
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
        .color = tigrRGB(200, 50, 50)
    };
}

void updateBoss(Boss* boss, Bullet* bullets, float playerX, float playerY) {
    boss->patternTimer++;
    
    switch (boss->phase) {
        case 1: 
            if (boss->patternTimer % 5 == 0) {
                float angle = boss->patternTimer * 0.1f;
                for (int i = 0; i < 3; i++) {
                    spawnBossBullet(bullets, 10, boss->x, boss->y, angle + i * (2*M_PI/3), PHASE_ONE_SPEED);
                }
            }
            break;
            
        case 2:
            if (boss->patternTimer % 30 == 0) {
                float aimAngle = atan2f(playerY - boss->y, playerX - boss->x);
                spawnBossBullet(bullets, 20, boss->x, boss->y, aimAngle, PHASE_TWO_SPEED);
                for (int i = 0; i < 8; i++) {
                    spawnBossBullet(bullets, 20, boss->x, boss->y, i * (2*M_PI/8), PHASE_TWO_SPEED);
                }
            }
            break;
    }
    
    if (boss->health < boss->maxHealth/2 && boss->phase == 1) {
        boss->phase = 2;
        boss->color = tigrRGB(255, 100, 100);
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