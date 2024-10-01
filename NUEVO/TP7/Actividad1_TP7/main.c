#include <stdio.h>
#include <string.h>
#include "TDAauto.h"

void datos_auto(Auto a) {
    printf("Marca: %s\n", Get_marca(a));
    printf("Modelo: %s\n", Get_modelo(a));
    printf("Anio de Fabricacion: %d\n", Get_anio(a));
    printf("Titular: %s\n", Get_titular(a));
    printf("Precio: %f\n", Get_precio(a));
    printf("kilometraje: %d\n", Get_cant_KM(a));
}

int main() {
    Auto miAuto;
    char marci[50];
    char model[50];
    int anio;
    char propeti[50];
    float preci;
    int cantKM;

    printf("---------Ingrese los datos del Auto----------\n");
    printf("Ingrese la marca del Auto\n");
    gets(marci);
    Set_marca(&miAuto, marci);

    printf("Ingrese el modelo del Auto\n");
    gets(model);
    Set_modelo(&miAuto, model);

    printf("Ingrese el kilometraje del Auto\n");
    scanf("%d", &cantKM);
    getchar();
    Set_cant_KM(&miAuto, cantKM);

    printf("Ingrese el anio del Auto\n");
    scanf("%d", &anio);
    getchar();  // Limpiar el buffer
    Set_anio(&miAuto, anio);

    printf("Ingrese el Nombre del propietario del Auto\n");
    gets(propeti);
    Set_titular(&miAuto, propeti);

    printf("Ingrese el Precio del Auto(USD)\n");
    scanf("%f", &preci);
    Set_precio(&miAuto, preci);

    printf("\nDatos del auto:\n");
    datos_auto(miAuto);

    printf("\nCambie el Nombre del Titular:\n");
    getchar();
    gets(propeti);
    Set_titular(&miAuto, propeti);

    printf("\nDatos del auto con el nuevo Titular:\n");
    datos_auto(miAuto);

    return 0;
}
