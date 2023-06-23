#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <pthread.h>

#define NULL_PROCESS_PID 0
#define NULL_PROCESS {0, 0, 0}

struct pcb_t {
    int id;
    int ttl;
    int quantum;
};
typedef struct pcb_t pcb_t;

struct node_t {
    pcb_t pcb;
    struct node_t* next;
};
typedef struct node_t node_t;

struct queue_t {
    node_t* first;
    node_t* last;
};
typedef struct queue_t queue_t;

struct core_t {
    pcb_t executing_process;
};
typedef struct core_t core_t;

struct cpu_t {
    core_t* cores;
    int n_cores;
};
typedef struct cpu_t cpu_t;

struct common_args {
    pthread_mutex_t mutex_clock;
    pthread_cond_t condition_pulse_consumed;
    pthread_cond_t condition_pulse_generated;
    pthread_mutex_t mutex_machine;
    pthread_mutex_t mutex_queue;
    int consumed_pulses;
    int n_timers;
    queue_t* ready;
    pcb_t null_process;
    cpu_t* cpus;
    int n_cpus;
};
typedef struct common_args common_args;

void init_queue(queue_t** queue);
unsigned int is_empty(queue_t queue);
void enqueue(queue_t* queue, pcb_t pcb);
pcb_t dequeue(queue_t* queue);
void free_queue(queue_t** queue);
void print_queue(queue_t* queue);

#endif