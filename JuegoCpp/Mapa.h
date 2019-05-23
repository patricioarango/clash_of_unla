#ifndef __MAPA_H__
#define __MAPA_H__

#include "Caravana.h"
#include "Villano.h"
#include "Mina.h"
#include "Moneda.h"

typedef struct{
    int f;
    int c;

    PtrNodoCarro ptrNodoCarro;
    Villano *ptrVillano;
    Mina *ptrMina;
    Moneda *ptrMoneda;
}Mapa;

void crearMapa(Mapa &mapa,int f,int c);
void dibujarMapa(SDL_Renderer* renderer,Mapa &mapa, int intervalo);
void destruirMapa(Mapa &mapa);
#endif
