#include <stdio.h>
#include <stdlib.h>
#include "TDAPila.h"

int main() {
    int opcion, valor;
    Pila pila;

    init_pila(&pila);

    do {
        printf("\n--- Menu Pila de Enteros ---\n");
        printf("1. Apilar (Push)\n");
        printf("2. Desapilar (Pop)\n");
        printf("3. Ver tope (Peek)\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (!es_llena(pila)) {
                    printf("Ingrese un valor entero para apilar: ");
                    scanf("%d", &valor);
                    push(&pila, valor);
                    printf("Valor %d apilado.\n", valor);
                } else {
                    printf("La pila est� llena.\n");
                }
                break;
            case 2:
                if (!es_vacia(pila)) {
                    valor = pop(&pila);
                    printf("Valor desapilado: %d\n", valor);
                } else {
                    printf("La pila est� vac�a.\n");
                }
                break;
            case 3:
                if (!es_vacia(pila)) {
                    printf("El valor en el tope es: %d\n", peek(pila));
                } else {
                    printf("La pila est� vac�a.\n");
                }
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci�n no v�lida.\n");
        }
    } while (opcion != 4);

    return 0;
}
