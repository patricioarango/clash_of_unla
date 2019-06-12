#include <cstdlib>
#include <iostream>
#include <string>
#include "Colaminas.h"
#include "Secuenciaproduccion.h"

using namespace std;
#ifndef MINAS_H_INCLUDED
#define MINAS_H_INCLUDED
#ifndef NULL
#define NULL 0
#endif
#include <SDL.h>
/**Tipo datos Mina
Atributos:
*posX,
*posY,
*tipoMineral,
*intervaloProduccion,
*Cola que contiene a SecuenciaProducion,

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
    string tipo;
    int intervaloproduccion;
    Cola secuenciaproduccion;
	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Minas;
//-------------------------------------------------------------------------------------
/**
PRE :La mina no debe haber sido creada.
POST :  Se mina queda creada y lista para ser usada.
*/
void crearMina(Minas &minas/**,SDL_Renderer* renderer, int f,int c, int anchoCasillero, int altoCasillero, int altoSprite*/);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo f para a contener el dato del archivo minas.txt
*/
void setf(Minas &minas, int dato);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo c para a contener el dato del archivo minas.txt
*/
void setc(Minas &minas, int dato);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo tipo para a contener el dato del archivo minas.txt
*/
void settipo(Minas &minas, string dato);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo intervaloproduccion para a contener el dato del archivo minas.txt
*/
void setintervaloproduccion(Minas &minas, int dato);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : agrega un tipo Secuenciaproduccion a la cola de Secuenciaproduccion.
*/
void agregarsecuenciaproduccionmina(Minas &minas, Secuenciaproduccion* ptrSecuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la ubicacion de la fila donde sera ubicada la mina.
*/
int getFila(Minas &minas);
//-------------------------------------------------------------------------------------]
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la ubicacion de la columna donde sera dibujada la mina.
*/
int getColumna(Minas &minas);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene el tipo de mineral que producira la mina.
*/
string getTipomineral(Minas &minas);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia en que producira minerales la mina.
*/
Secuenciaproduccion getSecuenciaproduccionMina(Minas &minas);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      Se debe haber obtenido la ubicacion en fila por la funcion getFila
      Se debe haber obtenido la ubicacion en columna por la funcion getColumna
POST :  Se dibuja en el mapa la mina en su ubicacion correspondiente.
*/

void dibujarMina(Minas *minas,SDL_Renderer* renderer);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      La mina debe haber sido ubicada en el mapa por la funcion ubicarMina.
POST : Se producen minerales en la mina segun secuencia de intervalos.
*/
int generarMinerales(Minas &minas);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      La mina debe haber sido dibujada por la funcion dibujarMina.
      La locomotora debe haber chocado con la mina.
      Se debe tener los valores de las funciones getTipomineral y getSecuenciaproduccion.
POST : Si hay minerales en la mina y se tiene espacio disponible se le entrega minerales en bagon del mismo mineral al jugador.
*/
int entregarMinerales(Minas &minas);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : La mina es eliminada de la partida.
*/
void eliminarMina(Minas &minas);


#endif // MINAS_H_INCLUDED
