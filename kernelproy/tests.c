#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "processgenerator.h"
#include "scheduler.h"

int main(int argc, char const *argv[])
{
    /*// usar getopt()
    pcb pcbpruebas = {
        .id = 0,
        .quantum = 100,
        .tiempodevida = 1000};

    nodo *nodopruebas0, *nodopruebas1, *nodopruebas2;
    nodopruebas0 = (nodo *)malloc(sizeof(nodo));
    nodopruebas0->pcbdelnodo = pcbpruebas;

    pcbpruebas.id = 1;
    nodopruebas1 = (nodo *)malloc(sizeof(nodo));
    nodopruebas1->pcbdelnodo = pcbpruebas;

    pcbpruebas.id = 2;
    nodopruebas2 = (nodo *)malloc(sizeof(nodo));
    nodopruebas2->pcbdelnodo = pcbpruebas;

    cola colapruebas;
    //init_cola(&colapruebas);

    printf("no exploto antes de encolar el primero\n");
    encolar(&colapruebas, nodopruebas0);
    printf("el id del primer nodo de la cola es %d\n", colapruebas.primero->pcbdelnodo.id);

    encolar(&colapruebas, nodopruebas1);

    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    if (nodopruebas0->siguiente != NULL)
        printf("Y el primer nodo apunta a algo siguiente\n");
    if (nodopruebas1->anterior != NULL)
        printf("Y el ultimo nodo apunta a algo anterior\n");

    encolar(&colapruebas, nodopruebas2);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);

    desencolar(&colapruebas, nodopruebas2);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);

    desencolar(&colapruebas, nodopruebas1);
    printf("el id del ultimo nodo de la cola es %d\n", colapruebas.ultimo->pcbdelnodo.id);
    if (colapruebas.primero == colapruebas.ultimo)
        printf("La cola solo tiene un elemento\n");

    desencolar(&colapruebas, nodopruebas0);
    if (colapruebas.primero == NULL)
        printf("la cola está vacía\n");
    */
    unsigned int pid;
    cola *ready, *blocked;
    nodo *proceso_ejecutandose = NULL;
    srand(time(NULL));
    ready = (cola *) malloc(sizeof(cola));
    blocked = (cola *) malloc(sizeof(cola));
    init_cola(ready);
    printf("no exploto al llegar a inicializar la cola.\n");
    processgenerator_routine(ready, pid);
    printf(
        "El id del primer proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->primero->pcbdelnodo.id,
        ready->primero->pcbdelnodo.tiempodevida,
        ready->primero->pcbdelnodo.quantum
    );
    pid++;
    processgenerator_routine(ready, pid);
    printf(
        "El id del ultimo proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->ultimo->pcbdelnodo.id,
        ready->ultimo->pcbdelnodo.tiempodevida,
        ready->ultimo->pcbdelnodo.quantum
    );
    pid++;
    processgenerator_routine(ready, pid);
    printf(
        "El id del ultimo proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->ultimo->pcbdelnodo.id,
        ready->ultimo->pcbdelnodo.tiempodevida,
        ready->ultimo->pcbdelnodo.quantum
    );
    pid++;
    processgenerator_routine(ready, pid);
    printf(
        "El id del ultimo proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->ultimo->pcbdelnodo.id,
        ready->ultimo->pcbdelnodo.tiempodevida,
        ready->ultimo->pcbdelnodo.quantum
    );

    printf(
        "El id del primer proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->primero->pcbdelnodo.id,
        ready->primero->pcbdelnodo.tiempodevida,
        ready->primero->pcbdelnodo.quantum
    );
    rutina_scheduler(ready, blocked, proceso_ejecutandose);
    proceso_ejecutandose->pcbdelnodo.quantum = 0;
    rutina_scheduler(ready, blocked, proceso_ejecutandose);

    return 0;
}
