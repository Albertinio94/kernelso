#include "processgenerator.h"
#include <stdlib.h>

void processgenerator(cola *ready, unsigned int pid)
{
    pcb *procesoagenerar;
    nodo *nuevonodo;
    srand(time(NULL));
    procesoagenerar = malloc(sizeof(pcb));
    procesoagenerar->id = pid;
    procesoagenerar->tiempodevida = rand() % 600 + 400;
    procesoagenerar->quantum = rand() % 600 + 400;
    nuevonodo = malloc(sizeof(nodo));
    nuevonodo->pcbdelnodo = *procesoagenerar;
    nuevonodo->siguiente = NULL;
    ready->ultimo.siguiente = *nuevonodo;
    ready->ultimo = *nuevonodo;
}