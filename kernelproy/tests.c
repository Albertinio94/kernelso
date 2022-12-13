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
    nodo *nodopruebas1, *nodopruebas2;
    pcbpruebas.id=1;
    nodopruebas1 = (nodo *) malloc(sizeof(nodo));
    nodopruebas1->pcbdelnodo = pcbpruebas;
    pcbpruebas.id=2;
    nodopruebas2 = (nodo *) malloc(sizeof(nodo));
    nodopruebas2->pcbdelnodo = pcbpruebas;

    cola colapruebas;
    
    encolar(&colapruebas, &nodopruebas0);
    printf("el id del primer nodo de la cola es %d\n", colapruebas.primero->pcbdelnodo.id);
    encolar(&colapruebas, nodopruebas1);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    if (nodopruebas0.siguiente != NULL) printf ("Y el primer nodo apunta a algo siguiente\n");
    if (nodopruebas1->anterior != NULL) printf ("Y el ultimo nodo apunta a algo anterior\n");
    encolar(&colapruebas, nodopruebas2);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    desencolar(&colapruebas, nodopruebas1);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    desencolar(&colapruebas, nodopruebas2);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    if (colapruebas.primero == colapruebas.ultimo) printf ("La cola solo tiene un elemento\n");


    return 0;
}
