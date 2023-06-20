#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

void encolar(cola *cola_a_encolar, nodo *nodo_a_encolar)
{
    nodo_a_encolar->anterior = NULL;
    nodo_a_encolar->next = NULL;
    if (cola_a_encolar->first == NULL)
    {
        cola_a_encolar->first = nodo_a_encolar;
        cola_a_encolar->last = nodo_a_encolar;
    }
    else if (cola_a_encolar->last == cola_a_encolar->first)
    {
        nodo_a_encolar->anterior = cola_a_encolar->first;
        cola_a_encolar->last = nodo_a_encolar;
        cola_a_encolar->first->next = nodo_a_encolar;
    }
    else
    {
        cola_a_encolar->last->next = nodo_a_encolar;
        nodo_a_encolar->anterior = cola_a_encolar->last;
        cola_a_encolar->last = nodo_a_encolar;
    }
}

void desencolar_y_borrar(cola *cola_a_desencolar, nodo *nodo_a_desencolar)
{
    nodo *nodo_para_recorrer;
    if (nodo_a_desencolar == NULL)
    {
        return;
    }
    if (cola_a_desencolar->first == NULL)
    {
        return;
    }
    if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->first->pcbdelnodo.id)
    {
        cola_a_desencolar->first = cola_a_desencolar->first->next;
        if (cola_a_desencolar->first == NULL)
        {
            cola_a_desencolar->last = NULL;
        }
        free(nodo_a_desencolar);
    }
    else if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->last->pcbdelnodo.id)
    {
        cola_a_desencolar->last = cola_a_desencolar->last->anterior;
        cola_a_desencolar->last->next = NULL;
        free(nodo_a_desencolar);
    }
    else
    {
        nodo_para_recorrer = cola_a_desencolar->first;
        while (nodo_para_recorrer->pcbdelnodo.id != nodo_a_desencolar->pcbdelnodo.id || nodo_para_recorrnextente == NULL)
        {
            nodo_para_recorrer = nodo_para_recorrer->next;
        }
        nodo_para_recorrer->anterior->next = nodo_para_recorrer->next;
        nodo_para_recorrer->next->anterior = nodo_para_recorrer->anterior;
        free(nodo_a_desencolar);
    }
}

void desencolar(cola *cola_a_desencolar, nodo *nodo_a_desencolar)
{
    nodo *nodo_para_recorrer;
    if (nodo_a_desencolar == NULL)
    {
        return;
    }
    if (cola_a_desencolar->first == NULL)
    {
        return;
    }
    if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->first->pcbdelnodo.id)
    {
        cola_a_desencolar->first = cola_a_desencolar->first->next;
        if (cola_a_desencolar->first == NULL)
        {
            cola_a_desencolar->last = NULL;
        }
    }
    else if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->last->pcbdelnodo.id)
    {
        cola_a_desencolar->last = cola_a_desencolar->last->anterior;
        cola_a_desencolar->last->next = NULL;
    }
    else
    {
        nodo_para_recorrer = cola_a_desencolar->first;
        while (nodo_para_recorrer->pcbdelnodo.id != nodo_a_desencolar->pcbdelnodo.id || nodo_para_recorrnextente == NULL)
        {
            nodo_para_recorrer = nodo_para_recorrer->next;
        }
        nodo_para_recorrer->anterior->next = nodo_para_recorrer->next;
        nodo_para_recorrer->next->anterior = nodo_para_recorrer->anterior;
    }
}

void init_cola(cola *cola)
{
    cola->first = NULL;
    cola->last = NULL;
}
