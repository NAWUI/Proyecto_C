#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[30];
    char apellido[30];
    char sexo;
    Fecha fechaNacimiento;
    float peso;
    float altura;
} RegistroSalud;

void ingresarDatos(RegistroSalud *persona) {
    printf("Ingrese el primer nombre: ");
    scanf("%s", persona->nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", persona->apellido);
    printf("Ingrese el sexo (M/F): ");
    scanf(" %c", &persona->sexo);
    printf("Ingrese la fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &persona->fechaNacimiento.dia, &persona->fechaNacimiento.mes, &persona->fechaNacimiento.anio);
    printf("Ingrese el peso en kg: ");
    scanf("%f", &persona->peso);
    printf("Ingrese la altura en metros: ");
    scanf("%f", &persona->altura);
}

int calcularEdad(Fecha fechaNacimiento) {
    time_t t = time(NULL);
    struct tm tiempoActual = *localtime(&t);

    int anioActual = tiempoActual.tm_year + 1900;
    int mesActual = tiempoActual.tm_mon + 1;
    int diaActual = tiempoActual.tm_mday;

    int edad = anioActual - fechaNacimiento.anio;
    if (mesActual < fechaNacimiento.mes || (mesActual == fechaNacimiento.mes && diaActual < fechaNacimiento.dia)) {
        edad--;
    }
    return edad;
}

float calcularIMC(RegistroSalud *persona) {
    return persona->peso / (persona->altura * persona->altura);
}

void clasificarIMC(float imc) {
    if (imc < 18.5) {
        printf("Bajo de peso.\n");
    } else if (imc >= 18.5 && imc < 25) {
        printf("Peso normal.\n");
    } else if (imc >= 25 && imc < 30) {
        printf("Sobrepeso.\n");
    } else {
        printf("Obesidad.\n");
    }
}

void mostrarDatos(RegistroSalud *persona) {
    printf("\n--- Datos del Registro de Salud ---\n");
    printf("Nombre: %s %s\n", persona->nombre, persona->apellido);
    printf("Sexo: %c\n", persona->sexo);
    printf("Fecha de nacimiento: %02d/%02d/%d\n", persona->fechaNacimiento.dia, persona->fechaNacimiento.mes, persona->fechaNacimiento.anio);
    printf("Peso: %.2f kg\n", persona->peso);
    printf("Altura: %.2f metros\n", persona->altura);

    int edad = calcularEdad(persona->fechaNacimiento);
    printf("Edad: %d anios\n", edad);

    float imc = calcularIMC(persona);
    printf("IMC: %.2f\n", imc);
    clasificarIMC(imc);
}
// fin datos del ejercicio 4
int main() {

    RegistroSalud *pSalud = (RegistroSalud*) malloc(sizeof(RegistroSalud));
    if (pSalud == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    ingresarDatos(pSalud);

    mostrarDatos(pSalud);

    RegistroSalud *pSaludArray = (RegistroSalud*) malloc(50000 * sizeof(RegistroSalud));
    if (pSaludArray == NULL) {
        printf("No se pudo asignar memoria para 50,000 estructuras.\n");
        free(pSalud);
        return 1;
    }

    int n;
    printf("Ingrese cantidad de estructuras a cargar (maximo 50,000): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nSalud %d:\n", i + 1);
        ingresarDatos(&pSaludArray[i]);
    }

    printf("\nDatos cargados:\n");
    for (int i = 0; i < n; i++) {
        mostrarDatos(&pSaludArray[i]);
    }

    // Liberar memoria
    free(pSalud);
    free(pSaludArray);

    return 0;
}
