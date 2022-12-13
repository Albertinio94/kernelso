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
    struct nodo *siguiente;
    struct nodo *anterior;
};
typedef struct nodo nodo;

typedef struct
{
    nodo *primero;
    nodo *ultimo;
} cola;

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t condicion1;
    pthread_cond_t condicion2;
    int done;
    int cantidadtemporizadores;
    cola *preparados;
    cola *bloqueados;
} argumentosparaclockytimer;

void encolar(cola *cola_a_encolar, nodo *nodo_a_encolar);
void desencolar(cola *cola_a_desencolar, nodo *nodo_a_desencolar);
#endif