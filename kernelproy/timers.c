#include "timers.h"
#include "process_generator.h"
#include "structures.h"
#include <pthread.h>
#include <stdio.h>

void* timer_scheduler_routine(void* input_args)
{
    common_args* args = input_args;
    int pulses = 1;
    pthread_mutex_lock(&args->mutex_clock);
    while (1) {
        args->done++;
        pulses++;
        if (pulses == 100) {
            printf("Soy el scheduler y he contado 100 pulsos\n");
            fflush(stdout);
            pulses = 1;
        }
        pthread_cond_signal(&args->condition_pulse_consumed);
        pthread_cond_wait(&args->condition_pulse_generated, &args->mutex_clock);
    }
}
void* timer_process_generator_routine(void* input_args)
{
    common_args* args = input_args;
    pthread_mutex_lock(&args->mutex_clock);
    int pulses = 1;
    while (1) {
        args->done++;
        pulses++;
        if (pulses == 500) {
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO 500 PULSOS\n");
            fflush(stdout);
            process_generator_routine(args->ready);
            pulses = 1;
            print_queue(args->ready);
        }
        pthread_cond_signal(&args->condition_pulse_consumed);
        pthread_cond_wait(&args->condition_pulse_generated, &args->mutex_clock);
    }
}

/*int disminuir_tiempo_de_vida(node* proceso_ejecutandose)
{
    if (proceso_ejecutandose != NULL) {
        proceso_ejecutandose->pcbdelnodo.quantum--;
        proceso_ejecutandose->pcbdelnodo.tiempodevida--;
        return proceso_ejecutandose->pcbdelnodo.quantum == 0 || proceso_ejecutandose->pcbdelnodo.tiempodevida == 0;
    }
    return 0;
}*/