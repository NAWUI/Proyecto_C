#include <stdio.h>

int compararStrings(char S1[], char S2[], int n) {
    if (n == 0) return 1;
    if (S1[n - 1] != S2[n - 1]) return 0;
    return compararStrings(S1, S2, n - 1);
}

int main() {
    char S1[] = "hola";
    char S2[] = "hola";
    int n = 4; // Longitud de las cadenas
    int iguales = compararStrings(S1, S2, n);
    printf("Las cadenas son %s\n", iguales ? "iguales" : "diferentes");
    return 0;
}
