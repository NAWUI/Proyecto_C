#include <stdio.h>
#include <stdlib.h>
#include "TDApersona.h"
#include "TDALista.h"

// Función para mostrar la lista de personas
void mostrar_lista(Lista *l) {
    if (is_emptys(l)) {
        printf("La lista está vacía.\n");
        return;
    }

    reset(l);
    while (!isOos(l)) {
        Persona a = is_copy(l);
        printf("Nombre: %s, Apellido: %s, DNI: %d, Email: %s\n",
               get_nombre(a), get_apellido(a), get_dni(a), get_email(a));
        forwards(l);
    }
}

// Función para crear una persona desde el input del usuario
Persona crear_Persona() {
    Persona nueva_persona;
    char nombre[max_char];
    char apellido[max_char];
    int dni;
    char email[max_char];

    printf("Ingrese nombre: ");
    fgets(nombre, max_char, stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
    set_nombre(&nueva_persona, nombre);

    printf("Ingrese apellido: ");
    fgets(apellido, max_char, stdin);
    apellido[strcspn(apellido, "\n")] = '\0'; // Eliminar el salto de línea
    set_apellido(&nueva_persona, apellido);

    printf("Ingrese email: ");
    fgets(email, max_char, stdin);
    email[strcspn(email, "\n")] = '\0'; // Eliminar el salto de línea
    set_email(&nueva_persona, email);

    printf("Ingrese dni: ");
    scanf("%d", &dni);
    set_dni(&nueva_persona, dni);
    getchar(); // Limpiar el buffer de entrada

    return nueva_persona;
}

// Función para buscar una persona por DNI
void buscar_persona(Lista *l, int dni) {
    reset(l);
    while (!isOos(l)) {
        Persona a = copy(l);
        if (get_dni(a) == dni) {
            printf("Persona encontrada:\n");
            printf("Nombre: %s, Apellido: %s, DNI: %d, Email: %s\n",
                   get_nombre(a), get_apellido(a), get_dni(a), get_email(a));
            return;
        }
        forwards(l);
    }
    printf("No se encontró ninguna persona con el DNI %d.\n", dni);
}

// Función para mostrar el menú
void mostrar_menu() {
    printf("\nMenu:\n");
    printf("1. Insertar una persona\n");
    printf("2. Suprimir la persona actual\n");
    printf("3. Mostrar lista de personas\n");
    printf("4. Buscar Persona por DNI\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Lista lista;
    init(&lista);  // Inicializamos la lista

    int opcion, dni;
    do {
        mostrar_menu();
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer de entrada después de leer la opción

        switch (opcion) {
            case 1: {
                Persona nueva_persona = crear_Persona();
                insert(&lista, nueva_persona);
                printf("Persona insertada correctamente.\n");
                break;
            }
            case 2: {
                if (empty(&lista)) {
                    printf("La lista está vacía, no se puede suprimir.\n");
                } else {
                    suppress(&lista);
                    printf("Persona suprimida correctamente.\n");
                }
                break;
            }
            case 3:
                mostrar_lista(&lista);
                break;
            case 4:
                printf("Ingrese el DNI de la persona que desea buscar: ");
                scanf("%d", &dni);
                buscar_persona(&lista, dni);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida, por favor seleccione otra opción.\n");
        }
    } while (opcion != 5);

    return 0;
}
