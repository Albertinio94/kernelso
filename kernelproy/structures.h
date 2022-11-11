#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>
struct argumentosparaclockytimer{
    pthread_mutex_t mutex;
    pthread_cond_t condicion1;
    pthread_cond_t condicion2;
    int done;
    int cantidad_temporizadores;
};
typedef struct argumentosparaclockytimer argumentosparaclockytimer;
#endif