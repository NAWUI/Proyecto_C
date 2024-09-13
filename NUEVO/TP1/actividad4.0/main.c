#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    printf("ingrese la edad:");
    scanf("%d", &edad);
    if (((edad>=16)&&(edad<18))||(edad>=70))
        printf("Usted puede votar pero no esta obligado");
    else{
        if(edad<16)
            printf("Usted no puede votar");
        else
            printf("Usted esta obligado a votar");
    }
   return 0;

}
