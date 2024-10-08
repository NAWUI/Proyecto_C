#include <stdio.h>
#include <stdlib.h>
#include "TDApersona.h"
#define MAX_user 2

int main() {
    Persona infoP[MAX_user];
    char nombre[max_char];
    char apellido[max_char];
    int dni;
    char email[max_char];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n--- Menu Persona ---\n");
        printf("1. Ingresar Persona\n");
        printf("2. Buscar Persona por DNI\n");
        printf("3. Modificar Persona\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                if (cantidad < MAX_user) {
                    printf("Ingrese nombre: ");
                    gets(nombre);
                    set_nombre(&infoP[cantidad], nombre);

                    printf("Ingrese apellido: ");
                    gets(apellido);
                    set_apellido(&infoP[cantidad], apellido);

                    printf("Ingrese email: ");
                    gets(email);
                    set_email(&infoP[cantidad], email);

                    printf("Ingrese dni: ");
                    scanf("%d", &dni);
                    set_dni(&infoP[cantidad], dni);
                    getchar();

                    cantidad++;
                } else {
                    printf("Se ha alcanzado el límite de usuarios.\n");
                }
                break;
            case 2:
                printf("Ingrese el DNI de la persona a buscar: ");
                scanf("%d", &dni);
                Persona *pEncontrada = buscar_persona_por_dni(infoP, cantidad, dni);
                if (pEncontrada != NULL) {
                    printf("Persona encontrada: %s %s, Email: %s, DNI: %d\n",
                           get_nombre(*pEncontrada), get_apellido(*pEncontrada),
                           get_email(*pEncontrada), get_dni(*pEncontrada));
                } else {
                    printf("Persona no encontrada.\n");
                }
                break;
            case 3:

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
