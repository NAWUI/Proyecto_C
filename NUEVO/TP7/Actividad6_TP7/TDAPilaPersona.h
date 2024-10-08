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

int is_emptys (Pila p) {
    return p.tope == -1;
}

int is_full(Pila p) {
    return p.tope == MAX - 1;
}

void push(Pila *p, Persona persona) {
    if (!is_full(*p)) {
        p->datos[++(p->tope)] = persona;
    }
}

Persona pop(Pila *p) {
    if (!is_emptys(*p)) {
        return p->datos[(p->tope)--];
    }
    Persona vacia;
    return vacia;
}

Persona peek(Pila p) {
    if (!is_emptys(p)) {
        return p.datos[p.tope];
    }
    Persona vacia;
    return vacia;
}

#endif // TDAPILAPERSONA_H_INCLUDED
