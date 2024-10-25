#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idturno;
    char nombre[20];        // Nombre del cliente (sin espacios)
    int idcliente;          // DNI del cliente habitual
    int tratamiento[10];    // IDs de tratamientos (puede haber varios por turno)
    char F_pago[10];        // Forma de pago (débito, crédito, QR, efectivo)
    float Total;            // Monto total a pagar
    Fecha Fecha_Turno;  // Fecha del turno
    int Realizado;          // 1 si el turno se realizó, 0 si no
} Turno;

typedef struct {
    int dia;
    int mes;
    int anio;
    int hora;
} Fecha;
/*
void initTurno(Turno *a) {
    a->idturno = 0;
    strcpy(a->nombre, "");
    a->idcliente = -1;
    for (int i = 0; i < 10; i++) {
        a->tratamiento[i] = 0;
    }
    strcpy(a->F_pago, "");
    a->Total = 0.0;
    a->Fecha_Turno.dia = 1;
    a->Fecha_Turno.mes = 1;
    a->Fecha_Turno.anio = 2024;
    a->Fecha_Turno.hora = 9;
    a->Realizado = 0;
}
*/
void Set_idTurno(Turno *a, int idturno) {
    a->idturno = idturno;
}

void Set_nombre(Turno *a, char *nombre) {
    strcpy(a->nombre, nombre);
}

void Set_idCliente(Turno *a, int idcliente) {
    a->idcliente = idcliente;
}

void Set_tratamiento(Turno *a, int *tratamientos, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        a->tratamiento[i] = tratamientos[i];
    }
}

void Set_formaPago(Turno *a, char *formaPago) {
    strcpy(a->F_pago, formaPago);
}

void Set_total(Turno *a, float total) {
    a->Total = total;
}

void Set_fecha(Turno *a, Fecha fecha) {
    a->Fecha_Turno = fecha;
}

void Set_realizado(Turno *a, int realizado) {
    a->Realizado = realizado;
}

int get_tratamiento(Turno * a,int indice){

}

int Get_idTurno(Turno a) {
    return a.idturno;
}

char* Get_nombre(Turno a) {
    return a.nombre;
}

int Get_idCliente(Turno a) {
    return a.idcliente;
}

float Get_total(Turno a) {
    return a.Total;
}

Fecha Get_fecha(Turno a) {
    return a.Fecha_Turno;
}

int Get_realizado(Turno a) {
    return a.Realizado;
}

#endif // TURNO_H_INCLUDED
