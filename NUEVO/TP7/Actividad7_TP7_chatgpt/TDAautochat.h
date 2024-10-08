#ifndef TDAAUTO_H_INCLUDED
#define TDAAUTO_H_INCLUDED

#include <string.h>
typedef struct {
    char marca[20];
    char modelo[20];
    int anio;
    char titular[30];
    float precio;
    int cant_KM;
} Auto;


void initAuto(Auto *a, char marca[], char modelo[], int anio, char titular[], float precio, int cant_KM) {
    strcpy(a->marca, marca);
    strcpy(a->modelo, modelo);
    strcpy(a->titular, titular);
    a->anio = anio;
    a->precio = precio;
    a->cant_KM = cant_KM;
}

char* Get_marca(Auto a) {
    return a.marca;
}

char* Get_modelo(Auto a) {
    return a.modelo;
}

int Get_anio(Auto a) {
    return a.anio;
}

char* Get_titular(Auto a) {
    return a.titular;
}

float Get_precio(Auto a) {
    return a.precio;
}

int Get_cant_KM(Auto a) {
    return a.cant_KM;
}

#endif
