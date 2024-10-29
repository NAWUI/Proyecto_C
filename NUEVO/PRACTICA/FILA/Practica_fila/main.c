#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TDAPRECIOS.h"
#include "FILA_PRECIOS.h"

void cargarProducto(FilaProductos *fila) {
    if (isFull(*fila)) {
        printf("Error: La fila esta llena, no se puede cargar el producto.\n");
        return;
    }

    productos nuevoProducto;
    int num_produ;
    float price_produ;
    char nom_produ[50];

    printf("Ingrese el nombre del Producto: \n");
    scanf(" %s", nom_produ);
    Set_No_pro(&nuevoProducto, nom_produ);
    printf("Ingrese el Numero del Producto: \n");
    scanf("%d", &num_produ);
    Set_N_pro(&nuevoProducto, num_produ);
    printf("Ingrese el Precio del Producto: \n");
    scanf("%f", &price_produ);
    Set_price(&nuevoProducto, price_produ);

    push(fila, nuevoProducto);
    printf("Producto cargado en la fila.\n");
}

void verPrimerProducto(FilaProductos *fila) {
    if (isEmpty(*fila)) {
        printf("La fila esta vacia.\n");
        return;
    }

    productos primerProducto = getPrimero(*fila);
    printf("Primer producto en la fila:\n");
    printf("Numero de Producto: %d\n", primerProducto.N_pro);
    printf("Precio de Producto: %.2f\n", primerProducto.price);
}

void quitarProductoDeFila(FilaProductos *fila) {
    if (isEmpty(*fila)) {
        printf("Error: La fila esta vacia, no se puede quitar ningun producto.\n");
        return;
    }

    productos productoEliminado = suppress(fila);  //suppress
    printf("Producto eliminado: Numero: %d \n", productoEliminado.N_pro);
    printf("Producto eliminado: Precio: %.2f \n", productoEliminado.price);
}

int main() {
    FilaProductos miFila;
    productos miproducto;
    int opcion;

    Init(&miproducto); // Inicializa el producto
    InitFila(&miFila);  // Inicializa la fila

    do {
        printf("----Menu----\n");
        printf("(1)- Cargar Producto\n");
        printf("(2)- Ver Primer Producto en la Fila\n");
        printf("(3)- Quitar Producto de la Fila\n");
        printf("(0)- Salir\n");
        printf("------------\n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("-Cargar Producto en la Fila- \n");
                cargarProducto(&miFila);
            break;

            case 2:
                printf("-Ver Primer Producto en la Fila- \n");
                verPrimerProducto(&miFila);
            break;

            case 3:
                printf("-Quitar Producto de la Fila- \n");
                quitarProductoDeFila(&miFila);
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
