#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

void encolar(cola *cola_a_encolar, nodo *nodo_a_encolar)
{
    nodo_a_encolar->anterior = NULL;
    nodo_a_encolar->siguiente = NULL;
    if (cola_a_encolar->primero == NULL)
    {
        cola_a_encolar->primero = nodo_a_encolar;
        cola_a_encolar->ultimo = nodo_a_encolar;
    }
    else if (cola_a_encolar->ultimo == cola_a_encolar->primero)
    {
        nodo_a_encolar->anterior = cola_a_encolar->primero;
        cola_a_encolar->ultimo = nodo_a_encolar;
        cola_a_encolar->primero->siguiente = nodo_a_encolar;
    }
    else
    {
        cola_a_encolar->ultimo->siguiente = nodo_a_encolar;
        nodo_a_encolar->anterior = cola_a_encolar->ultimo;
        cola_a_encolar->ultimo = nodo_a_encolar;
    }
}

void desencolar_y_borrar(cola *cola_a_desencolar, nodo *nodo_a_desencolar)
{
    nodo *nodo_para_recorrer;
    if (nodo_a_desencolar == NULL)
    {
        return;
    }
    if (cola_a_desencolar->primero == NULL)
    {
        return;
    }
    if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->primero->pcbdelnodo.id)
    {
        cola_a_desencolar->primero = cola_a_desencolar->primero->siguiente;
        if (cola_a_desencolar->primero == NULL)
        {
            cola_a_desencolar->ultimo = NULL;
        }
        free(nodo_a_desencolar);
    }
    else if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->ultimo->pcbdelnodo.id)
    {
        cola_a_desencolar->ultimo = cola_a_desencolar->ultimo->anterior;
        cola_a_desencolar->ultimo->siguiente = NULL;
        free(nodo_a_desencolar);
    }
    else
    {
        nodo_para_recorrer = cola_a_desencolar->primero;
        while (nodo_para_recorrer->pcbdelnodo.id != nodo_a_desencolar->pcbdelnodo.id || nodo_para_recorrer->siguiente == NULL)
        {
            nodo_para_recorrer = nodo_para_recorrer->siguiente;
        }
        nodo_para_recorrer->anterior->siguiente = nodo_para_recorrer->siguiente;
        nodo_para_recorrer->siguiente->anterior = nodo_para_recorrer->anterior;
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
    if (cola_a_desencolar->primero == NULL)
    {
        return;
    }
    if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->primero->pcbdelnodo.id)
    {
        cola_a_desencolar->primero = cola_a_desencolar->primero->siguiente;
        if (cola_a_desencolar->primero == NULL)
        {
            cola_a_desencolar->ultimo = NULL;
        }
    }
    else if (nodo_a_desencolar->pcbdelnodo.id == cola_a_desencolar->ultimo->pcbdelnodo.id)
    {
        cola_a_desencolar->ultimo = cola_a_desencolar->ultimo->anterior;
        cola_a_desencolar->ultimo->siguiente = NULL;
    }
    else
    {
        nodo_para_recorrer = cola_a_desencolar->primero;
        while (nodo_para_recorrer->pcbdelnodo.id != nodo_a_desencolar->pcbdelnodo.id || nodo_para_recorrer->siguiente == NULL)
        {
            nodo_para_recorrer = nodo_para_recorrer->siguiente;
        }
        nodo_para_recorrer->anterior->siguiente = nodo_para_recorrer->siguiente;
        nodo_para_recorrer->siguiente->anterior = nodo_para_recorrer->anterior;
    }
}

void init_cola(cola *cola)
{
    cola->primero = NULL;
    cola->ultimo = NULL;
}
