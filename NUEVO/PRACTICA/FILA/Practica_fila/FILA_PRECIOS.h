#ifndef FILA_PRECIOS_H_INCLUDED
#define FILA_PRECIOS_H_INCLUDED

#include "TDAPRECIOS.h"

#define N 100  // Tama�o de la fila

typedef struct {
    productos elementos[N];
    int frente; // �ndice del primer elemento
    int final;  // �ndice del �ltimo elemento
} FilaProductos;

// Inicializaci�n de la fila
void InitFila(FilaProductos *fila) {
    fila->frente = 0; // Inicializa el frente
    fila->final = 0;  // Inicializa el final
}

// Insertar producto en la fila (enqueue)
void push (FilaProductos *fila, productos producto) {
    fila->elementos[fila->final] = producto;
    fila->final = (fila->final + 1) % N; // Manejo circular
}

// Quitar producto de la fila (dequeue)
productos suppress(FilaProductos *fila) {
    productos producto = fila->elementos[fila->frente];
    fila->frente = (fila->frente + 1) % N; // Manejo circular
    return producto;
}

// Obtener el primer producto en la fila
productos getPrimero(FilaProductos fila) {
    return fila.elementos[fila.frente]; // Producto en el frente
}

// Funci�n para verificar si la fila est� vac�a
int isEmpty(FilaProductos fila) {
    return fila.frente == fila.final; // Verifica si el frente es igual al final
}

// Funci�n para verificar si la fila est� llena
int isFull(FilaProductos fila) {
    return (fila.final + 1) % N == fila.frente; // Verifica si el siguiente final es igual al frente
}

#endif // FILA_PRECIOS_H_INCLUDED
