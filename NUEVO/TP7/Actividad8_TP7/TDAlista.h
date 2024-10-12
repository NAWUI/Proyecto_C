#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED

#include "TDApersona.h"

struct nodo {
    Persona vipd;
    struct  nodo *next;
};

typedef struct nodo Nodo;


typedef struct {
    Nodo *acc;  // Acceso al primer nodo
    Nodo *cur;  // Cursor actual
    Nodo *aux;  // Cursor auxiliar (anterior al actual)
} Lista;

// Implementación de las funciones
void init(Lista *l) {
    l->acc = NULL;
    l->cur = NULL;
    l->aux = NULL;
}

int is_emptys(Lista *l) {
    return l->acc == NULL;
}

void forwards(Lista *l) {
    if (l->cur != NULL) {
        l->aux = l->cur;
        l->cur = l->cur->next;
    }
}

void reset(Lista *l) {
    l->cur = l->acc;
    l->aux = NULL;
}

Persona is_copy(Lista *l) {
    if (l->cur != NULL) {
        return l->cur->vipd;
    }
    Persona vacio = {"", "", 0, ""};
    return vacio;
}

void is_insert(Lista *l, Persona valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return;
    }
    nuevo->vipd = valor;
    nuevo->next = NULL;

    if (is_emptys(l)) {
        l->acc = nuevo;
        l->cur = nuevo;
        l->aux = NULL;
    }
    else if (l->cur == l->acc) {
        nuevo->next = l->cur;
        l->acc = nuevo;
        l->cur = nuevo;
        l->aux = nuevo;
    }
    else {
        l->aux->next = nuevo;
        nuevo->next = l->cur;
        l->cur = nuevo;
    }
}

void suppress(Lista *l) {
    if (is_emptys(l)) {
        printf("Lista vacía, no se puede suprimir.\n");
        return;
    }

    Nodo *eliminar = l->cur;

    if (l->cur == l->acc) {
        l->acc = l->cur->next;
        l->cur = l->acc;
    }
    else {
        l->aux->next = l->cur->next;
        l->cur = l->cur->next;
    }

    free(eliminar);
}

int isOos(Lista *l) {
    return l->cur == NULL;
}
#endif // TDALISTA_H_INCLUDED
