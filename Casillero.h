#ifndef __SUELO_H__
#define __SUELO_H__

#include <SDL.h>
#include "Caravana.h"
#include "Villano.h"
#include "Mina.h"
#include "Moneda.h"

typedef struct{
    int f;
    int c;
	SDL_Texture *imagen;
    SDL_Rect rectImag;

    PtrNodoCarro ptrNodoCarro;
    Villano *ptrVillano;
    Mina *ptrMina;
    Moneda *ptrMoneda;

}Casillero;

void crearCasillero(Casillero &casillero,int f,int c,int ancho, int alto, SDL_Renderer* renderer,char rand[]);
void dibujarCasillero(SDL_Renderer* renderer,Casillero &casillero);
void destruirCasillero(Casillero &casillero);
#endif

