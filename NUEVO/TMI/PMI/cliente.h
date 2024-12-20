#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
#define MAX_CHAR 41
#define MAX_IDCLIENTE 9
typedef struct {
    char id_cliente [MAX_IDCLIENTE];
    char nombre [MAX_CHAR];
    char apellido [MAX_CHAR];
    int canttratamientos;
    int nivel;
}Cliente;

void set_id_cliente (Cliente *c, char id []){
    strcpy ((*c).id_cliente,id);
}

char* get_id_cliente (Cliente c) {
    char *p;
    p = (char *)malloc(sizeof(char) * MAX_IDCLIENTE);
    if (p == NULL) exit (1);
    else {
        strcpy (p, c.id_cliente);
        return p;
    }
}

void set_nombre_cliente (Cliente *c, char nom []){
    strcpy ((*c).nombre,nom);
}

char* get_nombre_cliente (Cliente c) {
    char *p;
    p = (char *)malloc(sizeof(char) * MAX_CHAR);
    if (p == NULL) exit (1);
    else {
        strcpy (p, c.nombre);
        return p;
    }
}

void set_apellido_cliente (Cliente *c, char apell []){
    strcpy ((*c).apellido,apell);
}

char* get_apellido_cliente (Cliente c) {
    char *p;
    p = (char *)malloc(sizeof(char) * MAX_CHAR);
    if (p == NULL) exit (1);
    else {
        strcpy (p, c.apellido);
        return p;
    }
}

void set_canttratamientos_cliente (Cliente *c, int cantt){
    (*c).canttratamientos += cantt;
}

int get_canttratamientos_cliente (Cliente c) {
    return c.canttratamientos;
}

void inittratamientos_cliente (Cliente *c){
    (*c).canttratamientos = 0;
}

void set_nivel_cliente (Cliente *c, int nuevostr ){
    (*c).canttratamientos = nuevostr;

    if ((*c).canttratamientos == 0) {
        (*c).nivel = 0;
    } else if ((*c).canttratamientos >= 1 && (*c).canttratamientos <= 4) {
        (*c).nivel = 1;
    } else if ((*c).canttratamientos >= 5 && (*c).canttratamientos < 10) {
        (*c).nivel = 2;
    } else {
        (*c).nivel = 3;
    }
}

int get_nivel_cliente (Cliente c) {
    return c.nivel;
}

#endif // CLIENTE_H_INCLUDED
