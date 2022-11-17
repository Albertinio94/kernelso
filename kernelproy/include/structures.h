#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>
typedef struct{
    int id;
    int tiempo_de_vida;
    int quantum;
}
pcb;
typedef struct {
    pcb pcbdelnodo;
    pcb * siguiente;
}
nodo;

struct common_args{
    pthread_mutex_t mutex;
    pthread_cond_t condition1;
    pthread_cond_t condition2;
    int done;
    int n_timers;
};
typedef struct common_args common_args;
#endif