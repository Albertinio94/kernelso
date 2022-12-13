#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main(int argc, char const *argv[])
{
    pcb pcbpruebas = {
        .id = 0,
        .quantum = 100,
        .tiempodevida = 1000
    };

    nodo nodopruebas0 = {
        .anterior=NULL,
        .siguiente=NULL,
        .pcbdelnodo=pcbpruebas
    };
    pcbpruebas.id=1;
    nodo nodopruebas1 = {
        .anterior=NULL,
        .siguiente=NULL,
        .pcbdelnodo=pcbpruebas
    };
    cola colapruebas;
    
    encolar(&colapruebas, &nodopruebas0);
    printf("el id del primer nodo de la cola es %d\n", colapruebas.primero->pcbdelnodo.id);
    encolar(&colapruebas, &nodopruebas1);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    desencolar(&colapruebas, &nodopruebas1);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);


    return 0;
}
