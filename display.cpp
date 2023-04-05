#include "display.h"

void draw_Bg(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT )
{
    //xoa man hinh
    SDL_RenderClear(renderer);
    SDL_Texture *bg1 = loadTexture("bg1.png", renderer);
    renderTexture(bg1, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
}

void endGame(SDL_Renderer* renderer)
{
    SDL_Texture *home = loadTexture("home.png", renderer);
    renderTexture(home, renderer, 25, 450, 75, 30);
    SDL_Texture *returnn = loadTexture("return.png", renderer);
    renderTexture(returnn, renderer, 680, 450, 75, 30);

    SDL_RenderPresent(renderer);

}
int returnn(SDL_Renderer* renderer)  // return 1: home
{                                   // return 2: return
    int choice;
    SDL_Event e;
    SDL_Rect filled_rect;
    while (true) {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            filled_rect.x = e.button.x; // Lấy hoành độ x của chuột
            filled_rect.y = e.button.y; // Lấy tung độ y của chuột
            if (filled_rect.x >= 25 && filled_rect.y >= 450 && filled_rect.x <= 100 && filled_rect.y <= 480){
                    choice = 1;
                    break;
            }
            if (filled_rect.x >= 680 && filled_rect.y >= 450 && filled_rect.x <= 755 && filled_rect.y <= 480){
                    choice = 2;
                    break;
            }

        }
    }
    return choice;
}


