#include <stdio.h>
#include "TDAPRECIOS.h"
#include "PILA_PRECIOS.h"

void cargarProducto(PilaProductos *pila) {
    if (isFull(*pila)) {
        printf("Error: La pila esta llena, no se puede cargar el producto.\n");
        return;
    }

    productos nuevoProducto;
    int num_produ;
    float price_produ;

    printf("Ingrese el Numero del Producto: \n");
    scanf("%d", &num_produ);
    Set_N_pro(&nuevoProducto, num_produ);
    printf("Ingrese el Precio del Producto: \n");
    scanf("%f", &price_produ);
    Set_price(&nuevoProducto, price_produ);

    push(pila, nuevoProducto);
    printf("Producto cargado en la pila.\n");
}

void verProductoEnTope(PilaProductos *pila) {
    if (isEmpty(*pila)) {
        printf("La pila esta vacia.\n");
        return;
    }

    productos topeProducto = getTope(*pila);
    printf("Producto en la cima de la pila:\n");
    printf("Numero de Producto: %d\n", topeProducto.N_pro);
    printf("Precio de Producto: %.2f\n", topeProducto.price);
}

void quitarProductoDePila(PilaProductos *pila) {
    if (isEmpty(*pila)) {
        printf("Error: La pila esta vacia, no se puede quitar ningun producto.\n");
        return;
    }

    productos productoEliminado = pop(pila);
    printf("Producto eliminado: Numero: %d \n", productoEliminado.N_pro);
    printf("Producto eliminado: Precio: %.2f \n", productoEliminado.price);
}

int main() {
    PilaProductos miPila;
    productos miproducto;
    int opcion;

    Init(&miproducto); // Inicializaprecio
    InitPila(&miPila);  // Inicializa la pila

    do {
        printf("----Menu----\n");
        printf("(1)- Cargar Producto\n");
        printf("(2)- Ver Producto en la Cima\n");
        printf("(3)- Quitar Producto de la Pila\n");
        printf("(0)- Salir\n");
        printf("-----------\n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("-Cargar Producto en la Pila- \n");
                cargarProducto(&miPila);
            break;

            case 2:
                printf("-Ver Producto en la Cima de la Pila- \n");
                verProductoEnTope(&miPila);
            break;

            case 3:
                printf("-Quitar Producto de la Pila- \n");
                quitarProductoDePila(&miPila);
            break;

            case 0:
                printf("Saliendo.... \n");
            break;

            default:
                printf("Opcion Invalida \n");
        }

    } while(opcion != 0);

    return 0;
}

