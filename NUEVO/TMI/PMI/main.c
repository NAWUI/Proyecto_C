#include <stdio.h> //Permite el uso de funciones de entrada y salida, como printf y scanf
#include <stdlib.h> //Proporciona funciones como system, usada para limpiar la pantalla.
#include <windows.h>
#include <conio.h> //Facilita el manejo de caracteres en consola y la función getch(), usada para pausar la ejecución hasta que el usuario presione una tecla.
#include <string.h>

#include "turno.h"
#include "cliente.h"
#include "listaD _Turno.h"
#include "listaE_Cliente.h"

typedef struct
{
    char nombre_T[50];
    float precio_T;
} tratamientosDatos;

tratamientosDatos tratamientos_D[10] =
{
    {"Limpieza facial profunda", 20000.0},
    {"Depilacion laser", 25000.0},
    {"Depilacion con cera", 15000.0},
    {"Manicuria esmaltado semipermanente", 8000.0},
    {"Pedicuria y esmaltado semipermanente", 10000.0},
    {"Lifting de pestanas", 10000.0},
    {"Corte de pelo", 15000.0},
    {"Tintura", 40000.0},
    {"Mascarilla facial hidratante", 21000.0},
    {"Exfoliacion corporal", 30000.0}
};


// Funcion para cambiar color de texto
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Funcion para limpiar pantalla
void limpiarPantalla()
{
    system("cls");
}

// Funcion para mostrar el menu principal
void mostrarMenuPrincipal()
{
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
void mostrarMenuTurnos()
{
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
void mostrarMenuClientes()
{
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
void mostrarMenuReportes()
{
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
int obtenerOpcion()
{
    int opcion;
    while (1)
    {
        if (scanf("%d", &opcion) == 1)
        {
            fflush(stdin); // Limpiar el buffer en Windows
            return opcion;
        }
        else
        {
            printf("Entrada invalida. Por favor ingrese un numero.\n");
            fflush(stdin); // Limpiar el buffer en Windows
        }
    }
}
void registrarTurno(lista_de_turno *turnos, lista_de_clientes clientes)
{
    char id_cliente[9];
    int estado = 0;
    float Total = 0.0;
    Turno nuevoTurno;
    int tratamientoSeleccionado;
    int cantidadTratamientosSeleccionados = 0;
    int i;

    printf("Ingrese el ID del cliente para registrar el turno: ");
    scanf("%s", id_cliente);

    for (i = 0; i <= clientes.ultimo; i++)
    {
        if (strcmp(clientes.vipd[i].id_cliente, id_cliente) == 0)
        {
            estado = 1;
            setIdCliente(&nuevoTurno, atoi(id_cliente));
            setNombre(&nuevoTurno, clientes.vipd[i].nombre);
            printf("Cliente encontrado: %s %s\n", clientes.vipd[i].nombre, clientes.vipd[i].apellido);
            break;
        }
    }

    if (estado == 0)
    {
        printf("Cliente no encontrado. No se puede registrar el turno.\n");
        return;
    }

    setIdTurno(&nuevoTurno, generarIdTurno());

    printf("Seleccione hasta 3 tratamientos para el turno (0 para terminar):\n");
    for (i = 0; i < MAX_TRATAMIENTOS; i++)
    {
        printf("%d. %s - $%.2f\n", i + 1, tratamientos_D[i].nombre_T, tratamientos_D[i].precio_T);
    }

    int tratamientos[MAX_TRATAMIENTOS] = {0};
    do
    {
        if (cantidadTratamientosSeleccionados >= 3)
        {
            printf("Se ha alcanzado el limite de 3 tratamientos por turno.\n");
            break;
        }

        printf("Ingrese el numero del tratamiento: ");
        scanf("%d", &tratamientoSeleccionado);

        if (tratamientoSeleccionado > 0 && tratamientoSeleccionado <= MAX_TRATAMIENTOS)
        {
            if (tratamientos[tratamientoSeleccionado - 1] == 0)
            {
                tratamientos[tratamientoSeleccionado - 1] = 1;
                cantidadTratamientosSeleccionados++;
                Total += tratamientos_D[tratamientoSeleccionado - 1].precio_T;
                printf("Tratamiento agregado: %s\n", tratamientos_D[tratamientoSeleccionado - 1].nombre_T);
            }
            else
            {
                printf("Este tratamiento ya ha sido seleccionado.\n");
            }
        }
        else if (tratamientoSeleccionado != 0)
        {
            printf("Numero de tratamiento invalido. Intente nuevamente.\n");
        }
    }
    while (tratamientoSeleccionado != 0);

    int nivelCliente = clientes.vipd[i].nivel;  // Nivel del cliente obtenido de la estructura de clientes
    setTratamiento(&nuevoTurno, tratamientos);
    setTotal(&nuevoTurno, Total, nivelCliente);

    Fecha fechaTurno;
    do
    {
        printf("Ingrese la fecha del turno (dia mes anio hora): ");
        scanf("%d %d %d %d", &fechaTurno.dia, &fechaTurno.mes, &fechaTurno.anio, &fechaTurno.hora);
        if (!validarFecha(fechaTurno))
        {
            printf("Fecha no valida. Por favor ingrese una fecha dentro del horario de atencion (lunes a sabado, 9 a 20 hs).\n");
        }
    }
    while (!validarFecha(fechaTurno));
    setFecha(&nuevoTurno, fechaTurno);

    printf("Total sin descuento: %.2f\n", Total);


    switch (nivelCliente)
    {
    case 0: // Sin descuento
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    case 1: // 5% de descuento
        printf("Descuento por Nivel 1 (5%%): %.2f\n", Total * 0.05);
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    case 2: // 10% de descuento
        printf("Descuento por Nivel 2 (10%%): %.2f\n", Total * 0.10);
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    case 3: // 15% de descuento
        printf("Descuento por Nivel 3 (15%%): %.2f\n", Total * 0.15);
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    }


    int formaPago;
    do
    {
        printf("Seleccione la forma de pago:\n");
        printf("1. Debito\n");
        printf("2. Credito\n");
        printf("3. Efectivo\n");
        printf("4. QR\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &formaPago);

        switch (formaPago)
        {
        case 1:
            setFormaPago(&nuevoTurno, "debito");
            break;
        case 2:
            setFormaPago(&nuevoTurno, "credito");
            break;
        case 3:
            setFormaPago(&nuevoTurno, "efectivo");
            break;
        case 4:
            setFormaPago(&nuevoTurno, "QR");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            formaPago = 0;
        }
    }
    while (formaPago == 0);

    setRealizado(&nuevoTurno, 0);

    insertL_turno(turnos, nuevoTurno);
    printf("Turno registrado exitosamente.\n");
}
void mostrar_turno(Turno t) {
    char *nombre = get_nombre_T(t);
    int idTurno = get_idTurno(t);
    int idCliente = get_idCliente(t);
    int *tratamientos = get_tratamientos(t);
    char *formaPago = get_formaPago(t);
    float total = get_total(t);
    Fecha fecha = get_fecha(t);
    int realizado = get_realizado(t);

    printf("ID Turno: %d\n", idTurno);
    printf("Nombre: %s\n", nombre);
    printf("ID Cliente: %d\n", idCliente);
    printf("Tratamientos: ");
    for (int i = 0; i < MAX_TRATAMIENTOS; i++) {
        if (tratamientos[i] != 0) {
            printf("%d ", tratamientos[i]);
        }
    }
    printf("\nForma de Pago: %s\n", formaPago);
    printf("Total: %.2f\n", total);
    printf("Fecha: %02d/%02d/%d Hora: %02d:00\n", get_dia(fecha), get_mes(fecha), get_anio(fecha), get_hora(fecha));
    printf("Realizado: %s\n", realizado ? "Sí" : "No");

    // Liberar la memoria reservada
    free(nombre);
    free(tratamientos);
    free(formaPago);
}

// Función para registrar un nuevo cliente en la lista
void registrarCliente(lista_de_clientes *clientes)
{
    if (isfull(*clientes))
    {
        printf("Lista de clientes llena. No se pueden registrar mas clientes.\n");
        return;
    }

    Cliente nuevoCliente;
    char id_cliente[9];
    char nombre[20];
    char apellido[20];

    // Solicita y asigna el ID del cliente
    printf("Ingrese el ID del cliente: ");
    scanf("%s", id_cliente);
    set_id_cliente(&nuevoCliente, id_cliente);

    // Solicita y asigna el nombre del cliente
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombre);
    set_nombre(&nuevoCliente, nombre);

    // Solicita y asigna el apellido del cliente
    printf("Ingrese el apellido del cliente: ");
    scanf("%s", apellido);
    set_apellido(&nuevoCliente, apellido);

    // Inicializa canttratamientos y nivel
    initt(&nuevoCliente);  // canttratamientos a 0
    set_nivel(&nuevoCliente, 0); // nivel a 0

    insertl(clientes, nuevoCliente);
    printf("Cliente registrado exitosamente.\n");
}

// Función para buscar un cliente en la lista y mostrar sus datos
void buscarCliente(lista_de_clientes clientes)
{
    char id_cliente[9];
    printf("Ingrese el ID del cliente a buscar: ");
    scanf("%s", id_cliente);

    for (int i = 0; i <= clientes.ultimo; i++)
    {
        if (strcmp(clientes.vipd[i].id_cliente, id_cliente) == 0)
        {
            printf("Cliente encontrado:\n");
            printf("ID: %s\n", clientes.vipd[i].id_cliente);
            printf("Nombre: %s\n", clientes.vipd[i].nombre);
            printf("Apellido: %s\n", clientes.vipd[i].apellido);
            printf("Cantidad de tratamientos: %d\n", clientes.vipd[i].canttratamientos);
            printf("Nivel: %d\n", clientes.vipd[i].nivel);
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

// Función para eliminar un cliente de la lista
void eliminarCliente(lista_de_clientes *clientes)
{
    if (isempty(*clientes))
    {
        printf("La lista de clientes está vacia.\n");
        return;
    }

    char id_cliente[9];
    printf("Ingrese el ID del cliente a eliminar: ");
    scanf("%s", id_cliente);

    for (int i = 0; i <= clientes->ultimo; i++)
    {
        if (strcmp(clientes->vipd[i].id_cliente, id_cliente) == 0)
        {
            clientes->cursor = i; // Posiciona el cursor en el cliente encontrado
            supress(clientes);
            printf("Cliente eliminado exitosamente.\n");
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

// Función para mostrar todos los clientes registrados
void mostrarTodosLosClientes(lista_de_clientes clientes)
{
void buscarTurnoPorCliente(lista_de_turno *lista, int idCliente) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno turno = copy_turno(lista);
        if (get_idCliente(turno) == idCliente) {
            mostrar_turno(turno);
        }
        forwards_turno(lista);
    }
}

void mostrarTurnosPorMes(lista_de_turno *lista, int mes) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno turno = copy_turno(lista);
        if (get_mes(get_fecha(turno)) == mes) {
            mostrar_turno(turno);
        }
        forwards_turno(lista);
    }
}

void mostrarTurnosPorNombre(lista_de_turno *lista, const char *nombre) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno turno = copy_turno(lista);
        char *nombreTurno = get_nombre_T(turno);
        if (strcmp(nombreTurno, nombre) == 0) {
            mostrar_turno(turno);
        }
        free(nombreTurno);
        forwards_turno(lista);
    }
}

void modificarTratamientos(lista_de_turno *lista, int idTurno, int nuevosTratamientos[]) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno *turno = &lista->cur->vipd;
        if (get_idTurno(*turno) == idTurno) {
            setTratamiento(turno, nuevosTratamientos);
            printf("Cantidad de tratamientos actualizada para el turno ID %d.\n", idTurno);
            return;
        }
        forwards_turno(lista);
    }
    printf("Turno con ID %d no encontrado.\n", idTurno);
}

void modificarFormaPago(lista_de_turno *lista, int idTurno, const char *nuevaFormaPago) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno *turno = &lista->cur->vipd;
        if (get_idTurno(*turno) == idTurno) {
            setFormaPago(turno, nuevaFormaPago);
            printf("Forma de pago actualizada para el turno ID %d.\n", idTurno);
            return;
        }
        forwards_turno(lista);
    }
    printf("Turno con ID %d no encontrado.\n", idTurno);
}

void cancelarTurno(lista_de_turno *lista, int idTurno) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno turno = copy_turno(lista);
        if (get_idTurno(turno) == idTurno) {
            suppress_turno(lista);
            printf("Turno ID %d cancelado.\n", idTurno);
            return;
        }
        forwards_turno(lista);
    }
    printf("Turno con ID %d no encontrado.\n", idTurno);
}

void confirmarAsistenciaTurno(lista_de_turno *lista, int idTurno) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno *turno = &lista->cur->vipd;
        if (get_idTurno(*turno) == idTurno) {
            marcarRealizado(turno);
            printf("Asistencia confirmada para el turno ID %d.\n", idTurno);
            return;
        }
        forwards_turno(lista);
    }
    printf("Turno con ID %d no encontrado.\n", idTurno);
}

    if (isempty(clientes))
    {
        printf("La lista de clientes está vacia.\n");
        return;
    }

    printf("Lista de clientes registrados:\n");
    for (int i = 0; i <= clientes.ultimo; i++)
    {
        printf("ID: %s\n", clientes.vipd[i].id_cliente);
        printf("Nombre: %s\n", clientes.vipd[i].nombre);
        printf("Apellido: %s\n", clientes.vipd[i].apellido);
        printf("Cantidad de tratamientos: %d\n", clientes.vipd[i].canttratamientos);
        printf("Nivel: %d\n", clientes.vipd[i].nivel);
        printf("-------------------------\n");
    }
}
void mostrarTurnosNoRealizados(lista_de_turno *lista) {
    resetL_turno(lista);
    while (!is_Oos_turno(*lista)) {
        Turno turno = copy_turno(lista);
        if (!get_realizado(turno)) {
            mostrar_turno(turno);
        }
        forwards_turno(lista);
    }
}

// Funcion principal
int main()
{
    lista_de_turno turno;
    lista_de_clientes clientes;
    init_cliente(&clientes);
    // tratamientosDatos tratamientos_D[10];

    int opcionPrincipal, opcionTurnos, opcionClientes, opcionReportes;

    do
    {
        mostrarMenuPrincipal();
        opcionPrincipal = obtenerOpcion();

        switch(opcionPrincipal)
        {
        case 1:
            do
            {
                mostrarMenuTurnos();
                opcionTurnos = obtenerOpcion();
                switch(opcionTurnos)
                {
                case 1:
                    printf("Agendar un nuevo turno.\n");
                    registrarTurno(&turno,clientes);
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
            }
            while(opcionTurnos != 0);
            break;

        case 2:
            do
            {
                mostrarMenuClientes();
                opcionClientes = obtenerOpcion();
                switch(opcionClientes)
                {
                case 1:
                    registrarCliente(&clientes);
                    break;
                case 2:
                    buscarCliente(clientes);
                    break;
                case 3:
                    eliminarCliente(&clientes);
                    break;
                case 4:
                    printf("falta archivo");
                    break;
                case 5:
                    mostrarTodosLosClientes(clientes);
                    break;
                case 0:
                    printf("Volviendo al menu principal...\n");
                    break;
                default:
                    printf("Opción inválida. Intente nuevamente.\n");
                }
                printf("Presione cualquier tecla para continuar...\n");
                getch();
            }
            while(opcionClientes != 0);
            break;

        case 3:
            do
            {
                mostrarMenuReportes();
                opcionReportes = obtenerOpcion();
                switch(opcionReportes)
                {
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
            }
            while(opcionReportes != 0);
            break;

        case 4:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
        }
        printf("Presione cualquier tecla para continuar...\n");
        getch();
    }
    while(opcionPrincipal != 4);

    return 0;
}
