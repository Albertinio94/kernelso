#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>
struct pcb_t{
    int id;
    int ttl;
    int quantum;
};

typedef struct pcb_t pcb_t;

struct node_t {
    pcb_t pcb;
    struct node_t* next;
};
typedef struct node_t node_t;

struct queue_t
{
    node_t* first;
    node_t* last;
};

typedef struct queue_t queue_t;

/*struct common_args {
    pthread_mutex_t mutex;
    pthread_cond_t condition1;
    pthread_cond_t condition2;
    int done;
    int n_timers;
    queue_t* preparados;
    queue_t* bloqueados;
    node_t* proceso_ejecutandose;
};
typedef struct common_args common_args;*/

void init_queue(queue_t** queue);
unsigned int is_empty(queue_t queue);
void enqueue(queue_t* queue, pcb_t pcb);
pcb_t* dequeue(queue_t* queue);
void free_queue(queue_t** queue);

#endif