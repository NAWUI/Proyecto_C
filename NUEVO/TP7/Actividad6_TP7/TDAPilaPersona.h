#ifndef TDAPILAPERSONA_H_INCLUDED
#define TDAPILAPERSONA_H_INCLUDED

#include "TDApersona.h"

#define MAX 100

typedef struct {
    Persona datos[MAX];
    int tope;
} Pila;

void init_pila(Pila *p) {
    p->tope = -1;
}

int es_vacia(Pila p) {
    return p.tope == -1;
}

int es_llena(Pila p) {
    return p.tope == MAX - 1;
}

void push(Pila *p, Persona persona) {
    if (!es_llena(*p)) {
        p->datos[++(p->tope)] = persona;
    }
}

Persona pop(Pila *p) {
    if (!es_vacia(*p)) {
        return p->datos[(p->tope)--];
    }
    Persona vacia;
    return vacia;  // Retorna una persona vacía si la pila está vacía
}

Persona peek(Pila p) {
    if (!es_vacia(p)) {
        return p.datos[p.tope];
    }
    Persona vacia;
    return vacia;  // Retorna una persona vacía si la pila está vacía
}

#endif // TDAPILAPERSONA_H_INCLUDED
