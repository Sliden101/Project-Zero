#include "tigr.h"
#include "bullet.h"

typedef struct {
    float x, y;          // Position
    float hitboxRadius;  // Collision size
    int lives;           // Remaining lives
    int bombs;           // Bomb count (screen clear)
    int invincibleFrames;// Frames after being hit
    int focusMode;       // 0=normal, 1=focused (slow movement)
    int shootCooldown;
    int shootDelay;
    TPixel color;        // Base color
} Player;

void initPlayer(Player* player);
void drawPlayer(Tigr* screen, Player* player); // initialize player
void movePlayer(Tigr* screen,Player* player); // movement
void shootAtBoss(Tigr* screen, Player* player, Bullet* bullets, float bossX, float bossY); 