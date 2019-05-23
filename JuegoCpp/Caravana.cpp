#include "Caravana.h"
#include "Carro.h"
void crearCaravana(Caravana &caravana){
    caravana.primero=NULL;
}
bool listaVacia(Caravana &caravana){
    return (caravana.primero == NULL);
}
PtrNodoCarro primero(Caravana &caravana){
    return caravana.primero;
}
PtrNodoCarro siguiente(Caravana &caravana, PtrNodoCarro ptrNodo){
    PtrNodoCarro ptrNodoAux=NULL;
    if ((!listaVacia(caravana)) && (ptrNodo != NULL)){
        ptrNodoAux = ptrNodo->siguiente;
    }
    return ptrNodoAux;
}
PtrNodoCarro anterior(Caravana &caravana, PtrNodoCarro ptrNodo){
    PtrNodoCarro ptrPrevio = NULL;
    PtrNodoCarro ptrCursor = primero(caravana);

    while (( ptrCursor != NULL) && (ptrCursor != ptrNodo)) {
        ptrPrevio = ptrCursor;
        ptrCursor = siguiente(caravana,ptrCursor);
    }

    return ptrPrevio;
}
PtrNodoCarro ultimo(Caravana &caravana){
    return anterior(caravana,NULL);
}
PtrNodoCarro crearNodo(Carro carro){
    PtrNodoCarro ptrAux = new Nodo;//reservo memoria para el nodo
    ptrAux->carro =carro;
    ptrAux->siguiente = NULL;
    return ptrAux;
}
PtrNodoCarro adicionarPrincipio(Caravana &caravana, Carro carro){
    PtrNodoCarro ptrNuevoNodo = crearNodo(carro);//crea el nodo
    ptrNuevoNodo->siguiente=caravana.primero;//lo incorpora al principio de la lista
    caravana.primero = ptrNuevoNodo;
    return ptrNuevoNodo;
}
PtrNodoCarro adicionarAntes(Caravana &caravana, Carro carro, PtrNodoCarro ptrNodo){
    PtrNodoCarro ptrNuevoNodo = NULL;
    if(listaVacia(caravana)){//si la lista esta vacia se adiciona al principio
        ptrNuevoNodo = adicionarPrincipio(caravana,carro);
    }else{
        if (ptrNodo != NULL){
            if(ptrNodo==primero(caravana)){
                ptrNuevoNodo = adicionarPrincipio(caravana,carro);
            }else{
                ptrNuevoNodo = crearNodo(carro);
                PtrNodoCarro nodoAnterior = anterior(caravana,ptrNodo);
                nodoAnterior->siguiente=ptrNuevoNodo;
                ptrNuevoNodo->siguiente = ptrNodo;
            }
        }
    }
    return ptrNuevoNodo;
}
PtrNodoCarro adicionarDespues(Caravana &caravana, Carro carro, PtrNodoCarro ptrNodo){
    PtrNodoCarro ptrNuevoNodo = NULL;
    if(listaVacia(caravana)){//si la lista esta vacia se adiciona al principio
        ptrNuevoNodo = adicionarPrincipio(caravana,carro);
    }else{
        if (ptrNodo != NULL){
            ptrNuevoNodo = crearNodo(carro);
            ptrNuevoNodo->siguiente = ptrNodo->siguiente;
            ptrNodo->siguiente = ptrNuevoNodo;
        }
    }
    return ptrNuevoNodo;
}
PtrNodoCarro adicionarUltimo(Caravana &caravana, Carro carro){
    return adicionarDespues(caravana,carro,ultimo(caravana));
}
void eliminarNodo(Caravana &caravana, PtrNodoCarro ptrNodo){
    if ((!listaVacia(caravana)) && (ptrNodo != NULL)) {//verifica que la lista no esté vacia y que ptrNodo exista
        if (ptrNodo == primero(caravana)){//si es el primero entonces hago que la lista apunte a su siguiente
            caravana.primero = siguiente(caravana,ptrNodo);
        }else {
            PtrNodoCarro ptrPrevio = anterior(caravana, ptrNodo);
            ptrPrevio->siguiente = ptrNodo->siguiente;
        }
        destruirCarro(ptrNodo->carro);//como circulo es un TDA hay que llamar a su destructor.
        delete ptrNodo;//borro el nodo
   }
}
void destruirCaravana(Caravana &caravana){
    while (!listaVacia(caravana)){
        eliminarNodo(caravana,primero(caravana));
    }
}
int longitud(Caravana &caravana){
    PtrNodoCarro ptrCursor = primero(caravana);
    int longitud = 0;
    while(ptrCursor != NULL) {
        longitud++;
        ptrCursor = siguiente(caravana, ptrCursor);
    }
    return longitud;
}
