#ifndef TDAFILA_H_INCLUDED
#define TDAFILA_H_INCLUDED

#include "TDAauto.h"

typedef struct nodo {
    Auto vipd; // Elemento de la lista
    struct nodo *next;
} Nodo;

typedef struct {
    Nodo *acc; // Acceso a la lista
    Nodo *cur; // Cursor de la lista
    Nodo *aux; // Cursor auxiliar
} List_of_auto;


// Inicializa la lista
void init(List_of_auto *l) {
    l->acc = NULL;
    l->cur = NULL;
    l->aux = NULL;
}

// Inserta un nuevo auto en la lista
void inserts(List_of_auto *l, Auto a) {
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->vipd = a; // Asigna el auto al nodo
    n->next = NULL;

    if (isEmpty(*l)) {
        l->acc = n; // Si la lista está vacía, el nuevo nodo es el acceso
        l->cur = n; // El cursor también apunta al nuevo nodo
    } else {
        l->cur->next = n; // Agrega el nodo al final de la lista
        l->cur = n; // Mueve el cursor al nuevo nodo
    }
}

// Suprime el nodo al que apunta el cursor
void suppress(List_of_auto *l) {
    if (isEmpty(*l)) return;

    Nodo *temp = l->acc;
    if (l->cur == l->acc) {
        l->acc = l->acc->next; // Mueve el acceso al siguiente nodo
        free(temp);
        l->cur = l->acc; // Si se eliminó el acceso, el cursor también se mueve
    } else {
        while (temp->next != l->cur) {
            temp = temp->next; // Encuentra el nodo anterior al cursor
        }
        temp->next = l->cur->next; // Elimina el nodo del cursor
        free(l->cur);
        l->cur = temp->next; // Mueve el cursor
    }
}

// Comprueba si el cursor está fuera de la lista
int isOos(List_of_auto l) {
    return l.cur == NULL;
}

// Comprueba si la lista está vacía
int isEmpty(List_of_auto l) {
    return l.acc == NULL;
}

// Copia el auto en el nodo actual
Auto copyc(List_of_auto l) {
    return l.cur->vipd;
}

// Mueve el cursor hacia adelante
void forwards(List_of_auto *l) {
    if (l->cur != NULL) {
        l->aux = l->cur;
        l->cur = l->cur->next;
    }
}

// Resetea el cursor al inicio de la lista
void reset(List_of_auto *l) {
    l->cur = l->acc;
    l->aux = l->acc;
}

// Muestra los autos en la lista
/*
void mostrar(List_of_auto l) {
    Nodo *temp = l.acc;
    while (temp != NULL) {
        printf("Marca: %s, Modelo: %s, Año: %d, Titular: %s, Precio: %.2f, KM: %d\n",
               Get_marca(temp->vipd), Get_modelo(temp->vipd), Get_anio(temp->vipd),
               Get_titular(temp->vipd), Get_precio(temp->vipd), Get_cant_KM(temp->vipd));
        temp = temp->next;
    }
}
*/
#endif // TDAFILA_H_INCLUDED
