
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>
#include "Sho.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background;
SDL_Rect rect_background;

SDL_Rect rect_pausa;
SDL_Texture* texture_pausa;
bool pausa = false;

int contador = 0;
int contador_auxiliar = 0;

void act();
Sho* sho;
int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1024/*WIDTH*/, 768/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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
    background = IMG_LoadTexture(renderer,"textures/fondo.png");
    texture_pausa = IMG_LoadTexture(renderer,"textures/pausa.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;



    SDL_QueryTexture(texture_pausa, NULL, NULL, &w, &h);
    rect_pausa.x = rect_background.x + (rect_background.w/2) -(w/2);
    rect_pausa.y = rect_background.y + (rect_background.h/2) -(h/2);
    rect_pausa.w = w;
    rect_pausa.h = h;





    sho = new Sho(renderer);

    //Main Loop
    int frame=0;
    int animacion_sho = 0;



    while(true)
    {
        if(contador % 10 == 0)
        {

        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }

            if(Event.type == SDL_KEYDOWN)
            {


                          //retorna un entero, accesa al teclado
                int key = Event.key.keysym.sym ;

                switch(key)
                {

                    case SDLK_SPACE : {
                                        if(pausa)
                                            pausa = false;
                                        else
                                            pausa = true;
                                        break;
                                      }

                }
            }
            else  if(Event.type == SDL_KEYUP)
            {

            }


        }

        if(!pausa)
        act();


        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        if(pausa)
        {

            //dibuja un png de pausa
             SDL_RenderCopy(renderer, texture_pausa, NULL, &rect_pausa);

        }
        sho->draw(renderer);

        SDL_RenderPresent(renderer);

        frame++;

    }
    else
        contador_auxiliar++;
        if(contador_auxiliar>5)
        {
            contador_auxiliar=0;
            contador++;

        }
    }

	return 0;
}

void act()
{
    sho->act();
}



