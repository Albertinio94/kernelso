#include "machine.h"
#include <stdlib.h>

void init_cpus(cpu_t** cpus, int n_cores)
{
    *cpus = (cpu_t*)malloc(n_cores * sizeof(cpu_t));
}

void free_cpus(cpu_t** cpus)
{
    free(*cpus);
}