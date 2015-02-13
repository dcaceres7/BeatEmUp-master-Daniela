#include "Sho.h"
#include <iostream>
using namespace std;
Sho::Sho(SDL_Renderer* renderer)
{

    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    SDL_QueryTexture(sho_standing[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 450;
    rect.w = rect.w/2;
    rect.h = rect.h/2;
    frame = 0;
    animacion_sho = 0;
}

void Sho::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, sho_standing[animacion_sho], NULL, &rect);
        if(frame%95==0)
        {
            animacion_sho++;
            if(animacion_sho>=sho_standing.size())
                animacion_sho=0;
        }
        frame++;

}

void Sho::act()
{

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    bool run = currentKeyStates[SDL_SCANCODE_P];
    bool salto=currentKeyStates[SDL_SCANCODE_O];
    int velocidad = 1;
    if(run)
        velocidad=3;


    if(salto){
        rect.y=300;
    }
    else
        rect.y = 450;

    if(currentKeyStates[SDL_SCANCODE_A]){
        if(rect.x>-20){
          if(rect.y==450)
            rect.x-=velocidad;
        }
    }

    if(currentKeyStates[SDL_SCANCODE_D]){
        if(rect.x<938){
          if(rect.y==450)
            rect.x+=velocidad;
        }
    }

}

Sho::~Sho()
{
    //dtor
}
