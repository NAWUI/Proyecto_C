// main.c
#include <stdio.h>
#include "TDAauto.h"
#include "TDAfila.h"

int main() {
    List_of_auto filaAutos;
    init(&filaAutos); // Capacidad máxima de la fila
    Auto miAuto;
    char marci[50];
    char model[50];
    int anio;
    char propeti[100];
    float preci;
    int cantKM;
    int opcion, cursor = 0;

    do {
        printf("--------- Menú ---------\n");
        printf("1. Cargar Auto\n");
        printf("2. Mostrar Autos\n");
        printf("3. Mostrar Auto en Cursor\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer

        switch (opcion) {
            case 1:
                printf("Ingrese la marca del Auto:\n");
                fgets(marci, sizeof(marci), stdin);
                marci[strcspn(marci, "\n")] = '\0'; // Eliminar el salto de línea
                Set_marca(&miAuto, marci);

                printf("Ingrese el modelo del Auto:\n");
                fgets(model, sizeof(model), stdin);
                model[strcspn(model, "\n")] = '\0';
                Set_modelo(&miAuto, model);

                printf("Ingrese el kilometraje del Auto:\n");
                scanf("%d", &cantKM);
                Set_cant_KM(&miAuto, cantKM);

                printf("Ingrese el año del Auto:\n");
                scanf("%d", &anio);
                Set_anio(&miAuto, anio);

                getchar(); // Limpiar el buffer
                printf("Ingrese el Nombre del propietario del Auto:\n");
                fgets(propeti, sizeof(propeti), stdin);
                propeti[strcspn(propeti, "\n")] = '\0';
                Set_titular(&miAuto, propeti);

                printf("Ingrese el Precio del Auto (USD):\n");
                scanf("%f", &preci);
                Set_precio(&miAuto, preci);

                if (enqueue(&filaAutos, miAuto) == -1) {
                    printf("La fila está llena, no se puede agregar el auto.\n");
                } else {
                    printf("Auto agregado a la fila.\n");
                }
                break;

            case 2:
                printf("Autos en la fila:\n");
                mostrar(filaAutos);
                break;

            case 3:
                printf("Ingrese la posición del cursor (0 a %d): ", filaAutos.fondo - 1);
                scanf("%d", &cursor);
                mostrarCursor(filaAutos, cursor);
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida, intente de nuevo.\n");
        }
    } while (opcion != 4);

    free(filaAutos.autos); // Liberar memoria
    return 0;
}

