#include <stdio.h>

int buscarElemento(int arr[], int n, int elem) {
    if (n == 0) return -1;
    if (arr[n - 1] == elem) return n - 1;
    return buscarElemento(arr, n - 1, elem);
}

int main() {

    int arr[10];
    int n;
    int elem;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Ingrese un numero para guardar: ");
        scanf("%d", &arr[i]);  // Corregido: &arr[i]
    }
    do{
    printf("Ingrese en que rango buscar: ");
    scanf("%d", &n);
    }while(n>=10);
    printf("Ingrese un numero a buscar: ");
    scanf("%d", &elem);

    int indice = buscarElemento(arr, n, elem);
    if (indice != -1) {
        printf("Elemento %d encontrado en la posicion %d\n", elem, indice);
    } else {
        printf("Elemento %d no encontrado\n", elem);
    }

    return 0;
}
