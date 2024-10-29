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
}Turno;

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
    int cantidadTratamientos = 0;
    for (int i = 0; i < MAX_TRATAMIENTOS;i++){
        if (tratamientos[i]== 1){
                cantidadTratamientos++;
        }
    }
    if (tratamientos < MAX_TRATAMIENTOS && !t->realizado) {


    }
    return 0;
}

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
/*
void getTratamientos(const Turno *turno, int tratamientos[], int *cantidad) {
    *cantidad = turno->cantidadTratamientos;
    for (int i = 0; i < *cantidad; i++) {
        tratamientos[i] = turno->tratamientos[i];
    }
}
*/
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
float calcularTotal(Turno *t, int nivelCliente) {
    float total = 0.0;
    for (int i = 0; i < t->cantidadTratamientos; i++) {
        total += t->tratamientos[i].precio;
    }
    if (nivelCliente == 1) total *= 0.95;
    else if (nivelCliente == 2) total *= 0.90;
    else if (nivelCliente == 3) total *= 0.85;
    t->total = total;
    return total;
}
*/
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
