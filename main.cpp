#include <iostream>//iostream: es una libreria que nos permite la entrada (cin) y salida (cout) de datos
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <conio.h>// agrega la funcuion getch(); que es trabante de procesos
#include <stdlib.h>//permite utilizar new y delete

#include <Windows.h>//sonido
#include <MMsystem.h>//sonido

#include <SDL.h>
#include <SDL_image.h>

#include "Partida.h"
#include "Caravana.h"
#include "Carro.h"
#include "Villano.h"
#include "Mina.h"
#include "Moneda.h"

using namespace std;

#define milisegundos 30

void evaluarEventosTeclado(Partida &partida,SDL_Event &event,const unsigned char *keys);
void cambiarDireccion(PtrNodoCarro ptrNodo,char direccion[]);

void cambiarCapaInicio(Partida &partida,PtrNodoCarro ptrNodo);
void cambiarCapaFinal(Partida &partida,PtrNodoCarro ptrNodo);
void cambiarColumna(Partida &partida,PtrNodoCarro ptrNodo);
bool evaluarColisiones(Partida &partida,PtrNodoCarro ptrNodo);
int main(int argc, char** argv) {
        PlaySound(TEXT("media/musica.wav"),NULL, SND_ASYNC);
        //Si no se escucha la música es porque hay que agregar un linck al codeblocks:
        //settings->complier...->linker settings-> link libraries-> add-> escribimos winmm ->aceptamos todo.
        /*datros que leo desde un archivo************/
        int filas = 8;
        int columnas = 10;
        int anchoCasillero = 70;
        int altoCasillero = 40;
        int altoSprite = 70;
        /********************************************/
        int anchoVentana = (columnas+2)*anchoCasillero;
        int altoVentana = (filas+2)*altoCasillero;


    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){

        SDL_Window *window;
        SDL_Renderer *renderer;

        window = SDL_CreateWindow(
            "WesternGame",
            SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
            anchoVentana,altoVentana,
            SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC
            );

        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        IMG_Init(IMG_INIT_PNG);

        SDL_Event event;
        const unsigned char *keys;
        keys = SDL_GetKeyboardState(NULL);

        Partida partida;
        crearPartida(partida,filas,columnas,anchoCasillero,altoCasillero,altoSprite);
        setTablero(partida,renderer);
        setMapa(partida);

        Caravana caravana;
        crearCaravana(caravana);
        Carro carro;
        crearCarro(carro,"c1", 0, 4,"der",anchoCasillero, altoCasillero, altoSprite);//el primero es c1
        ubicarCarro(partida,adicionarPrincipio(caravana,carro));
        setDireccion(partida,getDireccion(primero(caravana)->carro));//la direccion de la partida es = a la del primer carro

        crearCarro(carro,"c2", 0, 3,"der",anchoCasillero, altoCasillero, altoSprite);//los demás son c2
        ubicarCarro(partida,adicionarUltimo(caravana,carro));
        crearCarro(carro,"c2", 0, 2,"der",anchoCasillero, altoCasillero, altoSprite);
        ubicarCarro(partida,adicionarUltimo(caravana,carro));
        crearCarro(carro,"c2", 0, 1,"der",anchoCasillero, altoCasillero, altoSprite);
        ubicarCarro(partida,adicionarUltimo(caravana,carro));
        crearCarro(carro,"c2", 0, 0,"der",anchoCasillero, altoCasillero, altoSprite);
        ubicarCarro(partida,adicionarUltimo(caravana,carro));

        Villano villano;
        Villano *ptrVillano = &villano;
        crearVillano(villano,renderer,4,4,anchoCasillero, altoCasillero, altoSprite);
        ubicarVillano(partida,ptrVillano);

        Mina mina;
        Mina *ptrMina = &mina;
        crearMina(mina,renderer,4,2,anchoCasillero, altoCasillero, altoSprite);
        ubicarMina(partida,ptrMina);

        Moneda moneda;
        Moneda *ptrMoneda = &moneda;
        crearMoneda(moneda,renderer,4,6,anchoCasillero, altoCasillero, altoSprite);
        ubicarMoneda(partida,ptrMoneda);


        dibujarTablero(partida,renderer);
        SDL_RenderPresent(renderer);//APLICA EL CAMBIO
        SDL_Delay(500);
        while(!getGameOver(partida)){

            evaluarEventosTeclado(partida,event,keys);//setea la direccion siguiente en partida.direccion

            if(getIntervalo(partida)==10){
                setIntervalo(partida,0);

                cambiarColumna(partida,primero(caravana));//fila del tablero
                cambiarCapaFinal(partida,primero(caravana));//capa del mapa
                //hasta aca todos los carritos se encuentran en su punto casilla de tablero
                //podemos evaluar la adquisición de monedas, de minas o ataques de villanos

                //luego redireccionamos a todos los carros desde el primero
                cambiarDireccion(primero(caravana),getDireccion(partida));

                setGameOver(partida,evaluarColisiones(partida,primero(caravana)));

            }
            if(!getGameOver(partida)){
                if(getIntervalo(partida)==1){
                    //desde el princpio de la lista, si se mira hacia abajo o hacia arribaen el intervalo 1
                    //entonces lo desplazo a la siquietne capa
                    cambiarCapaInicio(partida,primero(caravana));//capa del mapa
                }
                //Render
                SDL_RenderClear(renderer);//borro todo
                dibujarTablero(partida,renderer);
                SDL_RenderPresent(renderer);//APLICA EL CAMBIO
                SDL_Delay(milisegundos);

                setIntervalo(partida,getIntervalo(partida)+1);//partida.intervalo++;
            }
        }//FIN DEL BUCLE
        cout<<"Destruimos caravana"<<endl;
        destruirCaravana(caravana);
        cout<<"Destruimos partida"<<endl;
        destruirPartida(partida);
        cout<<"Destruimos renderer"<<endl;
        SDL_DestroyRenderer(renderer);
        cout<<"Destruimos window"<<endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        cout<<"GAME OVER!"<<endl;
    }//find el if
    cout<<"presione una tecla para salir..."<<endl;
    getch();
    return 0;
}
bool evaluarColisiones(Partida &partida,PtrNodoCarro ptrNodo){
    bool colision=true;
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(getDireccion(ptrNodo->carro),"aba")==0)desplazamientoVertical=1;
    if(strcmp(getDireccion(ptrNodo->carro),"arr")==0)desplazamientoVertical=-1;
    if(strcmp(getDireccion(ptrNodo->carro),"der")==0)desplazamientoHorizontal=1;
    if(strcmp(getDireccion(ptrNodo->carro),"izq")==0)desplazamientoHorizontal=-1;

    int c=getColumna(ptrNodo->carro)+desplazamientoHorizontal;
    int f=getFila(ptrNodo->carro)+desplazamientoVertical;

    if((c>=0 && c<getColumnaLimite(partida)) && (f>=0 && f<getFilaLimite(partida))){
        //el tren aun se encuentra en el tablero!
        Casillero casilleroAux =getTablero(partida)[f][c];
        if(casilleroAux.ptrNodoCarro==NULL){
            //y el tren no se chocoará con otro vagón
            colision=false;
        }else{
            cout<<"Chocamos con otro carro en "<<f<<"/"<<c<<endl;
        }
    }else{
        cout<<"Nos salimos del cuadrante en "<<f<<"/"<<c<<endl;
    }
    return colision;
}
void cambiarColumna(Partida &partida,PtrNodoCarro ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->carro),"der")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->carro),"izq")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Mapa **mapaAux=getMapa(partida);// partida.mapa
            mapaAux[getFila(ptrNodo->carro)*2][getColumna(ptrNodo->carro)].ptrNodoCarro=NULL;
            mapaAux[getFila(ptrNodo->carro)*2][getColumna(ptrNodo->carro)+desplazamiento].ptrNodoCarro=ptrNodo;
            Casillero **tableroAux=getTablero(partida);// partida.tablero
            tableroAux[getFila(ptrNodo->carro)][getColumna(ptrNodo->carro)].ptrNodoCarro=NULL;
            tableroAux[getFila(ptrNodo->carro)][getColumna(ptrNodo->carro)+desplazamiento].ptrNodoCarro=ptrNodo;
            setColumna(ptrNodo->carro,desplazamiento);
        }
        cambiarColumna(partida,ptrNodo->siguiente);
    }
}
void cambiarCapaInicio(Partida &partida, PtrNodoCarro ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->carro),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->carro),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Mapa **mapaAux=getMapa(partida);// partida.mapa
            mapaAux[getFila(ptrNodo->carro)*2][getColumna(ptrNodo->carro)].ptrNodoCarro=NULL;
            mapaAux[(getFila(ptrNodo->carro)*2)+desplazamiento][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;
            Casillero **tableroAux=getTablero(partida);// partida.mapa
            tableroAux[getFila(ptrNodo->carro)][getColumna(ptrNodo->carro)].ptrNodoCarro=NULL;
        }
        cambiarCapaInicio(partida,ptrNodo->siguiente);
    }
}
void cambiarCapaFinal(Partida &partida, PtrNodoCarro ptrNodo){
    if(ptrNodo!=NULL){
        int desplazamiento=0;
        if(strcmp(getDireccion(ptrNodo->carro),"aba")==0)desplazamiento=1;//subo una capa
        if(strcmp(getDireccion(ptrNodo->carro),"arr")==0)desplazamiento=-1;//bajo una capa
        if(desplazamiento!=0){
            Mapa **mapaAux=getMapa(partida);// partida.mapa
            mapaAux[(getFila(ptrNodo->carro)*2)+desplazamiento][getColumna(ptrNodo->carro)].ptrNodoCarro=NULL;
            mapaAux[(getFila(ptrNodo->carro)*2)+desplazamiento+desplazamiento][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;
            Casillero **tableroAux=getTablero(partida);// partida.mapa
            tableroAux[getFila(ptrNodo->carro)+desplazamiento][getColumna(ptrNodo->carro)].ptrNodoCarro=ptrNodo;
            setFila(ptrNodo->carro,desplazamiento);//actualizo la fila en la que se encuentra
        }
        cambiarCapaFinal(partida,ptrNodo->siguiente);
    }
}
void cambiarDireccion(PtrNodoCarro ptrNodo,char direccion[]){
    if(ptrNodo!=NULL){
        //validar la direccion;
        char dirAnterior[4];
        strcpy(dirAnterior,getDireccion(ptrNodo->carro));//guardo la direccion anterior
        //si dirAnterior es izq entonces direccion no puede ser der
        //si dirAnterior es der entonces direccion no puede ser izq
        //si dirAnterior es arr entonces direccion no puede ser aba
        //si dirAnterior es aba entonces direccion no puede ser arr
        if(
            (strcmp(dirAnterior,"izq")==0 && strcmp(direccion,"der")!=0) ||
            (strcmp(dirAnterior,"der")==0 && strcmp(direccion,"izq")!=0) ||
            (strcmp(dirAnterior,"arr")==0 && strcmp(direccion,"aba")!=0) ||
            (strcmp(dirAnterior,"aba")==0 && strcmp(direccion,"arr")!=0)
        ){
            setDireccion(ptrNodo->carro,direccion);//cargo la nueva dirección
        }
        cambiarDireccion(ptrNodo->siguiente,dirAnterior);
    }
}
void evaluarEventosTeclado(Partida &partida,SDL_Event &event,const unsigned char *keys){
    if(SDL_PollEvent(&event)){//indica que hay eventos pendientes
        switch(event.type){
            case SDL_QUIT:
                setGameOver(partida, true);
            break;
            case SDL_KEYDOWN:
                if(keys[SDL_SCANCODE_ESCAPE]){
                    setGameOver(partida, true);
                }
                if(keys[SDL_SCANCODE_LEFT]){
                    setDireccion(partida,"izq");
                }
                if(keys[SDL_SCANCODE_RIGHT]){
                    setDireccion(partida,"der");
                }
                if(keys[SDL_SCANCODE_UP]){
                    setDireccion(partida,"arr");
                }
                if(keys[SDL_SCANCODE_DOWN]){
                    setDireccion(partida,"aba");
                }
                if(keys[SDL_SCANCODE_SPACE]){
                    //
                }
                break;
                /*
            case SDL_MOUSEBUTTONDOWN:
                if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "CLICK","Con el boton izquierdo del mouse.",NULL);
                }
                break;
                */
        }
    }
}
