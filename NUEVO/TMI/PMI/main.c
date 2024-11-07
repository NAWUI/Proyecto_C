#include <stdio.h> //Permite el uso de funciones de entrada y salida, como printf y scanf
#include <stdlib.h> //Proporciona funciones como system, usada para limpiar la pantalla.
#include <windows.h>
#include <conio.h> //Facilita el manejo de caracteres en consola y la funci�n getch(), usada para pausar la ejecuci�n hasta que el usuario presione una tecla.
#include <string.h>

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
void registrarTurno(lista_de_turno *turnos, lista_de_clientes *clientes)
{
    char id_cliente[9];
    int estado = 0;
    int confirmar;
    float Total = 0.0;
    Turno nuevoTurno;
    int nivelCliente;
    int clienteEncontrado = 0;
    int tratamientoSeleccionado;
    int cantidadTratamientosSeleccionados = 0;
    int i;
    Cliente cliente_actual;

    printf("Ingrese el ID del cliente para registrar el turno: ");
    scanf("%s", id_cliente);

    // Buscar si el cliente ya est� registrado
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
        printf("Cliente no encontrado. Procediendo a registrar nuevo cliente.\n");
        registrarCliente(clientes);  // Llama a funci�n para registrar cliente
        // Luego de registrar el cliente, intenta encontrarlo en la lista
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
        printf("Error: No se pudo registrar el turno.\n");
        return;
    }

    // Configurar los detalles del turno basados en el cliente encontrado o reci�n registrado
    setIdCliente(&nuevoTurno, get_id_cliente(cliente_actual));
    nivelCliente = get_nivel_cliente(cliente_actual);  // Nivel del cliente
    setNombre(&nuevoTurno, get_nombre_cliente(cliente_actual));
    printf("Cliente encontrado: %s %s\n", get_nombre_cliente(cliente_actual), get_apellido_cliente(cliente_actual));

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
            printf("Se ha alcanzado el l�mite de 3 tratamientos por turno.\n");
            break;
        }

        printf("Ingrese el n�mero del tratamiento: ");
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
            printf("N�mero de tratamiento inv�lido. Intente nuevamente.\n");
        }
    }
    while (tratamientoSeleccionado != 0);

    setTratamiento(&nuevoTurno, tratamientos);
    setTotal(&nuevoTurno, Total, nivelCliente);

    Fecha fechaTurno;
    do
    {
        printf("Ingrese la fecha del turno (d�a mes a�o hora): ");
        scanf("%d %d %d %d", &fechaTurno.dia, &fechaTurno.mes, &fechaTurno.anio, &fechaTurno.hora);
        if (!validarFecha(fechaTurno))
        {
            printf("Fecha no v�lida. Por favor ingrese una fecha dentro del horario de atenci�n (lunes a s�bado, 9 a 20 hs).\n");
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
        printf("1. D�bito\n");
        printf("2. Cr�dito\n");
        printf("3. Efectivo\n");
        printf("4. QR\n");
        printf("Ingrese su elecci�n: ");
        scanf("%d", &formaPago);
    }
    while (formaPago < 1 || formaPago > 4);
    setFormaPago(&nuevoTurno, formaPago);

    setRealizado(&nuevoTurno, 0);

    printf("Confirmar turno? (1 = Si, 0 = No): ");
    scanf("%d", &confirmar);
    if (confirmar)
    {
        insertL_turno(turnos, nuevoTurno);
        printf("Turno registrado con �xito.\n");
    }
    else
    {
        printf("Turno cancelado.\n");
    }
}
Turno buscarTurnoPorIdCliente(lista_de_turno *turnos, char *id_cliente)
{
    resetL_turno(turnos);  // Inicializa los cursores

    // Recorrer la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno turno_actual = copy_turno(turnos);  // Obtener el turno actual

        // Comprobar si el turno corresponde al cliente y no ha sido realizado
        if (strcmp(get_idCliente(turno_actual), id_cliente) == 0 && !get_realizado(turno_actual))
        {
            return turno_actual;  // Retornar el turno si es el correcto y no realizado
        }

        forwards_turno(turnos);  // Mover al siguiente turno en la lista
    }

    // Si no se encontr� un turno no realizado, devolver un turno vac�o
    Turno turno_vacio = {};  // Turno vac�o
    return turno_vacio;
}



// Función para comparar dos fechas
int compararFechas(Fecha f1, Fecha f2)
{
    if (f1.anio != f2.anio) return f1.anio - f2.anio;
    if (f1.mes != f2.mes) return f1.mes - f2.mes;
    return f1.dia - f2.dia;  // Si las fechas son del mismo año y mes, se comparan por día
}

// Función para mostrar todos los turnos de un mes
void mostrarTurnosDeMes(lista_de_turno *turnos, int mes)
{
    resetL_turno(turnos);  // Inicializa el cursor de la lista
    int contador = 0;

    // Recorrer la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno turno_actual = copy_turno(turnos);

        // Si el turno es del mes especificado, lo mostramos
        if (get_mes(turno_actual.fecha) == mes)
        {
            printf("ID Turno: %d, Cliente: %s, Fecha: %02d/%02d/%d %d:00, Total: %.2f, Realizado: %s\n",
                   turno_actual.idTurno, turno_actual.nombre, turno_actual.fecha.dia, turno_actual.fecha.mes,
                   turno_actual.fecha.anio, turno_actual.fecha.hora, turno_actual.total,
                   turno_actual.realizado == 1 ? "Sí" : "No");
            contador++;
        }

        forwards_turno(turnos);  // Mueve al siguiente turno
    }

    // Si no se encontraron turnos para el mes
    if (contador == 0)
    {
        printf("No hay turnos para el mes %d.\n", mes);
    }
}


// Funci�n para buscar turnos por nombre de cliente y paginar la muestra de los resultados
void buscarYMostrarTurnosPorCliente(lista_de_turno *turnos, const char *nombreCliente)
{
    resetL_turno(turnos);  // Inicializa el cursor de la lista
    Turno turnos_cliente[MAX_TURNOS];  // Suponiendo un n�mero m�ximo de turnos a almacenar
    int contador = 0;

    // Buscar los turnos que coinciden con el nombre del cliente
    while (!is_Oos_turno(*turnos))
    {
        Turno turno_actual = copy_turno(turnos);
        if (strcmp(get_nombre_T(turno_actual), nombreCliente) == 0)
        {
            turnos_cliente[contador++] = turno_actual;
        }
        forwards_turno(turnos);  // Mueve al siguiente turno
    }

    // Si no se encuentran turnos para el cliente
    if (contador == 0)
    {
        printf("No se encontraron turnos para el cliente: %s\n", nombreCliente);
        return;
    }

    // Paginaci�n: mostrar los turnos de 3 en 3
    int pagina = 1;
    int turnosPorPagina = 3;
    int totalPaginas = (contador + turnosPorPagina - 1) / turnosPorPagina;  // Redondeo hacia arriba

    while (1)
    {
        int inicio = (pagina - 1) * turnosPorPagina;
        int fin = (pagina * turnosPorPagina < contador) ? pagina * turnosPorPagina : contador;

        printf("\nP�gina %d de %d:\n", pagina, totalPaginas);

        // Mostrar los turnos de la p�gina actual
        for (int i = inicio; i < fin; i++)
        {
            Turno t = turnos_cliente[i];
            printf("ID Turno: %d, Cliente: %s, Fecha: %02d/%02d/%d %d:00, Total: %.2f, Realizado: %s\n",
                   t.idTurno, t.nombre, t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora,
                   t.total, t.realizado == 1 ? "S�" : "No");
        }

        // Preguntar si el usuario quiere ver la siguiente p�gina
        if (pagina < totalPaginas)
        {
            printf("\n�Desea ver la siguiente p�gina? (s/n): ");
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

    // Recorremos la lista de turnos y mostramos cada uno
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual
        printf("ID Turno: %d, Cliente: %s, Fecha: %02d/%02d/%d %d:00, Total: %.2f, Realizado: %s\n",
               t.idTurno, t.nombre, t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora,
               t.total, t.realizado == 1 ? "Sí" : "No");
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }
}
// Función para seleccionar los tratamientos para el turno
void seleccionarTratamientos(int tratamientosSeleccionados[3])
{
    int cantidadTratamientosSeleccionados = 0;
    int tratamientoSeleccionado = 0;
    float Total = 0;

    printf("Seleccione hasta 3 tratamientos para el turno (0 para terminar):\n");
    for (int i = 0; i < MAX_TRATAMIENTOS; i++)
    {
        printf("%d. %s - $%.2f\n", i + 1, tratamientos_D[i].nombre_T, tratamientos_D[i].precio_T);
    }

    while (cantidadTratamientosSeleccionados < 3)
    {
        printf("Ingrese el número del tratamiento (0 para terminar): ");
        scanf("%d", &tratamientoSeleccionado);

        if (tratamientoSeleccionado == 0)
        {
            break;
        }

        if (tratamientoSeleccionado > 0 && tratamientoSeleccionado <= MAX_TRATAMIENTOS)
        {
            if (tratamientosSeleccionados[tratamientoSeleccionado - 1] == 0)
            {
                tratamientosSeleccionados[tratamientoSeleccionado - 1] = 1;
                cantidadTratamientosSeleccionados++;
                Total += tratamientos_D[tratamientoSeleccionado - 1].precio_T;
                printf("Tratamiento agregado: %s\n", tratamientos_D[tratamientoSeleccionado - 1].nombre_T);
            }
            else
            {
                printf("Este tratamiento ya ha sido seleccionado.\n");
            }
        }
        else
        {
            printf("Número de tratamiento inválido. Intente nuevamente.\n");
        }
    }

    printf("Total de los tratamientos seleccionados: $%.2f\n", Total);
}

// Función para modificar los tratamientos de un cliente según su idCliente
void modificarTratamientos(lista_de_turno *turnos, char* idCliente, int nuevosTratamientos[3])
{
    for (int i = 0; i <= turnos->ultimo; i++)
    {
        if (strcmp(turnos->turnos[i].id_cliente, idCliente) == 0)
        {
            printf("Modificando tratamientos para el cliente %s %s (ID: %s)\n",
                   turnos->turnos[i].nombre, turnos->turnos[i].apellido, idCliente);

            // Actualizamos los tratamientos
            for (int j = 0; j < 3; j++)
            {
                turnos->turnos[i].tratamientos[j] = nuevosTratamientos[j];
            }

            // Calcular el nuevo total
            float nuevoTotal = 0;
            for (int j = 0; j < 3; j++)
            {
                if (turnos->turnos[i].tratamientos[j] != 0)
                {
                    nuevoTotal += tratamientos_D[turnos->turnos[i].tratamientos[j] - 1].precio_T;
                }
            }

            turnos->turnos[i].total = nuevoTotal;
            printf("Tratamientos modificados con éxito. Nuevo total: %.2f\n", nuevoTotal);
            return;
        }
    }
    printf("Cliente con ID %s no encontrado.\n", idCliente);
}
// Función para modificar la forma de pago de un turno solicitado según su idCliente (solo si el turno no está realizado)
void modificarFormaPago(lista_de_turno *turnos, char *idCliente, int nuevaFormaPago)
{
    resetL_turno(turnos);  // Inicializamos los cursores de la lista

    // Recorremos la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual

        // Si el turno pertenece al cliente con el id proporcionado y no está realizado
        if (strcmp(t.idCliente, idCliente) == 0 && get_realizado(t) == 0)
        {
            setFormaPago(&t, nuevaFormaPago);  // Modificamos la forma de pago
            printf("Forma de pago actualizada para el cliente %s:\n", t.idCliente);
            printf("ID Turno: %d, Nombre: %s, Forma de Pago: %s\n", t.idTurno, t.nombre, get_formaPago(t));
            return;  // Terminamos la búsqueda y modificación
        }
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    printf("No se encontró un turno no realizado para el cliente con ID: %s\n", idCliente);
}
// Función para cancelar un turno por idCliente
void cancelarTurno(lista_de_turno *turnos, char *idCliente)
{
    resetL_turno(turnos);  // Inicializamos los cursores de la lista
    FILE *archivo = fopen("turnos_cancelados.txt", "a");  // Archivo donde guardamos los turnos cancelados
    if (!archivo)
    {
        printf("Error al abrir el archivo de cancelaciones.\n");
        return;
    }

    // Recorremos la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual

        // Si encontramos el turno correspondiente al idCliente y no está realizado
        if (strcmp(t.idCliente, idCliente) == 0 && get_realizado(t) == 0)
        {
            // Solicitar confirmación antes de eliminarlo
            char confirmacion;
            printf("¿Está seguro que desea cancelar el turno del cliente %s (ID Cliente: %s)? (s/n): ", t.nombre, t.idCliente);
            scanf(" %c", &confirmacion);  // Leer la respuesta del usuario

            if (confirmacion == 's' || confirmacion == 'S')
            {
                // Copiar los datos del turno en el archivo antes de borrarlo
                fprintf(archivo, "ID Turno: %d\n", t.idTurno);
                fprintf(archivo, "Nombre: %s\n", t.nombre);
                fprintf(archivo, "ID Cliente: %s\n", t.idCliente);
                fprintf(archivo, "Tratamientos: ");
                for (int i = 0; i < MAX_TRATAMIENTOS; i++)
                {
                    if (t.tratamientos[i] != 0)    // Solo mostrar los tratamientos que existen
                    {
                        fprintf(archivo, "%d ", t.tratamientos[i]);
                    }
                }
                fprintf(archivo, "\nForma de Pago: %s\n", get_formaPago(t));
                fprintf(archivo, "Total: %.2f\n", t.total);
                fprintf(archivo, "Fecha: %02d/%02d/%d %02d:00\n", t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora);
                fprintf(archivo, "Realizado: %d\n", t.realizado);
                fprintf(archivo, "---------------------------------------\n");

                // Ahora eliminamos el turno de la lista
                suppress_turno(turnos);  // Eliminar el turno de la lista de turnos

                printf("Turno cancelado y datos guardados en el archivo.\n");

                // Aquí deberías actualizar los tratamientos del cliente (esto depende de tu implementación)
                // Esta parte puede requerir más detalles para actualizar los datos del cliente.
                return;  // Terminamos la función, ya que hemos cancelado el turno
            }
            else
            {
                printf("Cancelación del turno cancelada.\n");
                return;  // Si el usuario no confirma, no se cancela el turno
            }
        }
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    printf("No se encontró un turno no realizado para el cliente con ID: %s\n", idCliente);
    fclose(archivo);  // Cerrar el archivo
}
// Función para almacenar los turnos pagados según la forma de pago
void almacenarTurnosPagados(lista_de_turno *turnos, int formaPago)
{
    FILE *archivo = fopen("turnos_pagados.txt", "w");  // Archivo donde guardamos los turnos pagados
    if (!archivo)
    {
        printf("Error al abrir el archivo para almacenar los turnos pagados.\n");
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
            fprintf(archivo, "---------------------------------------\n");

            contador++;  // Incrementamos el contador de turnos copiados
        }
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    printf("Se copiaron %d turnos con la forma de pago seleccionada al archivo 'turnos_pagados.txt'.\n", contador);

    fclose(archivo);  // Cerrar el archivo
}
// Función para mostrar los turnos de un tratamiento
void mostrarTurnosPorTratamiento(lista_de_turno *turnos, int tratamiento_id)
{
    resetL_turno(turnos);  // Inicializamos los cursores de la lista

    int encontrado = 0;  // Variable para verificar si se encontraron turnos

    // Recorremos la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno t = copy_turno(turnos);  // Obtenemos el turno actual

        // Verificamos si el turno tiene el tratamiento solicitado
        for (int i = 0; i < MAX_TRATAMIENTOS; i++)
        {
            if (t.tratamientos[i] == tratamiento_id)
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
                break;  // Si encontramos el tratamiento, ya no seguimos buscando en este turno
            }
        }
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    if (!encontrado)
    {
        printf("No se encontraron turnos para el tratamiento con ID: %d\n", tratamiento_id);
    }
}
// Función para precargar clientes desde un archivo
void precargarClientesDesdeArchivo(lista_de_clientes *clientes)
{
    FILE *archivo = fopen("clientes.txt", "r");  // Abrimos el archivo de clientes
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo de clientes.\n");
        return;
    }

    char id_cliente[9];
    char nombre[20];
    char apellido[20];
    int canttratamientos;
    int nivel;
    Cliente c;

    while (fscanf(archivo, "%s %s %s %d %d", id_cliente, nombre, apellido, &canttratamientos, &nivel) == 5)
    {
        // Asignamos los valores leídos a un nuevo cliente
        set_id_cliente(&c, id_cliente);
        set_nombre_cliente(&c, nombre);
        set_apellido_cliente(&c, apellido);
        set_canttratamientos_cliente(&c, canttratamientos);
        set_nivel_cliente(&c, nivel);

        // Insertamos el cliente en la lista
        insert_cliente(clientes, c);
    }

    fclose(archivo);  // Cerramos el archivo

    printf("Clientes precargados desde el archivo 'clientes.txt'.\n");
}
// Función para modificar el turno a confirmado por id_cliente
void modificarTurnoConfirmado(lista_de_turno *lt, lista_de_clientes *lc, char *id_cliente)
{
    int turnoEncontrado = 0;

    // Recorrer la lista de turnos para encontrar el turno correspondiente al cliente
    for (int i = 0; i <= lt->ultimo; i++)
    {
        Turno t = lt->vipd[i];

        // Si encontramos un turno con el idCliente que coincide
        if (strcmp(t.idCliente, id_cliente) == 0)
        {
            // Marcar el turno como realizado (confirmado)
            setRealizado(&t, 1);  // 1 significa que el turno ha sido realizado (confirmado)

            // Buscar al cliente en la lista de clientes para actualizar su cantidad de tratamientos
            for (int j = 0; j <= lc->ultimo; j++)
            {
                Cliente c = lc->vipd[j];

                // Si encontramos el cliente por su id_cliente
                if (strcmp(c.id_cliente, id_cliente) == 0)
                {
                    // Aumentar la cantidad de tratamientos
                    set_canttratamientos_cliente(&c, 1); // Aumentamos un tratamiento más
                    // Actualizar el nivel del cliente según la cantidad de tratamientos
                    set_nivel_cliente(&c, c.canttratamientos);
                    printf("El cliente %s ha asistido y su turno ha sido confirmado.\n", c.nombre);
                    turnoEncontrado = 1;
                    break;
                }
            }

            // Actualizamos el turno en la lista
            lt->vipd[i] = t;

            if (turnoEncontrado)
            {
                return;  // Salimos de la función si el cliente fue encontrado y actualizado
            }
        }
    }

    if (!turnoEncontrado)
    {
        printf("No se encontró un turno para el cliente con ID: %s.\n", id_cliente);
    }
}
// Función para mostrar los turnos no realizados
void mostrarTurnosNoRealizados(lista_de_turno lt)
{
    int encontrados = 0;

    // Recorrer la lista de turnos
    for (int i = 0; i <= lt.ultimo; i++)
    {
        Turno t = lt.vipd[i];

        // Verificar si el turno no ha sido realizado
        if (t.realizado == 0)
        {
            printf("ID Turno: %d\n", t.idTurno);
            printf("Cliente: %s %s\n", t.nombre, t.apellido);
            printf("Fecha: %02d/%02d/%d %02d:00\n", t.fecha.dia, t.fecha.mes, t.fecha.anio, t.fecha.hora);
            printf("Total: %.2f\n", t.total);
            printf("Forma de Pago: %s\n", get_formaPago(t));
            printf("\n");
            encontrados++;
        }
    }

    // Si no se encontraron turnos no realizados
    if (encontrados == 0)
    {
        printf("No hay turnos no realizados.\n");
    }
}
/*
// Función para eliminar un cliente según su id_cliente
void eliminarClientePorId(lista_de_clientes *l, char *id_cliente) {
    int encontrado = 0;

    // Recorremos la lista de clientes para encontrar al cliente
    for (int i = 0; i <= l->ultimo; i++) {
        if (strcmp(l->vipd[i].id_cliente, id_cliente) == 0) {
            // Cliente encontrado, se elimina
            for (int j = i; j < l->ultimo; j++) {
                l->vipd[j] = l->vipd[j + 1]; // Desplazamos los clientes hacia la izquierda
            }
            l->ultimo--;  // Reducimos el contador de clientes
            encontrado = 1;
            printf("Cliente con ID %s eliminado correctamente.\n", id_cliente);
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente con ID %s no encontrado.\n", id_cliente);
    }
}
/ Función para mostrar todos los clientes almacenados en la lista
void mostrarTodosLosClientes(lista_de_clientes l) {
    if (isempty_cliente(l)) {
        printf("No hay clientes almacenados.\n");
        return;
    }

    printf("Listado de clientes:\n");
    printf("ID Cliente    Nombre    Apellido     Tratamientos  Nivel\n");
    for (int i = 0; i <= l.ultimo; i++) {
        Cliente c = l.vipd[i];
        printf("%s    %s    %s    %d    %d\n",
               c.id_cliente, c.nombre, c.apellido,
               c.canttratamientos, c.nivel);
    }
}
//Funcion para mostrar un turno
void mostrar_turno(Turno t)
{
    char *nombre = get_nombre_T(t);
    int idTurno = get_idTurno(t);
    char *idCliente = get_idCliente(t);
    int *tratamientos = get_tratamientos(t);
    const char *formaPago = get_formaPago(t);
    float total = get_total(t);
    Fecha fecha = get_fecha(t);
    int realizado = get_realizado(t);

    printf("ID Turno: %d\n", idTurno);
    printf("Nombre: %s\n", nombre);
    printf("ID Cliente: %s\n", idCliente);
    printf("Tratamientos: ");
    for (int i = 0; i < MAX_TRATAMIENTOS; i++)
    {
        if (tratamientos[i] != 0)
        {
            printf("%d ", tratamientos[i]);
        }
    }
    printf("\nForma de Pago: %s\n", formaPago);
    printf("Total: %.2f\n", total);
    printf("Fecha: %02d/%02d/%d Hora: %02d:00\n", get_dia(fecha), get_mes(fecha), get_anio(fecha), get_hora(fecha));
    printf("Realizado: %s\n", realizado ? "S�" : "No");

    // Liberar la memoria reservada
    free(nombre);
    free(tratamientos);
}
*/
// Funci�n para registrar un nuevo cliente en la lista
void registrarCliente(lista_de_clientes *clientes)
{
    if (isfull_cliente(*clientes))
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
    set_nombre_cliente(&nuevoCliente, nombre);

    // Solicita y asigna el apellido del cliente
    printf("Ingrese el apellido del cliente: ");
    scanf("%s", apellido);
    set_apellido_cliente(&nuevoCliente, apellido);

    // Inicializa canttratamientos y nivel
    inittratamientos_cliente(&nuevoCliente);  // canttratamientos a 0
    set_nivel_cliente(&nuevoCliente, 0); // nivel a 0

    insert_cliente(clientes, nuevoCliente);
    printf("Cliente registrado exitosamente.\n");
}


// Funci�n para buscar un cliente en la lista y mostrar sus datos
void buscarCliente(lista_de_clientes clientes)
{
    char id_cliente[9];
    printf("Ingrese el ID del cliente a buscar: ");
    scanf("%s", id_cliente);

    for (int i = 0; i <= clientes.ultimo; i++)
    {
        // Usa la funci�n coppy_cliente() para obtener el cliente en la posici�n i
        Cliente cliente_actual = coppy_cliente(clientes);

        // Usa get_id_cliente() para obtener el id_cliente del cliente actual
        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0)
        {
            printf("Cliente encontrado:\n");
            printf("ID: %s\n", get_id_cliente(cliente_actual));
            printf("Nombre: %s\n", get_nombre_cliente(cliente_actual));
            printf("Apellido: %s\n", get_apellido_cliente(cliente_actual));
            printf("Cantidad de tratamientos: %d\n", get_canttratamientos_cliente(cliente_actual));
            printf("Nivel: %d\n", get_nivel_cliente(cliente_actual));
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}


// Funci�n para eliminar un cliente de la lista
void eliminarCliente(lista_de_clientes *clientes)
{
    if (isempty_cliente(*clientes))
    {
        printf("La lista de clientes est� vacia.\n");
        return;
    }

    char id_cliente[9];
    printf("Ingrese el ID del cliente a eliminar: ");
    scanf("%s", id_cliente);

    // Recorre la lista de clientes utilizando las funciones de la lista
    for (int i = 0; i <= clientes->ultimo; i++)
    {
        Cliente cliente_actual = coppy_cliente(*clientes);

        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0)
        {
            for (int j = 0; j < i; j++)
            {
                forwards_cliente(clientes);
            }

            supress_cliente(clientes); // Eliminar el cliente de la lista
            printf("Cliente eliminado exitosamente.\n");
            return;
        }
    }

    printf("Cliente no encontrado.\n");
}


/*//Funcion para confirmar asistencia a un turno
void confirmarAsistenciaTurno(lista_de_turno *listaTurnos, int idTurno) {
    // Verificar si la lista de turnos est� vac�a
    if (is_emptys_turno(listaTurnos)) {
        printf("La lista de turnos est� vac�a.\n");
        return;
    }

    resetL_turno(listaTurnos); // Reinicia el cursor al inicio de la lista de turnos

    while (!is_Oos_turno(*listaTurnos)) { // Itera hasta llegar al final de la lista
        Turno turno = copy_turno(listaTurnos); // Obtiene el turno actual

        // Si encontramos el turno con el id correspondiente
        if (get_idTurno(turno) == idTurno) {
            marcarRealizado(&turno); // Marca el turno como realizado

            // Actualiza el turno modificado en la lista (reemplaza el valor en la posici�n actual)
            insertL_turno(listaTurnos, turno);

            printf("Asistencia confirmada para el turno ID %d.\n", idTurno);

            // Mostrar detalles del turno actualizado:
            printf("ID: %d\n", get_idTurno(turno)); // Mostrar el ID del turno
            printf("Nombre del Cliente: %s\n", get_nombre(cliente)); // Mostrar el nombre del cliente (ajustar seg�n tu implementaci�n)
            printf("Fecha: %s\n", get_fechaTurno(turno)); // Mostrar la fecha del turno (ajustar seg�n tu implementaci�n)
            printf("-------------------------\n");

            return;
        }

        forwards_turno(listaTurnos); // Avanza al siguiente turno
    }

    printf("Turno con ID %d no encontrado.\n", idTurno); // Si no se encuentra el turno
}*/

//Funcion para mostrar los turnos que no han sido realizados
void mostrarTurnosNoRealizados(lista_de_turno *lista)
{
    resetL_turno(lista);
    while (!is_Oos_turno(*lista))
    {
        Turno turno = copy_turno(lista);
        if (!get_realizado(turno))
        {
            mostrar_turno(turno);
        }
        forwards_turno(lista);
    }
}

//Funcion que muestra todos los clientes almacenados en la lista de clientes:
void mostrarTodosLosClientes(lista_de_clientes *lista)
{
    // Verificar si la lista de clientes est� vac�a
    if (isempty_cliente(*lista))
    {
        printf("No hay clientes almacenados.\n");
        return;
    }

    reset_cliente(lista); // Reinicia el cursor al inicio de la lista
    printf("Lista de Clientes:\n");

    while (!isOos_cliente(*lista))   // Itera hasta que el cursor est� fuera de los l�mites
    {
        Cliente cliente = coppy_cliente(*lista); // Obtiene una copia del cliente actual

        printf("ID del Cliente: %s\n", cliente.id_cliente); // Mostrar ID del cliente
        printf("Nombre: %s\n", cliente.nombre); // Mostrar nombre del cliente
        printf("Apellido: %s\n", cliente.apellido); // Mostrar apellido del cliente
        printf("Cantidad de tratamientos: %d\n", cliente.canttratamientos); // Mostrar cantidad de tratamientos
        printf("Nivel: %d\n", cliente.nivel); // Mostrar nivel del cliente
        printf("-------------------------\n");

        forwards_cliente(lista); // Avanza al siguiente elemento
    }
}

// Funcion principal
int main()
{
    lista_de_turno turno;
    lista_de_clientes clientes;
    init_cliente(&clientes);
    init_turno(&turno);
    Turno miturno;
    int mes;
    char nombre[20];
    char clienteid[9];

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
                    registrarTurno(&turno,&clientes);
                    break;
                case 2:
                    printf("Mostrar todo los turnos\n");
                    mostrarTodosLosTurnos(&turno);
                    break;
                case 3:
                    printf("Mostrar todos los turnos de un mes.\n");
                    printf("Ingrese el mes a buscar(11-12) \n");
                    scanf("%d",&mes);
                    mostrarTurnosDeMes(&turno,mes);
                    break;
                case 4:
                    printf("Mostrar turnos por nombre de cliente.\n");
                    printf("Ingrese el Nombre a Buscar \n");
                    scanf("%s",nombre);
                    buscarTurnoPorIdCliente(&turno,nombre);
                    break;
                case 5:
                    printf("Modificar cantidad de tratamientos.\n");
                    printf("Ingrese el ID del cliente a cambiar tratamientos. \n");
                    scanf("%s",clienteid);
                    // Selección de tratamientos para el cliente 1
                    int tratamientosSeleccionados[3] = {0};  // Array para almacenar los tratamientos seleccionados
                    seleccionarTratamientos(tratamientosSeleccionados);

                    // Modificar los tratamientos del cliente
                    modificarTratamientos(&turnos, clienteid, tratamientosSeleccionados);

                    // Mostrar los turnos después de modificar
                    printf("\nTurnos después de modificar:\n");
                    resetL_turno(&turnos);
                    while (!is_Oos_turno(turnos))
                    {
                        Turno turno = copy_turno(&turnos);
                        printf("ID Cliente: %s, Nombre: %s %s, Tratamientos: ",
                               turno.id_cliente, turno.nombre, turno.apellido);
                        for (int i = 0; i < 3; i++)
                        {
                            if (turno.tratamientos[i] != 0)
                            {
                                printf("%s ", tratamientos_D[turno.tratamientos[i] - 1].nombre_T);
                            }
                        }
                        printf(", Total: %.2f\n", turno.total);
                        forwards_turno(&turnos);
                    }
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
                    mostrarTodosLosClientes(&clientes);
                    break;
                case 0:
                    printf("Volviendo al menu principal...\n");
                    break;
                default:
                    printf("Opci�n inv�lida. Intente nuevamente.\n");
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
