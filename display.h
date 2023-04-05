#ifndef DISPLAY__H
#define DISPLAY__H

#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"

void draw_Bg(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT );

void endGame(SDL_Renderer* renderer);

int returnn(SDL_Renderer* renderer);

#endif // DISPLAY__H
