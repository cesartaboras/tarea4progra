#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
using namespace std;
SDL_Window* window;
SDL_Renderer* renderer,*renderer2;
SDL_Event Event;
SDL_Texture *background,*b2,*character,*character2,*character3,*character4,*character6,*personaje, *my_image;
SDL_Rect rect_background,rect_b2,rect_character,rect_character2,rect_character3,rect_character4,rect_character6,rect_personaje, my_rect;

int screen_width = 500;
int screen_height = 250;

int main( int argc, char* args[] )
{
    int i=0;
//Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
//Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1200/*WIDTH*/, 600/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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
    background = IMG_LoadTexture(renderer,"fondo.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 1200;
    rect_background.h = 600;
    character2 = IMG_LoadTexture(renderer, "b1.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character2.x = 400;
    rect_character2.y = 300;
    rect_character2.w = 100;
    rect_character2.h = 50;
    character = IMG_LoadTexture(renderer, "suelo.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 500;
    rect_character.w = 1200;
    rect_character.h = 200;
    character4 = IMG_LoadTexture(renderer, "b2.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character4.x = 1000;
    rect_character4.y = 300;
    rect_character4.w = 100;
    rect_character4.h = 50;

    character6 = IMG_LoadTexture(renderer, "logo.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character6.x = 1000;
    rect_character6.y = 500;
    rect_character6.w = 100;
    rect_character6.h = 50;


    personaje = IMG_LoadTexture(renderer, "p1.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_personaje.x = 0;
    rect_personaje.y = 300;
    rect_personaje.w = 150;
    rect_personaje.h = 300;


    my_image = IMG_LoadTexture(renderer, "image.png");
    my_rect.x = 1200;
    my_rect.y = 600;
    my_rect.w = 50;
    my_rect.h = 50;

//Main Loop
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
                    rect_character.x++;
            }
        }
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, b2, NULL, &rect_b2);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, character2, NULL, &rect_character2);
        SDL_RenderCopy(renderer, character3, NULL, &rect_character3);
        SDL_RenderCopy(renderer, character4, NULL, &rect_character4);
        SDL_RenderCopy(renderer, character6, NULL, &rect_character6);
        SDL_RenderCopy(renderer, personaje, NULL, &rect_personaje);
        SDL_RenderCopy(renderer, my_image, NULL, &my_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }
    return 0;
}
