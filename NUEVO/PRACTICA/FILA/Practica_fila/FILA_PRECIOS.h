#ifndef FILA_PRECIOS_H_INCLUDED
#define FILA_PRECIOS_H_INCLUDED

#include "TDAPRECIOS.h"

#define N 100  // Tamaño de la fila

typedef struct {
    productos elementos[N];
    int ultimo;  // Índice del último elemento de la fila
} FilaProductos;

// Inicialización de la fila
void InitFila(FilaProductos *fila) {
    fila->ultimo = -1; // Inicializa en -1 para indicar que está vacía
}

// Insertar producto en la fila (enqueue)
void push(FilaProductos *fila, productos producto) {
    if (fila->ultimo < N - 1) {  // Verifica que no esté llena
        fila->elementos[++fila->ultimo] = producto;
    }
}

// Quitar producto de la fila (dequeue)
productos suppress(FilaProductos *fila) {
    productos producto = fila->elementos[0]; // Obtiene el primer elemento
    // Desplazamiento de los elementos hacia la izquierda
    for (int i = 0; i < fila->ultimo; i++) {
        fila->elementos[i] = fila->elementos[i + 1];
    }
    fila->ultimo--; // Decrementa el índice del último elemento
    return producto;
}

// Obtener el primer producto en la fila
productos getPrimero(FilaProductos fila) {
    return fila.elementos[0]; // Producto en el frente
}

// Función para verificar si la fila está vacía
int isEmpty(FilaProductos fila) {
    return fila.ultimo == -1; // Verifica si `ultimo` es -1
}

// Función para verificar si la fila está llena
int isFull(FilaProductos fila) {
    return fila.ultimo == N - 1; // Verifica si `ultimo` es el máximo índice permitido
}

#endif // FILA_PRECIOS_H_INCLUDED
