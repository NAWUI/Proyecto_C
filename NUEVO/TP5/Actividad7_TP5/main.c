#include <stdio.h>

int encontrarMayor(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxResto = encontrarMayor(arr, n - 1);
    return arr[n - 1] > maxResto ? arr[n - 1] : maxResto;
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int n = 6;
    printf("El mayor valor del arreglo es: %d\n", encontrarMayor(arr, n));
    return 0;
}
