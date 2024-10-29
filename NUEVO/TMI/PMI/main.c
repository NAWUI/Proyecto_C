#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "turno.h"
#include "listaD _Turno.h"
typedef struct {
char nombre_t[50];
float precio_t;
}tratamientosdatos;


// Funcion para cambiar color de texto
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Funcion para limpiar pantalla
void limpiarPantalla() {
    system("cls");
}

// Funcion para mostrar el menu principal
void mostrarMenuPrincipal() {
    limpiarPantalla();
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*      SISTEMA DE TURNOS         *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Gestion de Turnos\n");
    printf("2. Gestion de Clientes\n");
    printf("3. Reportes\n");
    printf("4. Salir\n");
    setColor(15); // Blanco
    printf("Seleccione una opcion: ");
}

// Submenu para la gestion de turnos
void mostrarMenuTurnos() {
    limpiarPantalla();
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*         GESTION DE TURNOS      *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Agendar un nuevo turno\n");
    printf("2. Buscar turno por cliente\n");
    printf("3. Mostrar todos los turnos de un mes\n");
    printf("4. Mostrar turnos por nombre de cliente\n");
    printf("5. Modificar cantidad de tratamientos\n");
    printf("6. Modificar forma de pago\n");
    printf("7. Cancelar un turno\n");
    printf("8. Confirmar asistencia de turno\n");
    printf("9. Mostrar turnos no realizados\n");
    printf("0. Volver al menu principal\n");
    setColor(15); // Blanco
    printf("Seleccione una opcion: ");
}

// Submenu para la gestion de clientes
void mostrarMenuClientes() {
    limpiarPantalla();
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*         GESTION DE CLIENTES    *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Registrar nuevo cliente\n");
    printf("2. Buscar y mostrar clientes\n");
    printf("3. Eliminar cliente\n");
    printf("4. Precargar lista de clientes\n");
    printf("5. Mostrar todos los clientes\n");
    printf("0. Volver al menu principal\n");
    setColor(15); // Blanco
    printf("Seleccione una opcion: ");
}

// Submenu para los reportes
void mostrarMenuReportes() {
    limpiarPantalla();
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*         REPORTES               *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Ganancia mensual\n");
    printf("2. Guardar turnos segun forma de pago\n");
    printf("3. Mostrar turnos por tratamiento\n");
    printf("0. Volver al menu principal\n");
    setColor(15); // Blanco
    printf("Seleccione una opcion: ");
}

// Validacion de entrada para asegurarse de que el usuario ingresa un numero
int obtenerOpcion() {
    int opcion;
    if (scanf("%d", &opcion) != 1) {
        printf("Entrada invalida. Por favor ingrese un numero.\n");
        fflush(stdin); // Limpiar el buffer en Windows
        opcion = -1;  // Indica opcion invalida
    }
    return opcion;
}

// Funcion principal
int main() {
    Turno miTurno;
    int opcionPrincipal, opcionTurnos, opcionClientes, opcionReportes;

    do {
        mostrarMenuPrincipal();
        opcionPrincipal = obtenerOpcion();

        switch(opcionPrincipal) {
            case 1:
                do {
                    mostrarMenuTurnos();
                    opcionTurnos = obtenerOpcion();
                    switch(opcionTurnos) {
                        case 1:
                            printf("Agendar un nuevo turno.\n");
                            break;
                        case 2:
                            printf("Buscar turno por cliente.\n");
                            break;
                        case 3:
                            printf("Mostrar todos los turnos de un mes.\n");
                            break;
                        case 4:
                            printf("Mostrar turnos por nombre de cliente.\n");
                            break;
                        case 5:
                            printf("Modificar cantidad de tratamientos.\n");
                            break;
                        case 6:
                            printf("Modificar forma de pago.\n");
                            break;
                        case 7:
                            printf("Cancelar un turno.\n");
                            break;
                        case 8:
                            printf("Confirmar asistencia de turno.\n");
                            break;
                        case 9:
                            printf("Mostrar turnos no realizados.\n");
                            break;
                        case 0:
                            printf("Volviendo al menu principal...\n");
                            break;
                        default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                    }
                    printf("Presione cualquier tecla para continuar...\n");
                    getch();
                } while(opcionTurnos != 0);
                break;

            case 2:
                do {
                    mostrarMenuClientes();
                    opcionClientes = obtenerOpcion();
                    switch(opcionClientes) {
                        case 1:
                            printf("Registrar nuevo cliente.\n");
                            break;
                        case 2:
                            printf("Buscar y mostrar clientes.\n");
                            break;
                        case 3:
                            printf("Eliminar cliente.\n");
                            break;
                        case 4:
                            printf("Precargar lista de clientes.\n");
                            break;
                        case 5:
                            printf("Mostrar todos los clientes.\n");
                            break;
                        case 0:
                            printf("Volviendo al menu principal...\n");
                            break;
                        default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                    }
                    printf("Presione cualquier tecla para continuar...\n");
                    getch();
                } while(opcionClientes != 0);
                break;

            case 3:
                do {
                    mostrarMenuReportes();
                    opcionReportes = obtenerOpcion();
                    switch(opcionReportes) {
                        case 1:
                            printf("Ganancia mensual.\n");
                            break;
                        case 2:
                            printf("Guardar turnos segun forma de pago.\n");
                            break;
                        case 3:
                            printf("Mostrar turnos por tratamiento.\n");
                            break;
                        case 0:
                            printf("Volviendo al menu principal...\n");
                            break;
                        default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                    }
                    printf("Presione cualquier tecla para continuar...\n");
                    getch();
                } while(opcionReportes != 0);
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
        printf("Presione cualquier tecla para continuar...\n");
        getch();
    } while(opcionPrincipal != 4);

    return 0;
}
