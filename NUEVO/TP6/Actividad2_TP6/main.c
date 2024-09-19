#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese la cantidad de enteros: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    // Inicializar y mostrar los valores
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("Valor %d: %d\n", i + 1, arr[i]);

    }

    free(arr);
    return 0;
}
