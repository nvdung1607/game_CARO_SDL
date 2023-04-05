#include "2Player16.h"
// test git thay doi
char MAP[16][16];
//void update(char MAP[16][16], int tdX, int tdY, int XO)
//{
//    for (int i== 1; i<= 16; i++){
//        for (int j==1; j<= 16; j++){
//            if ( i== tdX && j == tdY ){
//
//            }
//        }
//    }
//}

void draw_MAP(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT ) //display tic-tac-toe board
{

    //xoa man hinh
    SDL_RenderClear(renderer);
    SDL_Texture *bg = loadTexture("bg.png", renderer);
    renderTexture(bg, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture *dtDoc = loadTexture("dtDoc.png", renderer);
    SDL_Texture *dtNgang = loadTexture("dtNgang.png", renderer);
    for( int i= 0; i< 15; i++)
    {
        renderTexture(dtDoc, renderer, 224 + i* 25, 75, 2, 400);
        renderTexture(dtNgang, renderer, 200, 99+ i* 25, 400, 2);
    }
    for (int i= 0; i< 16; i++){
        for (int j= 0; j< 16; j++){
            if (MAP[i][j] == 'X'){
                SDL_Texture *X = loadTexture("X12.png", renderer);
                renderTexture(X, renderer, 200+ 25* i, 75+ 25* j, 25, 25);
            }
            if (MAP[i][j] == 'O'){
                SDL_Texture *O = loadTexture("O12.png", renderer);
                renderTexture(O, renderer, 200+ 25* i, 75+ 25* j, 25, 25);
            }
        }
    }
    SDL_RenderPresent(renderer);
    for (int i=0; i< 16; i++){
        for (int j= 0; j< 16; j++)
        {
            cout << MAP[j][i] << " ";
        }
    cout << endl;
    }
}
bool check_X_Win(char a[16][16])
{

    //Kiem tra hang
    for (int i=0; i< 16; i++)
    {
        for (int j=0; j<= 11; j++)
        {
            if (a[i][j] == 'X' && a[i][j+1] == 'X' && a[i][j+2] == 'X' && a[i][j+3] == 'X' && a[i][j+4] == 'X')
            {

                return true;
            }
        }
    }

    //Kiem tra Cot
    for (int j=0; j<16; j++)
    {
        for (int i=0; i<=11; i++)
        {
            if (a[i][j] == 'X' && a[i+1][j] == 'X' && a[i+2][j] == 'X' && a[i+3][j] == 'X' && a[i+4][j] == 'X')
            {
                return true;
            }

        }
    }

    //Kiem tra duong cheo chinh
    for (int i=0; i< 11; i++)
    {
        for (int j=0; j< 11; j++)
        {
            if (a[i][j]=='X' && a[i+1][j+1]=='X' && a[i+2][j+2]=='X' && a[i+3][j+3]=='X' && a[i+4][j+4]=='X' )
            {

                return true;
            }
        }
    }

    //Kiem tra duong cheo phu
    for (int i= 0; i< 12; i++)
    {
        for (int j=4; j< 16; j++)
        {
            if (a[i][j]=='X' && a[i+1][j-1]=='X' && a[i+2][j-2]=='X' && a[i+3][j-3]=='X' && a[i+4][j-4]=='X' )
            {
                return true;
            }
        }
    }
    return false;
}

bool check_O_Win(char a[16][16])
{

    //Kiem tra hang
    for (int i=0; i< 16; i++)
    {
        for (int j=0; j<= 11; j++)
        {
            if (a[i][j] == 'O' && a[i][j+1] == 'O' && a[i][j+2] == 'O' && a[i][j+3] == 'O' && a[i][j+4] == 'O')
            {

                return true;
            }
        }
    }

    //Kiem tra Cot
    for (int j=0; j<16; j++)
    {
        for (int i=0; i<=11; i++)
        {
            if (a[i][j] == 'O' && a[i+1][j] == 'O' && a[i+2][j] == 'O' && a[i+3][j] == 'O' && a[i+4][j] == 'O')
            {
                return true;
            }

        }
    }

    //Kiem tra duong cheo chinh
    for (int i=0; i< 11; i++)
    {
        for (int j=0; j< 11; j++)
        {
            if (a[i][j]=='O' && a[i+1][j+1]=='O' && a[i+2][j+2]=='O' && a[i+3][j+3]=='O' && a[i+4][j+4]=='O' )
            {

                return true;
            }
        }
    }

    //Kiem tra duong cheo phu
    for (int i= 0; i< 12; i++)
    {
        for (int j=4; j< 16; j++)
        {
            if (a[i][j]=='O' && a[i+1][j-1]=='O' && a[i+2][j-2]=='O' && a[i+3][j-3]=='O' && a[i+4][j-4]=='O' )
            {
                return true;
            }
        }
    }
    return false;
}

void playOneGame2Player16(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    //khoi tao am nhac
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        printf("%s", Mix_GetError());
    }

    Mix_Chunk* click1 = NULL;
    Mix_Chunk* click2 = NULL;

    //Load Sound Effect
    click1 = Mix_LoadWAV("click1.wav");
    click2 = Mix_LoadWAV("click2.wav");
    Mix_Chunk* win = NULL;
    win = Mix_LoadWAV("winn.wav");
    //---------------------------------------------------------------
    //Khoi tao
    for (int i=0; i< 16; i++){
        for (int j= 0; j< 16; j++)
        {
            MAP[i][j]= '*';
        }
    }
    draw_MAP(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

//    MAP[0][0] = 'X';
//    MAP[5][5] = 'O';
//    draw_MAP(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    int dem= 0; // xac dinh luot di cua x hay o
    SDL_Rect filled_rect;
    SDL_Event e;
        while (true) {
            SDL_Delay(10);
            if ( SDL_WaitEvent(&e) == 0) continue;
            if (e.type == SDL_QUIT) break;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                filled_rect.x = e.button.x; // Lấy hoành độ x của chuột
                filled_rect.y = e.button.y; // Lấy tung độ y của chuột
                Mix_PlayChannel (-1, click1, 0);
                int tdX= filled_rect.x- 200;
                int tdY= filled_rect.y- 75;
                while (tdX % 25 != 0 ) tdX--;
                while (tdY % 25 != 0 ) tdY--;
                cout << tdX << " " << tdY << endl;
                tdX= tdX/ 25;
                tdY= tdY/ 25;
                //dem++;
                if (MAP[tdX][tdY] == '*' && tdX>= 0 && tdY>= 0){
                        if (dem % 2 == 0) MAP[tdX][tdY]= 'X';
                        else MAP[tdX][tdY]= 'O';
                        dem++;
                }
                draw_MAP(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                if (check_X_Win(MAP)){
                    cout << "X thang";
                    SDL_Texture *XWon = loadTexture("X_Won.png", renderer);
                    renderTexture(XWon, renderer, 250, 0, 300, 100);
                    SDL_RenderPresent(renderer);
                    Mix_PlayChannel (-1, win, 0);
                    break;
                }
                if (check_O_Win(MAP)){
                    cout << "O thang";
                    SDL_Texture *OWon = loadTexture("O_Won.png", renderer);
                    renderTexture(OWon, renderer, 250, 0, 300, 100);
                    SDL_RenderPresent(renderer);
                    Mix_PlayChannel (-1, win, 0);
                    break;
                }
                if (dem >= 256){
                    cout << "Hoaf";
                    SDL_Texture *draw = loadTexture("draw.png", renderer);
                    renderTexture(draw, renderer, 250, 0, 300, 100);
                    SDL_RenderPresent(renderer);
                    Mix_PlayChannel (-1, win, 0);
                    break;
                }
            }
        }
}
