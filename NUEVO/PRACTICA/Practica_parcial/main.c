#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definición de struct */

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char localidad[20];
    char codigo[10];
    Fecha Fecha_R;
    float temp_max;
    float temp_min;
} Temperatura;

/* Fin de estructura */

/* Funciones */
int cargar_n_temperatura(Temperatura *registro, int *cantidadT, int rep) {
    for (rep; rep < (*cantidadT + rep); rep++) {
        printf("Ingrese el Nombre de la localidad\n");
        scanf(" %s", registro[*cantidadT].localidad);
        printf("Ingrese el código postal de la localidad (ej: B7107)\n");
        scanf(" %s", registro[*cantidadT].codigo);
        printf("Ingrese la fecha del informe (dd/mm/aa)\n");
        scanf("%d/%d/%d", &registro[*cantidadT].Fecha_R.dia, &registro[*cantidadT].Fecha_R.mes, &registro[*cantidadT].Fecha_R.anio);
        printf("Ingrese la temperatura máxima registrada\n");
        scanf("%f", &registro[*cantidadT].temp_max);
        printf("Ingrese la temperatura mínima registrada\n");
        scanf("%f", &registro[*cantidadT].temp_min);
    }
    *cantidadT += rep;
    return *cantidadT;
}

float temp_prom(Temperatura registro_t[], int cantidad, char localidad[]) {
    int total_registros = 0;
    float suma_temp_max = 0;

    for (int i = 0; i < cantidad; i++) {
        if (registro_t[i].Fecha_R.dia == 22 && registro_t[i].Fecha_R.mes == 3 && registro_t[i].Fecha_R.anio == 24) {
            if (strcmp(registro_t[i].localidad, localidad) == 0) {
                suma_temp_max += registro_t[i].temp_max;
                total_registros++;
            }
        }
    }
    return (total_registros > 0) ? suma_temp_max / total_registros : 0;
}

int temp_MAX(Temperatura registro[], int cantidad, float t_MAX) {
    if (cantidad == 0) return 0;
    return (registro[cantidad - 1].temp_max > t_MAX) ?
           1 + temp_MAX(registro, cantidad - 1, t_MAX) :
           temp_MAX(registro, cantidad - 1, t_MAX);
}

void mostrar_temperatura(Temperatura registro[], int cantidad, char localidad[]) {
    int encontrado = 0;

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(registro[i].localidad, localidad) == 0) {
            printf("Localidad: %s\n", registro[i].localidad);
            printf("Código Postal: %s\n", registro[i].codigo);
            printf("Fecha: %02d/%02d/%02d\n", registro[i].Fecha_R.dia, registro[i].Fecha_R.mes, registro[i].Fecha_R.anio);
            printf("Temperatura Máxima: %.2f\n", registro[i].temp_max);
            printf("Temperatura Mínima: %.2f\n", registro[i].temp_min);
            printf("-----------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron registros para la localidad: %s\n", localidad);
    }
}

/* Fin de funciones */

int main() {
    Temperatura registro_t[8200];
    int cantidadtotal = 0;
    int repetir;
    int opcion;
    char local[20];
    float temp_max;
    int resul;

    do {
        printf("1 - Carga de Temperatura.\n");
        printf("2 - Muestra la temperatura promedio de la fecha (22/03/24).\n");
        printf("3 - Muestre la temperatura máxima registrada.\n");
        printf("4 - Mostrar los registros de una localidad.\n");
        printf("0 - Salir.\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("(1) - Registrar varias Temperaturas\n");
                printf("(2) - Registrar una sola Temperatura\n");
                scanf("%d", &opcion);
                if (opcion == 1) {
                    printf("Ingrese la cantidad de temperaturas a cargar\n");
                    scanf("%d", &repetir);
                    if (cantidadtotal < 8200) {
                        cargar_n_temperatura(&registro_t[cantidadtotal], &cantidadtotal, repetir);
                    } else {
                        printf("Máximo alcanzado de registros\n");
                    }
                } else if (opcion == 2) {
                    if (cantidadtotal < 8200) {
                        cargar_n_temperatura(&registro_t[cantidadtotal], &cantidadtotal, 1);
                    } else {
                        printf("Máximo alcanzado de registros\n");
                    }
                } else {
                    printf("Opción Inválida\n");
                }
                break;
            case 2:
                if (cantidadtotal > 0) {
                    printf("Ingrese el nombre de la localidad para calcular el promedio de la fecha 22/03/24:\n");
                    scanf("%s", local);
                    float promedio = temp_prom(registro_t, cantidadtotal, local);
                    printf("Promedio de temperatura máxima: %.2f\n", promedio);
                } else {
                    printf("No hay registros cargados.\n");
                }
                break;
            case 3:
                printf("Ingrese la temperatura máxima a buscar\n");
                scanf("%f", &temp_max);
                resul = temp_MAX(registro_t, cantidadtotal, temp_max);
                printf("Se encontraron %d registros con temperatura máxima mayor a %.2f\n", resul, temp_max);
                break;
            case 4:
                if (cantidadtotal > 0) {
                    printf("Ingrese el nombre de la localidad\n");
                    scanf("%s", local);
                    mostrar_temperatura(registro_t, cantidadtotal, local);
                } else {
                    printf("No hay registros cargados.\n");
                }
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción Inválida\n");
        }
    } while (opcion != 0);

    return 0;
}
