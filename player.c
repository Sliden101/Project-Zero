#include "tigr.h"
#include "player.h"

void drawPlayer(Tigr* screen, Player* player){
   tigrCircle(screen, (int)player->x, (int)player->y, (int)player->hitboxRadius, player->color);
   tigrFillCircle(screen, (int)player->x, (int)player->y, (int)player->hitboxRadius, player->color);
   // drawCircleFill(screen,(int)player->x,(int)player->y,(int)player->hitboxRadius,player->color);
}

void movePlayer(Tigr* screen,Player* player){
  float speed=3.0f;
     if(tigrKeyHeld(screen,TK_RIGHT)){
        player->x+=speed;
     }
     if(tigrKeyHeld(screen,TK_LEFT)&&player->x-player->hitboxRadius > 0){
        player->x-=speed;
     }if(tigrKeyHeld(screen,TK_UP)){
        player->y-=speed;
     }if(tigrKeyHeld(screen,TK_DOWN)){
        player->y+=speed;
     }
}