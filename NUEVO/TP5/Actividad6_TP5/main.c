#include <stdio.h>

void imprimirInverso(char arr[], int n) {
    if (n == 0) return;
    printf("%c", arr[n - 1]);
    imprimirInverso(arr, n - 1);
}

int main() {
    char arr[] = "recursivo";
    int n = 9; 
    imprimirInverso(arr, n);
    return 0;
}
