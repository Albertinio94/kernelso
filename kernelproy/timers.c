#include "timers.h"
#include "commons.h"
#include "process_generator.h"
#include "scheduler.h"
#include "structures.h"
#include <pthread.h>
#include <stdio.h>

void* timer_scheduler_routine(void* input_args)
{
    common_args* args = input_args;
    int pulses = 1;

    pthread_mutex_lock(&args->mutex_clock);
    while (1) {
        args->consumed_pulses++;
        pulses++;
        if (pulses == SCHEDULER_TIMER_PULSES) {
            printf("Soy el scheduler y he contado %d pulsos\n", SCHEDULER_TIMER_PULSES);
            fflush(stdout);
            scheduler_routine(args->cpus, args->n_cpus, args->ready);
            pulses = 1;
        }
        pthread_cond_signal(&args->condition_pulse_consumed);
        pthread_cond_wait(&args->condition_pulse_generated, &args->mutex_clock);
    }
}

void* timer_process_generator_routine(void* input_args)
{
    common_args* args = input_args;
    int pulses = 1;

    pthread_mutex_lock(&args->mutex_clock);
    while (1) {
        args->consumed_pulses++;
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