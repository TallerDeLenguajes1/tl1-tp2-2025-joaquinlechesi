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
void mostrarMasVieja(Compu arreglo[], int longitud);
void mostrarMasVeloz(Compu arreglo[], int longitud);

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
    mostrarMasVieja(listaCompu, TAMA);
    mostrarMasVeloz(listaCompu, TAMA);
    
    return 0;
}

void listaPCs(Compu arreglo[], int longitud){
    puts("\tFUNCION LISTAR PCs:");
    for (size_t i = 0; i < longitud; i++)
    {
        printf("  Computadora numero: %d\nNombre: %s\nAño: %d\nVelocidad: %d Ghz\nCantidad de nucleos: %d\n", i+1, arreglo[i].tipo_cpu, arreglo[i].anio, arreglo[i].velocidad, arreglo[i].cantidad);
    }
}

void mostrarMasVieja(Compu arreglo[], int longitud){
    puts("\tFUNCION PC MAS ANTIGUA:");
    int posicion = 0;
    int anio = arreglo[0].anio;
    for (size_t i = 0; i < longitud; i++)
    {
        if (arreglo[i].anio < anio)
        {
            anio = arreglo[i].anio;
            posicion = i;
        }
    }
    printf("Nombre: %s\nAño: %d\nVelocidad: %d Ghz\nCantidad de nucleos: %d", arreglo[posicion].tipo_cpu, arreglo[posicion].anio, arreglo[posicion].velocidad, arreglo[posicion].cantidad);
}

void mostrarMasVeloz(Compu arreglo[], int longitud){
    puts("\n\tFUNCION PC MAS VELOZ");
    int posicion;
    int velocidad = arreglo[0].velocidad;
    for (size_t i = 0; i < longitud; i++)
    {
        if (arreglo[i].velocidad > velocidad)
        {
            velocidad = arreglo[i].velocidad;
            posicion = i;
        }
    }
    printf("Nombre: %s\nAño: %d\nVelocidad: %d Ghz\nCantidad %d", arreglo[posicion].tipo_cpu, arreglo[posicion].anio, arreglo[posicion].velocidad, arreglo[posicion].cantidad);
}