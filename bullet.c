#include "bullet.h"
#include "math.h"

void initBullets(Bullet* bullets){
    for(int i = 0; i < MAX_BULLETS;i++){
        bullets[i].active = 0;
    }
}

void spawnBullets(Bullet* bullets, float x, float y, float angle){
    for(int i = 0; i< MAX_BULLETS; i++){
        if(!bullets[i].active){
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].dx = cosf(angle) * BULLET_SPEED;
            bullets[i].dy = sinf(angle) * BULLET_SPEED;
            bullets[i].active = 1;
            bullets[i].damage = 100;
            return;
        }
    }
}

void updateBullets(Bullet* bullets){
    for(int i = 0; i<MAX_BULLETS;i++){
        if (bullets[i].active) {
            bullets[i].x += bullets[i].dx;
            bullets[i].y += bullets[i].dy;
        } 

        if(bullets[i].x < 0||bullets[i].x > 300 || bullets[i].y < 0 || bullets[i].y > 480){
            bullets[i].active = 0;
        }

    }
}

void drawBullets(Tigr* screen, Bullet* bullets){
    for(int i = 0; i<MAX_BULLETS;i++){
        if(bullets[i].active){
            tigrFillCircle(screen, bullets[i].x, bullets[i].y, 3, tigrRGB(248,216,49));
        }
    }
}

int checkCollision(float x1, float y1, float r1, float x2, float y2, float r2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    float distanceSquared = dx*dx + dy*dy;
    float radiusSum = r1 + r2;
    return distanceSquared < (radiusSum * radiusSum);
}