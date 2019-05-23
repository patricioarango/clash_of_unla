#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include <string>

#include "tren.h"

/* PARAMETROS
S: Segundos que dura un intervalo.
 P: cantidad máxima que puede pedir un bandido.
 A: posiciones para definir el área de Ataque de un bandido.
 posXE: posición x de la estación.
 posYE: posición y de la estación.
 IM: intervalo máximo para generación de monedas.
 VM: intervalos máximos de vida de una moneda.
 IB: máxima cantidad de intervalos para la aparición de bandidos.
 VB: tiempo máximo de vida de un bandido.
 IP: intervalos entre producciones de las minas.
/**/
using namespace std;

int main(int argc,char *argv[])
{
   if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
   {
        std::ifstream file("parametros.txt");
        std::string line;
        while (std::getline(file, line))
        {
	        std::string key = line.substr(0, line.find(":"));
            std::string value = line.substr(1, line.find(":"));

            if (key == "A"){
                cout << "el valor del parametro A" << value;
            }
        }

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"OK","SDL OK",NULL);
   }
    return 0;
}
