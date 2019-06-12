#include "Minas.h"
#include "Colaminas.h"
#include <SDL.h>
#include <SDL_image.h>

void crearMina(Minas &minas/**,SDL_Renderer* renderer, int f,int c, int anchoCasillero, int altoCasillero, int altoSprite*/){
    minas.f=0;//coordenada logica y
    minas.c=0;//coordenada logica x
    minas.intervaloproduccion=0;
    minas.tipo= "";
    crearCola(minas.secuenciaproduccion);
    /**
    minas.imagen=IMG_LoadTexture(renderer,"img/mina.png");
    //SDL_QueryTexture(mina.imagen,NULL,NULL,0,0);//tal vez este no haga falta, se utiliza para buscar el ancho/alto de la imagen pero nosotros ya lo tenemos de antemano

    minas.rectImag.y=(minas.f*altoCasillero)+altoCasillero-(altoSprite-altoCasillero);//coordenada de dibujo y
    minas.rectImag.x=(minas.c*anchoCasillero)+anchoCasillero;//coordenada de dibujo x
    minas.rectImag.w=anchoCasillero;//ancho
    minas.rectImag.h=altoSprite;//alto
    */
}
int getFila(Minas &minas){
    return minas.f;
}
int getColumna(Minas &minas){
    return minas.c;
}
void dibujarMina(Minas *minas,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,minas->imagen,NULL,&(minas->rectImag));
}
void destruirMina(Minas &minas){
//    SDL_DestroyTexture(minas->imagen);
    while(!colaVacia(minas.secuenciaproduccion)){

       Secuenciaproduccion* ptrSecuenciaproduccion = (Secuenciaproduccion*) desencolar(minas.secuenciaproduccion);
       eliminarSecuenciaproduccion(*ptrSecuenciaproduccion);

       delete ptrSecuenciaproduccion;
     }
}
void setf(Minas &minas, int dato){
    minas.f = dato;
}
void setc(Minas &minas, int dato){
    minas.c = dato;
}
void settipo(Minas &minas, string dato){
    minas.tipo = dato;
}
void setintervaloproduccion(Minas &minas, int dato){
    minas.intervaloproduccion = dato;
}
void agregarsecuenciaproduccionmina(Minas &minas, Secuenciaproduccion* ptrSecuenciaproduccion){
    encolar(minas.secuenciaproduccion, ptrSecuenciaproduccion);
}
string getTipomineral(Minas &minas){
    return minas.tipo;
}
Secuenciaproduccion getSecuenciaproduccionMina(Minas &minas){
    return *((Secuenciaproduccion*)(colaFrente(minas.secuenciaproduccion)->ptrDato));
}
//int generarMinerales(Minas &minas){
//    return *((Secuenciaproduccion*)(colaFrente(minas.secuenciaproduccion)->ptrDato)); /** ?????????????????????????*/
//    return a;
//}
//int entregarMinerales(Minas &minas){
//    return *((Secuenciaproduccion*)(colaFrente(minas.secuenciaproduccion)->ptrDato));/** ????????????????????????????????????????????????????????? */
//}
