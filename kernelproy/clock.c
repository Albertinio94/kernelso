#include "clock.h"
void clock_routine(pthread_mutex_t *mutex, pthread_cond_t *condicion1, pthread_cond_t *condicion2, int cantidad_temporizadores, int *done){
    while (1){
        pthread_mutex_lock(mutex);
        while(*done<cantidad_temporizadores){
            pthread_cond_wait(mutex, condicion1);
        }
        *done=0;
        pthread_cond_broadcast(condicion2);
        pthread_mutex_unlock(mutex);
    }
}