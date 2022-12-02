#include "timer.h"
#include <stdio.h>

void* timer_scheduler_routine(void* input_args)
{
    common_args* args = input_args;
    int pulses = 1;
    pthread_mutex_lock(&args->mutex);
    while (1) {
        args->done++;
        pulses++;
        if (pulses == 100) {
            printf("Soy el scheduler y he contado 100 pulsos\n");
            fflush(stdout);
            pulses = 1;
        }
        pthread_cond_signal(&args->condition1);
        pthread_cond_wait(&args->condition2, &args->mutex);
    }
}
void* timer_process_generator_routine(void* input_args)
{
    common_args* args = input_args;
    pthread_mutex_lock(&args->mutex);
    pcb procesogenerado;
    unsigned int pid = 0;
    int pulses = 1;
    while (1) {
        args->done++;
        pulses++;
        if (pulses == 500) {
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO 500 PULSOS\n");
            fflush(stdout);
            processgenerator(&args->preparados, pid);
            pid++;
            pulses = 1;
            printf("%d\n", args->preparados->ultimo->pcbdelnodo.id);
        }
        pthread_cond_signal(&args->condition1);
        pthread_cond_wait(&args->condition2, &args->mutex);
    }
}