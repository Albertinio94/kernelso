#ifndef MACHINE_H
#define MACHINE_H
#include "structures.h"

struct core {
    pcb executing_process;
};
typedef struct core core;

struct cpu {
    core* cores;
};
typedef struct cpu cpu;

#endif