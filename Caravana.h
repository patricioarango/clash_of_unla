#ifndef __CARAVANA_H__
#define __CARAVANA_H__

#include "Carro.h"

#ifndef NULL
#define NULL 0
#endif

struct Nodo{
    Carro carro;
	Nodo* siguiente;
};
typedef Nodo* PtrNodoCarro;

typedef struct{
	PtrNodoCarro primero;
}Caravana;

void crearCaravana(Caravana &caravana);
bool listaVacia(Caravana &caravana);
PtrNodoCarro primero(Caravana &caravana);
PtrNodoCarro siguiente(Caravana &caravana, PtrNodoCarro ptrNodoCarro);
PtrNodoCarro anterior(Caravana &caravana, PtrNodoCarro ptrNodoCarro);
PtrNodoCarro ultimo(Caravana &caravana);
PtrNodoCarro crearNodo(Carro carro);
PtrNodoCarro adicionarPrincipio(Caravana &caravana, Carro carro);
PtrNodoCarro adicionarAntes(Caravana &caravana, Carro carro, PtrNodoCarro ptrNodoCarro);
PtrNodoCarro adicionarDespues(Caravana &caravana, Carro carro, PtrNodoCarro ptrNodoCarro);
PtrNodoCarro adicionarUltimo(Caravana &caravana, Carro carro);
void eliminarNodo(Caravana &caravana, PtrNodoCarro ptrNodoCarro);
void destruirCaravana(Caravana &caravana);
int longitud(Caravana &caravana);
/*----------------------------------------------------------------------------*/

#endif

