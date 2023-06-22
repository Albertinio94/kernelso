#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main(int argc, char const *argv[])
{
    queue_t *queue;
    pcb_t pcb = {
        .id = 0,
        .ttl = 1000,
        .quantum = 100
    };
    unsigned char has_error = 0;

    init_queue(&queue);
    enqueue(queue, pcb);

    if (is_empty(*queue)){
        printf("error!\n");
        return 1;
    }

    pcb = dequeue(queue, &has_error);
    if (has_error){
        printf("error!\n");
        return 1;
    }

    pcb = dequeue(queue, &has_error);
    if (has_error){
        printf("pcb has no value, queue is empty\n");
    }

    if (!is_empty(*queue)){
        printf("error!\n");
        return 1;
    }
    print_queue(queue);

    enqueue(queue, pcb);
    enqueue(queue, pcb);
    enqueue(queue, pcb);
    enqueue(queue, pcb);

    print_queue(queue);
    
    /*free_queue(&queue);
    if (queue != NULL){
        printf("error!\n");
        return 1;
    }*/
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

    printf("el id del last nodo de la cola es %d\n", colapruebas.last->pcbdelnodo.id);
    if (nodopruebas0->next != NULL)
        printf("Y el primer nodo apunta a algo next\n");
    if (nodopruebas1->anterior != NULL)
        printf("Y el last nodo apunta a algo anterior\n");

    encolar(&colapruebas, nodopruebas2);
    printf("el id del last nodo de la cola es %d\n", colapruebas.last->pcbdelnodo.id);

    desencolar(&colapruebas, nodopruebas2);
    printf("el id del last nodo de la cola es %d\n", colapruebas.last->pcbdelnodo.id);

    desencolar(&colapruebas, nodopruebas1);
    printf("el id del last nodo de la cola es %d\n", colapruebas.last->pcbdelnodo.id);
    if (colapruebas.primero == colapruebas.last)
        printf("La cola solo tiene un elemento\n");

    desencolar(&colapruebas, nodopruebas0);
    if (colapruebas.primero == NULL)
        printf("la cola está vacía\n");
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
        "El id del last proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->last->pcbdelnodo.id,
        ready->last->pcbdelnodo.tiempodevida,
        ready->last->pcbdelnodo.quantum
    );
    pid++;
    processgenerator_routine(ready, pid);
    printf(
        "El id del last proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->last->pcbdelnodo.id,
        ready->last->pcbdelnodo.tiempodevida,
        ready->last->pcbdelnodo.quantum
    );
    pid++;
    processgenerator_routine(ready, pid);
    printf(
        "El id del last proceso de la cola es %d, su tiempo de vida es %d y su quantum es %d\n",
        ready->last->pcbdelnodo.id,
        ready->last->pcbdelnodo.tiempodevida,
        ready->last->pcbdelnodo.quantum
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
*/
    return 0;
}
