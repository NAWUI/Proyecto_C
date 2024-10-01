#include <stdio.h>
#include "TDAfraccion.h"

int main() {
    int n;
    printf("Ingrese la cantidad de fracciones a sumar: ");
    scanf("%d", &n);

    Fraccion fracciones[n];
    int numerador, denominador;

    for (int i = 0; i < n; i++) {
        printf("Ingrese el numerador de la fracción %d: ", i + 1);
        scanf("%d", &numerador);
        printf("Ingrese el denominador de la fracción %d: ", i + 1);
        scanf("%d", &denominador);
        fracciones[i] = Set_crear_fraccion(numerador, denominador);
    }

    Fraccion suma = fracciones[0];
    for (int i = 1; i < n; i++) {
        suma = Get_sumar_fracciones(suma, fracciones[i]);
    }

    printf("La suma de las fracciones es: ");
    imprimir_fraccion(suma);

    return 0;
}
