#include <stdio.h>
#include <stdbool.h>
#include "TDA.h" // Asegúrate de que la definición de Persona esté incluida aquí

#define MAX_LISTA 100 // Tamaño máximo de la lista estática

typedef struct {
    Persona vipd;
    int next; // Índice del siguiente nodo
} Nodo;

typedef struct {
    Nodo elementos[MAX_LISTA];
    int acc;    // Índice del primer elemento en la lista
    int cur;    // Índice del cursor actual
    int aux;    // Índice del cursor auxiliar
    int libre;  // Índice del primer nodo libre en el array
} Lista;

void init(Lista *l) {
    l->acc = -1;
    l->cur = -1;
    l->aux = -1;

    for (int i = 0; i < MAX_LISTA - 1; i++) {
        l->elementos[i].next = i + 1;
    }
    l->elementos[MAX_LISTA - 1].next = -1;
    l->libre = 0;
}

void insertL(Lista *l, Persona a) {
   // if (l->libre == -1) return;

    int nuevo = l->libre;
    l->libre = l->elementos[l->libre].next;

    l->elementos[nuevo].vipd = a;

    if (l->acc == -1) {
        l->acc = nuevo;
        l->elementos[nuevo].next = -1;
    } else {
        l->elementos[nuevo].next = l->cur;
        l->elementos[l->aux].next = nuevo;
    }
    l->cur = nuevo;
}

Persona is_copy(Lista *l) {
    return l->elementos[l->cur].vipd;
}

bool is_emptys(Lista *l) {
    return l->acc == -1;
}

bool is_Full(Lista *l) {
    return l->libre == -1;
}

void forwards(Lista *l) {
  //  if (l->cur != -1) {
        l->aux = l->cur;
        l->cur = l->elementos[l->cur].next;
 //   }
}

void suppress(Lista *l) {
    //if (l->cur == -1) return;

    int temp = l->cur;

    if (l->cur == l->acc) {
        l->acc = l->elementos[l->cur].next;
        l->cur = l->acc;
    } else {
        l->elementos[l->aux].next = l->elementos[l->cur].next;
        l->cur = l->elementos[l->aux].next;
    }

    l->elementos[temp].next = l->libre;
    l->libre = temp;
}
/*
void imprimir(Lista *l) {
    int actual = l->acc;
    while (actual != -1) {
        printf("Elemento: %d\n", l->elementos[actual].vipd);
        actual = l->elementos[actual].next;
    }
}
*/
