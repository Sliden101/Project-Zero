# Project Zero


## Dependencies

https://github.com/mackron/miniaudio
https://github.com/erkkah/tigr

```sh
#Windows
gcc main.c tigr.c player.c boss.c bullet.c audio.c screen.c highscore.c -o .\dist\out.exe -lgdi32 -lopengl32 -mwindows
# Linux
gcc main.c tigr.c player.c boss.c bullet.c audio.c screen.c highscore.c -o ./dist/out -lGLU -lGL -lX11 -lm && ./dist/out

```

touhou style game

player

10 health

10 damage per bullet
3 hit per second

3 bomb

boss
health 3000

3 attack patterns, stage 1-2-3


stage 1: 3000-2000

simple circle attack pattern

stage 2: 2000-1000

spiral attack pattern

stage 3: 1000-0

lasers + left right float?

story:


story lines