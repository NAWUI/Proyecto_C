#ifndef PILA_PRECIOS_H_INCLUDED
#define PILA_PRECIOS_H_INCLUDED

#include "TDAPRECIOS.h"

#define N 100  // Tamaño de la pila

typedef struct {
    productos elementos[N];
    int tope;
} PilaProductos;

// Inicialización de la pila
void InitPila(PilaProductos *pila) {
    pila->tope = -1;  // Inicializa el tope en -1 para indicar que está vacía
}

// Insertar producto en la pila (push)
void push(PilaProductos *pila, productos producto) {
    pila->tope++;
    pila->elementos[pila->tope] = producto;
}

// Quitar producto de la pila (pop)
productos pop(PilaProductos *pila) {
    productos producto = pila->elementos[pila->tope];
    pila->tope--;
    return producto;
}

// Obtener el producto en la cima de la pila
productos getTope(PilaProductos pila) {
    return pila.elementos[pila.tope];  // Producto en la cima
}
// Función para verificar si la pila está vacía
int isEmpty(PilaProductos pila) {
    return pila.tope == -1;
}

// Función para verificar si la pila está llena
int isFull(PilaProductos pila) {
    return pila.tope == N - 1;
}


#endif // PILA_PRECIOS_H_INCLUDED
