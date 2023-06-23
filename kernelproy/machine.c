#include "machine.h"
#include <stdio.h>
#include <stdlib.h>

void init_cpus(cpu_t** cpus, int n_cpus, int n_cores, pcb_t null_process)
{
    int i, j = 0;

    *cpus = (cpu_t*)malloc(n_cpus * sizeof(cpu_t));
    for (i = 0; i < n_cpus; i++) {
        (*cpus)[i].cores = (core_t*)malloc(n_cores * sizeof(core_t));
        (*cpus)[i].n_cores = n_cores;
        for (j = 0; j < n_cores; j++) {
            (*cpus)[i].cores[j].executing_process = null_process;
        }
    }
}

void free_cpus(cpu_t** cpus, int n_cpus)
{
    int i = 0;
    for (i = 0; i < n_cpus; i++) {
        free((*cpus)[i].cores);
    }
    free(*cpus);
}

void print_machine(cpu_t* cpus, int n_cpus)
{
    int i, j;
    pcb_t current;

    for (i = 0; i < n_cpus; i++) {
        for (j = 0; j < cpus[i].n_cores; j++) {
            current = cpus[i].cores[j].executing_process;
            printf("cpu: %d, core: %d\n\tid:%d, ttl:%d, quantum:%d\n", i, j, current.id, current.ttl, current.quantum);
        }
        printf("\n");
    }
}