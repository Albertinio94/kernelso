#include "commons.h"
#include "clock.h"
#include "timer.h"
#include "structures.h"
#include "unistd.h"
#include "stdio.h"
int main(int argc, char const *argv[])
{
    int i;
    pthread_t threads[N_THREADS];
    void * (*functions[N_THREADS]) (void*);
    common_args argumentos = 
    {.cantidad_temporizadores=2, 
    .condicion1=PTHREAD_COND_INITIALIZER, 
    .condicion2=PTHREAD_COND_INITIALIZER, 
    .mutex=PTHREAD_MUTEX_INITIALIZER, 
    .done=0};
    functions[0] = clock_routine;
    functions[1] = timer_scheduler_routine;
    functions[2] = timer_process_generator_routine;

    if (argc != 2){
        fprintf(stderr, "Usage: kernel number_of_cores\n");
        return 1;
    }

    for (i = 0; i < N_THREADS; i++){
        pthread_create(&threads[i], NULL, functions[i], &argumentos);
    }
    for (i = 0; i < N_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}
