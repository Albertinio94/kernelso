#include <pthread.h>
#include <stdio.h>

void clock_routine(pthread_mutex_t *mutex, pthread_cond_t *condicion1, pthread_cond_t *condicion2, int cantidad_temporizadores, int *done);