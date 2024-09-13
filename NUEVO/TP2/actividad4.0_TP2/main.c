#include <stdio.h>
#include <stdlib.h>



int ingreso_notas(int x,int y){
int i;
    for(i=1;i <=4; i++){
    printf("Ingrese la nota %d\n", i);

    scanf("%d", &x);
    y+=x;
    system("cls");
    }
    printf("la nota final de %d\n",y/4);

    return y/4;
}

int main()
{
    int nota;
    int pre_nota = 0;
    int opcion;

    do
    {
    printf("***********************\n");
    printf("Sistema de Notas(Aprobado O Desaprobado)\n");
    printf("1)-ingreso de Notas\n");
    printf("***********************\n");

    scanf("%d", &opcion);

    if (opcion != 1){
        system("cls");
        printf("ingrese un valor correcto\n");
        }
    }while (opcion != 1);

    system("cls");

    pre_nota = ingreso_notas(nota,pre_nota);

    if (pre_nota>= 7){
        printf("APROBADO");
    }else{
        printf("DESAPROBADO");
    }



}

