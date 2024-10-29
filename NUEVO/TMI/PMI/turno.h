#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#include <stdlib.h>
#include <string.h> // Para usar strcpy
#include <stdio.h>  // Para usar printf

#define MAX_TRATAMIENTOS 10

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    int idTurno;
    char nombre[50];
    int idCliente;
    int tratamientos[MAX_TRATAMIENTOS];
    int cantidadTratamientos;
    char formaPago[10];
    float total;
    Fecha fecha;
    int realizado;
} Turno;

void setIdTurno(Turno *turno, int id) {
    turno->idTurno = id;
}

void setNombre(Turno *turno, const char *nombre) {
    strcpy(turno->nombre, nombre);
}

void setIdCliente(Turno *turno, int idCliente) {
    turno->idCliente = idCliente;
}
/*
void setTratamientos(Turno *turno, int tratamientos[], int cantidad) {
    if (cantidad <= MAX_TRATAMIENTOS) {
        for (int i = 0; i < cantidad; i++) {
            turno->tratamientos[i] = tratamientos[i];
        }
        turno->cantidadTratamientos = cantidad;
    } else {
        printf("Error: No se pueden agregar más de %d tratamientos.\n", MAX_TRATAMIENTOS);
    }
}
*/
void setFormaPago(Turno *turno, const char *formaPago) {
    strcpy(turno->formaPago, formaPago);
}

void setTotal(Turno *turno, float total) {
    turno->total = total;
}

void setFecha(Turno *turno, Fecha fecha) {
    turno->fecha = fecha;
}

void setRealizado(Turno *turno, int realizado) {
    turno->realizado = realizado;
}

int getIdTurno(const Turno *turno) {
    return turno->idTurno;
}

char* getNombre(const Turno *turno) {
    char *nombre = (char *)malloc((strlen(turno->nombre) + 1) * sizeof(char));
    if (nombre != NULL) {
        strcpy(nombre, turno->nombre);
    }
    return nombre;
}

int getIdCliente(const Turno *turno) {
    return turno->idCliente;
}

void getTratamientos(const Turno *turno, int tratamientos[], int *cantidad) {
    *cantidad = turno->cantidadTratamientos;
    for (int i = 0; i < *cantidad; i++) {
        tratamientos[i] = turno->tratamientos[i];
    }
}

char* getFormaPago(const Turno *turno) {
    char *formaPago = (char *)malloc((strlen(turno->formaPago) + 1) * sizeof(char));
    if (formaPago != NULL) {
        strcpy(formaPago, turno->formaPago);
    }
    return formaPago;
}

float getTotal(const Turno *turno) {
    return turno->total;
}

Fecha getFecha(const Turno *turno) {
    return turno->fecha;
}

int getRealizado(const Turno *turno) {
    return turno->realizado;
}


/*

// Función para agregar un tratamiento (por su ID)
int agregarTratamiento(Turno *t, int tratamientoId) {
    if (t->cantidadTratamientos < MAX_TRATAMIENTOS && !t->realizado) {
        t->tratamientos[t->cantidadTratamientos] = tratamientoId;
        t->cantidadTratamientos++;
        return 1; // Éxito
    }
    return 0; // Fallo
}

// Función para setear la forma de pago
int setFormaPago(Turno *t, const char *formaPago) {
    if (t->realizado) {
        return 0; // No se puede modificar si ya fue realizado
    }
    strncpy(t->formaPago, formaPago, sizeof(t->formaPago) - 1);
    t->formaPago[sizeof(t->formaPago) - 1] = '\0';
    return 1; // Éxito
}

// Función para cambiar el estado de realizado
void marcarRealizado(Turno *t) {
    t->realizado = 1; // Cambiar a realizado
}

// Función para obtener el total a pagar (considerando descuentos si es cliente habitual)
float calcularTotal(Turno *t, float precios[MAX_TRATAMIENTOS]) {
    float total = 0.0;
    for (int i = 0; i < t->cantidadTratamientos; i++) {
        total += precios[t->tratamientos[i]]; // Sumar el precio del tratamiento
    }

    // Aplicar descuento si es cliente habitual
    if (t->idCliente > 0) { // Asumimos que ID de cliente > 0 indica que es habitual
        if (t->idCliente == 1) { // Nivel 1
            total *= 0.95; // 5% de descuento
        } else if (t->idCliente == 2) { // Nivel 2
            total *= 0.90; // 10% de descuento
        } else if (t->idCliente == 3) { // Nivel 3
            total *= 0.85; // 15% de descuento
        }
    }

    t->total = total; // Asignar total calculado al turno
    return total;
}


// Función para validar la fecha y hora
int validarFecha(Fecha fecha) {
    if (fecha.anio < 2024 || fecha.anio > 2024) {
        return 0; // Año fuera de rango
    }
    if (fecha.mes < 11 || fecha.mes > 12) {
        return 0; // Mes fuera de rango
    }
    if (fecha.dia < 1 || fecha.dia > 31) {
        return 0; // Día fuera de rango
    }

    // Control de días de la semana (lunes a sábado)
    // Para simplificar, consideramos el día 1/11/2024 como viernes (cálculo manual o función)
    int diaSemana = (fecha.dia + (fecha.mes - 11) * 30) % 7; // Cálculo simple, puedes usar una mejor función

    if (diaSemana == 0) {
        return 0; // Domingo
    }

    // Control de horas (de 9 a 20)
    if (fecha.hora < 9 || fecha.hora > 20) {
        return 0; // Hora fuera de rango
    }

    return 1; // Fecha válida
}
*/

#endif // TURNO_H_INCLUDED
