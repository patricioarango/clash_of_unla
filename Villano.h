#ifndef __VILLANO_H__
#define __VILLANO_H__

#include <SDL.h>

typedef struct{
    int f;
    int c;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Villano;

void crearVillano(Villano &villano,SDL_Renderer* renderer, int f,int c, int anchoCasillero, int altoCasillero, int altoSprite);
int getFila(Villano *villano);
int getColumna(Villano *villano);
void dibujarVillano(Villano *villano,SDL_Renderer* renderer);
void destruirVillano(Villano *villano);

#endif
