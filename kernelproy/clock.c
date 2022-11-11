#include "clock.h"
void * clock_routine(void * args){
    argumentosparaclockytimer * argumentosinterpretados = args;
    while (1){
        pthread_mutex_lock(&argumentosinterpretados->mutex);
        while(argumentosinterpretados->done<argumentosinterpretados->cantidad_temporizadores){
            pthread_cond_wait(&argumentosinterpretados->condicion1, &argumentosinterpretados->mutex);
        }
        ((argumentosparaclockytimer *)args)->done=0;
        pthread_cond_broadcast(&argumentosinterpretados->condicion2);
        pthread_mutex_unlock(&argumentosinterpretados->mutex);
    }
}