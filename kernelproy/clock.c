#include "clock.h"
#include "structures.h"

void* clock_routine(void* input_args)
{
    common_args* args = (common_args*)input_args;
    while (1) {
        pthread_mutex_lock(&args->mutex);
        while (args->done < args->n_timers) {
            pthread_cond_wait(&args->condition1, &args->mutex);
        }
        args->done = 0;
        pthread_cond_broadcast(&args->condition2);
        pthread_mutex_unlock(&args->mutex);
    }
}