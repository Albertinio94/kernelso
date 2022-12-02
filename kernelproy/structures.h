#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>

typedef struct
{
    unsigned int id;
    int tiempodevida;
    int quantum;
} pcb;
struct nodo
{
    pcb pcbdelnodo;
    nodo *siguiente;
    nodo *anterior;
};
typedef struct nodo nodo;
struct cola
{
    nodo *primero;
    nodo *ultimo;
};
typedef struct cola cola;
struct argumentosparaclockytimer
{
    pthread_mutex_t mutex;
    pthread_cond_t condicion1;
    pthread_cond_t condicion2;
    int done;
    int cantidadtemporizadores;
    cola *preparados;
    cola *bloqueados;
};
typedef struct argumentosparaclockytimer argumentosparaclockytimer;

void encolar(cola *cola_a_encolar, nodo *nodo_a_encolar);
void desencolar(cola *cola_a_desencolar, nodo *nodo_a_desencolar);
#endif