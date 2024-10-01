#include <stdio.h>
#include <stdlib.h>
#include "TDApersona.h"
#define MAX_user 2

int main()
{
    Persona infoP [MAX_user];

    char nombre[max_char];
    char apellido[max_char];
    int dni;
    char email[max_char];
    int cantidad = 0;
    int opcion;

    printf("---Menu Persona---\n");
    printf("Ingresar Persona\n");
    printf("Buscar persona\n");
    printf("Modificar persona\n");
    scanf("%d", &opcion);

    switch(){
    case 1:

    }

    do{
    printf("Ingrese nombre \n");
    gets(nombre);
    set_nombre(&infoP[cantidad],nombre);

    printf("Ingrese apellido\n");
    gets(apellido);
    set_apellido(&infoP[cantidad],apellido);

    printf("Ingrese email \n");
    gets(email);
    set_email(&infoP[cantidad],email);


    printf("Ingrese dni\n");
    scanf("%d", &dni);
    set_dni(&infoP[cantidad],dni);
    getchar();

    printf("%s\n",get_nombre(infoP[cantidad]));
    printf("%s\n",get_apellido(infoP[cantidad]));
    printf("%d\n",get_dni(infoP[cantidad]));
    printf("%s\n",get_email(infoP[cantidad]));
    cantidad++;

    }while(cantidad != 2);

    return 0;
}
