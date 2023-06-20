#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>
typedef struct {
    int id;
    int ttl;
    int quantum;
} pcb;

typedef struct {
    pcb pcbdelnodo;
    pcb* next;
} node;

typedef struct
{
    node* first;
    node* last;
} queue;

struct common_args {
    pthread_mutex_t mutex;
    pthread_cond_t condition1;
    pthread_cond_t condition2;
    int done;
    int n_timers;
    queue* preparados;
    queue* bloqueados;
    node* proceso_ejecutandose;
};
typedef struct common_args common_args;

void init_cola(queue* queue);
void encolar(queue* cola_a_encolar, node* nodo_a_encolar);
void desencolar_y_borrar(queue* cola_a_desencolar, node* nodo_a_desencolar);
void desencolar(queue* cola_a_desencolar, node* nodo_a_desencolar);

#endif