#include <stdio.h>
#include "TDAautochat.h"
#include <stdlib.h> // Necesario para malloc y free

typedef struct Nodo {
    Auto vipd;
    struct Nodo *next;
} Nodo;

typedef struct {
    Nodo *acc; // Acceso al primer nodo
    Nodo *cur; // Cursor de la lista
} List_of_auto;
void initList(List_of_auto *l) {
    l->acc = NULL;
    l->cur = NULL;
}

int isEmpty(List_of_auto l) {
    return l.acc == NULL;
}

void inserts(List_of_auto *l, Auto a) {
    Nodo *newNode = (Nodo*) malloc(sizeof(Nodo));
    if (newNode != NULL) {
        newNode->vipd = a;
        newNode->next = l->acc;
        l->acc = newNode;
    }
}

int enqueue(List_of_auto *l, Auto a) {
    inserts(l, a); // Usamos inserts para insertar en la lista
    return 0;
}

void mostrar(List_of_auto l) {
    Nodo *temp = l.acc;
    while (temp != NULL) {
        printf("Marca: %s, Modelo: %s, Año: %d, Titular: %s, Precio: %.2f, KM: %d\n",
               Get_marca(temp->vipd), Get_modelo(temp->vipd), Get_anio(temp->vipd),
               Get_titular(temp->vipd), Get_precio(temp->vipd), Get_cant_KM(temp->vipd));
        temp = temp->next;
    }
}

int count(List_of_auto l) {
    int count = 0;
    Nodo *temp = l.acc;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void free_list(List_of_auto *l) {
    Nodo *temp;
    while (l->acc != NULL) {
        temp = l->acc;
        l->acc = l->acc->next;
        free(temp);
    }
    l->cur = NULL;
}
