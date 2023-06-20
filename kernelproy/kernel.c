#include "clock.h"
#include "commons.h"
#include "stdio.h"
#include "structures.h"
#include "timer.h"
#include "unistd.h"
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    int i;
    pthread_t threads[N_THREADS];
    void* (*functions[N_THREADS])(void*);
    common_args arguments = {
        .n_timers = 2,
        .condition1 = PTHREAD_COND_INITIALIZER,
        .condition2 = PTHREAD_COND_INITIALIZER,
        .mutex = PTHREAD_MUTEX_INITIALIZER,
        .done = 0,
        .preparados = malloc(sizeof(cola)),
        .bloqueados = malloc(sizeof(cola))
    };
    functions[0] = clock_routine;
    functions[1] = timer_scheduler_routine;
    functions[2] = timer_process_generator_routine;

    if (argc != 2) {
        fprintf(stderr, "Usage: kernel number_of_cores\n");
        return 1;
    }

    for (i = 0; i < N_THREADS; i++) {
        pthread_create(&threads[i], NULL, functions[i], &arguments);
    }
    for (i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
