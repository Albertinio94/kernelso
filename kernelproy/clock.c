#include "clock.h"
#include "scheduler.h"
#include "structures.h"

void* clock_routine(void* input_args)
{
    common_args* args = (common_args*)input_args;
    int i, j;

    while (1) {
        pthread_mutex_lock(&args->mutex_clock);
        while (args->consumed_pulses < args->n_timers) {
            pthread_cond_wait(&args->condition_pulse_consumed, &args->mutex_clock);
        }
        args->consumed_pulses = 0;

        /*Advance machine*/
        pthread_mutex_lock(&args->mutex_machine);
        for (i = 0; i < args->n_cpus; i++) {
            for (j = 0; j < args->cpus[i].n_cores; j++) {
                if (--(args->cpus[i].cores[j].executing_process.ttl) <= 0) {
                    pthread_mutex_lock(&args->mutex_queue);
                    schedule_dispatch(&args->cpus[i].cores[j], args->ready);
                    pthread_mutex_unlock(&args->mutex_queue);
                }
            }
        }
        pthread_mutex_unlock(&args->mutex_machine);
        pthread_cond_broadcast(&args->condition_pulse_generated);
        pthread_mutex_unlock(&args->mutex_clock);
    }
}