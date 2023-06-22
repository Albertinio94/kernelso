#include "structures.h"
#include <pthread.h>

void* timer_scheduler_routine(void* args);
void* timer_process_generator_routine(void* args);