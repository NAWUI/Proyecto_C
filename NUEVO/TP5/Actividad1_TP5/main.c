#include <stdio.h>

void imprimirNaturales(int n) {
    if (n > 0) {
        imprimirNaturales(n - 1);
        printf("%d ", n);
    }
}

int main() {
    int n;
    printf("Ingrese un numero natural?\n");
    scanf("%d", &n);
    imprimirNaturales(n);
    return 0;
}
