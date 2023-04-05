#ifndef TWOPLAYER16__H
#define TWOPLAYER16__H


#include <SDL.h>
#include <SDL_mixer.h>
#include "SDL_utils.h"

void draw_MAP(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void playOneGame2Player16(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);

#endif // 2PLAYER16__H
