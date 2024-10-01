#include <stdio.h>
#include "TDAfraccion.h"

int main() {
    int n;
    printf("Ingrese la cantidad de fracciones: ");
    scanf("%d", &n);

    Fraccion fracciones[n];
    for (int i = 0; i < n; i++) {
        int numerador, denominador;
        printf("Ingrese numerador y denominador de la fracción %d (separados por espacio): ", i + 1);
        scanf("%d %d", &numerador, &denominador);
        fracciones[i] = init_fraccion(numerador, denominador);
    }

    Fraccion suma_total = init_fraccion(0, 1);
    for (int i = 0; i < n; i++) {
        suma_total = sumar(suma_total, fracciones[i]);
    }

    printf("La suma de todas las fracciones es: %d/%d\n", get_numerador(suma_total), get_denominador(suma_total));
    printf("Valor real de la suma: %f\n", get_valor_real(suma_total));

    return 0;
}
