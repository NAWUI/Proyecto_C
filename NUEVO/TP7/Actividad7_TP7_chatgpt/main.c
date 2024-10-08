#include <stdio.h>
#include "TDAautochat.h"
#include "TDAfilachat.h"

void mostrarMenu() {
    printf("\n--- MENÚ ---\n");
    printf("1. Agregar auto\n");
    printf("2. Mostrar autos\n");
    printf("3. Contar autos registrados\n");
    printf("4. Liberar memoria y salir\n");
    printf("Elija una opcion: ");
}

int main() {
    List_of_auto filaAutos;
    initList(&filaAutos);
    int opcion = 0;

    while (opcion != 4) {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1: {
                char marca[20], modelo[20], titular[30];
                int anio, cant_KM;
                float precio;

                printf("\nIngrese la marca del auto: ");
                fgets(marca, 20, stdin);
                printf("Ingrese el modelo del auto: ");
                fgets(modelo, 20, stdin);
                printf("Ingrese el anio del auto: ");
                scanf("%d", &anio);
                getchar(); // Limpiar buffer

                printf("Ingrese el titular del auto: ");
                fgets(titular, 30, stdin);
                printf("Ingrese el precio del auto: ");
                scanf("%f", &precio);
                printf("Ingrese la cantidad de KM del auto: ");
                scanf("%d", &cant_KM);
                getchar(); // Limpiar buffer

                Auto nuevoAuto;
                initAuto(&nuevoAuto, marca, modelo, anio, titular, precio, cant_KM);
                enqueue(&filaAutos, nuevoAuto);

                printf("\nAuto agregado exitosamente.\n");
                break;
            }

            case 2:
                printf("\nLista de autos registrados:\n");
                if (isEmpty(filaAutos)) {
                    printf("No hay autos registrados.\n");
                } else {
                    mostrar(filaAutos);
                }
                break;

            case 3:
                printf("\nCantidad de autos registrados: %d\n", count(filaAutos));
                break;

            case 4:
                free_list(&filaAutos);
                printf("\nMemoria liberada. Saliendo...\n");
                break;

            default:
                printf("\nOpción no válida. Por favor, elija una opción válida.\n");
                break;
        }
    }

    return 0;
}
