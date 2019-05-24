#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <SDL.h>
#include "Partida.h"
#include "Casillero.h"
#include "Mapa.h"
#include "Caravana.h"
#include "Villano.h"
#include <ctime> //time.h o ctime agregan funciones que leen el reloj interno del procesador. la funcion time(NULL) devuelve el tiempo actual en milisegundos. la usamos para los aleatorios.
#include <stdlib.h>//permite utilizar itoa(int,char,int); y la funcion para aleatorios rand()

void crearPartida(Partida &partida,int filas,int columnas,int anchoCasillero,int altoCasillero,int altoSprite){
    partida.gameover=false;
    partida.intervalo=0;

    partida.anchoCasillero=anchoCasillero;
    partida.altoCasillero=altoCasillero;
    partida.altoSprite=altoSprite;

    partida.filas=filas;
    partida.columnas=columnas;
    partida.filasMapa = (filas*2)-1;

    partida.tablero= new Casillero*[partida.filas];
    for (int f = 0; f < partida.filas; f++){
        partida.tablero[f] = new Casillero[partida.columnas];
    }

    partida.mapa= new Mapa*[partida.filasMapa];
    for (int f = 0; f < partida.filasMapa; f++){
        partida.mapa[f] = new Mapa[partida.columnas];
    }
    strcpy(partida.direccion,"aba");
}
int getAnchoCasillero(Partida &partida){
    return partida.anchoCasillero;
}
int getAltoCasillero(Partida &partida){
    return partida.altoCasillero;
}
int getIntervalo(Partida &partida){
    return partida.intervalo;
}
void setIntervalo(Partida &partida, int intervalo){
    partida.intervalo=intervalo;
}
void setTablero(Partida &partida,SDL_Renderer* renderer){
    srand(time(0));//semilla para aleatorio: cambia el valor inicial del random dentro de la libreria stdlib.h
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            Casillero casillero;

            char aux [2];//cadena que guarda valores entre 0 y 4
            itoa((rand()%6),aux,10);//valor aleatorio entre 0 y 4, pasados a string en base 10
            crearCasillero(casillero,f,c,getAnchoCasillero(partida),getAltoCasillero(partida),renderer,aux);
            partida.tablero[f][c]=casillero;
        }
    }
}
Casillero** getTablero(Partida &partida){
    return partida.tablero;
}
void setMapa(Partida &partida){
    for(int f=0;f<partida.filasMapa;f++){
        for(int c=0;c<partida.columnas;c++){
            Mapa mapa;
            crearMapa(mapa,f,c);
            partida.mapa[f][c]=mapa;
        }
    }
}
Mapa** getMapa(Partida &partida){
    return partida.mapa;
}
void dibujarTablero(Partida partida,SDL_Renderer *renderer){
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            dibujarCasillero(renderer,partida.tablero[f][c]);
        }
    }
    for(int f=0;f<partida.filasMapa;f++){
        for(int c=0;c<partida.columnas;c++){
            dibujarMapa(renderer,partida.mapa[f][c],partida.intervalo);
        }
    }
}
void destruirPartida(Partida &partida){
    for(int f=0;f<partida.filas;f++){
        for(int c=0;c<partida.columnas;c++){
            destruirCasillero(partida.tablero[f][c]);
        }
    }
    for(int f=0;f<partida.filasMapa;f++){
        for(int c=0;c<partida.columnas;c++){
            destruirMapa(partida.mapa[f][c]);
        }
    }
    //delete &partida;
}
bool getGameOver(Partida &partida){
    return partida.gameover;
}
void setGameOver(Partida &partida, bool flag){
    partida.gameover=flag;
}
void ubicarCarro(Partida &partida,PtrNodoCarro ptrNodo){
    partida.tablero[getFila(ptrNodo->carro)][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;//casillero.ptrNosoCarro=ptrNodo
    partida.mapa[getFila(ptrNodo->carro)*2][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;//mapa.ptrNosoCarro=ptrNodo
}
void ubicarVillano(Partida &partida,Villano *villano){
    partida.tablero[getFila(villano)][getColumna(villano)].ptrVillano=villano;
    partida.mapa[(getFila(villano)*2)-1][getColumna(villano)].ptrVillano=villano;
}
void ubicarMina(Partida &partida,Mina *mina){
    partida.tablero[getFila(mina)][getColumna(mina)].ptrMina=mina;
    int ajusteFila=(getFila(mina)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.mapa[ajusteFila][getColumna(mina)].ptrMina=mina;
}
void ubicarMoneda(Partida &partida,Moneda *moneda){
    partida.tablero[getFila(moneda)][getColumna(moneda)].ptrMoneda=moneda;
    int ajusteFila=(getFila(moneda)*2)-1;
    if(ajusteFila<0)ajusteFila=0;
    partida.mapa[ajusteFila][getColumna(moneda)].ptrMoneda=moneda;
}
void setDireccion(Partida &partida,char direccion[]){
    strcpy(partida.direccion,direccion);
}
char* getDireccion(Partida &partida){
    return partida.direccion;
}
int getColumnaLimite(Partida &partida){
    return partida.columnas;
}
int getFilaLimite(Partida &partida){
    return partida.filas;
}
