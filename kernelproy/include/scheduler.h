#ifndef SCHED_H
#define SCHED_H
#include "structures.h"

void schedule_dispatch(core_t* core, queue_t* ready);
void scheduler_routine(cpu_t* cpus, int n_cpus, queue_t* ready);

#endif