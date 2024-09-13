#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int letra = 64;
    printf("ingrese un numero menor o igual a 26\n");
    scanf("%d", &numero);
    if (1 <= numero && numero <= 26){
        letra = letra + numero;
        printf("la letra es %c con el numero ASCII %d",letra,letra);
    }else{
        printf("el numero ingresado es mayor a 26 o menor a 1");
    }
    return 0;
}
