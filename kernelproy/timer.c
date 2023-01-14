#include "timer.h"
<<<<<<< HEAD
#include <stdio.h>
=======
#include "processgenerator.h"
#include "scheduler.h"

int disminuir_tiempo_de_vida(nodo *proceso_ejecutandose);
>>>>>>> 322bae3 (no funciona el scheduler, el valor de proceso_ejecutandose no cambia, tema de dereferenciacion, podemos cambiar la cola para devolver un nodo)

void* timer_scheduler_routine(void* input_args)
{
<<<<<<< HEAD
    common_args* args = input_args;
    int pulses = 1;
    pthread_mutex_lock(&args->mutex);
    while (1) {
        args->done++;
        pulses++;
        if (pulses == 100) {
            printf("Soy el scheduler y he contado 100 pulsos\n");
            fflush(stdout);
            pulses = 1;
=======
    argumentosparaclockytimer *argumentosinterpretados = args;
    int cuentapulsos = 1;
    int evento_fin_ejecucion = 0;
    pthread_mutex_lock(&argumentosinterpretados->mutex);
    while (1)
    {
        argumentosinterpretados->done++;
        cuentapulsos++;
        evento_fin_ejecucion = disminuir_tiempo_de_vida(argumentosinterpretados->proceso_ejecutandose);
        if (evento_fin_ejecucion == 1)
        {
            printf("llamando al scheduler porque se ha terminado el proceso\n");
            fflush(stdout);
            rutina_scheduler(argumentosinterpretados->preparados, argumentosinterpretados->bloqueados, argumentosinterpretados->proceso_ejecutandose);
            cuentapulsos = 0;
        }
        if (cuentapulsos == 99)
        {
            printf("llamando al scheduler porque se ha terminado el tiempo\n");
            fflush(stdout);
            rutina_scheduler(argumentosinterpretados->preparados, argumentosinterpretados->bloqueados, argumentosinterpretados->proceso_ejecutandose);
            cuentapulsos = 0;
>>>>>>> 322bae3 (no funciona el scheduler, el valor de proceso_ejecutandose no cambia, tema de dereferenciacion, podemos cambiar la cola para devolver un nodo)
        }
        pthread_cond_signal(&args->condition1);
        pthread_cond_wait(&args->condition2, &args->mutex);
    }
}
void* timer_process_generator_routine(void* input_args)
{
    common_args* args = input_args;
    pthread_mutex_lock(&args->mutex);
    pcb procesogenerado;
    unsigned int pid = 0;
<<<<<<< HEAD
    int pulses = 1;
    while (1) {
        args->done++;
        pulses++;
        if (pulses == 500) {
            printf("SOY EL PROCESS GENERATOR Y HE CONTADO 500 PULSOS\n");
            fflush(stdout);
            processgenerator(&args->preparados, pid);
=======
    int cuentapulsos = 1;
    while (1)
    {
        argumentosinterpretados->done++;
        cuentapulsos++;
        if (cuentapulsos == 500)
        {
            processgenerator_routine(argumentosinterpretados->preparados, pid);
>>>>>>> 1f85be2 (probado el process generator, añadidos tests y modificado el encolado)
            pid++;
<<<<<<< HEAD
            pulses = 1;
            printf("%d\n", args->preparados->ultimo->pcbdelnodo.id);
=======
            cuentapulsos = 1;
            printf("La id del nuevo proceso es %d\n", argumentosinterpretados->preparados->ultimo->pcbdelnodo.id);
>>>>>>> 322bae3 (no funciona el scheduler, el valor de proceso_ejecutandose no cambia, tema de dereferenciacion, podemos cambiar la cola para devolver un nodo)
        }
        pthread_cond_signal(&args->condition1);
        pthread_cond_wait(&args->condition2, &args->mutex);
    }
}

int disminuir_tiempo_de_vida(nodo *proceso_ejecutandose)
{
    if (proceso_ejecutandose != NULL)
    {
        proceso_ejecutandose->pcbdelnodo.quantum--;
        proceso_ejecutandose->pcbdelnodo.tiempodevida--;
        return proceso_ejecutandose->pcbdelnodo.quantum == 0 || proceso_ejecutandose->pcbdelnodo.tiempodevida == 0;
    }
    return 0;
}