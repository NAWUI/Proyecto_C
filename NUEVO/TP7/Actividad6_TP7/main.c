#include <stdio.h>
#include <stdlib.h>
#include "TDAPilaPersona.h"
#include "TDApersona.h"

int main() {
    int opcion;
    Persona persona;
    Pila pila_persona;

    init_pila(&pila_persona);

    do {
        printf("\n--- Menú Pila de Personas ---\n");
        printf("1. Apilar Persona\n");
        printf("2. Desapilar Persona\n");
        printf("3. Ver Persona en tope\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar buffer de entrada

        switch (opcion) {
            case 1:
                if (!es_llena(pila_persona)) {
                    // Ingresar datos de la persona
                    char nombre[max_char], apellido[max_char], email[max_char];
                    int dni;

                    printf("Ingrese nombre: ");
                    gets(nombre);
                    set_nombre(&persona, nombre);

                    printf("Ingrese apellido: ");
                    gets(apellido);
                    set_apellido(&persona, apellido);

                    printf("Ingrese DNI: ");
                    scanf("%d", &dni);
                    set_dni(&persona, dni);
                    getchar();  // Limpiar buffer de entrada

                    printf("Ingrese email: ");
                    gets(email);
                    set_email(&persona, email);

                    push(&pila_persona, persona);
                    printf("Persona apilada correctamente.\n");
                } else {
                    printf("La pila está llena.\n");
                }
                break;

            case 2:
                if (!es_vacia(pila_persona)) {
                    persona = pop(&pila_persona);
                    printf("Persona desapilada: %s %s, DNI: %d\n", get_nombre(persona), get_apellido(persona), get_dni(persona));
                } else {
                    printf("La pila está vacía.\n");
                }
                break;

            case 3:
                if (!es_vacia(pila_persona)) {
                    persona = peek(pila_persona);
                    printf("Persona en el tope: %s %s, DNI: %d\n", get_nombre(persona), get_apellido(persona), get_dni(persona));
                } else {
                    printf("La pila está vacía.\n");
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
