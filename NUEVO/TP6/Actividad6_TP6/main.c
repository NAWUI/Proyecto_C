#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define anio_actual 2024

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nom[30];
    int TipoDoc;  // 1=DNI, 2=PAS, 3=CF, 4=CIPE
    int NroDoc[8];
    int Hijos;
    Fecha Nacim;
} Empleado;

void ingresar_empleados(Empleado *arr[], int *cantidad) {
    printf("Ingrese la cantidad de empleados (maximo 10): ");
    getchar();
    scanf("%d", cantidad);
            getchar();

    if (*cantidad > 10) {
        printf("La cantidad no puede ser mayor a 10.\n");
        *cantidad = 10;
    }

    for (int i = 0; i < *cantidad; i++) {
        arr[i] = (Empleado*)malloc(sizeof(Empleado));

        if (arr[i] == NULL) {
            printf("Error al asignar memoria.\n");
            exit(1);
        }

        printf("\nEmpleado %d:\n", i + 1);
        printf("Nombre: ");
        gets(arr[i]->nom);

        printf("Tipo de Documento (1=DNI, 2=PAS, 3=CF, 4=CIPE): \n");
        scanf("%d", &arr[i]->TipoDoc);
        printf("Numero de Documento (8 digitos): \n");
        for (int j = 0; j < 8; j++) {
            scanf("%d", &arr[i]->NroDoc[j]);
        }

        printf("Cantidad de hijos: \n");
        getchar();
        scanf("%d", &arr[i]->Hijos);
        getchar();
        printf("Fecha de Nacimiento (Dia Mes Anio): \n");
                getchar();
        scanf("%d %d %d", &arr[i]->Nacim.dia, &arr[i]->Nacim.mes, &arr[i]->Nacim.anio);
            getchar();
    }
}

void mostrar_empleados(Empleado *arr[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nEmpleado %d:\n", i + 1);
        printf("Nombre: %s\n", arr[i]->nom);
        printf("Tipo de Documento: %d\n", arr[i]->TipoDoc);
        printf("Numero de Documento: ");
        for (int j = 0; j < 8; j++) {
            printf("%d", arr[i]->NroDoc[j]);
        }
        printf("\nCantidad de hijos: %d\n", arr[i]->Hijos);
        printf("Fecha de Nacimiento: %d/%d/%d\n", arr[i]->Nacim.dia, arr[i]->Nacim.mes, arr[i]->Nacim.anio);
    }
}

void listar_mayores_de_40(Empleado *arr[], int cantidad) {
    printf("\nEmpleados mayores de 40 anios:\n");

    for (int i = 0; i < cantidad; i++) {
        int edad = anio_actual - arr[i]->Nacim.anio;

        if (edad > 40) {
            printf("%s\n", arr[i]->nom);
        }
    }
}

int contar_sin_hijos(Empleado *arr[], int cantidad) {
    int sin_hijos = 0;

    for (int i = 0; i < cantidad; i++) {
        if (arr[i]->Hijos == 0) {
            sin_hijos++;
        }
    }

    return sin_hijos;
}

int main() {
    int opcion;
    int cantidad = 0;
    Empleado *arr[10];  // Arreglo de punteros a Empleado

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Ingresar empleados\n");
        printf("2. Mostrar empleados\n");
        printf("3. Listar empleados mayores de 40 anios\n");
        printf("4. Contar empleados sin hijos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresar_empleados(arr, &cantidad);
                break;

            case 2:
                mostrar_empleados(arr, cantidad);
                break;

            case 3:
                listar_mayores_de_40(arr, cantidad);
                break;

            case 4:
                printf("Cantidad de empleados sin hijos: %d\n", contar_sin_hijos(arr, cantidad));
                break;

            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 5);

    // Liberar memoria asignada
    for (int i = 0; i < cantidad; i++) {
        free(arr[i]);
    }

    return 0;
}
