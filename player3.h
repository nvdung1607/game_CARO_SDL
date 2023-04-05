#ifndef ONEPLAYER__H
#define ONEPLAYER__H

#include <SDL.h>
#include "SDL_utils.h"
#include "display.h"
#include <SDL_mixer.h>
void playOneGame1Player(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void playOneGame2Player(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);

int isFull();
int user_won();
int cpu_won();
void draw_board(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT );
int minimax(bool flag);
int playerTurn(SDL_Renderer* renderer);

#endif // 1PLAYER__H
