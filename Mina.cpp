#include "Mina.h";
#include <SDL.h>
#include <SDL_image.h>

void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCasillero, int altoCasillero, int altoSprite){
    mina.f=f;//coordenada logica y
    mina.c=c;//coordenada logica x

    mina.imagen=IMG_LoadTexture(renderer,"img/mina.png");
    //SDL_QueryTexture(mina.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    mina.rectImag.y=(mina.f*altoCasillero)+altoCasillero-(altoSprite-altoCasillero);//coordenada de dibujo y
    mina.rectImag.x=(mina.c*anchoCasillero)+anchoCasillero;//coordenada de dibujo x
    mina.rectImag.w=anchoCasillero;//ancho
    mina.rectImag.h=altoSprite;//alto
}
int getFila(Mina *mina){
    return mina->f;
}
int getColumna(Mina *mina){
    return mina->c;
}
void dibujarMina(Mina *mina,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,mina->imagen,NULL,&(mina->rectImag));
}
void destruirMina(Mina *mina){
    SDL_DestroyTexture(mina->imagen);
}

