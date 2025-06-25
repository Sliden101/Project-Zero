#include "tigr.h"
#include "bullet.h"

typedef struct {
    float x, y;
    float hitboxRadius;  
    float speed;
    float angle;         //Direction radians
    int type;            // 0 = Player Bullet, 1 = Enemy Bullet, 
    int active;          // 0 = Inactive, 1 = Active
    TPixel color;        
} Bullet;
