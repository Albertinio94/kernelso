#include "process_generator.h"
#include "commons.h"
#include "structures.h"
#include <stdlib.h>

int next_pid()
{
    static int pid = 0;

    return ++pid;
}

pcb_t generate_pcb()
{
    pcb_t pcb;
    pcb.id = next_pid();
    pcb.ttl = rand() % 1000 + 1;
    pcb.quantum = 0;

    return pcb;
}

void process_generator_routine(queue_t* ready)
{
    enqueue(ready, generate_pcb());
}
