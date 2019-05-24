#ifndef __PARTIDA_H__
#define __PARTIDA_H__

#include <SDL.h>
#include "Casillero.h"
#include "Mapa.h"
#include "Caravana.h"
typedef struct{
    bool gameover;
    int intervalo;

    int anchoCasillero;
    int altoCasillero;
    int altoSprite;

    int filas;
    int columnas;
    int filasMapa;

    Casillero** tablero;

    Mapa** mapa;

    char direccion[4];

}Partida;

void crearPartida(Partida &partida,int filas,int columnas,int anchoCasillero,int altoCasillero, int altoSprite);
int getAnchoCasillero(Partida &partida);
int getAltoCasillero(Partida &partida);
int getIntervalo(Partida &partida);
void setIntervalo(Partida &partida, int intervalo);
void setTablero(Partida &partida,SDL_Renderer *renderer);
Casillero** getTablero(Partida &partida);
void setMapa(Partida &partida);
Mapa** getMapa(Partida &partida);
void dibujarTablero(Partida partida,SDL_Renderer *renderer);
bool getGameOver(Partida &partida);
void setGameOver(Partida &partida, bool flag);
void destruirPartida(Partida &partida);
void ubicarCarro(Partida &partida,PtrNodoCarro ptrNodo);
void ubicarVillano(Partida &partida,Villano *villano);
void ubicarMina(Partida &partida,Mina *mina);
void ubicarMoneda(Partida &partida,Moneda *moneda);
void setDireccion(Partida &partida,char direccion[]);
char* getDireccion(Partida &partida);
int getColumnaLimite(Partida &partida);
int getFilaLimite(Partida &partida);
#endif
