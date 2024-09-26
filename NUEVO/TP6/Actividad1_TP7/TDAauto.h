#ifndef TDAAUTO_H
#define TDAAUTO_H

typedef struct {
    char marca[50];
    char modelo[50];
    int anio;
    char titular[100];
    float precio;
} Auto;
//crerar un get para cadu uno de los struct//
void Get_Auto(Auto *a, const char *marca, const char *modelo, int anio, const char *titular, float precio);
void Modifi_Titular(Auto *a, const char *nuevoTitular);
void View_Auto(const Auto *a);

#endif
