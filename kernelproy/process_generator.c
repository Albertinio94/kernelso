#include "process_generator.h"
#include "structures.h"
#include <stdlib.h>

void process_generator_routine(queue_t *ready)
{
    enqueue(ready, generate_pcb());
}

pcb_t generate_pcb ()
{
    pcb_t pcb; 
    pcb.id = next_pid();
    pcb.ttl = rand() % 1000 + 1;
    pcb.quantum = rand() % 500 + 101;

    return pcb;
}

int next_pid(){
    static int pid = 0;

    return ++pid;
}