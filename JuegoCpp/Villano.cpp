#include "Villano.h";
#include <SDL.h>
#include <SDL_image.h>

void crearVillano(Villano &villano,SDL_Renderer* renderer, int f,int c, int anchoCasillero, int altoCasillero, int altoSprite){
    villano.f=f;//coordenada logica y
    villano.c=c;//coordenada logica x

    villano.imagen=IMG_LoadTexture(renderer,"img/villano.png");
    //SDL_QueryTexture(villano.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    villano.rectImag.y=(villano.f*altoCasillero)+altoCasillero-(altoSprite-altoCasillero);//coordenada de dibujo y
    villano.rectImag.x=(villano.c*anchoCasillero)+anchoCasillero;//coordenada de dibujo x
    villano.rectImag.w=anchoCasillero;//ancho
    villano.rectImag.h=altoSprite;//alto
}
int getFila(Villano *villano){
    return villano->f;
}
int getColumna(Villano *villano){
    return villano->c;
}
void dibujarVillano(Villano *villano,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,villano->imagen,NULL,&(villano->rectImag));
}
void destruirVillano(Villano *villano){
    SDL_DestroyTexture(villano->imagen);
}
