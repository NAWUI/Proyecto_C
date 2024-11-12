#include <stdio.h> //Permite el uso de funciones de entrada y salida, como printf y scanf
#include <stdlib.h> //Proporciona funciones como system, usada para limpiar la pantalla.
#include <windows.h>
#include <conio.h> //Facilita el manejo de caracteres en consola y la funcion getch(), usada para pausar la ejecucion hasta que el usuario presione una tecla.
#include <string.h>
#include <ctype.h>  // Para isdigit()
//TDA y Listas incluidas en el main
#include "turno.h"
#include "cliente.h"
#include "listaD _Turno.h"
#include "listaE_Cliente.h"

typedef struct
{
    char nombre_T[50]; //nombre del tratamiento
    float precio_T; //precio del tratamiento
} tratamientosDatos;

void registrarCliente(lista_de_clientes *clientes);
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
}; //arreglo de tratamiento que almacena los nombres y el precio de cada tratamiento

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
    printf("\n********************************\n");
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
    printf("\n********************************\n");
    printf("*         GESTION DE TURNOS      *\n");
    printf("**********************************\n");
    setColor(11); // Cian claro
    printf("1. Agendar un nuevo turno\n");
    printf("2. Mostrar todos los turnos de un cliente\n");
    printf("3. Mostrar todos los turnos de un mes\n");
    printf("4. Mostrar turnos por nombre de cliente\n");
    printf("5. Mostrar todos los turnos\n");
    printf("6. Modificar forma de pago\n");
    printf("7. Mostrar turnos por tratamiento\n");
    printf("8. Cancelar un turno\n");
    printf("9. Confirmar asistencia de turno\n");
    printf("10. Mostrar turnos no realizados\n");
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







/*ZONA DE TURNO*/
//Funcion para registrar un turno:
void registrarTurno(lista_de_turno *turnos, lista_de_clientes *clientes)
{
    char id_cliente[9];
    int confirmar;
    float Total = 0.0;
    Turno nuevoTurno;
    int nivelCliente;
    int clienteEncontrado = 0;
    int tratamientoSeleccionado;
    int cantidadTratamientosSeleccionados = 0;
    int i;
    Cliente cliente_actual;

    int idValido;
    char idTemporal[11];
    do
    {
        idValido = 1;
        printf("Ingrese el ID del cliente para registrar el turno (solo numeros, maximo 8 caracteres): \n");
        printf("--------------------\n");
        scanf("%10s", idTemporal);

        if (strlen(idTemporal) > 8)
        {
            printf("--------------------\n");
            printf("Error: El ID no puede superar los 8 caracteres.\n");
            idValido = 0;
            printf("--------------------\n");
        }

        for (int j = 0; j < strlen(idTemporal); j++)
        {
            if (!isdigit(idTemporal[j]))
            {
                printf("--------------------\n");
                printf("Error: El ID debe contener solo numeros.\n");
                idValido = 0;
                printf("--------------------\n");
                break;
            }
        }

        if (idValido)
        {
            strncpy(id_cliente, idTemporal, 8);
            id_cliente[8] = '\0';
        }
    }
    while (!idValido);

    reset_cliente(clientes);
    while (!isOos_cliente(*clientes))
    {
        cliente_actual = coppy_cliente(*clientes);
        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0)
        {
            clienteEncontrado = 1;
            break;
        }
        forwards_cliente(clientes);
    }

    if (!clienteEncontrado)
    {
        printf("--------------------\n");
        printf("Cliente no encontrado. Procediendo a registrar nuevo cliente.\n");
        printf("--------------------\n");
        registrarCliente(clientes);
        reset_cliente(clientes);
        while (!isOos_cliente(*clientes))
        {
            cliente_actual = coppy_cliente(*clientes);
            if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0)
            {
                clienteEncontrado = 1;
                break;
            }
            forwards_cliente(clientes);
        }
    }

    if (!clienteEncontrado)
    {
        printf("--------------------\n");
        printf("Error: No se pudo registrar el turno.\n");
        printf("--------------------\n");
        return;
    }

    setIdCliente(&nuevoTurno, get_id_cliente(cliente_actual));
    nivelCliente = get_nivel_cliente(cliente_actual);
    setNombre(&nuevoTurno, get_nombre_cliente(cliente_actual));
    printf("Cliente encontrado: %s %s\n", get_nombre_cliente(cliente_actual), get_apellido_cliente(cliente_actual));
    printf("--------------------\n");
    setIdTurno(&nuevoTurno, generarIdTurno());

    // Control de turno no realizado existente
    int turnoPendiente = 0;
    resetL_turno(turnos);
    while (!is_Oos_turno(*turnos))
    {
        Turno turnoExistente = copy_turno(turnos);
        if (strcmp(get_idCliente(turnoExistente), id_cliente) == 0 && !get_realizado(turnoExistente))
        {
            turnoPendiente = 1;
            break;
        }
        forwards_turno(turnos);
    }

    if (turnoPendiente)
    {
        printf("--------------------\n");
        printf("Error: Este cliente ya tiene un turno pendiente sin realizar.\n");
        printf("--------------------\n");
        return;
    }

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
            printf("--------------------\n");
            printf("Se ha alcanzado el limite de 3 tratamientos por turno.\n");
            printf("--------------------\n");
            break;
        }

        printf("Ingrese el numero del tratamiento: \n");
        printf("--------------------\n");
        scanf("%d", &tratamientoSeleccionado);

        if (tratamientoSeleccionado > 0 && tratamientoSeleccionado <= MAX_TRATAMIENTOS)
        {
            if (tratamientos[tratamientoSeleccionado - 1] == 0)
            {
                tratamientos[tratamientoSeleccionado - 1] = 1;
                cantidadTratamientosSeleccionados++;
                Total += tratamientos_D[tratamientoSeleccionado - 1].precio_T;
                printf("--------------------\n");
                printf("Tratamiento agregado: %s\n", tratamientos_D[tratamientoSeleccionado - 1].nombre_T);
            }
            else
            {
                printf("Este tratamiento ya ha sido seleccionado.\n");
                printf("--------------------\n");
            }
        }
        else if (tratamientoSeleccionado != 0)
        {
            printf("Numero de tratamiento invalido. Intente nuevamente.\n");
            printf("--------------------\n");
        }
    }
    while (tratamientoSeleccionado != 0);

    setTratamiento(&nuevoTurno, tratamientos);
    setTotal(&nuevoTurno, Total, nivelCliente);

    Fecha fechaTurno;
    int colisionFecha;  // Declara colisionFecha aquí para que esté disponible en todo el bloque

    do
    {
        printf("Ingrese el dia del turno (1 a 31): \n");
        scanf("%d", &fechaTurno.dia);

        printf("Ingrese el mes del turno (11 a 12): \n");
        scanf("%d", &fechaTurno.mes);

        printf("Ingrese el anio del turno (formato AAAA): \n");
        scanf("%d", &fechaTurno.anio);

        printf("Ingrese la hora del turno (9 a 20): \n");
        scanf("%d", &fechaTurno.hora);
        printf("--------------------\n");
        colisionFecha = 0;  // Reinicia el valor de colisionFecha antes de cada verificación
        resetL_turno(turnos);

        while (!is_Oos_turno(*turnos))
        {
            Turno turnoExistente = copy_turno(turnos);
            Fecha fechaExistente = get_fecha(turnoExistente);

            if (fechaExistente.dia == fechaTurno.dia &&
                fechaExistente.mes == fechaTurno.mes &&
                fechaExistente.anio == fechaTurno.anio &&
                fechaExistente.hora == fechaTurno.hora)
            {
                colisionFecha = 1;
                break;
            }
            forwards_turno(turnos);
        }

        if (colisionFecha)
        {
            printf("Error: Ya existe un turno registrado en la misma fecha y hora.\n");
            printf("--------------------\n");
        }
        else if (!validarFecha(fechaTurno))
        {
            printf("Fecha no valida. Por favor ingrese una fecha dentro del horario de atencion (lunes a sabado, 9 a 20 hs).\n");
            printf("--------------------\n");
        }

    } while (!validarFecha(fechaTurno) || colisionFecha == 1);

    // Procede a registrar el nuevo turno si no hay colisión
    setFecha(&nuevoTurno, fechaTurno);
    printf("Total sin descuento: %.2f\n", Total);

    switch (nivelCliente)
    {
    case 0:
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    case 1:
        printf("Descuento por Nivel 1 (5%%): %.2f\n", Total * 0.05);
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    case 2:
        printf("Descuento por Nivel 2 (10%%): %.2f\n", Total * 0.10);
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    case 3:
        printf("Descuento por Nivel 3 (15%%): %.2f\n", Total * 0.15);
        printf("Total a pagar: %.2f\n", get_total(nuevoTurno));
        break;
    }

    int formaPago;
    do
    {
        printf("--------------------\n");
        printf("Seleccione la forma de pago:\n");
        printf("1. Debito\n");
        printf("2. Credito\n");
        printf("3. Efectivo\n");
        printf("4. QR\n");
        printf("Ingrese su eleccion: \n");
        printf("--------------------\n");
        scanf("%d", &formaPago);
    }
    while (formaPago < 1 || formaPago > 4);
    setFormaPago(&nuevoTurno, formaPago);
    setRealizado(&nuevoTurno, 0);
    printf("--------------------\n");
    printf("Confirmar turno? (1 = Si, 0 = No): \n");
    printf("--------------------\n");
    scanf("%d", &confirmar);
    if (confirmar)
    {
        insertL_turno(turnos, nuevoTurno);
        printf("--------------------\n");
        printf("Turno registrado con exito.\n");
        printf("--------------------\n");
    }
    else
    {
        printf("--------------------\n");
        printf("Turno cancelado.\n");
        printf("--------------------\n");
    }
}


// Función para mostrar todos los turnos de un mes
void mostrarTurnosDeMes(lista_de_turno *turnos, int mes)
{

    resetL_turno(turnos);  // Inicializa el cursor de la lista
    int contador = 0;

    // Recorre la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno turno_actual = copy_turno(turnos);

        // Si el turno es del mes especificado, lo mostramos
        if (get_mes(turno_actual.fecha) == mes)
        {
            printf("--------------------\n");
            printf("ID Turno: %d\n Cliente: %s\n Fecha: %02d/%02d/%d %d:00\n Total: %.2f\n Realizado: %s\n",
                   turno_actual.idTurno, turno_actual.nombre, turno_actual.fecha.dia, turno_actual.fecha.mes,
                   turno_actual.fecha.anio, turno_actual.fecha.hora, turno_actual.total,
                   turno_actual.realizado == 1 ? "Si" : "No");
                   printf("--------------------\n");
            contador++;
        }

        forwards_turno(turnos);  // Mueve al siguiente turno
    }

    // Si no se encontraron turnos para el mes
    if (contador == 0)
    {
        printf("--------------------\n");
        printf("No hay turnos para el mes %d.\n", mes);
        printf("--------------------\n");
    }
}

// Funcion para buscar turnos por nombre de cliente y paginar la muestra de los resultados
void buscarYMostrarTurnosPorCliente(lista_de_turno turnos, char *nombreCliente)
{

    resetL_turno(&turnos);  // Inicializa el cursor de la lista
    int contador = 0;

    // Busca los turnos que coincidan con el nombre del cliente
    while (!is_Oos_turno(turnos))
    {
        Turno turno_actual = copy_turno(&turnos);  // Obtener el turno actual

        if (strcmp(get_nombre_T(turno_actual), nombreCliente) == 0)
        {
            contador++;
        }
        forwards_turno(&turnos);  // Mueve al siguiente turno
    }

    // Si no se encuentran turnos para el cliente
    if (contador == 0)
    {
        printf("--------------------\n");
        printf("No se encontraron turnos para el cliente: %s\n", nombreCliente);
        return;
        printf("--------------------\n");
    }

    // Paginación: mostrar los turnos de 3 en 3
    int pagina = 1;
    int turnosPorPagina = 3;
    int totalPaginas = (contador + turnosPorPagina - 1) / turnosPorPagina;  // Redondeo hacia arriba

    while (1)
    {
        int inicio = (pagina - 1) * turnosPorPagina;
        int fin = (pagina * turnosPorPagina < contador) ? pagina * turnosPorPagina : contador;
        printf("--------------------\n");
        printf("\nPagina %d de %d:\n", pagina, totalPaginas);
        printf("--------------------\n");
        // Mostrar los turnos de la página actual
        resetL_turno(&turnos);  // Restablecee el cursor de la lista
        for (int i = 0; i < inicio; i++)  // Avanza hasta el turno de inicio
        {
            forwards_turno(&turnos);
        }

        for (int i = inicio; i < fin; i++)
        {
            Turno turno_actual = copy_turno(&turnos);  // Obttiene el turno actual
            printf("ID Turno: %d\n Cliente: %s\n Fecha: %02d/%02d/%d %d:00\n Total: %.2f\n Realizado: %s\n",
                   turno_actual.idTurno, turno_actual.nombre, turno_actual.fecha.dia,
                   turno_actual.fecha.mes, turno_actual.fecha.anio, turno_actual.fecha.hora,
                   turno_actual.total, turno_actual.realizado == 1 ? "Si" : "No");
            printf("--------------------\n");
            forwards_turno(&turnos);  // Mueve al siguiente turno
        }

        // Preguntar si el usuario quiere ver la siguiente página
        if (pagina < totalPaginas)
        {
            printf("--------------------\n");
            printf("Desea ver la siguiente pagina? (s/n): \n");
            printf("--------------------\n");
            char opcion;
            scanf(" %c", &opcion);
            if (opcion == 's' || opcion == 'S')
            {
                pagina++;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

// Función recursiva para mostrar los turnos solicitados por un cliente según su idCliente
void mostrarTurnosPorCliente(lista_de_turno *turnos, const char *idCliente, int *contador)
{
    // Si la lista está vacía o el cursor está fuera de la lista, terminamos la recursión
    if (is_emptys_turno(turnos) || is_Oos_turno(*turnos)) {
        return;
    }

    // Obtenemos el turno actual
    Turno t = copy_turno(turnos);
    // Si el idCliente del turno coincide con el proporcionado, mostramos la información
    if (strcmp(get_idCliente(t), idCliente) == 0) {
        printf("ID Turno: %d\n Fecha: %02d/%02d/%d %d:00\n Total: %.2f\n",
               get_idTurno(t), get_dia(get_fecha(t)), get_mes(get_fecha(t)),
               get_anio(get_fecha(t)), get_hora(get_fecha(t)), get_total(t));
        printf("--------------------\n");
        (*contador)++; // Incrementa el contador al mostrar un turno válido
    }

    // Avanza al siguiente turno
    forwards_turno(turnos);
    // Llamada recursiva
    mostrarTurnosPorCliente(turnos, idCliente, contador);
}

// Función para mostrar todos los turnos almacenados en la lista de turnos
void mostrarTodosLosTurnos(lista_de_turno *turnos)
{

    resetL_turno(turnos);  // Inicializamos los cursores de la lista

    // Verificamos si la lista está vacía
    if (is_emptys_turno(turnos))
    {
        printf("No hay turnos registrados.\n");
        return;
    }

    printf("Lista de turnos registrados:\n");
    printf("--------------------\n");
    // Recorremos la lista de turnos y mostramos cada uno
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual
        printf("ID Turno: %d\n Cliente: %s\n Fecha: %02d/%02d/%d %d:00\n Total: %.2f\n Realizado: %s\n",
               t.idTurno, t.nombre, t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora,
               t.total, t.realizado == 1 ? "Si" : "No");
        printf("--------------------\n");
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }
}

// Función para modificar la forma de pago de un turno solicitado según su idCliente (solo si el turno no está realizado)
void modificarFormaPago(lista_de_turno *turnos, char *idCliente, int nuevaFormaPago) {
    resetL_turno(turnos);

    while (!is_Oos_turno(*turnos)) {
        Turno t = copy_turno(turnos);

        if (strcmp(t.idCliente, idCliente) == 0 && get_realizado(t) == 0) {
            if (t.formaPago == nuevaFormaPago) {
                printf("La nueva forma de pago es la misma que la actual. Seleccione otra.\n");
                printf("--------------------\n");
                return;
            }
            setFormaPago(&t, nuevaFormaPago);
            printf("--------------------\n");
            printf("Forma de pago actualizada para el cliente %s:\n", t.idCliente);
            printf("--------------------\n");
            printf("ID Turno: %d\n Nombre: %s Nueva Forma de Pago: %s\n", t.idTurno, t.nombre, get_formaPago(t));
            printf("--------------------\n");
            return;
        }
        forwards_turno(turnos);
    }
    printf("--------------------\n");
    printf("No se encontro un turno no realizado para el cliente con ID: %s\n", idCliente);
    printf("--------------------\n");
}


// Función para cancelar un turno por idCliente
void cancelarTurno(lista_de_turno *turnos, char *idCliente)
{
    if (is_emptys_turno(turnos))
    {
        printf("--------------------\n");
        printf("No hay turnos cargados en la lista.\n");
        printf("--------------------\n");
        return;
    }

    resetL_turno(turnos);
    FILE *archivo = fopen("turnos_cancelados.txt", "a");
    if (!archivo)
    {
        printf("--------------------\n");
        printf("Error al abrir el archivo de cancelaciones.\n");
        printf("--------------------\n");
        return;
    }

    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);

        if (strcmp(t.idCliente, idCliente) == 0 && get_realizado(t) == 0)
        {
            char confirmacion;
            printf("--------------------\n");
            printf("Esta seguro que desea cancelar el turno del cliente %s (ID Cliente: %s)? (s/n): \n", t.nombre, t.idCliente);
            scanf(" %c", &confirmacion);
            printf("--------------------\n");
            if (confirmacion == 's' || confirmacion == 'S')
            {
                printf("--------------------\n");
                fprintf(archivo, "ID Turno: %d\n", t.idTurno);
                fprintf(archivo, "Nombre: %s\n", t.nombre);
                fprintf(archivo, "ID Cliente: %s\n", t.idCliente);
                fprintf(archivo, "Tratamientos: ");
                for (int i = 0; i < MAX_TRATAMIENTOS; i++)
                {
                    if (t.tratamientos[i] != 0)
                    {
                        fprintf(archivo, "%d ", t.tratamientos[i]);
                    }
                }
                fprintf(archivo, "\nForma de Pago: %s\n", get_formaPago(t));
                fprintf(archivo, "Total: %.2f\n", t.total);
                fprintf(archivo, "Fecha: %02d/%02d/%d %02d:00\n", t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora);
                fprintf(archivo, "Realizado: %d\n", t.realizado);
                fprintf(archivo, "---------------------------------------\n");

                suppress_turno(turnos);
                printf("Turno cancelado y datos guardados en el archivo.\n");
                printf("--------------------\n");
                fclose(archivo);
                return;
            }
            else
            {
                printf("Cancelacion del turno cancelada.\n");
                printf("--------------------\n");
                fclose(archivo);
                return;
            }
        }
        forwards_turno(turnos);
    }
    printf("No se encontró un turno no realizado para el cliente con ID: %s\n", idCliente);
    printf("--------------------\n");
    fclose(archivo);
}

// Función para almacenar los turnos pagados según la forma de pago
void almacenarTurnosPagados(lista_de_turno *turnos, int formaPago)
{
    FILE *archivo = fopen("turnos_pagados.txt", "w");  // Archivo donde guardamos los turnos pagados
    if (!archivo)
    {
        printf("\n--------------------------------------\n");
        printf("Error: No se pudo abrir el archivo para almacenar los turnos pagados.\n");
        printf("--------------------------------------\n\n");
        return;
    }

    int contador = 0;  // Contador para los turnos copiados
    resetL_turno(turnos);  // Inicializamos los cursores de la lista

    // Recorremos la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual

        // Si el turno está realizado y coincide con la forma de pago proporcionada
        if (get_realizado(t) == 1 && t.formaPago == formaPago)
        {
            // Guardar los datos del turno en el archivo
            fprintf(archivo, "ID Turno: %d\n", get_idTurno(t));

            char *nombreCliente = get_nombre_T(t);
            fprintf(archivo, "Nombre: %s\n", nombreCliente);
            free(nombreCliente);

            char *idCliente = get_idCliente(t);
            fprintf(archivo, "ID Cliente: %s\n", idCliente);
            free(idCliente);

            fprintf(archivo, "Tratamientos: ");
            int *tratamientos = get_tratamientos(t);
            for (int i = 0; i < MAX_TRATAMIENTOS; i++)
            {
                if (tratamientos[i] != 0)
                {
                    fprintf(archivo, "%d ", tratamientos[i]);
                }
            }
            free(tratamientos);

            fprintf(archivo, "\nForma de Pago: %s\n", get_formaPago(t));
            fprintf(archivo, "Total: %.2f\n", get_total(t));

            Fecha fecha = get_fecha(t);
            fprintf(archivo, "Fecha: %02d/%02d/%d %02d:00\n",
                    get_dia(fecha), get_mes(fecha), get_anio(fecha), get_hora(fecha));
            fprintf(archivo, "---------------------------------------\n");

            contador++;   // Incrementamos el contador de turnos copiados
        }

        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    printf("Se copiaron %d turnos con la forma de pago seleccionada al archivo 'turnos_pagados.txt'.\n", contador);
    fclose(archivo);  // Cerrar el archivo
}



// Función para mostrar los turnos de un tratamiento
void mostrarTurnosPorTratamiento(lista_de_turno *turnos, int tratamiento_id)
{
    resetL_turno(turnos);  // Inicializamos el cursor en la lista

    int encontrado = 0;  // Variable para verificar si se encuentran turnos

    // Recorremos la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual

        // Verificamos si el turno incluye el tratamiento solicitado
        if (tratamiento_id > 0 && tratamiento_id <= MAX_TRATAMIENTOS && t.tratamientos[tratamiento_id - 1] == 1)
        {
            // Si encontramos el tratamiento, mostramos el turno
            printf("ID Turno: %d\n", t.idTurno);
            printf("Nombre: %s\n", t.nombre);
            printf("ID Cliente: %s\n", t.idCliente);
            printf("Forma de Pago: %s\n", get_formaPago(t));
            printf("Total: %.2f\n", t.total);
            printf("Fecha: %02d/%02d/%d %02d:00\n", t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora);
            printf("Realizado: %d\n", t.realizado);
            printf("---------------------------------------\n");

            encontrado = 1;
        }
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    if (!encontrado)
    {
        printf("No se encontraron turnos para el tratamiento con ID: %d\n", tratamiento_id);
        printf("--------------------\n");
    }
}


//Funcion para confirmar asistencia a un turno
void confirmarAsistenciaTurno(lista_de_turno *listaTurnos, char *idCliente, lista_de_clientes *listaCliente)
{
    if (is_emptys_turno(listaTurnos))
    {
        printf("La lista de turnos está vacía.\n");
        printf("--------------------\n");
        return;
    }

    resetL_turno(listaTurnos);

    while (!is_Oos_turno(*listaTurnos))
    {
        Turno turno = copy_turno(listaTurnos);
        int *tratamientos = get_tratamientos(turno);
        int can_tratamientos = 0;
        for (int i = 0; i < MAX_TRATAMIENTOS; i++)
        {
            can_tratamientos += tratamientos[i];
        }

        if (strcmp(get_idCliente(turno), idCliente) == 0)
        {
            if(get_realizado(turno)== 0)
            {
                // Marca el turno como realizado
                setRealizado(&turno, 1);

                // Suprime el turno original y re-inserta el actualizado
                suppress_turno(listaTurnos);  // Elimina el turno original
                insertL_turno(listaTurnos, turno);  // Inserta el turno actualizado

                printf("Asistencia confirmada para el cliente ID %s.\n", idCliente);
                printf("ID: %s\n", get_idCliente(turno));
                printf("Nombre del Cliente: %s\n", get_nombre_T(turno));
                printf("Fecha: %d/%d/%d\n", get_dia(get_fecha(turno)), get_mes(get_fecha(turno)), get_anio(get_fecha(turno)));
                printf("-------------------------\n");

                reset_cliente(listaCliente);

                while (!isOos_cliente(*listaCliente))
                {
                    Cliente cliente = coppy_cliente(*listaCliente);

                    if (strcmp(get_id_cliente(cliente), idCliente) == 0)
                    {
                        // Actualiza la cantidad de tratamientos del cliente
                        set_canttratamientos_cliente(&cliente, can_tratamientos);
                        set_nivel_cliente(&cliente, cliente.canttratamientos);

                        // Suprime el cliente original y re-inserta el actualizado
                        supress_cliente(listaCliente);  // Elimina el cliente original
                        insert_cliente(listaCliente, cliente);  // Inserta el cliente actualizado

                        printf("El cliente %s ha asistido y su cantidad de tratamientos ha sido actualizada.\n", get_nombre_cliente(cliente));
                        printf("--------------------\n");
                        return;
                    }

                    forwards_cliente(listaCliente);
                }
            }
            else
            {
                printf("El turno del cliente esta realizado.\n");
                printf("--------------------\n");
            }
            printf("Cliente con ID %s no encontrado.\n", idCliente);
            printf("--------------------\n");
            return;
        }

        forwards_turno(listaTurnos);
    }

    printf("Turno con ID %s no encontrado.\n", idCliente);
    printf("--------------------\n");
}


// Función para mostrar los turnos no realizados
void mostrarTurnosNoRealizados(lista_de_turno *l)
{
    if (is_emptys_turno(l))
    {
        printf("La lista de turnos está vacía.\n");
        printf("--------------------\n");
        return;
    }

    resetL_turno(l);

    int encontrado = 0;

    while (!is_Oos_turno(*l))
    {
        Turno turno = copy_turno(l);

        // Verifica si el turno no ha sido realizado
        if (get_realizado(turno) == 0)
        {
            printf("ID del turno: %d\n", get_idTurno(turno));
            printf("Nombre del cliente: %s\n", get_nombre_T(turno));
            printf("Fecha del turno: %02d/%02d/%04d a las %02d:00\n",
                   get_dia(turno.fecha), get_mes(turno.fecha), get_anio(turno.fecha), get_hora(turno.fecha));
            printf("Forma de pago: %s\n", get_formaPago(turno));
            printf("Total: %.2f\n", get_total(turno));
            printf("----------\n");
            encontrado = 1;
        }

        forwards_turno(l);
    }

    if (!encontrado)
    {
        printf("No hay turnos no realizados.\n");
        printf("--------------------\n");
    }
}

/*FUNCIONES AUXILIARES*/
void mostrarMetodoPagoActual(lista_de_turno *turnos, const char *idCliente) {
    resetL_turno(turnos);

    while (!is_Oos_turno(*turnos)) {
        Turno t = copy_turno(turnos);
        if (strcmp(t.idCliente, idCliente) == 0 && get_realizado(t) == 0) {
            printf("Forma de pago actual para el cliente %s: %s\n", idCliente, get_formaPago(t));
            printf("--------------------\n");
            return; // Salir después de mostrar la primera coincidencia
        }
        forwards_turno(turnos);
    }
}

int verificarTurnoCliente(lista_de_turno *turnos, const char *idCliente) {
    resetL_turno(turnos);
    int contador = 0;

    while (!is_Oos_turno(*turnos)) {
        Turno t = copy_turno(turnos);
        if (strcmp(t.idCliente, idCliente) == 0) {
            contador++;
        }
        forwards_turno(turnos);
    }
    return contador;  // Retorna el número de turnos encontrados para el cliente
}

// Función para mostrar los tratamientos disponibles
void mostrarTratamientos()
{

    printf("Tratamientos disponibles:\n");
    for (int i = 0; i < MAX_TRATAMIENTOS; i++)
    {
        printf("%d. %s\n", i + 1, tratamientos_D[i].nombre_T);
    }
}

// Función que verifica si hay un turno no realizado para el cliente y muestra el método de pago actual
int verificarTurnoNoRealizadoCliente(lista_de_turno *turnos, char *idCliente) {
    resetL_turno(turnos);

    while (!is_Oos_turno(*turnos)) {
        Turno t = copy_turno(turnos);

        // Verifica si el turno pertenece al cliente y no está realizado
        if (strcmp(t.idCliente, idCliente) == 0 && get_realizado(t) == 0) {
            printf("--------------------\n");
            printf("Metodo de pago actual para el cliente %s: %s\n", idCliente, get_formaPago(t));
            return 1;  // Retorna 1 si hay un turno no realizado para el cliente
        }

        forwards_turno(turnos);
    }

    return 0;  // Retorna 0 si no hay turnos no realizados para el cliente
}

/*ZONA DE CLIENTE*/

// FUNCION DE PRECARGA (n)
void precargarClientesDesdeArchivo(lista_de_clientes *clientes)
{
    FILE *archivo = fopen("clientes.txt", "r");
    if (archivo == NULL)
    {
        printf("Error en la apertura del archivo.\n");
        printf("--------------------\n");
        exit(1);
    }

    Cliente c;
    int i = 0, canttratamientos, nivel;
    char id_cliente[9];
    char nombre[41], apellido[41];

    rewind(archivo);
    int count = 0;
    while (fscanf(archivo, "%8s %40[^\n] %40[^\n] %d %d", id_cliente, nombre, apellido, &canttratamientos, &nivel) == 5)
    {
        // Reiniciar estructura Cliente antes de cada inserción
        memset(&c, 0, sizeof(Cliente));
        inittratamientos_cliente(&c);  // Reinicia `canttratamientos` a 0
        c.nivel = 0;  // Reinicia `nivel` a 0

        // Asignar valores leídos al cliente
        set_id_cliente(&c, id_cliente);
        set_nombre_cliente(&c, nombre);
        set_apellido_cliente(&c, apellido);
        set_canttratamientos_cliente(&c, canttratamientos);
        set_nivel_cliente(&c, canttratamientos);

        // Insertar en la lista
        insert_cliente(clientes, c);
        i++;
        count++;
    }

    fclose(archivo);
    printf("Precarga de %d clientes completada.\n", count);
    printf("--------------------\n");
}

void registrarCliente(lista_de_clientes *clientes)
{

    if (isfull_cliente(*clientes))
    {
        printf("Lista de clientes llena. No se pueden registrar mas clientes.\n");
        printf("--------------------\n");
        return;
    }

    Cliente nuevoCliente;
    char id_cliente[9];
    char nombre[20];
    char apellido[20];
    int idValido, nombreValido, apellidoValido;
    char idTemporal[11];
    char nombreTemporal[25];
    char apellidoTemporal[25];

    // Solicita y asigna el ID del cliente con validaciones
    do
    {
        idValido = 1;
        printf("Ingrese el ID del cliente (solo numeros, maximo 8 caracteres): ");
        scanf("%10s", idTemporal);
        printf("--------------------\n");

        if (strlen(idTemporal) > 8)
        {
            printf("--------------------\n");
            printf("Error: El ID no puede superar los 8 caracteres.\n");
            idValido = 0;
            printf("--------------------\n");
        }

        for (int j = 0; j < strlen(idTemporal); j++)
        {
            if (!isdigit(idTemporal[j]))
            {
                printf("--------------------\n");
                printf("Error: El ID debe contener solo numeros.\n");
                printf("--------------------\n");
                idValido = 0;

                break;
            }
        }

        if (idValido)
        {
            strncpy(id_cliente, idTemporal, 8);
            id_cliente[8] = '\0';
        }

        reset_cliente(clientes);
        while (!isOos_cliente(*clientes))
        {
            Cliente actual = coppy_cliente(*clientes);
            if (strcmp(get_id_cliente(actual), id_cliente) == 0)
            {
                printf("--------------------\n");
                printf("Error: Ya existe un cliente con ese ID.\n");
                printf("--------------------\n");
                idValido = 0;
                break;
            }
            forwards_cliente(clientes);
        }
    }
    while (!idValido);
    set_id_cliente(&nuevoCliente, id_cliente);

    // Solicita y asigna el nombre del cliente con validación de caracteres
    do
    {
        nombreValido = 1;
        printf("Ingrese el nombre del cliente (solo letras y espacios): \n");
        printf("--------------------\n");
        scanf(" %[^\n]%*c", nombreTemporal);

        for (int i = 0; i < strlen(nombreTemporal); i++)
        {
            if (!isalpha(nombreTemporal[i]) && nombreTemporal[i] != ' ')
            {
                printf("--------------------\n");
                printf("Error: El nombre solo debe contener letras y espacios.\n");
                printf("--------------------\n");
                nombreValido = 0;
                break;
            }
        }

        if (nombreValido)
        {
            strncpy(nombre, nombreTemporal, 19);
            nombre[19] = '\0';
        }
    }
    while (!nombreValido);
    set_nombre_cliente(&nuevoCliente, nombre);

    // Solicita y asigna el apellido del cliente con validación de caracteres
    do
    {
        apellidoValido = 1;
        printf("--------------------\n");
        printf("Ingrese el apellido del cliente (solo letras y espacios): \n");
        printf("--------------------\n");
        scanf(" %[^\n]%*c", apellidoTemporal);

        for (int i = 0; i < strlen(apellidoTemporal); i++)
        {
            if (!isalpha(apellidoTemporal[i]) && apellidoTemporal[i] != ' ')
            {
                printf("--------------------\n");
                printf("Error: El apellido solo debe contener letras y espacios.\n");
                printf("--------------------\n");
                apellidoValido = 0;
                break;
            }
        }

        if (apellidoValido)
        {
            strncpy(apellido, apellidoTemporal, 19);
            apellido[19] = '\0';
        }
    }
    while (!apellidoValido);
    set_apellido_cliente(&nuevoCliente, apellido);

    // Inicializa canttratamientos y nivel
    inittratamientos_cliente(&nuevoCliente);  // canttratamientos a 0
    set_nivel_cliente(&nuevoCliente, 0);      // nivel a 0

    // Inserta el cliente en la lista
    insert_cliente(clientes, nuevoCliente);
    printf("--------------------\n");
    printf("Cliente registrado exitosamente.\n");
    printf("--------------------\n");
}

void buscarCliente(lista_de_clientes clientes)
{
    if (isempty_cliente(clientes))
    {

        printf("La lista de clientes esta vacia. No hay clientes para buscar.\n");
        printf("--------------------\n");
        return;
    }

    reset_cliente(&clientes);  // Asegura que el cursor comience desde el inicio

    char id_cliente[9];
    char idTemporal[11];
    int idValido;

    // Validación del ID del cliente ingresado
    do
    {
        idValido = 1;

        printf("Ingrese el ID del cliente a buscar (solo numeros, maximo 8 caracteres): \n");
        printf("--------------------\n");
        scanf("%10s", idTemporal);

        if (strlen(idTemporal) > 8)
        {
            printf("--------------------\n");
            printf("Error: El ID no puede superar los 8 caracteres.\n");
            printf("--------------------\n");
            idValido = 0;
        }

        for (int j = 0; j < strlen(idTemporal); j++)
        {
            if (!isdigit(idTemporal[j]))
            {
                printf("--------------------\n");
                printf("Error: El ID debe contener solo numeros.\n");
                printf("--------------------\n");
                idValido = 0;
                break;
            }
        }

        if (idValido)
        {
            strncpy(id_cliente, idTemporal, 8);
            id_cliente[8] = '\0';
        }
    }
    while (!idValido);

    // Búsqueda del cliente en la lista
    for (int i = 0; i <= clientes.ultimo; i++)
    {
        Cliente cliente_actual = coppy_cliente(clientes);

        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0)
        {
            printf("--------------------\n");
            printf("Cliente encontrado:\n");
            printf("--------------------\n");
            printf("ID: %s\n", get_id_cliente(cliente_actual));
            printf("Nombre: %s\n", get_nombre_cliente(cliente_actual));
            printf("Apellido: %s\n", get_apellido_cliente(cliente_actual));
            printf("Cantidad de tratamientos: %d\n", get_canttratamientos_cliente(cliente_actual));
            printf("Nivel: %d\n", get_nivel_cliente(cliente_actual));
            printf("--------------------\n");
            // Libera la memoria de las cadenas asignadas dinámicamente
            free(get_id_cliente(cliente_actual));
            free(get_nombre_cliente(cliente_actual));
            free(get_apellido_cliente(cliente_actual));
            return;
        }

        forwards_cliente(&clientes);
    }
    printf("--------------------\n");
    printf("Cliente no encontrado.\n");
    printf("--------------------\n");
}

// Funcion para eliminar un cliente de la lista
void eliminarCliente(lista_de_clientes *clientes)
{
    if (isempty_cliente(*clientes))
    {
        printf("La lista de clientes esta vacia.\n");
        printf("--------------------\n");
        return;
    }

    reset_cliente(clientes);  // Asegura que el cursor comience desde el inicio

    char id_cliente[9];
    printf("Ingrese el ID del cliente a eliminar: \n");
    printf("--------------------\n");
    scanf("%8s", id_cliente);

    // Recorre la lista de clientes utilizando el cursor y las funciones de la lista
    for (int i = 0; i <= clientes->ultimo; i++)
    {
        Cliente cliente_actual = coppy_cliente(*clientes);

        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0)
        {
            supress_cliente(clientes);// Eliminar el cliente de la lista
            printf("--------------------\n");
            printf("Cliente eliminado exitosamente.\n");
            printf("--------------------\n");
            // Libera la memoria asignada dinámicamente
            free(get_id_cliente(cliente_actual));
            free(get_nombre_cliente(cliente_actual));
            free(get_apellido_cliente(cliente_actual));
            return;
        }

        forwards_cliente(clientes);

        // Libera la memoria asignada dinámicamente en cada iteración
        free(get_id_cliente(cliente_actual));
        free(get_nombre_cliente(cliente_actual));
        free(get_apellido_cliente(cliente_actual));
    }
    printf("--------------------\n");
    printf("Cliente no encontrado.\n");
    printf("--------------------\n");
}

//Funcion que muestra todos los clientes almacenados en la lista de clientes:
void mostrarTodosLosClientes(lista_de_clientes *clientes)
{
    if (isempty_cliente(*clientes))
    {
        printf("No hay clientes almacenados.\n");
        printf("--------------------\n");
        return;
    }

    printf("Lista de clientes:\n");
    printf("--------------------\n");
    reset_cliente(clientes);  // Asegura que el cursor esté al inicio de la lista

    while (!isOos_cliente(*clientes))
    {
        Cliente cliente_actual = coppy_cliente(*clientes);

        // Obtener los datos una sola vez en variables temporales
        char *id = get_id_cliente(cliente_actual);
        char *nombre = get_nombre_cliente(cliente_actual);
        char *apellido = get_apellido_cliente(cliente_actual);

        if (id && nombre && apellido)
        {
            printf("ID: %s\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Apellido: %s\n", apellido);
            printf("Cantidad de tratamientos: %d\n", get_canttratamientos_cliente(cliente_actual));
            printf("Nivel: %d\n", get_nivel_cliente(cliente_actual));
            printf("--------------------\n");
        }
        else
        {
            printf("Error: No se pudo obtener los datos del cliente.\n");
        }

        // Liberar memoria para cada atributo obtenido
        free(id);
        free(nombre);
        free(apellido);

        // Mueve el cursor al siguiente cliente
        forwards_cliente(clientes);
    }
}


/*ZONA DE REPORTES*/
// Función recursiva que calcula la ganancia mensual según un mes pasado por parámetro
float funcrec_gananciam(lista_de_turno *lista, float ganancia, int mes)
{
    // Si la lista está vacía o el cursor está fuera de la lista, se termina la recursión
    if (is_emptys_turno(lista) || is_Oos_turno(*lista)) {
        return ganancia;
    }

    // Obtenemos el turno actual
    Turno turno_actual = copy_turno(lista);

    // Verifica si el mes coincide y si el turno fue realizado
    if (get_mes(turno_actual.fecha) == mes && get_realizado(turno_actual) == 1)
    {
        // Acumula la ganancia del turno actual
        ganancia += get_total(turno_actual);
    }

    // Avanza el cursor al siguiente elemento en la lista
    forwards_turno(lista);

    // Llamada recursiva sin duplicar el avance
    return funcrec_gananciam(lista, ganancia, mes);
}


/*MAIN*/
// Funcion principal
int main()
{
    lista_de_turno turno;
    lista_de_clientes clientes;
    init_cliente(&clientes);
    init_turno(&turno);
    int mes;
    char nombre[20];
    char clienteid[9];
    int formaPago;
    int opcionPrincipal, opcionTurnos, opcionClientes, opcionReportes;
    float ganancia_inicial = 0.0;
    int mes_deseado;


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
                    printf("--------------------\n");
                    registrarTurno(&turno,&clientes);
                    break;
                case 2:
                    printf("Mostrar todos los turnos de un cliente\n");
                    printf("--------------------\n");
                    printf("Ingrese el ID del cliente: \n");
                    printf("--------------------\n");
                    scanf("%s", clienteid);
                    printf("--------------------\n");

                    // Verificar si el ID del cliente no está vacío
                    if (strlen(clienteid) == 0) {
                        printf("No se ingreso un ID de cliente valido\n");
                        printf("--------------------\n");
                    } else if (is_emptys_turno(&turno)) {
                        // Verificar si la lista de turnos está vacía
                        printf("No hay turnos cargados en el sistema\n");
                        printf("--------------------\n");
                    } else {
                        int turnos_mostrados = 0; // Inicializa el contador de turnos mostrados para el cliente
                        resetL_turno(&turno);

                        // Llamada a la función recursiva para mostrar los turnos
                        mostrarTurnosPorCliente(&turno, clienteid, &turnos_mostrados);

                        // Mensajes finales según la cantidad de turnos mostrados
                        if (turnos_mostrados == 0) {
                            printf("No se encontraron turnos para el cliente con ID: %s\n", clienteid);
                            printf("--------------------\n");
                        } else {
                            printf("No se encontraron mas turnos para el cliente con ID: %s\n", clienteid);
                            printf("--------------------\n");
                        }
                    }
                    break;
                case 3:
                    printf("Mostrar todos los turnos de un mes.\n");
                    printf("--------------------\n");
                    printf("Ingrese el mes a buscar(11-12) \n");
                    printf("--------------------\n");
                    scanf("%d",&mes);

                    mostrarTurnosDeMes(&turno,mes);
                    break;
                case 4:
                    printf("Mostrar turnos por nombre de cliente.\n");
                    printf("--------------------\n");
                    printf("Ingrese el nombre del cliente a buscar:  \n");
                    printf("--------------------\n");
                    scanf("%s",nombre);

                    buscarYMostrarTurnosPorCliente(turno,nombre);
                    break;
                case 5:
                    printf("Mostrar todos los turno.\n");
                    printf("--------------------\n");
                    mostrarTodosLosTurnos(&turno);
                    break;
                case 6:
                    printf("Modificar forma de pago.\n");
                    printf("--------------------\n");
                    printf("Ingrese el ID del cliente \n");
                    scanf("%s", clienteid);  // Leemos el ID del cliente

                    if (is_emptys_turno(&turno)) {
                        // Verificar si la lista de turnos está vacía
                        printf("--------------------\n");
                        printf("No hay turnos cargados en el sistema\n");
                        printf("--------------------\n");
                    } else {
                        // Verificar si existe al menos un turno para el cliente
                        int turnosEncontrados = verificarTurnoCliente(&turno, clienteid);
                        if (turnosEncontrados == 0) {
                            printf("--------------------\n");
                            printf("No se encontraron turnos para el cliente con ID: %s \n", clienteid);
                            printf("--------------------\n");
                        } else {
                            // Verificar si alguno de los turnos no está realizado y mostrar el método de pago actual si es el caso
                            int turnoNoRealizado = verificarTurnoNoRealizadoCliente(&turno, clienteid);

                            if (turnoNoRealizado == 0) {
                                printf("--------------------\n");
                                printf("No se encontraron turnos no realizados para el cliente con ID: %s \n", clienteid);
                                printf("--------------------\n");
                            } else {
                                // Mostrar la selección de la nueva forma de pago
                                printf("--------------------\n");
                                printf("Seleccione la nueva forma de pago para el cliente con ID %s:\n", clienteid);
                                printf("1. Debito\n");
                                printf("2. Credito\n");
                                printf("3. Efectivo\n");
                                printf("4. QR\n");
                                printf("--------------------\n");

                                do {
                                    printf("Ingrese su eleccion (1-4): ");
                                    scanf("%d", &formaPago);
                                } while (formaPago < 1 || formaPago > 4);

                                modificarFormaPago(&turno, clienteid, formaPago);  // Modificar la forma de pago
                            }
                        }
                    }
                    break;
                case 7:
                    printf("Mostrar turnos por tratamiento.\n");
                    printf("--------------------\n");
                    // Mostrar los tratamientos disponibles
                    mostrarTratamientos();
                    // Solicitar al usuario que ingrese el ID del tratamiento a buscar
                    int tratamiento_id;
                    printf("--------------------\n");
                    printf("Ingrese el ID del tratamiento que desea buscar: \n");
                    printf("--------------------\n");
                    scanf("%d", &tratamiento_id);

                    // Llamamos a la función para mostrar los turnos para el tratamiento con el ID dado
                    mostrarTurnosPorTratamiento(&turno, tratamiento_id);
                    break;
                case 8:
                    printf("Cancelar un turno.\n");
                    printf("--------------------\n");
                    printf("- Desea cancelar un turno?\n");
                    printf("--------------------\n");
                    printf("Ingrese el ID del cliente a cancelar turno: \n");
                    printf("--------------------\n");
                    scanf("%s", clienteid);  // Leemos el ID del cliente

                    cancelarTurno(&turno, clienteid);  // Llamamos a la función para cancelar el turno

                    break;
                case 9:
                    printf("Confirmar asistencia de turno.\n");
                    printf("--------------------\n");
                    printf("Ingrese el ID del cliente para confirmar asistencia: \n");
                    printf("--------------------\n");
                    scanf("%s", clienteid);
                    confirmarAsistenciaTurno(&turno,clienteid,&clientes);
                    break;
                case 10:
                    printf("Mostrar turnos no realizados.\n");
                    printf("--------------------\n");
                    mostrarTurnosNoRealizados(&turno);
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
                    printf("Registrar cliente \n");
                    printf("--------------------\n");
                    registrarCliente(&clientes);
                    break;
                case 2:
                    printf("Buscar cliente \n");
                    printf("--------------------\n");
                    buscarCliente(clientes);
                    break;
                case 3:
                    printf("Eliminar cliente \n");
                    printf("--------------------\n");
                    eliminarCliente(&clientes);
                    break;
                case 4:
                    printf("Precarga de clientes \n");
                    printf("--------------------\n");
                    precargarClientesDesdeArchivo(&clientes);
                    break;
                case 5:
                    printf("Mostrar Todos los clientes \n");
                    printf("--------------------\n");
                    mostrarTodosLosClientes(&clientes);
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
                    do {
                        printf("\n -----Consultar ganancia mensual por mes.-----\n");
                        printf("Ingrese el mes del que desea saber la ganancia mensual (11-12): \n");
                        printf("--------------------\n");
                        scanf("%d", &mes_deseado);

                        // Verificar si el mes ingresado está dentro del rango válido
                        if (mes_deseado < 11 || mes_deseado > 12) {
                            printf("--------------------\n");
                            printf("Mes ingresado no valido, por favor ingrese un numero entre 11 y 12 \n");
                            printf("--------------------\n");
                        } else if (is_emptys_turno(&turno)) {
                            // Verificar si la lista de turnos está vacía antes de llamar a la función recursiva
                            printf("--------------------\n");
                            printf("No hay turnos cargados en el sistema\n");
                            printf("--------------------\n");
                        } else {
                            resetL_turno(&turno);
                            // Llamada a la función recursiva para calcular la ganancia
                            float ganancia_final = funcrec_gananciam(&turno, ganancia_inicial, mes_deseado);

                            // Comprobar si la ganancia es cero, lo que indicaría que no hubo turnos realizados en el mes especificado
                            if (ganancia_final == 0.0) {
                                printf("--------------------\n");
                                printf("No se encontraron turnos realizados en el mes %d\n", mes_deseado);
                                printf("--------------------\n");
                            } else {
                                printf("La ganancia total para el mes %d es: %.2f\n", mes_deseado, ganancia_final);
                            }
                        }
                    } while (mes_deseado < 11 || mes_deseado > 12);


                    break;
                case 2:
                    printf("Guardar turnos segun forma de pago.\n\n");
                    printf("--------------------\n");
                    printf("Ingrese la forma de pago para almacenar los turnos pagados:\n");
                    printf("--------------------\n");
                    printf("1. Debito\n");
                    printf("2. Credito\n");
                    printf("3. Efectivo\n");
                    printf("4. QR\n");
                    printf("--------------------\n");
                    do
                    {
                        printf("\nSeleccione forma de pago para almacenar los turnos pagados (1-4): \n");
                        printf("--------------------\n");
                        scanf("%d", &formaPago);

                        if (formaPago < 1 || formaPago > 4)
                        {
                            printf("--------------------\n");
                            printf("Error: Opcion invalida. Seleccione un numero entre 1 y 4.\n");
                            printf("--------------------\n");
                        }
                    }
                    while (formaPago < 1 || formaPago > 4);

                    // Continue to call almacenarTurnosPagados function here
                    almacenarTurnosPagados(&turno, formaPago);
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
