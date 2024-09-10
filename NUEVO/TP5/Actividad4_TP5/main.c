#include <stdio.h>
#include <string.h>
#define MAX_CADENA 10
int compararStrings(char S1[], char S2[], int n) {
    if (n == 0) return 1;
    if (S1[n - 1] != S2[n - 1]) return 0;
    return compararStrings(S1, S2, n - 1);
}

int main() {
    char S1[MAX_CADENA];
    char S2[MAX_CADENA];
    printf("Ingrese la cadena 1");
    scanf("%S", &S1);

    printf("Ingrese la cadena 2");
    scanf("%S", &S2);

    int iguales = compararStrings(S1, S2, MAX_CADENA);
    printf("Las cadenas son %s\n", iguales ? "iguales" : "diferentes");
    return 0;
}
