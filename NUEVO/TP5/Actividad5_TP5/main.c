#include <stdio.h>

double sumaArreglo(double arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumaArreglo(arr, n - 1);
}

int main() {
    double arr[] = {1.1, 2.2, 3.3, 4.4};
    int n = 4;
    printf("Suma del arreglo: %.2f\n", sumaArreglo(arr, n));
    return 0;
}
