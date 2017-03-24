
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*background2,*character,*character2,*suelo;
SDL_Rect rect_background,rect_background2,rect_background3,rect_background4,rect_character,rect_character2,rect_suelo;


int screen_width = 500;
int screen_height = 250;

vector<SDL_Texture*> texture_c1;
SDL_Rect rect_c1;
int current_c1 = 0;


bool estaColisionando(SDL_Rect a, SDL_Rect b)
{
    if(a.x + a.w < b.x)
        return false;

    if(b.x + b.w < a.x)
        return false;

    if(b.y + b.h < a.y)
        return false;

    if(a.y + a.h < b.y)
        return false;

    return true;
}


int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1322/*WIDTH*/, 700/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondox.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = 1522; rect_background.h = 800;

    character2 = IMG_LoadTexture(renderer, "Piccolo.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x =350; rect_character.y = 350; rect_character.w = 70; rect_character.h = 50;

     character = IMG_LoadTexture(renderer, "goku.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x =350; rect_character.y = 350; rect_character.w = 70; rect_character.h = 50;



    texture_c1.push_back(IMG_LoadTexture(renderer, "c1.png"));
    texture_c1.push_back(IMG_LoadTexture(renderer, "c2.png"));
    rect_c1.x = 350;
    rect_c1.y = 350;
    rect_c1.w= 100;
    rect_c1.h=100;
            SDL_Delay(20);


    int frames=0;



    //Main Loop



    char c1_orientation = 'r';

    int velocidad=2;
    while(true)
    {
        while(SDL_PollEvent(&Event))

        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++
                    ;
            }
            if(Event.type == SDL_QUIT)
                {
                  return 0;
                }
            if(Event.type == SDL_KEYDOWN)
                {
                  if(Event.key.keysym.sym == SDLK_a)
                      rect_character.x-=1;
                }
             if(Event.type == SDL_QUIT)
                {
                  return 0;
                }
            if(Event.type == SDL_KEYDOWN)
                {
                  if(Event.key.keysym.sym == SDLK_w)
                      rect_character.y--;
                }
              if(Event.type == SDL_QUIT)
                {
                  return 0;
                }
            if(Event.type == SDL_KEYDOWN)
                {
                  if(Event.key.keysym.sym == SDLK_s)
                      rect_character.y++;
                }


            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_background.x-=velocidad-1;
                if(Event.key.keysym.sym == SDLK_d)
                    rect_background2.x-=velocidad-1;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_background.x+=velocidad-1;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_background2.x+=velocidad-1;

            }
        }

        if(rect_c1.x>40)
            c1_orientation='1';

        if(rect_c1.x<20)
            c1_orientation='r';

        if(c1_orientation == '1')
            rect_c1.x+=2;
        if(c1_orientation == 'r')
            rect_c1.x-=2;


        if(frames%10==0)
            {

            current_c1++;
        if(current_c1 >=texture_c1.size())
            {
                current_c1 =0;
            }



            }
            frames++;




        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, background2, NULL, &rect_background2);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, character2, NULL, &rect_character2);
        SDL_RenderCopy(renderer, suelo, NULL, &rect_suelo);
        SDL_RenderCopy(renderer, texture_c1[current_c1], NULL , &rect_c1);
        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

	return 0;
}
