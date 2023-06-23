#include "clock.h"
#include "commons.h"
#include "machine.h"
#include "stdio.h"
#include "structures.h"
#include "timers.h"
#include "unistd.h"
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    int i, n_cores;
    pthread_t threads[N_THREADS];
    void* (*functions[N_THREADS])(void*);
    common_args arguments = {
        .n_timers = N_TIMERS,
        .condition_pulse_consumed = PTHREAD_COND_INITIALIZER,
        .condition_pulse_generated = PTHREAD_COND_INITIALIZER,
        .mutex_clock = PTHREAD_MUTEX_INITIALIZER,
        .mutex_machine = PTHREAD_MUTEX_INITIALIZER,
        .mutex_queue = PTHREAD_MUTEX_INITIALIZER,
        .consumed_pulses = 0,
        .null_process = NULL_PROCESS
    };

    functions[0] = clock_routine;
    functions[1] = timer_scheduler_routine;
    functions[2] = timer_process_generator_routine;

    if (argc != 3) {
        fprintf(stderr, "Usage: kernel number_of_cpus number_of_cores\n");
        return 1;
    }

    arguments.n_cpus = atoi(argv[1]);
    n_cores = atoi(argv[2]);

    init_cpus(&arguments.cpus, arguments.n_cpus, n_cores, arguments.null_process);
    init_queue(&arguments.ready);
    for (i = 0; i < N_THREADS; i++) {
        pthread_create(&threads[i], NULL, functions[i], &arguments);
    }
    for (i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free_queue(&arguments.ready);
    free_cpus(&arguments.cpus, arguments.n_cpus);

    return 0;
}
