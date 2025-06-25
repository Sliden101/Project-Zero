#include "tigr.h"
#include "player.h"

typedef struct {
    float x, y;          // Position
    float hitboxRadius;  // Collision size
    int lives;           // Remaining lives
    int bombs;           // Bomb count (screen clear)
    int invincibleFrames;// Frames after being hit
    int focusMode;       // 0=normal, 1=focused (slow movement)
    TPixel color;        // Base color
} Player;