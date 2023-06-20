#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>
struct pcb_t{
    int id;
    int ttl;
    int quantum;
};
typedef pcb_t pcb_t;

struct node_t {
    pcb_t pcb;
    struct node_t* next;
};
typedef struct node_t node_t;

typedef struct
{
    node* first;
    node* last;
} queue_t;

struct common_args {
    pthread_mutex_t mutex;
    pthread_cond_t condition1;
    pthread_cond_t condition2;
    int done;
    int n_timers;
    queue_t* preparados;
    queue_t* bloqueados;
    node_t* proceso_ejecutandose;
};
typedef struct common_args common_args;

void init_cola(queue* queue);
void encolar(queue* cola_a_encolar, node* nodo_a_encolar);
void desencolar_y_borrar(queue* cola_a_desencolar, node* nodo_a_desencolar);
void desencolar(queue* cola_a_desencolar, node* nodo_a_desencolar);

#endif