#include "tigr.h"
#include "player.h"
#include "math.h"

void initPlayer(Player* player){
   *player = (Player){
      .x = 285/2,
      .y = 480-60,
      .hitboxRadius = 3.0f,
      .lives = 10,
      .bombs = 3,
      .color = tigrRGB(0, 255, 255),
      .shootDelay = 10,
      .shootCooldown = 0,
   };
}

void drawPlayer(Tigr* screen, Player* player){
   Tigr* picture=tigrLoadImage("assets/sprite.png");
   tigrBlitAlpha(screen,picture, player->x-15, player->y-15, 0, 0, picture->w, picture->h, 1.0f);
   tigrFillCircle(screen, (int)player->x, (int)player->y, (int)player->hitboxRadius, player->color);

}

void movePlayer(Tigr* screen,Player* player){
   float speed=3.0f; float shift_speed=1.0f;
   if(tigrKeyHeld(screen,TK_SHIFT)){
      player->focusMode=1;
   }
   else {
      player->focusMode=0;
   }
   float currentSpeed=(player->focusMode==1)? shift_speed:speed;
     if(tigrKeyHeld(screen,TK_RIGHT)&&player->x+player->hitboxRadius<(float)(280-3)){
        player->x+=currentSpeed;
     }
     if(tigrKeyHeld(screen,TK_LEFT)&&player->x-player->hitboxRadius >10){
        player->x-=currentSpeed;
     }
     if(tigrKeyHeld(screen,TK_UP)&&player->y-player->hitboxRadius>10){
        player->y-=currentSpeed;
     }
     if(tigrKeyHeld(screen,TK_DOWN)&&player->y+player->hitboxRadius<(float)(455-3)){
        player->y+=currentSpeed;
     }
}

void shootAtBoss(Tigr* screen,Player* player, Bullet* bullets, float bossX, float bossY){
   if(player->focusMode==1){
      player->shootDelay = 5;
   } else {
      player->shootDelay = 10;
   }
   if(player->shootCooldown>0){
      player->shootCooldown--;
      return; // Skip basically
   }

   if(tigrKeyHeld(screen, 'Z')){
      float angle = atan2f(bossY - player->y, bossX - player->x);
      spawnPlayerBullets(bullets, 3, player->x, player->y, angle);
   }

   player->shootCooldown = player->shootDelay;
}

