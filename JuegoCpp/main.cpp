#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#define x_size 600
#define y_size 600
#define nave_size 20
#define nave_vel 5
#define misil_size 10
#define misil_vel -5
#define milisegundos 20
#define IMG_PATH "fondo.png"

struct Misil{//una linea
    int x1,y1;
    int x2,y2;
    int vx,vy;
    Misil *siguiente;
};
struct Nave{//un triangulo
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int vx,vy;
    Misil *misiles;
};
void dibujarNave(Nave *nave, SDL_Renderer *renderer);
void naveDispara(Nave *nave);
void misilAvanza(Misil *misil);
void borrarMisil(Misil *misil);
void dibujarFondo(SDL_Renderer *renderer,SDL_Texture *background,SDL_Rect *rectanguloBackground);

int main(int argc,char *argv[]){

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){

        SDL_Window *window;
        SDL_Renderer *renderer;

        window = SDL_CreateWindow(
            "Titulo de la ventana",
            SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
            x_size,y_size,
            SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC
            );

        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


        int typeEvent;
        SDL_Event event;
        const unsigned char *keys;
        keys = SDL_GetKeyboardState(NULL);

        int gameOver=false;

        Nave nave ={
            x_size/2,y_size/2,
            (x_size/2)-nave_size,(y_size/2)+nave_size,
            (x_size/2)+nave_size,(y_size/2)+nave_size,
            nave_vel,nave_vel,NULL};

        IMG_Init(IMG_INIT_PNG);
        SDL_Texture *imagen = NULL;
        SDL_Rect rectImag;
        int w_aux=0,h_aux=0;
        imagen=IMG_LoadTexture(renderer,"fondo.png");
        SDL_QueryTexture(imagen,NULL,NULL,&w_aux,&h_aux);
        rectImag.x=0;rectImag.y=0;rectImag.w=w_aux;rectImag.h=h_aux;


        while(gameOver==false){
            //EVENTOS
            if(SDL_PollEvent(&event)){//indica que hay eventos pendientes
                typeEvent=event.type;
                switch(typeEvent){
                    case SDL_QUIT:
                        gameOver=true;
                    break;
                    case SDL_KEYDOWN:
                        if(keys[SDL_SCANCODE_ESCAPE]){
                            gameOver=true;
                        }
                        if(keys[SDL_SCANCODE_LEFT]){
                            nave.x1 -=nave.vx;
                            nave.x2 -=nave.vx;
                            nave.x3 -=nave.vx;
                        }
                        if(keys[SDL_SCANCODE_RIGHT]){
                            nave.x1 +=nave.vx;
                            nave.x2 +=nave.vx;
                            nave.x3 +=nave.vx;
                        }
                        if(keys[SDL_SCANCODE_UP]){
                            nave.y1 -=nave.vy;
                            nave.y2 -=nave.vy;
                            nave.y3 -=nave.vy;
                        }
                        if(keys[SDL_SCANCODE_DOWN]){
                            nave.y1 +=nave.vy;
                            nave.y2 +=nave.vy;
                            nave.y3 +=nave.vy;
                        }
                        if(keys[SDL_SCANCODE_SPACE]){
                            naveDispara(&nave);
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "CLICK","Con el boton izquierdo del mouse.",NULL);
                        }
                        break;
                }
            }

            //Evaluo el escenario
            borrarMisil(nave.misiles);//borramos los misiles fuera

            //Render
            SDL_RenderClear(renderer);//borro todo
            dibujarFondo(renderer,imagen,&rectImag);
            dibujarNave(&nave,renderer);

            SDL_RenderPresent(renderer);//APLICA EL CAMBIO
            SDL_Delay(milisegundos);

        }//FIN DEL BUCLE

        SDL_DestroyTexture(imagen);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    }//find el if

    return 0;
}//fin del programa

void dibujarNave(Nave *nave, SDL_Renderer *renderer){

    SDL_SetRenderDrawColor(renderer,255,255,255,0);//pintamos la nave
    Misil *nextMisil=nave->misiles;
    while (nextMisil!=NULL){
            misilAvanza(nextMisil);
        SDL_RenderDrawLine(renderer, nextMisil->x1,nextMisil->y1,nextMisil->x2,nextMisil->y2);
        nextMisil=nextMisil->siguiente;
    }
    SDL_Point puntos[4] = {
        {nave->x1,nave->y1},
        {nave->x2,nave->y2},
        {nave->x3,nave->y3}
    };
    puntos[3]=puntos[0];
    SDL_RenderDrawLines(renderer, puntos,4);//contamos el primer punto dos veces

}
void misilAvanza(Misil *misil){
    misil->x1+=misil->vx;
    misil->y1+=misil->vy;
    misil->x2+=misil->vx;
    misil->y2+=misil->vy;
}
void naveDispara(Nave *nave){
    if(nave->misiles == NULL){
        nave->misiles=(Misil *)SDL_malloc(sizeof(Misil));
        nave->misiles->x1=nave->x1;
        nave->misiles->y1=nave->y1;
        nave->misiles->x2=nave->x1;
        nave->misiles->y2=nave->y2 - misil_size;
        nave->misiles->vx=0;
        nave->misiles->vy=misil_vel;
        nave->misiles->siguiente=NULL;
    }else{
        Misil *nextMisil = nave->misiles;
        while (nextMisil->siguiente !=NULL){
            nextMisil = nextMisil->siguiente;
        }
        nextMisil->siguiente = (Misil *)SDL_malloc(sizeof(Misil));
        nextMisil = nextMisil->siguiente;
        nextMisil->x1 = nave->x1;
        nextMisil->y1 = nave->y1;
        nextMisil->x2 =nave->x1;
        nextMisil->y2 = nave->y1 - misil_size;
        nextMisil->vx=0;
        nextMisil->vy= misil_vel;
        nextMisil->siguiente=NULL;

    }
}
void borrarMisil(Misil *misiles){
    Misil *nextMisil = misiles;
    if(nextMisil!=NULL){
        Misil *auxMisil;
        while(nextMisil->siguiente !=NULL){
            if(nextMisil->siguiente->y1<0){
                auxMisil = nextMisil->siguiente->siguiente;
                SDL_free(nextMisil->siguiente);
                nextMisil->siguiente=auxMisil;
            }else{
                nextMisil = nextMisil->siguiente;
            }
        }
    }
}
void dibujarFondo(SDL_Renderer *renderer,SDL_Texture *imagen,SDL_Rect *rectImag){
    SDL_SetRenderDrawColor(renderer,0,0,0,0);//RGB0
    SDL_RenderCopy(renderer,imagen,NULL,rectImag);

    /*//para rotar una figura y dibujarla en un punto en particular
    SDL_Point centro;
    centro.x=0;centro.y=0;
    SDL_RenderCopyEx(renderer,background,NULL,rectanguloBackground,90,centro,SDL_FLIP_NONE);
    */
}
