#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMA 5
struct compu
{
    int velocidad;
    int anio;
    int cantidad;
    char * tipo_cpu;
};
typedef struct compu Compu;

void listaPCs(Compu arreglo[], int longitud);

int main()
{
    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    Compu listaCompu[TAMA];
    srand(time(NULL));
    for (size_t i = 0; i < TAMA; i++)
    {
        //valores aleatorios
        listaCompu[i].velocidad = 1+rand()%4;
        listaCompu[i].anio = 2015 + rand()%9;
        listaCompu[i].cantidad = 1 + rand()%8;
        listaCompu[i].tipo_cpu = tipos[rand()%5];
    }
    listaPCs(listaCompu, TAMA);
    
    return 0;
}

void listaPCs(Compu arreglo[], int longitud){
    puts("\tFUNCION LISTAR PCs:");
    for (size_t i = 0; i < longitud; i++)
    {
        printf("  Computadora numero: %d\nNombre: %s\nAño: %d\nVelocidad: %d\nCantidad de nucleos: %d\n", i+1, arreglo[i].tipo_cpu, arreglo[i].anio, arreglo[i].velocidad, arreglo[i].cantidad);
    }
}