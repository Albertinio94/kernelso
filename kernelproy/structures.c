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

pcb_t* dequeue(queue_t* queue)
{
    pcb_t* pcb;

    if (is_empty(*queue)) {
        return NULL;
    }
    pcb = (pcb_t*) malloc(sizeof(pcb_t));
    pcb->id = queue->first->pcb.id;
    pcb->ttl = queue->first->pcb.ttl;
    pcb->quantum = queue->first->pcb.quantum;

    queue->first = queue->first->next;

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