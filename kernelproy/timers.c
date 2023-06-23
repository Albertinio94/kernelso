#include "timers.h"
#include "machine.h"
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
            pthread_mutex_lock(&args->mutex_machine);
            pthread_mutex_lock(&args->mutex_queue);
            scheduler_routine(args->cpus, args->n_cpus, args->ready);
            print_machine(args->cpus, args->n_cpus);
            pthread_mutex_unlock(&args->mutex_queue);
            pthread_mutex_unlock(&args->mutex_machine);
            pulses = 0;
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
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO %d PULSOS\n", PROCESS_GENERATOR_PULSES);
            fflush(stdout);
            pthread_mutex_lock(&args->mutex_machine);
            pthread_mutex_lock(&args->mutex_queue);
            process_generator_routine(args->ready);
            pthread_mutex_unlock(&args->mutex_queue);
            pthread_mutex_unlock(&args->mutex_machine);
            print_queue(args->ready);
            pulses = 0;
        }
        pthread_cond_signal(&args->condition_pulse_consumed);
        pthread_cond_wait(&args->condition_pulse_generated, &args->mutex_clock);
    }
}