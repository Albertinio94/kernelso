#include "processgenerator.h"
#include <stdlib.h>

nodo *init_nodo(unsigned int pid);
void assign_pcb(nodo *nodo, unsigned int pid);
void processgenerator_routine(cola *ready, unsigned int pid);

void processgenerator_routine(cola *ready, unsigned int pid)
{
    pcb *procesoagenerar;
    nodo *nuevonodo;
    nuevonodo = init_nodo(pid);
    encolar(ready, nuevonodo);
}

nodo *init_nodo(unsigned int pid)
{
    nodo *nuevonodo;
    nuevonodo = malloc(sizeof(nodo));
    assign_pcb(nuevonodo, pid);
    nuevonodo->siguiente = NULL;
    nuevonodo->anterior = NULL;
    return nuevonodo;
}

void assign_pcb(nodo *nodo, unsigned int pid)
{
    nodo->pcbdelnodo.id = pid;
    nodo->pcbdelnodo.quantum = rand() % 600 + 401;
    nodo->pcbdelnodo.tiempodevida = rand() % 1000 + 401;
}