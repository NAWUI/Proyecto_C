#include <stdio.h>
#include <stdlib.h>
#include "TDAFila.h"

int main() {
    int opcion;
    char caracter;
    Fila fila;

    init_fila(&fila);

    do {
        printf("\n--- Menú Fila de Caracteres ---\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Ver frente\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar buffer

        switch (opcion) {
            case 1:
                if (!es_llena_fila(fila)) {
                    printf("Ingrese un carácter para encolar: ");
                    scanf("%c", &caracter);
                    encolar(&fila, caracter);
                    printf("Carácter '%c' encolado.\n", caracter);
                } else {
                    printf("La fila está llena.\n");
                }
                break;
            case 2:
                if (!es_vacia_fila(fila)) {
                    caracter = desencolar(&fila);
                    printf("Carácter desencolado: '%c'\n", caracter);
                } else {
                    printf("La fila está vacía.\n");
                }
                break;
            case 3:
                if (!es_vacia_fila(fila)) {
                    printf("El carácter al frente es: '%c'\n", frente(fila));
                } else {
                    printf("La fila está vacía.\n");
                }
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
