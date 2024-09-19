#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pInt = (int*) malloc(sizeof(int));
    *pInt = 10;
    printf("Entero: valor = %d, direccion = %p, tamanio = %d bytes\n", *pInt, (void*)pInt, sizeof(int));

    char *pChar = (char*) malloc(sizeof(char));
    *pChar = 'A';
    printf("Char: valor = %c, direccion = %p, tamanio = %d bytes\n", *pChar, (void*)pChar, sizeof(char));

    float *pFloat = (float*) malloc(sizeof(float));
    *pFloat = 3.14;
    printf("Float: valor = %f, direccion = %p, tamanio = %d bytes\n", *pFloat, (void*)pFloat, sizeof(float));

    int n;
    printf("Ingrese cantidad de enteros: ");
    scanf("%d", &n);
    int *pArray = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        pArray[i] = i + 1;
        printf("Entero %d: valor = %d, direccion = %p\n", i + 1, pArray[i], (void*)&pArray[i]);
    }

    free(pInt);
    free(pChar);
    free(pFloat);
    free(pArray);

    return 0;
}
