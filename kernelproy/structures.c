#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(queue_t** queue)
{
    *queue = (queue_t*)malloc(sizeof(queue_t));
    (*queue)->first = NULL;
    (*queue)->last = NULL;
}

unsigned int is_empty(queue_t queue)
{
    return (queue.first == NULL);
}

void enqueue(queue_t* queue, pcb_t pcb)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->pcb = pcb;
    new_node->next = NULL;

    if (is_empty(*queue)) {
        queue->first = queue->last = new_node;
    } else if (queue->first == queue->last) {
        queue->last = new_node;
        queue->first->next = queue->last;
    } else {
        queue->last->next = new_node;
        queue->last = new_node;
    }
}

/*If the queue is empty, it will return the null process*/
pcb_t dequeue(queue_t* queue)
{
    pcb_t pcb = NULL_PROCESS;
    node_t* node;

    if (is_empty(*queue)) {
        return pcb;
    }
    pcb = queue->first->pcb;
    node = queue->first,

    queue->first = queue->first->next;
    free(node);

    if (queue->first == NULL) {
        queue->first = queue->last = NULL;
    }

    return pcb;
}

void free_queue(queue_t** queue)
{
    while (!is_empty(**queue)) {
        dequeue(*queue);
    }
    free(*queue);
    *queue = NULL;
}

void print_queue(queue_t* queue)
{
    node_t* node;

    if (is_empty(*queue)) {
        printf("The queue is empty\n");
        return;
    }

    node = queue->first;
    while (node != NULL) {
        printf("id: %d, ttl: %d, quantum: %d\n", node->pcb.id, node->pcb.ttl, node->pcb.quantum);
        node = node->next;
    }
}