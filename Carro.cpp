#include "Carro.h"
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <stdlib.h>//permite utilizar itoa(int,char,int);
#include <SDL.h>
#include <SDL_image.h>

void crearCarro(Carro &carro,char tipo[], int f,int c, char direccion[], int anchoCasillero, int altoCasillero, int altoSprite){
    strcpy(carro.tipo,tipo);
    carro.f=f;//coordenada logica y
    carro.c=c;//coordenada logica x
    strcpy(carro.direccion,direccion);
    carro.anchoCasillero=anchoCasillero;
    carro.altoCasillero=altoCasillero;
    carro.altoSprite=altoSprite;
}
int getFila(Carro &carro){
    return carro.f;
}
int getColumna(Carro &carro){
    return carro.c;
}
void setFila(Carro &carro,int desplazamiento){
    carro.f=carro.f+desplazamiento;
}
void setColumna(Carro &carro,int desplazamiento){
    carro.c=carro.c+desplazamiento;
}
void dibujarCarro(Carro &carro,SDL_Renderer* renderer,int intervalo){
    char imagen[30] = "img/";
    strcat(imagen,carro.tipo);strcat(imagen,"/");

    strcat(imagen,carro.direccion);strcat(imagen,"/");

    char cadenaIntervalo[5];
    itoa(intervalo,cadenaIntervalo,10);
    strcat(imagen,cadenaIntervalo);strcat(imagen,".png");

    //img\c1\aba\0.png

    carro.imagen=IMG_LoadTexture(renderer,imagen);
    //SDL_QueryTexture(carro.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    //evaluamos los desplazamientos
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(carro.direccion,"aba")==0)desplazamientoVertical=1;
    if(strcmp(carro.direccion,"arr")==0)desplazamientoVertical=-1;
    if(strcmp(carro.direccion,"der")==0)desplazamientoHorizontal=1;
    if(strcmp(carro.direccion,"izq")==0)desplazamientoHorizontal=-1;

    carro.rectImag.y=((carro.f*carro.altoCasillero)+carro.altoCasillero-(carro.altoSprite-carro.altoCasillero))+(desplazamientoVertical*(carro.altoCasillero/10)*intervalo);//coordenada de dibujo y
    carro.rectImag.x=((carro.c*carro.anchoCasillero)+carro.anchoCasillero)+(desplazamientoHorizontal*(carro.anchoCasillero/10)*intervalo);//coordenada de dibujo x
    carro.rectImag.w=carro.anchoCasillero;//70
    carro.rectImag.h=carro.altoSprite;//70

    SDL_RenderCopy(renderer,carro.imagen,NULL,&(carro.rectImag));
}
void destruirCarro(Carro &carro){
    SDL_DestroyTexture(carro.imagen);
    //delete &carro;
}
char* getDireccion(Carro &carro){
    return carro.direccion;
}
void setDireccion(Carro &carro,char direccion[]){
    strcpy(carro.direccion,direccion);
}
