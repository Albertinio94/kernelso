#ifndef MACHINE_H
#define MACHINE_H
#include "structures.h"

struct core_t {
    pcb_t executing_process;
};
typedef struct core_t core_t;

struct cpu_t {
    core_t* cores;
};
typedef struct cpu_t cpu_t;

void init_cpus (cpu_t** cpus, int n_cores);
void free_cpus(cpu_t** cpus);
#endif