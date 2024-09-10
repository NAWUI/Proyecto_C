#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PACIENTES 100

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

float calcularIMC(RegistroSalud persona) {
    return persona.peso / (persona.altura * persona.altura);
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

void mostrarDatos(RegistroSalud persona) {
    printf("\n--- Datos del Registro de Salud ---\n");
    printf("Nombre: %s %s\n", persona.nombre, persona.apellido);
    printf("Sexo: %c\n", persona.sexo);
    printf("Fecha de nacimiento: %02d/%02d/%d\n", persona.fechaNacimiento.dia, persona.fechaNacimiento.mes, persona.fechaNacimiento.anio);
    printf("Peso: %.2f kg\n", persona.peso);
    printf("Altura: %.2f metros\n", persona.altura);

    int edad = calcularEdad(persona.fechaNacimiento);
    printf("Edad: %d anios\n", edad);

    float imc = calcularIMC(persona);
    printf("IMC: %.2f\n", imc);
    clasificarIMC(imc);
}

int main() {
    RegistroSalud pacientes[MAX_PACIENTES];
    int canPacientes;
    int numPacientes = 0;
    int opcion;

    do {
        printf("\n----- Menu de Salud -----\n");
        printf("(1) - Guardar un nuevo paciente\n");
        printf("(2) - Ver informe de un paciente\n");
        printf("(3) - Ver nombre de los pacientes registrados\n");
        printf("(0) - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        switch (opcion) {
            case 1:
                printf("\n----- Menu de Salud -----\n");
                printf("(1)-cargar varios pacientes\n");
                printf("(2)-cargar un solo paciente\n");
                scanf("%d", &opcion);
                if (opcion == 1){
                    printf("Ingrese la cantidad de pacientes que deasea cargar\n");
                    scanf("%d", &canPacientes);
                    for (canPacientes;canPacientes > 0;canPacientes--){
                        if (numPacientes < MAX_PACIENTES) {
                            ingresarDatos(&pacientes[numPacientes]);
                            numPacientes++;
                        }else {
                        printf("Limite de pacientes alcanzado.\n");
                        }
                        }
                }else if (opcion == 2){
                    if (numPacientes < MAX_PACIENTES) {
                        ingresarDatos(&pacientes[numPacientes]);
                        numPacientes++;
                    }else {
                        printf("Limite de pacientes alcanzado.\n");
                    }
                }else{
                 printf("Opcion no válida. Intente nuevamente.\n");
                }
                break;
            case 2: {
                int indice;
                printf("Ingrese el NUMERO DEL PACIENTE (Pacientes cargados: %d): ", numPacientes);
                scanf("%d", &indice);
                if ((indice-1) >= 0 && (indice-1) < numPacientes) {
                    mostrarDatos(pacientes[(indice-1)]);
                } else {
                    printf("Índice no válido.\n");
                }
                break;
            }
            case 3:
                printf("\n--- Lista de pacientes registrados ---\n");
                for (int i = 0; i < numPacientes; i++) {
                    printf("%d. %s %s\n", i+1, pacientes[i].nombre, pacientes[i].apellido);
                }
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
