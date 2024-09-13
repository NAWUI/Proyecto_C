#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Rsalud{
char nombre;
char apellido;
char sexo;
int dia;
int mes;
int anio;
};


int main()
{
    time_t tiempo_actual;

    tiempo_actual = time(NULL);

    struct tm *tiempo_local = localtime(&tiempo_actual);

    // Imprimir solo el día, mes y año en formato: DD/MM/AAAA
    /*printf("Fecha actual: %02d/%02d/%d\n",
           tiempo_local->tm_mday,
           tiempo_local->tm_mon + 1,    // tm_mon cuenta los meses desde 0
           tiempo_local->tm_year + 1900); // tm_year cuenta los años desde 1900
*/

    printf("****************");
    printf("Registro de datos");
    printf("****************");


    printf("****************");
    printf("Registro de salud para un ");
    printf("Calcular IMC");
    printf("Calcular edad(Años)");
    printf("****************");
}
