#include "Mapa.h"
#include "Caravana.h"
#include "Villano.h";
#include "Mina.h"
#include "Moneda.h"

void crearMapa(Mapa &mapa,int f,int c){
    mapa.f=f;//coordenada logica y
    mapa.c=c;//coordenada logica x

    mapa.ptrNodoCarro=NULL;//al principio no tiene carros
    mapa.ptrVillano=NULL;//un unico villano por casilla
    mapa.ptrMina=NULL;
    mapa.ptrMoneda=NULL;
}
void dibujarMapa(SDL_Renderer* renderer,Mapa &mapa, int intervalo){
    if(mapa.ptrVillano!=NULL){
        dibujarVillano(mapa.ptrVillano,renderer);
    }
    if(mapa.ptrMina!=NULL){
        dibujarMina(mapa.ptrMina,renderer);
    }
    if(mapa.ptrMoneda!=NULL){
        dibujarMoneda(mapa.ptrMoneda,renderer);
    }
    if(mapa.ptrNodoCarro!=NULL){
        dibujarCarro(mapa.ptrNodoCarro->carro,renderer,intervalo);
    }
}
void destruirMapa(Mapa &mapa){
    //la caravana se destruye en otro lugar, pero aquí hay otros tda:
    if(mapa.ptrVillano!=NULL){
        destruirVillano(mapa.ptrVillano);
        delete mapa.ptrVillano;
    }
    if(mapa.ptrMina!=NULL){
        destruirMina(mapa.ptrMina);
        delete mapa.ptrMina;
    }
    if(mapa.ptrMoneda!=NULL){
        destruirMoneda(mapa.ptrMoneda);
        delete mapa.ptrMoneda;
    }
    //delete &mapa;
}

