#include <stdio.h>
#include <stdlib.h>
#include "TDAAuto.h"
#include "TDALista.h"



// Función para mostrar la lista de autos
void mostrar_lista(Lista *l) {
    if (empty(l)) {
        printf("La lista está vacía.\n");
        return;
    }

    reset(l);
    while (!isOos(l)) {
        Auto a = copy(l);
        printf("Marca: %s, Modelo: %s, Titular: %s, Precio: %.2f, KM: %d, Año: %d\n",
               Get_marca(a), Get_modelo(a), Get_titular(a), Get_precio(a), Get_cant_KM(a), Get_anio(a));
        forwards(l);
    }
}

// Función para crear un auto desde el input del usuario
Auto crear_auto() {
    Auto nuevo_auto;
    char marca[50], modelo[50], titular[100];
    float precio;
    int km, anio;

    printf("Ingrese la marca del auto: ");
    scanf("%s", marca);
    Set_marca(&nuevo_auto, marca);

    printf("Ingrese el modelo del auto: ");
    scanf("%s", modelo);
    Set_modelo(&nuevo_auto, modelo);

    printf("Ingrese el titular del auto: ");
    scanf("%s", titular);
    Set_titular(&nuevo_auto, titular);

    printf("Ingrese el precio del auto: ");
    scanf("%f", &precio);
    Set_precio(&nuevo_auto, precio);

    printf("Ingrese la cantidad de kilometros: ");
    scanf("%d", &km);
    Set_cant_KM(&nuevo_auto, km);

    printf("Ingrese el año de fabricacion: ");
    scanf("%d", &anio);
    Set_anio(&nuevo_auto, anio);

    return nuevo_auto;
}

// Función para mostrar el menú
void mostrar_menu() {
    printf("\nMenu:\n");
    printf("1. Insertar un auto\n");
    printf("2. Suprimir el auto actual\n");
    printf("3. Mostrar lista de autos\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Lista lista;
    init(&lista);  // Inicializamos la lista

    int opcion;
    do {
        mostrar_menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Auto nuevo_auto = crear_auto();
                insert(&lista, nuevo_auto);
                printf("Auto insertado correctamente.\n");
                break;
            }
            case 2: {
                if (empty(&lista)) {
                    printf("La lista esta vacia, no se puede suprimir.\n");
                } else {
                    suppress(&lista);
                    printf("Auto suprimido correctamente.\n");
                }
                break;
            }
            case 3:
                mostrar_lista(&lista);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida, por favor seleccione otra opcion.\n");
        }
    } while (opcion != 4);

    return 0;
}
