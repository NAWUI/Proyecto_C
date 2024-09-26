#include <stdio.h>
#include <string.h>
#include "TDAauto.h"

void Get_Auto(Auto *a, const char *marca, const char *modelo, int anio, const char *titular, float precio) {
    strcpy(a->marca, marca);
    strcpy(a->modelo, modelo);
    a->anio = anio;
    strcpy(a->titular, titular);
    a->precio = precio;
}

void Modifi_Titular(Auto *a, const char *nuevoTitular) {
    strcpy(a->titular, nuevoTitular);
}

void View_Auto(const Auto *a) {
    printf("Marca: %s\n", a->marca);
    printf("Modelo: %s\n", a->modelo);
    printf("Anio: %d\n", a->anio);
    printf("Titular: %s\n", a->titular);
    printf("Precio: %f\n", a->precio);

}

int main() {
    Auto miAuto;
    char marci [50];
    char model [50];
    int anio;
    char propeti[50];
    float preci;
    printf("---------Ingrese los datos del Auto----------\n");
    printf("Ingrese la marca del Auto\n");
    gets(marci);
    printf("Ingrese el modelo del Auto\n");
    gets(model);
    printf("Ingrese el anio del Auto\n");
    scanf(" %d",&anio);
    getchar();
    printf("Ingrese el Nombre del propietario del Auto\n");
    gets(propeti);
    printf("Ingrese el Precio del Auto(USD)\n");
    scanf("%f",&preci);

    Get_Auto(&miAuto, &marci, &model, anio, &propeti, preci);

    printf("Datos del auto:\n");
    View_Auto(&miAuto);

    Modifi_Titular(&miAuto, "Maria Lopez");
    printf("\nDatos del auto luego de modificar el titular:\n");
    View_Auto(&miAuto);

    return 0;
}
