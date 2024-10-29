#include <stdio.h>
#include <windows.h>

// Función para cambiar color de texto
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*      SISTEMA DE TURNOS         *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Gestión de Turnos\n");
    printf("2. Gestión de Clientes\n");
    printf("3. Reportes\n");
    printf("4. Salir\n");
    setColor(15); // Blanco
    printf("Seleccione una opción: ");
}

// Submenú para la gestión de turnos
void mostrarMenuTurnos() {
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*         GESTIÓN DE TURNOS      *\n");
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
    printf("0. Volver al menú principal\n");
    setColor(15); // Blanco
    printf("Seleccione una opción: ");
}

// Submenú para la gestión de clientes
void mostrarMenuClientes() {
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*         GESTIÓN DE CLIENTES    *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Registrar nuevo cliente\n");
    printf("2. Buscar y mostrar clientes\n");
    printf("3. Eliminar cliente\n");
    printf("4. Precargar lista de clientes\n");
    printf("5. Mostrar todos los clientes\n");
    printf("0. Volver al menú principal\n");
    setColor(15); // Blanco
    printf("Seleccione una opción: ");
}

// Submenú para los reportes
void mostrarMenuReportes() {
    setColor(14); // Amarillo
    printf("\n**********************************\n");
    printf("*         REPORTES               *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Ganancia mensual\n");
    printf("2. Guardar turnos según forma de pago\n");
    printf("3. Mostrar turnos por tratamiento\n");
    printf("0. Volver al menú principal\n");
    setColor(15); // Blanco
    printf("Seleccione una opción: ");
}

// Función principal
int main() {
    int opcionPrincipal, opcionTurnos, opcionClientes, opcionReportes;

    do {
        mostrarMenuPrincipal();
        scanf("%d", &opcionPrincipal);

        switch(opcionPrincipal) {
            case 1:
                do {
                    mostrarMenuTurnos();
                    scanf("%d", &opcionTurnos);
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
                            printf("Volviendo al menú principal...\n");
                            break;
                        default:
                            printf("Opción inválida. Intente nuevamente.\n");
                    }
                } while(opcionTurnos != 0);
                break;

            case 2:
                do {
                    mostrarMenuClientes();
                    scanf("%d", &opcionClientes);
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
                            printf("Volviendo al menú principal...\n");
                            break;
                        default:
                            printf("Opción inválida. Intente nuevamente.\n");
                    }
                } while(opcionClientes != 0);
                break;

            case 3:
                do {
                    mostrarMenuReportes();
                    scanf("%d", &opcionReportes);
                    switch(opcionReportes) {
                        case 1:
                            printf("Ganancia mensual.\n");
                            break;
                        case 2:
                            printf("Guardar turnos según forma de pago.\n");
                            break;
                        case 3:
                            printf("Mostrar turnos por tratamiento.\n");
                            break;
                        case 0:
                            printf("Volviendo al menú principal...\n");
                            break;
                        default:
                            printf("Opción inválida. Intente nuevamente.\n");
                    }
                } while(opcionReportes != 0);
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while(opcionPrincipal != 4);

    return 0;
}
