#include "player3.h"
int index1;
char board[9] = {'*','*','*','*','*','*','*','*','*'};// Single array represents the board '*' means empty box in board

int isFull()// Board is full
{
    for(int i =0;i<9;i++)
    {
        if(board[i]!='X')
        {
            if(board[i]!='O')
               {
                 return 0;
               }
        }
    }
return 1;
}

int user_won()//Checks whether user has won // O_Won
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='O'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='O'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='O'))
    {
        return 1;
    }
    return 0;
}

int cpu_won()// Checks whether CPU has won //X_Won
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='X'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='X'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='X'))
    {
        return 1;
    }
    return 0;
}

void draw_board(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT ) //display tic-tac-toe board
{
    //xoa man hinh
    SDL_RenderClear(renderer);
    //in background
    SDL_Texture *background = loadTexture("bgBang.png", renderer);
    renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Texture *dtDoc = loadTexture("dtDoc.png", renderer);
    SDL_Texture *dtNgang = loadTexture("dtNgang.png", renderer);
    renderTexture(dtDoc, renderer, 347, 100, 6, 300);
    renderTexture(dtDoc, renderer, 447, 100, 6, 300);
    renderTexture(dtNgang, renderer, 250, 193, 300, 6);
    renderTexture(dtNgang, renderer, 250, 293, 300, 6);

    int x= 250, y= 100;
    for (int i = 0; i< 9; i++){
                if (i== 3 || i== 6){
                        y= y+ 100;
                        x= 250;
                }
                if (board[i]== 'X'){
                    SDL_Texture *X = loadTexture("X.png", renderer);
                    renderTexture(X, renderer, x, y, 100, 100);
                }
                if (board[i]== 'O'){
                    SDL_Texture *O = loadTexture("O.png", renderer);
                    renderTexture(O, renderer, x, y, 100, 100);
                }
                x= x+ 100;

    }

    SDL_RenderPresent(renderer);

}

int minimax(bool flag)// The minimax function
{

    int max_val=-1000,min_val=1000;
    int i,j,value = 1;
    if(cpu_won() == 1)
        {return 10;}
    else if(user_won() == 1)
        {return -10;}
    else if(isFull()== 1)
        {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};//if score[i]=1 then it is empty

        for(i=0;i<9;i++)
            {
                 if(board[i] == '*')
                {
                    if(min_val>max_val) // reverse of pruning condition.....
                  {
                      if(flag == true)
                   {
                     board[i] = 'X';
                     value = minimax(false);
                   }
                    else
                    {
                      board[i] = 'O';
                      value = minimax(true);
                    }
                  board[i] = '*';
                  score[i] = value;
                 }
               }
            }

        if(flag == true)
        {
                 max_val = -1000;
                 for(j=0;j<9;j++)
                {
                    if(score[j] > max_val && score[j] != 1)
                    {
                        max_val = score[j];
                        index1 = j;
                    }
                }
                return max_val;
        }
        if(flag == false)
        {
                min_val = 1000;
                for(j=0;j<9;j++)
                {
                    if(score[j] < min_val && score[j] != 1)
                    {
                        min_val = score[j];
                        index1 = j;
                    }
                }
            return min_val;
        }
}

int playerTurn(SDL_Renderer* renderer)
{
        int click;
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
                if (filled_rect.x> 250 && filled_rect.y> 100 && filled_rect.x< 350 && filled_rect.y< 200) {click = 0; break;};
                if (filled_rect.x> 350 && filled_rect.y> 100 && filled_rect.x< 450 && filled_rect.y< 200) {click = 1; break;};
                if (filled_rect.x> 450 && filled_rect.y> 100 && filled_rect.x< 550 && filled_rect.y< 200) {click = 2; break;};
                if (filled_rect.x> 250 && filled_rect.y> 200 && filled_rect.x< 350 && filled_rect.y< 300) {click = 3; break;};
                if (filled_rect.x> 350 && filled_rect.y> 200 && filled_rect.x< 450 && filled_rect.y< 300) {click = 4; break;};
                if (filled_rect.x> 450 && filled_rect.y> 200 && filled_rect.x< 550 && filled_rect.y< 300) {click = 5; break;};
                if (filled_rect.x> 250 && filled_rect.y> 300 && filled_rect.x< 350 && filled_rect.y< 400) {click = 6; break;};
                if (filled_rect.x> 350 && filled_rect.y> 300 && filled_rect.x< 450 && filled_rect.y< 400) {click = 7; break;};
                if (filled_rect.x> 450 && filled_rect.y> 300 && filled_rect.x< 550 && filled_rect.y< 400) {click = 8; break;};
            }
        }
        return click;
}


void playOneGame1Player(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
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

    //
    for (int i= 0; i< 9; i++) board[i]= '*';
    int move;
    SDL_RenderClear(renderer);
    SDL_Texture *bg1Player = loadTexture("bg1Player.png", renderer);
    renderTexture(bg1Player, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
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
                if (filled_rect.x> 100 && filled_rect.y> 210 && filled_rect.x< 380 && filled_rect.y< 295) {
                        Mix_PlayChannel (-1, click2, 0);
                        draw_board(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                        int move;
                        lamlai:
                                move= playerTurn(renderer);
                                Mix_PlayChannel (-1, click1, 0);
                                if(board[move]=='*')
                                 {
                                   board[move] = 'O';
                                    draw_board(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                                 }
                                 else
                                 {
                                     cout<<endl<<"Invalid Move......Try different move";
                                     goto lamlai;
                                 }
                        break;
                }
                if (filled_rect.x> 430 && filled_rect.y> 210 && filled_rect.x< 720 && filled_rect.y< 295)
                {
                    Mix_PlayChannel (-1, click2, 0);
                    break;
                }
            }
        }

    while(true)
    {
        SDL_Delay(500);
        Mix_PlayChannel (-1, click1, 0);
        minimax(true);
        board[index1] = 'X';
        draw_board(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        if(cpu_won()==1)
        {
            cout<<endl<<"CPU WON.....";
            SDL_Texture *botWon = loadTexture("botWon.png", renderer);
            renderTexture(botWon, renderer, 250, 0, 300, 100);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel (-1, win, 0);
            break;
        }
        if(isFull()==1)
        {
            cout<<endl<<"Draw....";
            SDL_Texture *draw = loadTexture("draw.png", renderer);
            renderTexture(draw, renderer, 250, 0, 300, 100);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel (-1, win, 0);
            break;
        }
again:
        move = playerTurn(renderer);
         Mix_PlayChannel (-1, click1, 0);
        if(board[move]=='*')
         {
           board[move] = 'O';
           draw_board(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
         }
         else
         {
             cout<<endl<<"nhap lai";
             goto again;
         }
         if(user_won()==1)
         {
             cout<<endl<<"You Won......";
             SDL_Texture *youWon = loadTexture("youWon.png", renderer);
             renderTexture(youWon, renderer, 250, 0, 300, 100);
             SDL_RenderPresent(renderer);
             Mix_PlayChannel (-1, win, 0);
             break;
         }
         if(isFull() == 1)
        {
            cout<<endl<<"Draw....";
            SDL_Texture *draw = loadTexture("draw.png", renderer);
            renderTexture(draw, renderer, 250, 0, 300, 100);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel (-1, win, 0);
            break;
        }
    }
}

void playOneGame2Player(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT )
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

    //----------------------------------------------------
     for ( int i=0; i< 9; i++) board[i]= '*';
    draw_board(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    int dem=0;
    while(true)
    {
        dem++;
        again:
        int click = playerTurn(renderer);

        if (board[click]== '*'){
            if (dem% 2== 1){
                    Mix_PlayChannel (-1, click1, 0);
                    board[click]= 'X';
            }
            if (dem% 2== 0){
                    Mix_PlayChannel (-1, click1, 0);
                    board[click]= 'O';
            }
        }
        else{
            goto again;
        }

        draw_board(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (cpu_won()== 1){
            SDL_Texture *XWon = loadTexture("X_Won.png", renderer);
            renderTexture(XWon, renderer, 250, 0, 300, 100);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel (-1, win, 0);
            break;
        }
        if (user_won()== 1){
            SDL_Texture *OWon = loadTexture("O_Won.png", renderer);
            renderTexture(OWon, renderer, 250, 0, 300, 100);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel (-1, win, 0);
            break;
        }
        if(dem == 9 ){
            SDL_Texture *draw = loadTexture("draw.png", renderer);
            renderTexture(draw, renderer, 250, 0, 300, 100);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel (-1, win, 0);
            break;
        }
        cout << click;
    }
}
