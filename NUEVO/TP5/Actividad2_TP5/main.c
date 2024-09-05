#include <stdio.h>

int sumaNaturales(int n) {
    if (n == 0) return 0;
    return n + sumaNaturales(n - 1);
}

int main() {
    int n;
    printf("Ingrese un numero natural?\n");
    scanf("%d", &n);
    printf("Suma de los primeros %d naturales: %d\n", n, sumaNaturales(n));
    return 0;
}
