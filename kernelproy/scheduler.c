#include "commons.h"
#include "structures.h"
#include <stdlib.h>

void schedule_dispatch(core_t* core, queue_t* ready)
{
    pcb_t next_pcb;
    pcb_t current_pcb = core->executing_process;

    if(current_pcb.ttl > 0){
        enqueue(ready, current_pcb);
    } 

    next_pcb = dequeue(ready);

    if (next_pcb.id != NULL_PROCESS_PID) {
        next_pcb.quantum = (rand() % 10 + 1);
    }
    core->executing_process = next_pcb;
}

void scheduler_routine(cpu_t* cpus, int n_cpus, queue_t* ready)
{
    int i, j;

    for (i = 0; i < n_cpus; i++) {
        for (j = 0; j < cpus[i].n_cores; j++) {
            if (--(cpus[i].cores[j].executing_process.quantum) <= 0) {
                schedule_dispatch(&cpus[i].cores[j], ready);
            }
        }
    }
}