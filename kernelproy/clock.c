#include "clock.h"
#include "structures.h"

void* clock_routine(void* input_args)
{
    common_args* args = (common_args*)input_args;
    while (1) {
        pthread_mutex_lock(&args->mutex_clock);
        while (args->done < args->n_timers) {
            pthread_cond_wait(&args->condition_pulse_consumed, &args->mutex_clock);
        }
        args->done = 0;
        pthread_cond_broadcast(&args->condition_pulse_generated);
        pthread_mutex_unlock(&args->mutex_clock);
    }
}