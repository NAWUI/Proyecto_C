#include <stdio.h>
#define MAX 10

// Funci�n recursiva para sumar los elementos del arreglo
double sumaArreglo(double arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumaArreglo(arr, n - 1);
}

int main() {
    double arr[MAX];
    int n, i;

    printf("Ingrese la cantidad de elementos a recorrer (m�ximo 10):\n");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Error: El n�mero m�ximo de elementos es 10.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Ingrese el valor para el elemento %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
    printf("Suma del arreglo: %.2f\n", sumaArreglo(arr, n));
    return 0;
}
