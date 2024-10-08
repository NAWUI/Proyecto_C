#include <stdio.h>
#include <stdlib.h>
#include "TDAPilaPersona.h"
#include "TDApersona.h"

int main() {
    int opcion;
    Persona personal;
    Pila pila_persona;

    init_pila(&pila_persona);
    char nombre[max_char], apellido[max_char], email[max_char];
    int dni;

    do {
        printf("\n--- Menú Pila de Personas ---\n");
        printf("1. Apilar Persona\n");
        printf("2. Desapilar Persona\n");
        printf("3. Ver Persona en tope\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                if (!is_full(pila_persona)) {

                    printf("Ingrese nombre: ");
                    gets(nombre);
                    set_nombre(&personal, nombre);

                    printf("Ingrese apellido: ");
                    gets(apellido);
                    set_apellido(&personal, apellido);

                    printf("Ingrese DNI: ");
                    scanf("%d", &dni);
                    set_dni(&personal, dni);
                    getchar();

                    printf("Ingrese email: ");
                    gets(email);
                    set_email(&personal, email);

                    push(&pila_persona, personal);
                    printf("Persona apilada correctamente.\n");
                } else {
                    printf("La pila está llena.\n");
                }
                break;

            case 2:
                if (!is_emptys(pila_persona)) {
                    personal = pop(&pila_persona);
                    printf("Persona desapilada: %s %s, DNI: %d\n", get_nombre(personal), get_apellido(personal), get_dni(personal));
                } else {
                    printf("La pila esta vacía.\n");
                }
                break;

            case 3:
                if (!is_emptys(pila_persona)) {
                    personal = peek(pila_persona);
                    printf("Persona en el tope: %s %s, DNI: %d\n", get_nombre(personal), get_apellido(personal), get_dni(personal));
                } else {
                    printf("La pila esta vacia.\n");
                }
                break;

            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;
}
