#ifndef TDAAUTO_H
#define TDAAUTO_H
#include <stdio.h>
#include <string.h>

typedef struct {
    char marca[50];
    char modelo[50];
    char titular[100];
    float precio;
    int cont_km;
    int anio_fab;
} Auto;


void Set_marca (Auto *a,char *marca){
    strcpy(a->marca, marca);
}
//
void Set_modelo (Auto *a,char *modelo){
    strcpy(a->modelo, modelo);
}
//
void Set_anio (Auto *a,int anio_fab){
    a->anio_fab = anio_fab;
}
//
void Set_titular (Auto *a,char *titular){
    strcpy(a->titular, titular);
}

//
void Set_precio (Auto *a,float precio){
    a->precio = precio;
}
//
void Set_cant_KM (Auto *a,int cont_km){
    a->cont_km = cont_km;
}
//

int Get_anio (Auto a){
    return a.anio_fab;
}
//
float Get_precio (Auto a){
    return a.precio;
}
//
int Get_cant_KM (Auto a){
    return a.cont_km;
}
//t
char* Get_marca(Auto a) {
    char *marca = (char *)malloc((strlen(a.marca) + 1) * sizeof(char));
    if (marca != NULL) {
        strcpy(marca, a.marca);
    }
    return marca;
}
//
char* Get_modelo(Auto a) {
    char *modelo = (char *)malloc((strlen(a.modelo) + 1) * sizeof(char));
    if (modelo != NULL) {
        strcpy(modelo, a.modelo);
    }
    return modelo;
}
//
char* Get_titular(Auto a) {
    char *titular = (char *)malloc((strlen(a.titular) + 1) * sizeof(char));
    if (titular != NULL) {
        strcpy(titular, a.titular);
    }
    return titular;
}


#endif
