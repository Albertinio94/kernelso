#include "timer.h"
void * timer_scheduler_routine(void * args){
    common_args *argumentosinterpretados = args;
    int cuentapulsos=1;
    pthread_mutex_lock(&argumentosinterpretados->mutex);
    while(1){
        argumentosinterpretados->done++;
        cuentapulsos++;
        if(cuentapulsos==100){
            printf("Soy el scheduler y he contado 100 pulsos\n");
            fflush(stdout);
            cuentapulsos=1;
        }
        pthread_cond_signal(&argumentosinterpretados->condicion1);
        pthread_cond_wait(&argumentosinterpretados->condicion2, &argumentosinterpretados->mutex);
    }
}
void * timer_process_generator_routine(void * args){
    common_args *argumentosinterpretados = args;
    pthread_mutex_lock(&argumentosinterpretados->mutex);
    int cuentapulsos=1;
    while(1){
        argumentosinterpretados->done++;
        cuentapulsos++;
        if(cuentapulsos==500){
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO 500 PULSOS\n");
            fflush(stdout);
            cuentapulsos=1;
            
        }
        pthread_cond_signal(&argumentosinterpretados->condicion1);
        pthread_cond_wait(&argumentosinterpretados->condicion2, &argumentosinterpretados->mutex);
    }
}