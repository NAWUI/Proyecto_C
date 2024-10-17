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

        l->cur->next = nuevo;
        l->aux = l->cur;
        l->cur = nuevo;
    }
    else {
        l->aux->next = nuevo;
        nuevo->next = l->cur;
        l->cur = nuevo;
    }
}

void suppress(Lista *l) {

  //  Nodo *eliminar = l->cur;

    // Caso 1: Eliminar el primer nodo
    if (l->cur == l->acc) {
            printf("flacooooo2");
        l->acc = l->cur->next;  // Actualizamos el puntero acc al siguiente nodo
        free((void*)l->cur);
        l->cur = l->acc;         // Avanzamos el cursor al nuevo primer nodo
        l->aux = l->acc;

    }
    // Caso 2: Eliminar un nodo intermedio o el último
    else {
        // Ajustamos el puntero del nodo anterior (aux->next) al siguiente del nodo actual (cur->next)
        l->aux->next = l->cur->next;
        free((void*)l->cur);
        l->cur = l->aux->next;  // Avanzamos el cursor

        }

    }
int isOos(Lista *l) {
    return l->cur == NULL;
}
#endif // TDALISTA_H_INCLUDED
