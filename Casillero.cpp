#include "Casillero.h"
#include "Caravana.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);

void crearCasillero(Casillero &casillero,int f,int c,int ancho, int alto, SDL_Renderer* renderer,char rand[]){
    casillero.f=f;//coordenada logica y
    casillero.c=c;//coordenada logica x

    char imagen[30]="img/suelo_";
	strcat(imagen,rand);
    strcat(imagen,".png");
    casillero.imagen=IMG_LoadTexture(renderer,imagen);
    //SDL_QueryTexture(casillero.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    casillero.rectImag.y=(casillero.f*alto)+alto;//coordenada de dibujo y
    casillero.rectImag.x=(casillero.c*ancho)+ancho;//coordenada de dibujo x
    casillero.rectImag.w=ancho;//ancho
    casillero.rectImag.h=alto;//alto

    casillero.ptrNodoCarro=NULL;//al principio no tiene carros
    casillero.ptrVillano=NULL;//un unico villano por casillero
    casillero.ptrMoneda=NULL;
}
void dibujarCasillero(SDL_Renderer* renderer,Casillero &casillero){
    SDL_RenderCopy(renderer,casillero.imagen,NULL,&(casillero.rectImag));
}
void destruirCasillero(Casillero &casillero){
    SDL_DestroyTexture(casillero.imagen);
    //delete &casillero;
}
