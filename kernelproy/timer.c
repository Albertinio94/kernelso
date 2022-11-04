#include "timer.h"
#include "structures.h"
void * timer_scheduler_routine(void * args){
    argumentosparaclockytimer *argumentosinterpretados = args;
    int cuentapulsos=0;
    pthread_mutex_lock(&argumentosinterpretados->mutex);
    while(1){
        argumentosinterpretados->done++;
        cuentapulsos++;
        if(cuentapulsos=10){
            printf("Soy el scheduler y he contado 10 pulsos\n");
            cuentapulsos=0;
        }
        pthread_cond_signal(&argumentosinterpretados->condicion1);
        pthread_cond_wait(&argumentosinterpretados->condicion2, &argumentosinterpretados->mutex);
    }
}
void * timer_process_generator_routine(void * args){
    argumentosparaclockytimer *argumentosinterpretados = args;
    pthread_mutex_lock(&argumentosinterpretados->mutex);
    int cuentapulsos=0;
    while(1){
        argumentosinterpretados->done++;
        cuentapulsos++;
        if(cuentapulsos=50){
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO 50 PULSOS\n");
            cuentapulsos=0;
            
        }
        pthread_cond_signal(&argumentosinterpretados->condicion1);
        pthread_cond_wait(&argumentosinterpretados->condicion2, &argumentosinterpretados->mutex);
    }
}