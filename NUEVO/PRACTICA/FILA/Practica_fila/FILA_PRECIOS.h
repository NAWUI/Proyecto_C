#ifndef FILA_PRECIOS_H_INCLUDED
#define FILA_PRECIOS_H_INCLUDED

#include "TDAPRECIOS.h"

#define N 100  // Tama�o de la fila

typedef struct {
    productos elementos[N];
    int ultimo;  // �ndice del �ltimo elemento de la fila
} FilaProductos;

// Inicializaci�n de la fila
void InitFila(FilaProductos *fila) {
    fila->ultimo = -1; // Inicializa en -1 para indicar que est� vac�a
}

// Insertar producto en la fila (enqueue)
void push(FilaProductos *fila, productos producto) {
    if (fila->ultimo < N - 1) {  // Verifica que no est� llena
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
    fila->ultimo--; // Decrementa el �ndice del �ltimo elemento
    return producto;
}

// Obtener el primer producto en la fila
productos getPrimero(FilaProductos fila) {
    return fila.elementos[0]; // Producto en el frente
}

// Funci�n para verificar si la fila est� vac�a
int isEmpty(FilaProductos fila) {
    return fila.ultimo == -1; // Verifica si `ultimo` es -1
}

// Funci�n para verificar si la fila est� llena
int isFull(FilaProductos fila) {
    return fila.ultimo == N - 1; // Verifica si `ultimo` es el m�ximo �ndice permitido
}

#endif // FILA_PRECIOS_H_INCLUDED
