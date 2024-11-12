#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_TRATAMIENTOS 10
#define MAX_NOMBRE 41
#define MAX_IDCLIENTE 9
typedef struct {
    int dia;
    int mes;
    int anio;
    int hora;
} Fecha;

typedef struct {
    int idTurno;
    char nombre[MAX_NOMBRE];
    char idCliente[MAX_IDCLIENTE];
    int tratamientos[MAX_TRATAMIENTOS];
    int formaPago;
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

void setIdCliente(Turno *turno, char *idCliente) {
    strcpy(turno->idCliente, idCliente);
}

void setTratamiento(Turno *t, int tratamientos[]) {
    for (int i = 0; i < MAX_TRATAMIENTOS; i++) {
        t->tratamientos[i] = tratamientos[i];
    }
}

void setFormaPago(Turno *turno, int formapago){
        turno->formaPago = formapago;

}

void setTotal(Turno *t, float total, int nivelCliente) {
    float descuento = 0.0;
    float totalFinal = 0.0;
    // Determinar el porcentaje de descuento seg n el nivel
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
    t->total = totalFinal;
}

void setFecha(Turno *t, Fecha fecha) {
    t->fecha = fecha;
}

void setRealizado(Turno *t, int realizado) {
    t->realizado = realizado;
}
char* get_nombre_T(Turno t) {
    char *nombre = (char *)malloc(MAX_NOMBRE * sizeof(char));
    if (nombre != NULL) {
        strcpy(nombre, t.nombre);
    }
    return nombre;
}

int get_idTurno(Turno t) {
    return t.idTurno;
}

char* get_idCliente(Turno t) {
    char *idcliente = (char *)malloc(MAX_IDCLIENTE * sizeof(char));
    if (idcliente != NULL) {
        strcpy(idcliente, t.idCliente);
    }
    return idcliente;
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

const char* get_formaPago(Turno t) {
    switch(t.formaPago) {
        case 1: return "Debito";
        case 2: return "Credito";
        case 3: return "Efectivo";
        case 4: return "QR";
        default: return "Desconocido";
    }
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
