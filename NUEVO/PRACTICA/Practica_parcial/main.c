#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definicion de struct*/

typedef struct{
int dia;
int mes;
int anio;
}Fecha;

typedef struct {
    char localidad[20];
    char codigo[10];
    Fecha Fecha_R;
    float temp_max;
    float temp_min;
} Temperatura;

/*FIN De Estructura*/
//22/03/24
/*Funciones*/
void cargar_n_temperatura(Temperatura *registro){
    printf("Ingrese el Nombre de la localidad\n");
    scanf(" %s", registro->localidad);
    printf("Ingrese el codigo postal de la localidad(ej:B7107)\n");
    scanf(" %s", registro->codigo);
    printf("Ingrese la fecha del informe(dd/mm/aa)\n");
    scanf("%d" "%d" "%d",registro->Fecha_R.dia,registro->Fecha_R.mes,registro->Fecha_R.anio);
    printf("Ingrese la temperatura maxima registrada\n");
    scanf("%d", registro-> temp_max);
    printf("Ingrese la temperatura minima registrada\n");
    scanf("%d", registro-> temp_min);
}


float temp_prom(Temperatura registro_t[], int cantidad, char localidad[]) {
    int total_registros = 0;
    int i;
    float suma_temp_max = 0;

    for (i = 0; i < cantidad; i++) {
        if (registro_t[i].Fecha_R.dia == 22 && registro_t[i].Fecha_R.mes == 03 && registro_t[i].Fecha_R.anio == 24) {
            if (strcmp(registro_t[i].localidad, localidad) == 0) {
                suma_temp_max += registro_t[i].temp_max;
                total_registros++;
            }
        }
    }
    return suma_temp_max / total_registros;

}
/*
int temp_MAX(Temperatura registro[],int cantidad,float t_MAX, int cont){

    if (cantidad == 0){
        return cont;
    }
    else {
            if (registro[cantidad].temp_max> t_MAX){
                    cont++;
    }

    }
    return temp_MAX(registro,cantidad-1,t_MAX,cont);
}*/
// Sin acumulador

int temp_MAX(Temperatura registro[], int cantidad, float t_MAX) {
    // Caso base: si ya no hay m�s elementos que verificar, devolvemos 0
    if (cantidad == 0) {
        return 0;
    }

    // Verificamos si la temperatura m�xima en este registro es mayor que t_MAX
    if (registro[cantidad - 1].temp_max > t_MAX) {
        return 1 + temp_MAX(registro, cantidad - 1, t_MAX);
    } else {
        return temp_MAX(registro, cantidad - 1, t_MAX);
    }
}

/*fin funciones*/


int main() {
    Temperatura registro_t[8200];
    int cantidadtotal = 0;
    int repetir;
    int opcion;
    char local[20];
    int contador = 0;
    float temp_max;

    do {
        printf("1-Carga de Temperatura.\n");
        printf("2-Muestra la temperatura promedio de la fecha(22/03/24).\n");
        printf("3-Muestre la temperatura maxima registrada.\n");
        printf("0-Salir.\n");
        scanf("%d", &opcion);

    switch(opcion){
    case 1:
        printf("(1)-Registrar varias Temperatura\n");
        printf("(2)-Registrar una sola Temperatura\n");
        scanf("%d", &opcion);
        if(opcion == 1){
            printf("Ingrese cantidad de registras a cargar\n");
            scanf("%d", &repetir);
            for(repetir;repetir > 0;repetir--){
                if (cantidadtotal < 8200){
                    cargar_n_temperatura(&registro_t[cantidadtotal]);
                    cantidadtotal++;
                }else{
                    printf("Maximo alcanzado de registro\n");
                }
            }
        }else if(opcion == 2){
            if (cantidadtotal < 8200){
                cargar_n_temperatura(&registro_t[cantidadtotal]);
                cantidadtotal++;
            }else{
                printf("Maximo alcanzado de registro\n");
            }
        }else{
            printf("Opcion Invalida\n");
        }
    break;
    case 2:
                if (cantidadtotal > 0) {
                    printf("Ingrese el nombre de la localidad para calcular el promedio de la fecha 22/03/24:\n");
                    scanf("%s", local);
                    temp_prom(registro_t, cantidadtotal, local);
                } else {
                    printf("No hay registros cargados.\n");
                }
                break;
            case 3:
                printf("Ingrese la temperatura maxima a buscar\n");
                scanf("%f", &temp_max);
                int resul = temp_MAX(registro_t, cantidadtotal, temp_max, contador);
                printf("Se encontraron %d registros con temperatura maxima mayor a %.2f\n", resul, temp_max);
                break;
            case 0:
                printf("Saliendo..\n");
                if (cantidadtotal > 0) {
                    printf("Ingrese el nombre de la localidad para calcular el promedio de la fecha 22/03/24:\n");
                    scanf("%s", local);
                    temp_prom(registro_t, cantidadtotal, local);
                } else {
                    printf("No hay registros cargados.\n");
                }

                if (resul == 0){
                printf("Se encontraron 0 registros\n");
                }else{
                printf("Se encontraron %d registros con temperatura maxima mayor a %.2f\n", resul, temp_max);
                }
                break;
            default:
                printf("Opcion Invalida\n");
        }
    } while(opcion != 0);
}
