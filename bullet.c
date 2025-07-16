#include "bullet.h"
#include <stdbool.h>
#include "math.h"

void initBullets(Bullet* bullets){
    for(int i = 0; i < MAX_BULLETS;i++){
        bullets[i].active = 0;
    }
}

void spawnBullets(Bullet* bullets, int size, float x, float y, float angle){
    for(int i = 0; i< MAX_BULLETS; i++){
        if(!bullets[i].active){
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].dx = cosf(angle) * BULLET_SPEED;
            bullets[i].dy = sinf(angle) * BULLET_SPEED;
            bullets[i].size = size;
            bullets[i].active = 1;
            bullets[i].damage = PLAYER_DAMAGE;
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

void drawBossBullets(Tigr* screen, Bullet* bullets){
    Tigr* bullet=tigrLoadImage("assets/bullet.png");
    for(int i = 0; i<MAX_BULLETS;i++){
        if(bullets[i].active){
            tigrFillCircle(screen, bullets[i].x, bullets[i].y, bullets[i].size, tigrRGB(248,216,49));
            tigrBlitAlpha(screen,bullet,bullets[i].x-15,bullets[i].y-20,0,0,bullet->w,bullet->h,1.0f);
        }
    }
}

void drawPlayerBullets(Tigr* screen, Bullet* bullets){
    Tigr* bullet = tigrLoadImage("assets/playerbullet.png");
    for(int i = 0; i<MAX_BULLETS;i++){
        if(bullets[i].active){
            tigrFillCircle(screen, bullets[i].x, bullets[i].y, bullets[i].size, tigrRGB(248,216,49));
            tigrBlitAlpha(screen,bullet,bullets[i].x-10,bullets[i].y,0,0,bullet->w,bullet->h,1.0f);
        }
    }
}

bool checkCollision(float x1, float y1, float r1, float x2, float y2, float r2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    float distanceSquared = dx*dx + dy*dy;
    float radiusSum = r1 + r2;
    return distanceSquared <= (radiusSum * radiusSum);
}

void bombClear(Bullet* bullets){
    for(int i = 0; i<MAX_BULLETS;i++){
        bullets[i].active = 0;
    }
}