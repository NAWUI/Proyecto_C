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
    char idTemporal[11];  // Temporal para capturar hasta 10 caracteres
    do {
        idValido = 1;
        printf("Ingrese el ID del cliente para registrar el turno (solo números, máximo 8 caracteres): ");
        scanf("%10s", idTemporal); // Limita la entrada a 10 caracteres

        // Verifica si supera el límite de 8 caracteres
        if (strlen(idTemporal) > 8) {
            printf("Error: El ID no puede superar los 8 caracteres.\n");
            idValido = 0;
        }

        // Verifica si todos los caracteres son números
        for (int j = 0; j < strlen(idTemporal); j++) {
            if (!isdigit(idTemporal[j])) {
                printf("Error: El ID debe contener solo números.\n");
                idValido = 0;
                break;
            }
        }

        // Copia solo los primeros 8 caracteres en id_cliente si el ID es válido
        if (idValido) {
            strncpy(id_cliente, idTemporal, 8);
            id_cliente[8] = '\0';  // Asegura que la cadena está terminada en NULL
        }
    } while (!idValido);

    // Buscar si el cliente ya está registrado
    reset_cliente(clientes);
    while (!isOos_cliente(*clientes)) {
        cliente_actual = coppy_cliente(*clientes);
        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0) {
            clienteEncontrado = 1;
            break;
        }
        forwards_cliente(clientes);
    }

    // Si no encuentra el cliente, procede a registrarlo
    if (!clienteEncontrado) {
        printf("Cliente no encontrado. Procediendo a registrar nuevo cliente.\n");
        registrarCliente(clientes);
        reset_cliente(clientes);
        while (!isOos_cliente(*clientes)) {
            cliente_actual = coppy_cliente(*clientes);
            if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0) {
                clienteEncontrado = 1;
                break;
            }
            forwards_cliente(clientes);
        }
    }

    if (!clienteEncontrado) {
        printf("Error: No se pudo registrar el turno.\n");
        return;
    }

    setIdCliente(&nuevoTurno, get_id_cliente(cliente_actual));
    nivelCliente = get_nivel_cliente(cliente_actual);
    setNombre(&nuevoTurno, get_nombre_cliente(cliente_actual));
    printf("Cliente encontrado: %s %s\n", get_nombre_cliente(cliente_actual), get_apellido_cliente(cliente_actual));
    setIdTurno(&nuevoTurno, generarIdTurno());

    printf("Seleccione hasta 3 tratamientos para el turno (0 para terminar):\n");
    for (i = 0; i < MAX_TRATAMIENTOS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tratamientos_D[i].nombre_T, tratamientos_D[i].precio_T);
    }

    int tratamientos[MAX_TRATAMIENTOS] = {0};
    do {
        if (cantidadTratamientosSeleccionados >= 3) {
            printf("Se ha alcanzado el limite de 3 tratamientos por turno.\n");
            break;
        }

        printf("Ingrese el numero del tratamiento: ");
        scanf("%d", &tratamientoSeleccionado);

        if (tratamientoSeleccionado > 0 && tratamientoSeleccionado <= MAX_TRATAMIENTOS) {
            if (tratamientos[tratamientoSeleccionado - 1] == 0) {
                tratamientos[tratamientoSeleccionado - 1] = 1;
                cantidadTratamientosSeleccionados++;
                Total += tratamientos_D[tratamientoSeleccionado - 1].precio_T;
                printf("Tratamiento agregado: %s\n", tratamientos_D[tratamientoSeleccionado - 1].nombre_T);
            } else {
                printf("Este tratamiento ya ha sido seleccionado.\n");
            }
        } else if (tratamientoSeleccionado != 0) {
            printf("Numero de tratamiento invalido. Intente nuevamente.\n");
        }
    } while (tratamientoSeleccionado != 0);

    setTratamiento(&nuevoTurno, tratamientos);
    setTotal(&nuevoTurno, Total, nivelCliente);

    Fecha fechaTurno;
    do {
        printf("Ingrese la fecha del turno (dia mes año hora): ");
        scanf("%d %d %d %d", &fechaTurno.dia, &fechaTurno.mes, &fechaTurno.anio, &fechaTurno.hora);
        if (!validarFecha(fechaTurno)) {
            printf("Fecha no valida. Por favor ingrese una fecha dentro del horario de atencion (lunes a sabado, 9 a 20 hs).\n");
        }
    } while (!validarFecha(fechaTurno));

    // Verificar si existe ya un turno en la misma fecha y hora para el cliente
    int colisionFecha = 0;
    resetL_turno(turnos);
    while (!is_Oos_turno(*turnos)) {
        Turno turnoExistente = copy_turno(turnos);
        if (strcmp(get_idCliente(turnoExistente), id_cliente) == 0) {
            Fecha fechaExistente = get_fecha(turnoExistente);
            if (fechaExistente.dia == fechaTurno.dia &&
                fechaExistente.mes == fechaTurno.mes &&
                fechaExistente.anio == fechaTurno.anio &&
                fechaExistente.hora == fechaTurno.hora) {
                colisionFecha = 1;
                break;
            }
        }
        forwards_turno(turnos);
    }

    if (colisionFecha) {
        printf("Error: Ya existe un turno registrado para este cliente en la misma fecha y hora.\n");
        return;
    }

    setFecha(&nuevoTurno, fechaTurno);
    printf("Total sin descuento: %.2f\n", Total);

    // Aplicar el descuento según el nivel del cliente y mostrar el total a pagar
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

    // Seleccionar la forma de pago
    int formaPago;
    do {
        printf("Seleccione la forma de pago:\n");
        printf("1. Debito\n");
        printf("2. Credito\n");
        printf("3. Efectivo\n");
        printf("4. QR\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &formaPago);
    } while (formaPago < 1 || formaPago > 4);
    setFormaPago(&nuevoTurno, formaPago);

    // Confirmar turno
    printf("Confirmar turno? (1 = Si, 0 = No): ");
    scanf("%d", &confirmar);
    if (confirmar) {
        insertL_turno(turnos, nuevoTurno);
        printf("Turno registrado con exito.\n");
    } else {
        printf("Turno cancelado.\n");
    }
}

//Funcion para buscar turno por idcliente:
Turno buscarTurnoPorIdCliente(lista_de_turno *turnos, char *id_cliente)
{
    resetL_turno(turnos);  // Inicializa los cursores

    // Recorre la lista de turnos
    while (!is_Oos_turno(*turnos))
    {
        Turno turno_actual = copy_turno(turnos);  // Obtiene el turno actual

        // Comprueba si el turno corresponde al cliente y no ha sido realizado
        if (strcmp(get_idCliente(turno_actual), id_cliente) == 0 && !get_realizado(turno_actual))
        {
            return turno_actual;  // Retorna el turno si es el correcto y no realizado
        }

        forwards_turno(turnos);  // Mueve al siguiente turno en la lista
    }

    // Si no se encontro  un turno no realizado, devuelve un  turno vacio
    Turno turno_vacio = {};  // Turno vacio
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

    // Recorre la lista de turnos
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
            // Si coincide el nombre del cliente, mostrar el turno
            printf("ID Turno: %d, Cliente: %s, Fecha: %02d/%02d/%d %d:00, Total: %.2f, Realizado: %s\n",
                   turno_actual.idTurno, turno_actual.nombre, turno_actual.fecha.dia,
                   turno_actual.fecha.mes, turno_actual.fecha.anio, turno_actual.fecha.hora,
                   turno_actual.total, turno_actual.realizado == 1 ? "Sí" : "No");

            contador++;
        }
        forwards_turno(&turnos);  // Mueve al siguiente turno
    }

    // Si no se encuentran turnos para el cliente
    if (contador == 0)
    {
        printf("No se encontraron turnos para el cliente: %s\n", nombreCliente);
        return;
    }

    // Paginación: mostrar los turnos de 3 en 3
    int pagina = 1;
    int turnosPorPagina = 3;
    int totalPaginas = (contador + turnosPorPagina - 1) / turnosPorPagina;  // Redondeo hacia arriba

    while (1)
    {
        int inicio = (pagina - 1) * turnosPorPagina;
        int fin = (pagina * turnosPorPagina < contador) ? pagina * turnosPorPagina : contador;

        printf("\nPágina %d de %d:\n", pagina, totalPaginas);

        // Mostrar los turnos de la página actual
        resetL_turno(&turnos);  // Restablecee el cursor de la lista
        for (int i = 0; i < inicio; i++)  // Avanza hasta el turno de inicio
        {
            forwards_turno(&turnos);
        }

        for (int i = inicio; i < fin; i++)
        {
            Turno turno_actual = copy_turno(&turnos);  // Obttiene el turno actual

            printf("ID Turno: %d, Cliente: %s, Fecha: %02d/%02d/%d %d:00, Total: %.2f, Realizado: %s\n",
                   turno_actual.idTurno, turno_actual.nombre, turno_actual.fecha.dia,
                   turno_actual.fecha.mes, turno_actual.fecha.anio, turno_actual.fecha.hora,
                   turno_actual.total, turno_actual.realizado == 1 ? "Sí" : "No");

            forwards_turno(&turnos);  // Mueve al siguiente turno
        }

        // Preguntar si el usuario quiere ver la siguiente página
        if (pagina < totalPaginas)
        {
            printf("\n¿Desea ver la siguiente página? (s/n): ");
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

// Función para mostrar los tratamientos disponibles
void mostrarTratamientos()
{
    printf("Tratamientos disponibles:\n");
    for (int i = 0; i < MAX_TRATAMIENTOS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tratamientos_D[i].nombre_T, tratamientos_D[i].precio_T);
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

//Funcion que modifica tratamientos segun idcliente
void modificarTratamientos(lista_de_turno *turnos, const char* idCliente, int nuevosTratamientos[3])
{
    resetL_turno(turnos);  // Iniciamos desde el primer nodo

    // Iteramos por la lista de turnos
    while (!is_Oos_turno(*turnos)) {  // Mientras no lleguemos al final de la lista
        // Obtenemos el turno actual
        Turno turno_actual = copy_turno(turnos);

        // Verificamos si el idCliente coincide
        if (strcmp(turno_actual.idCliente, idCliente) == 0) {
            printf("Modificando tratamientos para el cliente %s (ID: %s)\n", turno_actual.nombre, idCliente);

            // Actualizamos los tratamientos usando la función `setTratamiento`
            setTratamiento(&turno_actual, nuevosTratamientos);

            // Calcular el nuevo total
            float nuevoTotal = 0;
            for (int j = 0; j < 3; j++) {
                if (turno_actual.tratamientos[j] != 0) {
                    nuevoTotal += tratamientos_D[turno_actual.tratamientos[j] - 1].precio_T;
                }
            }

            // Actualizamos el total usando la función `setTotal`
            setTotal(&turno_actual, nuevoTotal, 0);  // Asumimos nivelCliente = 0 para no aplicar descuento

            // Guardamos los cambios en el nodo actual usando `insertL_turno`
            suppress_turno(turnos);  // Eliminamos el nodo actual
            insertL_turno(turnos, turno_actual);  // Insertamos el turno actualizado

            printf("Tratamientos modificados con éxito. Nuevo total: %.2f\n", nuevoTotal);
            return;
        }

        forwards_turno(turnos);  // Avanzamos al siguiente nodo de la lista
    }

    // Si no encontramos el cliente
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
    // Verificar si la lista de turnos está vacía
    if (is_emptys_turno(turnos))
    {
        printf("No hay turnos cargados en la lista.\n");
        return;
    }

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
            printf("¿Esta seguro que desea cancelar el turno del cliente %s (ID Cliente: %s)? (s/n): ", t.nombre, t.idCliente);
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
                fclose(archivo);  // Cerrar el archivo
                return;  // Terminamos la función, ya que hemos cancelado el turno
            }
            else
            {
                printf("Cancelacion del turno cancelada.\n");
                fclose(archivo);  // Cerrar el archivo
                return;  // Si el usuario no confirma, no se cancela el turno
            }
        }
        forwards_turno(turnos);  // Avanzamos al siguiente turno
    }

    printf("No se encontro un turno no realizado para el cliente con ID: %s\n", idCliente);
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
void modificarTurnoConfirmado(lista_de_turno *turno, lista_de_clientes *cliente, char *id_cliente)
{
    int turnoEncontrado = 0;

    // Reseteamos el cursor de la lista de turnos para empezar desde el principio
    resetL_turno(turno);

    // Recorre la lista de turnos para encontrar el turno correspondiente al cliente
    while (!is_Oos_turno(*turno)) {  // Mientras no lleguemos al final de la lista de turnos
        Turno t = copy_turno(turno);  // Obtener el turno del nodo actual

        // Si encontramos un turno con el id_cliente que coincide
        if (strcmp(t.idCliente, id_cliente) == 0) {
            // Marcar el turno como realizado (confirmado)
            setRealizado(&t, 1);  // 1 significa que el turno ha sido realizado (confirmado)

            // Buscar al cliente en la lista de clientes
            reset_cliente(cliente);  // Reseteamos el cursor de la lista de clientes
            while (!isOos_cliente(*cliente)) {  // Mientras no lleguemos al final de la lista de clientes
                Cliente c = coppy_cliente(*cliente);  // Obtener el cliente actual

                // Si encontramos el cliente por su id_cliente
                if (strcmp(c.id_cliente, id_cliente) == 0) {
                    // Aumentar la cantidad de tratamientos
                    set_canttratamientos_cliente(&c, 1);  // Aumentamos un tratamiento más

                    // Actualizar el nivel del cliente según la cantidad de tratamientos
                    set_nivel_cliente(&c, c.canttratamientos);
                    printf("El cliente %s ha asistido y su turno ha sido confirmado.\n", c.nombre);

                    // Actualizamos el cliente en la lista de clientes
                    insert_cliente(cliente, c);  // Insertamos al cliente actualizado

                    turnoEncontrado = 1;
                    break;
                }

                forwards_cliente(cliente);  // Avanzamos al siguiente cliente
            }

            // Actualizamos el turno en la lista de turnos
            suppress_turno(turno);  // Suprimir el turno actual
            insertL_turno(turno, t);  // Insertar el turno actualizado

            if (turnoEncontrado) {
                return;  // Salimos de la función si el cliente fue encontrado y actualizado
            }
        }

        forwards_turno(turno);  // Avanzamos al siguiente turno en la lista
    }

    if (!turnoEncontrado) {
        printf("No se encontró un turno para el cliente con ID: %s.\n", id_cliente);
    }
}

int existeCliente(lista_de_clientes clientes, char *id_cliente) {
    reset_cliente(&clientes);
    while (!isOos_cliente(clientes)) {
        Cliente actual = coppy_cliente(clientes);
        if (strcmp(get_id_cliente(actual), id_cliente) == 0) {
            return 1;  // Existe un cliente con el mismo ID
        }
        forwards_cliente(&clientes);
    }
    return 0;  // No existe un cliente con ese ID
}

int validarID(char *id_cliente) {
    // Verifica que sea numérico y no supere 8 caracteres
    if (strlen(id_cliente) > 8) {
        printf("Error: El ID no puede superar los 8 caracteres.\n");
        return 0;
    }
    for (int i = 0; i < strlen(id_cliente); i++) {
        if (!isdigit(id_cliente[i])) {
            printf("Error: El ID debe contener solo números.\n");
            return 0;
        }
    }
    return 1;
}

int validarNombreApellido(char *cadena) {
    // Verifica que solo contenga letras y espacios
    for (int i = 0; i < strlen(cadena); i++) {
        if (!isalpha(cadena[i]) && cadena[i] != ' ') {
            printf("Error: El nombre y apellido solo deben contener letras y espacios.\n");
            return 0;
        }
    }
    return 1;
}

void registrarCliente(lista_de_clientes *clientes) {
    if (isfull_cliente(*clientes)) {
        printf("Lista de clientes llena. No se pueden registrar más clientes.\n");
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
    do {
        idValido = 1;
        printf("Ingrese el ID del cliente (solo números, máximo 8 caracteres): ");
        scanf("%10s", idTemporal);

        if (strlen(idTemporal) > 8) {
            printf("Error: El ID no puede superar los 8 caracteres.\n");
            idValido = 0;
        }

        for (int j = 0; j < strlen(idTemporal); j++) {
            if (!isdigit(idTemporal[j])) {
                printf("Error: El ID debe contener solo números.\n");
                idValido = 0;
                break;
            }
        }

        if (idValido) {
            strncpy(id_cliente, idTemporal, 8);
            id_cliente[8] = '\0';
        }

        reset_cliente(clientes);
        while (!isOos_cliente(*clientes)) {
            Cliente actual = coppy_cliente(*clientes);
            if (strcmp(get_id_cliente(actual), id_cliente) == 0) {
                printf("Error: Ya existe un cliente con ese ID.\n");
                idValido = 0;
                break;
            }
            forwards_cliente(clientes);
        }
    } while (!idValido);
    set_id_cliente(&nuevoCliente, id_cliente);

    // Solicita y asigna el nombre del cliente con validación de caracteres
    do {
        nombreValido = 1;
        printf("Ingrese el nombre del cliente (solo letras y espacios): ");
        scanf(" %[^\n]%*c", nombreTemporal);

        for (int i = 0; i < strlen(nombreTemporal); i++) {
            if (!isalpha(nombreTemporal[i]) && nombreTemporal[i] != ' ') {
                printf("Error: El nombre solo debe contener letras y espacios.\n");
                nombreValido = 0;
                break;
            }
        }

        if (nombreValido) {
            strncpy(nombre, nombreTemporal, 19);
            nombre[19] = '\0';
        }
    } while (!nombreValido);
    set_nombre_cliente(&nuevoCliente, nombre);

    // Solicita y asigna el apellido del cliente con validación de caracteres
    do {
        apellidoValido = 1;
        printf("Ingrese el apellido del cliente (solo letras y espacios): ");
        scanf(" %[^\n]%*c", apellidoTemporal);

        for (int i = 0; i < strlen(apellidoTemporal); i++) {
            if (!isalpha(apellidoTemporal[i]) && apellidoTemporal[i] != ' ') {
                printf("Error: El apellido solo debe contener letras y espacios.\n");
                apellidoValido = 0;
                break;
            }
        }

        if (apellidoValido) {
            strncpy(apellido, apellidoTemporal, 19);
            apellido[19] = '\0';
        }
    } while (!apellidoValido);
    set_apellido_cliente(&nuevoCliente, apellido);

    // Inicializa canttratamientos y nivel
    inittratamientos_cliente(&nuevoCliente);  // canttratamientos a 0
    set_nivel_cliente(&nuevoCliente, 0);      // nivel a 0

    // Inserta el cliente en la lista
    insert_cliente(clientes, nuevoCliente);
    printf("Cliente registrado exitosamente.\n");
}

void buscarCliente(lista_de_clientes clientes) {
    if (isempty_cliente(clientes)) {
        printf("La lista de clientes está vacía. No hay clientes para buscar.\n");
        return;
    }
    printf("Posición actual del cursor: %d\n", clientes.cursor);
    if (!isOos_cliente(clientes)) {
        printf("El cursor no está en la última posición. No se puede realizar la búsqueda.\n");
        return;
    }

    char id_cliente[9];
    char idTemporal[11];
    int idValido;

    // Validación del ID del cliente ingresado
    do {
        idValido = 1;
        printf("Ingrese el ID del cliente a buscar (solo números, máximo 8 caracteres): ");
        scanf("%10s", idTemporal);

        if (strlen(idTemporal) > 8) {
            printf("Error: El ID no puede superar los 8 caracteres.\n");
            idValido = 0;
        }

        for (int j = 0; j < strlen(idTemporal); j++) {
            if (!isdigit(idTemporal[j])) {
                printf("Error: El ID debe contener solo números.\n");
                idValido = 0;
                break;
            }
        }

        if (idValido) {
            strncpy(id_cliente, idTemporal, 8);
            id_cliente[8] = '\0';
        }
    } while (!idValido);

    // Búsqueda del cliente en la lista
    for (int i = 0; i <= clientes.ultimo; i++) {
        Cliente cliente_actual = coppy_cliente(clientes);

        if (strcmp(get_id_cliente(cliente_actual), id_cliente) == 0) {
            printf("Cliente encontrado:\n");
            printf("ID: %s\n", get_id_cliente(cliente_actual));
            printf("Nombre: %s\n", get_nombre_cliente(cliente_actual));
            printf("Apellido: %s\n", get_apellido_cliente(cliente_actual));
            printf("Cantidad de tratamientos: %d\n", get_canttratamientos_cliente(cliente_actual));
            printf("Nivel: %d\n", get_nivel_cliente(cliente_actual));
            return;
        }

        forwards_cliente(&clientes);
    }

    printf("Cliente no encontrado.\n");
}


// Funcion para eliminar un cliente de la lista
void eliminarCliente(lista_de_clientes *clientes)
{
    if (isempty_cliente(*clientes))
    {
        printf("La lista de clientes esta vacia.\n");
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

//Funcion para confirmar asistencia a un turno
void confirmarAsistenciaTurno(lista_de_turno *listaTurnos, int idCliente, lista_de_clientes *listaCliente)
{
    // Verifica si la lista de turnos está vacía
    if (is_emptys_turno(listaTurnos)) {
        printf("La lista de turnos está vacía.\n");
        return;
    }

    resetL_turno(listaTurnos); // Reinicia el cursor al inicio de la lista de turnos

    while (!is_Oos_turno(*listaTurnos)) { // Itera hasta llegar al final de la lista
        Turno turno = copy_turno(listaTurnos); // Obtiene el turno actual

        // Si encontramos el turno con el id correspondiente
        if (get_idCliente(turno) == idCliente) {
            setRealizado(&turno, 1); // Marca el turno como realizado

            // Actualiza el turno modificado en la lista (reemplaza el valor en la posición actual)
            insertL_turno(listaTurnos, turno);

            printf("Asistencia confirmada para el cliente ID %d.\n", idCliente);

            // Mostrar detalles del turno actualizado:
            printf("ID: %s\n", get_idCliente(turno)); // Mostrar el ID del turno
            printf("Nombre del Cliente: %s\n", get_nombre_T(turno)); // Mostrar el nombre del cliente
            printf("Fecha: %s\n", get_fecha(turno)); // Mostrar la fecha del turno
            printf("-------------------------\n");

            // Ahora actualizamos la cantidad de tratamientos del cliente en la lista de clientes
            reset_cliente(listaCliente); // Reinicia el cursor de clientes

            // Buscar el cliente en la lista de clientes y actualizar su cantidad de tratamientos
            while (!isOos_cliente(*listaCliente)) {
                Cliente cliente = coppy_cliente(*listaCliente); // Obtener el cliente actual

                if (get_id_cliente(cliente) == idCliente) {
                    set_canttratamientos_cliente(&cliente, cliente.canttratamientos + 1); // Aumentar un tratamiento
                    set_nivel_cliente(&cliente, cliente.canttratamientos); // Actualizar nivel del cliente

                    // Actualizar el cliente en la lista
                    insert_cliente(listaCliente, cliente);
                    printf("El cliente %s ha asistido y su cantidad de tratamientos ha sido actualizada.\n", get_nombre_cliente(cliente));

                    return; // Salir después de actualizar el cliente
                }

                forwards_cliente(listaCliente); // Avanza al siguiente cliente
            }

            // Si no se encuentra el cliente en la lista
            printf("Cliente con ID %d no encontrado.\n", idCliente);
            return;
        }

        forwards_turno(listaTurnos); // Avanza al siguiente turno
    }

    printf("Turno con ID %d no encontrado.\n", idCliente); // Si no se encuentra el turno
}

// Función para mostrar los turnos no realizados
void mostrarTurnosNoRealizados(lista_de_turno *l)
{
    // Verificamos si la lista de turnos está vacía
    if (is_emptys_turno(l)) {
        printf("La lista de turnos está vacía.\n");
        return;
    }

    resetL_turno(l); // Reinicia el cursor al inicio de la lista

    int encontrado = 0;

    // Recorremos la lista de turnos hasta el final
    while (!is_Oos_turno(*l)) {
        Turno turno = copy_turno(l);  // Obtenemos el turno actual

        // Si el turno no ha sido realizado (estado realizado es 0)
        if (get_realizado(turno) == 0) {
            // Mostramos los detalles del turno no realizado
            printf("ID del turno: %d\n", get_idTurno(turno));
            printf("Nombre del cliente: %s\n", get_nombre_T(turno));  // Nombre del cliente
            printf("Fecha del turno: %02d/%02d/%04d a las %02d:00\n",
                   get_dia(turno.fecha), get_mes(turno.fecha), get_anio(turno.fecha), get_hora(turno.fecha));
            printf("Forma de pago: %s\n", get_formaPago(turno));
            printf("Total: %.2f\n", get_total(turno));
            printf("----------\n");
            encontrado = 1;
        }

        forwards_turno(l); // Avanza al siguiente turno
    }

    // Si no se encontró ningún turno no realizado
    if (!encontrado) {
        printf("No hay turnos no realizados.\n");
    }
}

//Funcion que muestra todos los clientes almacenados en la lista de clientes:
void mostrarTodosLosClientes(lista_de_clientes *lista)
{
    // Verificar si la lista de clientes est  vac a
    if (isempty_cliente(*lista))
    {
        printf("No hay clientes almacenados.\n");
        return;
    }

    reset_cliente(lista); // Reinicia el cursor al inicio de la lista
    printf("Lista de Clientes:\n");

    while (!isOos_cliente(*lista))   // Itera hasta que el cursor est  fuera de los l mites
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

//Funcion recursiva que calcula la ganancia mensual segun un mes pasado por parametro
float funcrec_gananciam(lista_de_turno *lista, float ganancia, int mes, Turno turno_actual)
{
    // Si la lista está vacía o el cursor está fuera de la lista
    if (is_Oos_turno(*lista)) {
        return ganancia;
    }

    // Verifica si el mes coincide y si el turno fue realizado
    if (get_mes(turno_actual.fecha) == mes && get_realizado(turno_actual) == 1) {
        // Acumula la ganancia del turno actual
        ganancia += get_total(turno_actual);
    }

    // Avanza el cursor al siguiente elemento en la lista
    forwards_turno(lista);

    // Llamada recursiva
    return funcrec_gananciam(lista, ganancia, mes, turno_actual);
}

//Mostrar los turnos solicitados por un cliente según idcliente (recursiva)

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
                    registrarTurno(&turno,&clientes);
                    break;
                case 2:
                    printf("Mostrar todos los turnos\n");
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
                    printf("Ingrese el nombre del cliente a buscar:  \n");
                    scanf("%s",nombre);
                    buscarTurnoPorIdCliente(&turno,nombre);
                    break;
                case 5:
                    printf("Modificar cantidad de tratamientos.\n");
                    printf("Ingrese el ID del cliente a cambiar tratamientos:  \n");
                    scanf("%s",clienteid);

                    // Selección de tratamientos para el cliente 1
                    int tratamientosSeleccionados[3] = {0};  // Array para almacenar los tratamientos seleccionados
                    seleccionarTratamientos(tratamientosSeleccionados);

                    // Modificar los tratamientos del cliente
                    modificarTratamientos(&turno, clienteid, tratamientosSeleccionados);
                    break;
                case 6:
                    printf("Modificar forma de pago.\n");
                    printf("\nIngrese el ID del cliente para cambiar tratamientos: ");
                    scanf("%s", clienteid);  // Leemos el ID del cliente

                    printf("Seleccione la forma de pago para el cliente con ID %s:\n", clienteid);
                    printf("1. Débito\n");
                    printf("2. Crédito\n");
                    printf("3. Efectivo\n");
                    printf("4. QR\n");
                    do
                    {
                        printf("Ingrese su elección (1-4): ");
                        scanf("%d", &formaPago);
                    }
                    while (formaPago < 1 || formaPago > 4);

                    // Cambiar la forma de pago de acuerdo al ID del cliente
                    modificarFormaPago(&turno, clienteid, formaPago);  // Llamamos a la función para modificar la forma de pago
                    break;
                case 7:
                    printf("Cancelar un turno.\n");

                    // Solicitar la cancelación de un turno por ID de cliente
                    printf("\n¿Desea cancelar un turno?\n");
                    printf("Ingrese el ID del cliente a cancelar turno: \n");
                    scanf("%s", clienteid);  // Leemos el ID del cliente

                    cancelarTurno(&turno, clienteid);  // Llamamos a la función para cancelar el turno

                    break;
                case 8:
                    printf("Confirmar asistencia de turno.\n");
                    printf("\nIngrese el ID del cliente para confirmar asistencia: \n");
                    scanf("%s", clienteid);
                    confirmarAsistenciaTurno(&turno,clienteid,&clientes);
                    break;
                case 9:
                    printf("Mostrar turnos no realizados.\n");
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
                    registrarCliente(&clientes);
                    break;
                case 2:
                    buscarCliente(clientes);
                    break;
                case 3:
                    eliminarCliente(&clientes);
                    break;
                case 4:
                    precargarClientesDesdeArchivo(&clientes);
                    break;
                case 5:
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
                    printf("\n -----Consultar ganancia mensual por mes.-----\n");
                    printf ("Ingrese el mes del que desea saber la ganancia mensual (11/12): \n");
                    scanf ("%d", &mes_deseado);

                    // Obtiene el primer turno de la lista
                    Turno turno_actual = copy_turno(&turno);

                    // Llamada a la función recursiva para calcular la ganancia
                    float ganancia_final = funcrec_gananciam(&turno, ganancia_inicial, mes_deseado, turno_actual);

                    printf("La ganancia total para el mes %d es: %.2f\n", mes_deseado, ganancia_final);
                    break;
                case 2:
                    printf("Guardar turnos segun forma de pago.\n");
                    // Almacenar turnos pagados en un archivo
                    printf("\nIngrese la forma de pago para almacenar los turnos pagados: ");
                    printf("1. Debito\n");
                    printf("2. Credito\n");
                    printf("3. Efectivo\n");
                    printf("4. QR\n");
                    do {
                    printf("Seleccione forma de pago para almacenar los turnos pagados (1-4): \n");
                    scanf("%d", &formaPago);
                    } while (formaPago < 1 || formaPago > 4);

                    almacenarTurnosPagados(&turno, formaPago);  // Llamamos a la función para almacenar los turnos pagados
                    break;
                case 3:
                    printf("Mostrar turnos por tratamiento.\n");
                    // Mostrar los tratamientos disponibles
                    mostrarTratamientos();
                    // Solicitar al usuario que ingrese el ID del tratamiento a buscar
                    int tratamiento_id;
                    printf("Ingrese el ID del tratamiento que desea buscar: \n");
                    scanf("%d", &tratamiento_id);

                    // Llamamos a la función para mostrar los turnos para el tratamiento con el ID dado
                    mostrarTurnosPorTratamiento(&turno, tratamiento_id);
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
