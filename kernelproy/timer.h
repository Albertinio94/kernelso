#include <pthread.h>
#include <stdio.h>
void timer_scheduler_routine(pthread_mutex_t *mutex, pthread_cond_t *condicion1, pthread_cond_t *condicion2, int *done);
void timer_process_generator_routine(pthread_mutex_t *mutex, pthread_cond_t *condicion1, pthread_cond_t *condicion2, int *done);