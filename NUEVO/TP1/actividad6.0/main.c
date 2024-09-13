#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pesos;
    int dolar = 1270;
    printf("Ingrese la cantidad de pesos que quiere cambiar a dolares \n");
    scanf("%d", &pesos);
    printf("El dolar esta $1270 pesos, asi que le cambio seria $%d",pesos/dolar);
    return 0;
}
