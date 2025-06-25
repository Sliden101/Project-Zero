#include "tigr.h"

typedef struct {
    float x, y;          // Position
    float hitboxRadius;  // Collision size
    int lives;           // Remaining lives
    int bombs;           // Bomb count (screen clear)
    int power;           // Shot power level (1-5)
    int invincibleFrames;// Frames after being hit
    int hitFlashFrames;  // Visual feedback when hit
    int focusMode;       // 0=normal, 1=focused (slow movement)
    TPixel color;        // Base color
} Player;