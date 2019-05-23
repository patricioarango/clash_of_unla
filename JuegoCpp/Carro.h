#ifndef __CARRO_H__
#define __CARRO_H__

#include <SDL.h>

typedef struct{
    char tipo[3];
    int f;
    int c;
    char direccion[4];
    int anchoCasillero;
    int altoCasillero;
    int altoSprite;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Carro;

void crearCarro(Carro &carro,char tipo[], int f,int c, char direccion[], int anchoCasillero, int altoCasillero, int altoSprite);
int getFila(Carro &carro);
int getColumna(Carro &carro);
void setFila(Carro &carro,int desplazamiento);
void setColumna(Carro &carro,int desplazamiento);
void dibujarCarro(Carro &carro,SDL_Renderer* renderer,int intervalo);
void destruirCarro(Carro &carro);
char* getDireccion(Carro &carro);
void setDireccion(Carro &carro,char direccion[]);

#endif
