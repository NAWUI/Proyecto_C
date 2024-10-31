#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_TRATAMIENTOS 10
#define MAX_NOMBRE 50

typedef struct {
    int dia;
    int mes;
    int anio;
    int hora;
} Fecha;

typedef struct {
    int idTurno;
    char nombre[MAX_NOMBRE];
    int idCliente;
    int tratamientos[MAX_TRATAMIENTOS];
    char formaPago[10];
    float total;
    Fecha fecha;
    int realizado;
} Turno;

int generarIdTurno() {
    static int contador = 0;
    return ++contador;
}

void setIdTurno(Turno *turno, int id) {
    turno->idTurno = id;
}

void setNombre(Turno *turno, const char *nombre) {
    strcpy(turno->nombre, nombre);
}

void setIdCliente(Turno *turno, int idCliente) {
    turno->idCliente = idCliente;
}

int setTratamiento(Turno *t, int tratamientos[]) {
    for (int i = 0; i < MAX_TRATAMIENTOS; i++) {
        t->tratamientos[i] = tratamientos[i];
    }
    return 0;
}

void setFormaPago(Turno *turno, const char *formaPago) {
    if (strcmp(formaPago, "debito") == 0 || strcmp(formaPago, "credito") == 0 ||
        strcmp(formaPago, "QR") == 0 || strcmp(formaPago, "efectivo") == 0) {
        strcpy(turno->formaPago, formaPago);
    }
}

void setTotal(Turno *turno, float total, int nivelCliente) {
    float descuento = 0.0;
    float totalFinal = 0.0;
    // Determinar el porcentaje de descuento seg�n el nivel
    switch (nivelCliente) {
        case 0: // Sin descuento
            descuento = 0.0;
            break;
        case 1: // 5% de descuento
            descuento = total * 0.05;
            break;
        case 2: // 10% de descuento
            descuento = total * 0.10;
            break;
        case 3: // 15% de descuento
            descuento = total * 0.15;
            break;
        default: // Si el nivel es incorrecto, no aplica descuento
            descuento = 0.0;
            break;
    }
    totalFinal = total - descuento;
    turno->total = totalFinal;
}

void setFecha(Turno *turno, Fecha fecha) {
    turno->fecha = fecha;
}

void setRealizado(Turno *turno, int realizado) {
    turno->realizado = realizado;
}
char* get_nombre_T(Turno turno) {
    char *nombre = (char *)malloc((strlen(turno.nombre) + 1) * sizeof(char));
    if (nombre != NULL) {
        strcpy(nombre, turno.nombre);
    }
    return nombre;
}

int get_idTurno(Turno t) {
    return t.idTurno;
}

int get_idCliente(Turno t) {
    return t.idCliente;
}

int* get_tratamientos(Turno t) {
    int *tratamientos = (int *)malloc(MAX_TRATAMIENTOS * sizeof(int));
    if (tratamientos != NULL) {
        for (int i = 0; i < MAX_TRATAMIENTOS; i++) {
            tratamientos[i] = t.tratamientos[i];
        }
    }
    return tratamientos;
}

char* get_formaPago(Turno t) {
    char *formaPago = (char *)malloc((strlen(t.formaPago) + 1) * sizeof(char));
    if (formaPago != NULL) {
        strcpy(formaPago, t.formaPago);
    }
    return formaPago;
}

Fecha get_fecha(Turno t) {
    return t.fecha;
}

int get_realizado(Turno t) {
    return t.realizado;
}

// Funciones `get` para `Fecha` anidada en `Turno`
int get_dia(Fecha fecha) {
    return fecha.dia;
}

int get_mes(Fecha fecha) {
    return fecha.mes;
}

int get_anio(Fecha fecha) {
    return fecha.anio;
}

int get_hora(Fecha fecha) {
    return fecha.hora;
}
float get_total(Turno turno){
    return turno.total;
}


int validarFecha(Fecha fecha) {
    if (fecha.anio != 2024 || fecha.mes < 11 || fecha.mes > 12 ||
        fecha.dia < 1 || fecha.dia > 31 || fecha.hora < 9 || fecha.hora > 20) {
        return 0;
    }
    int diaSemana = (fecha.dia + (fecha.mes - 11) * 30) % 7;
    if (diaSemana == 0) return 0;
    return 1;
}

void marcarRealizado(Turno *t) {
    t->realizado = 1;
}

#endif // TURNO_H_INCLUDED
