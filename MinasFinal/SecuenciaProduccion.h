#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
#ifndef SECUENCIAPRODUCCION_H_INCLUDED
#define SECUENCIAPRODUCCION_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

typedef struct{
    int secprod;
    } Secuenciaproduccion;

/**
  pre : la Secuenciaproduccion no debe haber sido creado.
  post: Secuenciaproduccion queda creado y preparado para ser usado.

  Secuenciaproduccion: estructura de datos a ser creada.
*/

void crearSecuenciaproduccion(Secuenciaproduccion &secuenciaproduccion);

/*----------------------------------------------------------------------------*/
/**
  pre : Secuenciaproduccion creado con crearSecuenciaproduccion().
  post: el campo Secprod pasa a contener el dato ingresado.

  Secuenciaproduccion: estructura sobre la cual se invoca la primitiva.
  dato: dato a ingresarse.
*/

void setSecprodSecuenciaproduccion(Secuenciaproduccion &secuenciaproduccion, int dato);

/**
  pre : Secuenciaproduccion creado con crearSecuenciaproduccion().
  post: devuelve el dato contenido en el campo Secprod.

  mina : estructura sobre la cual se invoca la primitiva.
*/

int getSecprodSecuenciaproduccion (Secuenciaproduccion &secuenciaproduccion);


/**
  pre : secuenciaproduccion creado con crearSecuenciaproduccion().

  mina : estructura sobre la cual se invoca la primitiva.
*/

void eliminarSecuenciaproduccion(Secuenciaproduccion &secuenciaproduccion);
#endif // SECUENCIAPRODUCCION_H_INCLUDED
