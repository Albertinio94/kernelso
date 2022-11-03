#include "timer.h"

void timer_scheduler_routine(pthread_mutex_t *mutex, pthread_cond_t *condicion1, pthread_cond_t *condicion2, int *done){
    pthread_mutex_lock(mutex);
    int cuentapulsos=0;
    while(1){
        *done++;
        cuentapulsos++;
        if(cuentapulsos=10){
            printf("Soy el scheduler y he contado 10 pulsos\n");
            cuentapulsos=0;
        }
        pthread_cond_signal(condicion1);
        pthread_cond_wait(condicion2, mutex);
    }
}
void timer_process_generator_routine(pthread_mutex_t *mutex, pthread_cond_t *condicion1, pthread_cond_t *condicion2, int *done){
    pthread_mutex_lock(mutex);
    int cuentapulsos=0;
    while(1){
        *done++;
        cuentapulsos++;
        if(cuentapulsos=50){
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO 50 PULSOS\n");
            cuentapulsos=0;
            
        }
        pthread_cond_signal(condicion1);
        pthread_cond_wait(condicion2, mutex);
    }
}