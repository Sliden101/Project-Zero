#include "tigr.h"
#include "player.h"

void drawCircleFill(Tigr* screen, int cx, int cy, int r, TPixel color) {
    for (int y = -r; y <= r; y++) { // this loop create a square and condition is circle equation 
        for (int x = -r; x <= r; x++) {
            if (x * x + y * y <= r * r) {
                tigrPlot(screen, cx + x, cy + y, color);
            }
        }
    }
}
void drawPlayer(Tigr* screen, Player* player){
   drawCircleFill(screen,(int)player->x,(int)player->y,(int)player->hitboxRadius,player->color);
}

void playerMovment(Tigr* screen,Player* player){
  float speed=3.0f;
     if(tigrKeyHeld(screen,TK_RIGHT)){
        player->x+=speed;
     }
     if(tigrKeyHeld(screen,TK_LEFT)){
        player->x-=speed;
     }if(tigrKeyHeld(screen,TK_UP)){
        player->y+=speed;
     }if(tigrKeyHeld(screen,TK_DOWN)){
        player->y-=speed;
     }
}