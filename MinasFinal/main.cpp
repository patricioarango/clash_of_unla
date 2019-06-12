#include <iostream>//iostream: es una libreria que nos permite la entrada (cin) y salida (cout) de datos
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <conio.h>// agrega la funcuion getch(); que es trabante de procesos
#include <stdlib.h>//permite utilizar new y delete
#include <stdio.h>
#include <cstdlib>
#include <Windows.h>//sonido
#include <MMsystem.h>//sonido

#include <SDL.h>
#include <SDL_image.h>
#include "Minas.h"
#include "Secuenciaproduccion.h"
#include "Listaminas.h"
#include "Colaminas.h"
using namespace std;

struct datos{
int f;
int c;
string coditem;
int ip;
int secx[5];
}dato[6];
typedef struct datos DATO[6];
struct archivos{
int fa;
int ca;
char coditema[8];
int ipa;
int secxa[5];
}archivo;
typedef struct archivos ARCHIVO;
ResultadoComparacion compararListaMinas(PtrDato ptrDato1, PtrDato ptrDato2) {
    string dato1 = ((Minas*) ptrDato1)->tipo;
    string dato2 = ((Minas*) ptrDato2)->tipo;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}
void cargarminastxt();
void flush_stdin();
void verminastxt();
//void crearlistaminas(DATO);

int main(int argc, char** argv)
{
    int a,b,c,d,i;
    a=0;
    DATO m;
    m[0].coditem= "oro";
    m[0].f=3;
    m[0].c=4;
    m[0].ip=10;
    m[0].secx[0]=1;
    m[0].secx[1]=2;
    m[0].secx[2]=3;
    m[0].secx[3]=4;
    m[0].secx[4]=5;
    m[1].coditem= "plata";
    m[1].f=6;
    m[1].c=11;
    m[1].ip=10;
    m[1].secx[0]=1;
    m[1].secx[1]=2;
    m[1].secx[2]=3;
    m[1].secx[3]=4;
    m[1].secx[4]=5;
    m[2].coditem= "bronce";
    m[2].f=8;
    m[2].c=7;
    m[2].ip=5;
    m[2].secx[0]=3;
    m[2].secx[1]=4;
    m[2].secx[2]=5;
    m[2].secx[3]=6;
    m[2].secx[4]=7;
    m[3].coditem= "platino";
    m[3].f=13;
    m[3].c=14;
    m[3].ip=10;
    m[3].secx[0]=1;
    m[3].secx[1]=2;
    m[3].secx[2]=3;
    m[3].secx[3]=4;
    m[3].secx[4]=5;
    m[4].coditem= "roca";
    m[4].f=14;
    m[4].c=6;
    m[4].ip=5;
    m[4].secx[0]=3;
    m[4].secx[1]=4;
    m[4].secx[2]=5;
    m[4].secx[3]=6;
    m[4].secx[4]=7;
    m[5].coditem= "carbon";
    m[5].f=19;
    m[5].c=11;
    m[5].ip=5;
    m[5].secx[0]=3;
    m[5].secx[1]=4;
    m[5].secx[2]=5;
    m[5].secx[3]=6;
    m[5].secx[4]=7;
/**        for(i=0;i<6;i++){
    printf("coditem: %s \n",m[i].coditem.c_str());
    printf("posX: %i \n",m[i].f);
    printf("posY: %i \n",m[i].c);
    printf("intervalo de produccion: %i \n",m[i].ip);
    printf("1^ secuencia de produccion: %i \n",m[i].secx[0]);
    printf("2^ secuencia de produccion: %i \n",m[i].secx[1]);
    printf("3^ secuencia de produccion: %i \n",m[i].secx[2]);
    printf("4^ secuencia de produccion: %i \n",m[i].secx[3]);
    printf("5^ secuencia de produccion: %i \n",m[i].secx[4]);}
    printf("\n\n\n");
*/
while(a!=4){
            printf("1 cargar minas.txt\n2 Ver contenido minas.txt\n3 Arraca programa\n4 Salir\n");
    scanf("%d",&a);
switch(a){
case 1:
    for(i=0;i<6;i++){
        cargarminastxt();}
break;
case 2:
        verminastxt();
        printf("VOLVI DE LA FUNCION LEER\n\n\n");

    break;
case 3:{
    printf("NOCE PORQUE MIERDA ME QUEDO EN UN LOOP\n\n\n");
        int i;
    i=0;
    Lista minasTipo;
    crearLista(minasTipo, compararListaMinas);
    Minas* ptrMinas1 = new Minas;
    crearMina(*ptrMinas1);
    setc(*ptrMinas1, m[i].c);
    setf(*ptrMinas1, m[i].f);
    setintervaloproduccion(*ptrMinas1, m[i].ip);
    settipo(*ptrMinas1, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas1);

    Secuenciaproduccion* ptrsecuenciaProduccion1 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion1);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion1, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion1);

        Secuenciaproduccion* ptrsecuenciaProduccion2 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion2);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion2, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion2);

        Secuenciaproduccion* ptrsecuenciaProduccion3 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion3);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion3, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion3);

        Secuenciaproduccion* ptrsecuenciaProduccion4 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion4);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion4, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion4);

        Secuenciaproduccion* ptrsecuenciaProduccion5 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion5);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion5, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion5);
//-----------------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas2 = new Minas;
    crearMina(*ptrMinas2);
    setc(*ptrMinas2, m[i].c);
    setf(*ptrMinas2, m[i].f);
    setintervaloproduccion(*ptrMinas2, m[i].ip);
    settipo(*ptrMinas2, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas2);

    Secuenciaproduccion* ptrsecuenciaProduccion6 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion6);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion6, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion6);

        Secuenciaproduccion* ptrsecuenciaProduccion7 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion7);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion7, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion7);

        Secuenciaproduccion* ptrsecuenciaProduccion8 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion8);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion8, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion8);

        Secuenciaproduccion* ptrsecuenciaProduccion9 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion9);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion9, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion9);

        Secuenciaproduccion* ptrsecuenciaProduccion10 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion10);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion10, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion10);
//-------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas3 = new Minas;
    crearMina(*ptrMinas3);
    setc(*ptrMinas3, m[i].c);
    setf(*ptrMinas3, m[i].f);
    setintervaloproduccion(*ptrMinas3, m[i].ip);
    settipo(*ptrMinas3, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas3);

    Secuenciaproduccion* ptrsecuenciaProduccion11 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion11);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion11, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion11);

        Secuenciaproduccion* ptrsecuenciaProduccion12 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion12);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion12, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion12);

        Secuenciaproduccion* ptrsecuenciaProduccion13 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion13);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion13, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion13);

        Secuenciaproduccion* ptrsecuenciaProduccion14 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion14);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion14, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion14);

        Secuenciaproduccion* ptrsecuenciaProduccion15 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion15);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion15, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion15);
//-----------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas4 = new Minas;
    crearMina(*ptrMinas4);
    setc(*ptrMinas4, m[i].c);
    setf(*ptrMinas4, m[i].f);
    setintervaloproduccion(*ptrMinas4, m[i].ip);
    settipo(*ptrMinas4, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas4);

    Secuenciaproduccion* ptrsecuenciaProduccion16 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion16);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion16, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion16);

        Secuenciaproduccion* ptrsecuenciaProduccion17 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion17);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion17, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion17);

        Secuenciaproduccion* ptrsecuenciaProduccion18 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion18);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion18, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion18);

        Secuenciaproduccion* ptrsecuenciaProduccion19 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion19);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion19, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion19);

        Secuenciaproduccion* ptrsecuenciaProduccion20 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion20);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion20, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion20);
//-------------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas5 = new Minas;
    crearMina(*ptrMinas5);
    setc(*ptrMinas5, m[i].c);
    setf(*ptrMinas5, m[i].f);
    setintervaloproduccion(*ptrMinas5, m[i].ip);
    settipo(*ptrMinas5, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas5);

    Secuenciaproduccion* ptrsecuenciaProduccion21 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion21);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion21, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion21);

        Secuenciaproduccion* ptrsecuenciaProduccion22 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion22);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion22, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion22);

        Secuenciaproduccion* ptrsecuenciaProduccion23 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion23);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion23, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion23);

        Secuenciaproduccion* ptrsecuenciaProduccion24 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion24);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion24, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion24);

        Secuenciaproduccion* ptrsecuenciaProduccion25 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion25);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion25, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion25);
//----------------------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas6 = new Minas;
    crearMina(*ptrMinas6);
    setc(*ptrMinas6, m[i].c);
    setf(*ptrMinas6, m[i].f);
    setintervaloproduccion(*ptrMinas6, m[i].ip);
    settipo(*ptrMinas6, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas6);

    Secuenciaproduccion* ptrsecuenciaProduccion26 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion26);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion26, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion26);

        Secuenciaproduccion* ptrsecuenciaProduccion27 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion27);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion27, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion27);

        Secuenciaproduccion* ptrsecuenciaProduccion28 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion28);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion28, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion28);

        Secuenciaproduccion* ptrsecuenciaProduccion29 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion29);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion29, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion29);

        Secuenciaproduccion* ptrsecuenciaProduccion30 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion30);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion30, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion30);
    c=0;
    d=0;
    //se abre el juego
    for (b=0;b<100;b++){
        if (b%4==0){
        printf("numero de intervalo= %d , lingotes en mina= %d \n",b,c);
        }
        if(b%10==0){
                if(c==0){
                        switch(d){
                            case 0:
                                printf("se producieron lingotes\n");
          c = getSecprodSecuenciaproduccion(*ptrsecuenciaProduccion1);
        d++;
        break;
        case 1:
                                            printf("se producieron lingotes\n");
        c = getSecprodSecuenciaproduccion(*ptrsecuenciaProduccion2);
        d=0;
        }}}
        if(b%24==0){
            c=0;
        printf("ocurrio colision el tren se llevo los lingotes\n");
        }
    }
    eliminarLista(minasTipo);
    printf("lista eliminada\n\n");
    i=1;
    break;}
        case 4:
            break;
    default:{
    printf("eleccion no valida");
    break;}
}}
    return 0;
}

void cargarminastxt(){
        FILE *Minas;
    ARCHIVO a;
    Minas=fopen("Minas.txt","ab");


    printf("ingrese coditem: \n");fflush(stdin);
    gets(a.coditema);flush_stdin();
    printf("ingrese posX: \n");fflush(stdin);
    scanf("%i",&a.fa);flush_stdin();
    printf("ingrese posY: \n");fflush(stdin);
    scanf("%i",&a.ca);flush_stdin();
    printf("ingrese intervalo de produccion: \n");fflush(stdin);
    scanf("%i",&a.ipa);flush_stdin();
    printf("ingrese 1^ secuencia de produccion: \n");fflush(stdin);
    scanf("%i",&a.secxa[0]);flush_stdin();
    printf("ingrese 2^ secuencia de produccion: \n");fflush(stdin);
    scanf("%i",&a.secxa[1]);flush_stdin();
    printf("ingrese 3^ secuencia de produccion: \n");fflush(stdin);
    scanf("%i",&a.secxa[2]);flush_stdin();
    printf("ingrese 4^ secuencia de produccion: \n");fflush(stdin);
    scanf("%i",&a.secxa[3]);flush_stdin();
    printf("ingrese 5^ secuencia de produccion: \n");fflush(stdin);
    scanf("%i",&a.secxa[4]);flush_stdin();
    fwrite(&a,sizeof(a),1,Minas);

    fclose(Minas);
}

void flush_stdin(){
    int ch;
    while ((ch= getchar()) != '\n' && ch != EOF );
}

void verminastxt(){
    FILE *Minas;
    ARCHIVO a;
    Minas=fopen("Minas.txt","rb");
    fread(&a,sizeof(a),1,Minas);
    while(feof(Minas)==0){
    printf("coditem: %s \n",a.coditema);
    printf("posX: %i \n",a.fa);
    printf("posY: %i \n",a.ca);
    printf("intervalo de produccion: %i \n",a.ipa);
    printf("1^ secuencia de produccion: %i \n",a.secxa[0]);
    printf("2^ secuencia de produccion: %i \n",a.secxa[1]);
    printf("3^ secuencia de produccion: %i \n",a.secxa[2]);
    printf("4^ secuencia de produccion: %i \n",a.secxa[3]);
    printf("5^ secuencia de produccion: %i \n",a.secxa[4]);
    fread(&a,sizeof(a),1,Minas);
    }
    fclose(Minas);

}
/**
void crearlistaminas(DATO){
    int i;
    i=0;
    DATO m;
    Lista minasTipo;
    crearLista(minasTipo, compararListaMinas);
    Minas* ptrMinas1 = new Minas;
    crearMina(*ptrMinas1);
    setc(*ptrMinas1, m[i].c);
    setf(*ptrMinas1, m[i].f);
    setintervaloproduccion(*ptrMinas1, m[i].ip);
    settipo(*ptrMinas1, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas1);

    Secuenciaproduccion* ptrsecuenciaProduccion1 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion1);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion1, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion1);

        Secuenciaproduccion* ptrsecuenciaProduccion2 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion2);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion2, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion2);

        Secuenciaproduccion* ptrsecuenciaProduccion3 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion3);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion3, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion3);

        Secuenciaproduccion* ptrsecuenciaProduccion4 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion4);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion4, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion4);

        Secuenciaproduccion* ptrsecuenciaProduccion5 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion5);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion5, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas1, ptrsecuenciaProduccion5);
//-----------------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas2 = new Minas;
    crearMina(*ptrMinas2);
    setc(*ptrMinas2, m[i].c);
    setf(*ptrMinas2, m[i].f);
    setintervaloproduccion(*ptrMinas2, m[i].ip);
    settipo(*ptrMinas2, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas2);

    Secuenciaproduccion* ptrsecuenciaProduccion6 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion6);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion6, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion6);

        Secuenciaproduccion* ptrsecuenciaProduccion7 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion7);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion7, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion7);

        Secuenciaproduccion* ptrsecuenciaProduccion8 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion8);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion8, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion8);

        Secuenciaproduccion* ptrsecuenciaProduccion9 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion9);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion9, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion9);

        Secuenciaproduccion* ptrsecuenciaProduccion10 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion10);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion10, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas2, ptrsecuenciaProduccion10);
//-------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas3 = new Minas;
    crearMina(*ptrMinas3);
    setc(*ptrMinas3, m[i].c);
    setf(*ptrMinas3, m[i].f);
    setintervaloproduccion(*ptrMinas3, m[i].ip);
    settipo(*ptrMinas3, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas3);

    Secuenciaproduccion* ptrsecuenciaProduccion11 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion11);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion11, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion11);

        Secuenciaproduccion* ptrsecuenciaProduccion12 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion12);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion12, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion12);

        Secuenciaproduccion* ptrsecuenciaProduccion13 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion13);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion13, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion13);

        Secuenciaproduccion* ptrsecuenciaProduccion14 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion14);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion14, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion14);

        Secuenciaproduccion* ptrsecuenciaProduccion15 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion15);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion15, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas3, ptrsecuenciaProduccion15);
//-----------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas4 = new Minas;
    crearMina(*ptrMinas4);
    setc(*ptrMinas4, m[i].c);
    setf(*ptrMinas4, m[i].f);
    setintervaloproduccion(*ptrMinas4, m[i].ip);
    settipo(*ptrMinas4, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas4);

    Secuenciaproduccion* ptrsecuenciaProduccion16 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion16);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion16, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion16);

        Secuenciaproduccion* ptrsecuenciaProduccion17 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion17);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion17, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion17);

        Secuenciaproduccion* ptrsecuenciaProduccion18 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion18);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion18, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion18);

        Secuenciaproduccion* ptrsecuenciaProduccion19 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion19);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion19, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion19);

        Secuenciaproduccion* ptrsecuenciaProduccion20 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion20);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion20, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas4, ptrsecuenciaProduccion20);
//-------------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas5 = new Minas;
    crearMina(*ptrMinas5);
    setc(*ptrMinas5, m[i].c);
    setf(*ptrMinas5, m[i].f);
    setintervaloproduccion(*ptrMinas5, m[i].ip);
    settipo(*ptrMinas5, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas5);

    Secuenciaproduccion* ptrsecuenciaProduccion21 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion21);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion21, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion21);

        Secuenciaproduccion* ptrsecuenciaProduccion22 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion22);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion22, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion22);

        Secuenciaproduccion* ptrsecuenciaProduccion23 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion23);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion23, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion23);

        Secuenciaproduccion* ptrsecuenciaProduccion24 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion24);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion24, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion24);

        Secuenciaproduccion* ptrsecuenciaProduccion25 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion25);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion25, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas5, ptrsecuenciaProduccion25);
//----------------------------------------------------------------------------------------------------------------
    i++;
    Minas* ptrMinas6 = new Minas;
    crearMina(*ptrMinas6);
    setc(*ptrMinas6, m[i].c);
    setf(*ptrMinas6, m[i].f);
    setintervaloproduccion(*ptrMinas6, m[i].ip);
    settipo(*ptrMinas6, m[i].coditem);

    adicionarFinal(minasTipo, ptrMinas6);

    Secuenciaproduccion* ptrsecuenciaProduccion26 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion26);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion26, m[i].secx[0]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion26);

        Secuenciaproduccion* ptrsecuenciaProduccion27 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion27);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion27, m[i].secx[1]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion27);

        Secuenciaproduccion* ptrsecuenciaProduccion28 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion28);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion28, m[i].secx[2]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion28);

        Secuenciaproduccion* ptrsecuenciaProduccion29 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion29);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion29, m[i].secx[3]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion29);

        Secuenciaproduccion* ptrsecuenciaProduccion30 = new Secuenciaproduccion;
    crearSecuenciaproduccion(*ptrsecuenciaProduccion30);
    setSecprodSecuenciaproduccion(*ptrsecuenciaProduccion30, m[i].secx[4]);

    agregarsecuenciaproduccionmina(*ptrMinas6, ptrsecuenciaProduccion30);

}
*/
