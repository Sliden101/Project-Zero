#include "tigr.h"
#include "player.h"

void drawPlayer(Tigr* screen, Player* player){
   tigrCircle(screen, (int)player->x, (int)player->y, (int)player->hitboxRadius, player->color);
   // tigrFillCircle(screen, (int)player->x, (int)player->y, (int)player->hitboxRadius, player->color);
   // drawCircleFill(screen,(int)player->x,(int)player->y,(int)player->hitboxRadius,player->color);
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
     if(tigrKeyHeld(screen,TK_RIGHT)&&player->x+player->hitboxRadius<(float)(300-3)){
        player->x+=currentSpeed;
     }
     if(tigrKeyHeld(screen,TK_LEFT)&&player->x-player->hitboxRadius > 0){
        player->x-=currentSpeed;
     }
     if(tigrKeyHeld(screen,TK_UP)&&player->y-player->hitboxRadius>0){
        player->y-=currentSpeed;
     }
     if(tigrKeyHeld(screen,TK_DOWN)&&player->y+player->hitboxRadius<(float)(480-3)){
        player->y+=currentSpeed;
     }
   }
   
    

