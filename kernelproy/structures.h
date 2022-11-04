#include <pthread.h>
typedef struct argumentosparaclockytimer {
    pthread_mutex_t mutex;
    pthread_cond_t condicion1;
    pthread_cond_t condicion2;
    int done;
    int cantidad_temporizadores;
}argumentosparaclockytimer;