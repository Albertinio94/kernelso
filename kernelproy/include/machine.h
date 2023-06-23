#ifndef MACHINE_H
#define MACHINE_H
#include "structures.h"

void init_cpus(cpu_t** cpus, int n_cpus, int n_cores, pcb_t null_process);
void free_cpus(cpu_t** cpus, int n_cpus);
void print_machine(cpu_t *cpus, int n_cpus);

#endif