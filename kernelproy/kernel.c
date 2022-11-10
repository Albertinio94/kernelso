#include "clock.h"
#include "timer.h"
#include "structures.h"
#include "unistd.h"
int main(int argc, char const *argv[])
{
    pthread_t clock, timersched, timerprocessgenerator;
    argumentosparaclockytimer argumentos = 
    {.cantidad_temporizadores=2, 
    .condicion1=PTHREAD_COND_INITIALIZER, 
    .condicion2=PTHREAD_COND_INITIALIZER, 
    .mutex=PTHREAD_MUTEX_INITIALIZER, 
    .done=0};


    pthread_create(&clock, NULL, &clock_routine, &argumentos);
    pthread_create(&timersched, NULL, &timer_scheduler_routine, &argumentos);
    pthread_create(&timerprocessgenerator, NULL, &timer_process_generator_routine, &argumentos);
    sleep(5);
    return 0;
}
