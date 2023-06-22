#ifndef MACHINE_H
#define MACHINE_H
#include "structures.h"

void init_cpus (cpu_t** cpus, int n_cores);
void free_cpus(cpu_t** cpus);
#endif