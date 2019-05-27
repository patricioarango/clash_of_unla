#ifndef MINAS_H_INCLUDED
#define MINAS_H_INCLUDED

#include <SDL.h>
/**Tipo datos Mina
Atributos:
*posX,
*posY,
*tipoMineral,
*intervaloProduccion,
*SecuenciaProducion,

Axiomas:
*PosX > 0 & < 15 & no ocupada por otra entidad (estacion, posicion inicial del carro u otra mina)
*posY > 0 & < 20 & no ocupada por otra entidad (estacion, posicion inicial del carro u otra mina)
*TipoMaterial = oro, plata, cobre, platino, carbon o roca
*intervaloProduccion > 0
*SecuenciaProduccion > 0
*/

typedef struct{
    int f;
    int c;
    char tipo;
    int ip;
    int seq;
	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Mina;
//-------------------------------------------------------------------------------------
/**
PRE :La mina no debe haber sido creada.
POST :  Se mina queda creada y lista para ser usada.
*/
void crearMina(Mina &mina,SDL_Renderer* renderer, int f,int c, int anchoCasillero, int altoCasillero, int altoSprite);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la ubicacion de la fila donde sera ubicada la mina.
*/
int getFila(Mina *mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la ubicacion de la columna donde sera dibujada la mina.
*/
int getColumna(Mina *mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene el tipo de mineral que producira la mina.
*/
void getTipomineral(Mina *mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia en que producira minerales la mina.
*/
void getSecuenciaproduccion(Mina *mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      Se debe haber obtenido la ubicacion en fila por la funcion getFila
      Se debe haber obtenido la ubicacion en columna por la funcion getColumna
POST :  Se dibuja en el mapa la mina en su ubicacion correspondiente.
*/
void dibujarMina(Mina *mina,SDL_Renderer* renderer);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      La mina debe haber sido ubicada en el mapa por la funcion ubicarMina.
POST : Se producen minerales en la mina segun secuencia de intervalos.
*/
void generarMinerales(Mina *mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      La mina debe haber sido dibujada por la funcion dibujarMina.
      La locomotora debe haber chocado con la mina.
      Se debe tener los valores de las funciones getTipomineral y getSecuenciaproduccion.
POST : Si hay minerales en la mina y se tiene espacio disponible se le entrega minerales en bagon del mismo mineral al jugador.
*/
void entregarMinerales(Mina *mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : La mina es eliminada de la partida.
*/
void destruirMina(Mina *mina);


#endif // MINAS_H_INCLUDED
