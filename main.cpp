#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include <string>
using namespace std;

int main(int argc,char *argv[])
{
   if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
   {
        std::ifstream file("parametros.txt");
        std::string str;
        while (std::getline(file, str))
        {
            cout << str;
        }

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"OK","SDL OK",NULL);
   }
    return 0;
}
