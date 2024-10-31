#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>

typedef struct {
    char id_cliente [9];
    char nombre [20];
    char apellido [20];
    int canttratamientos;
    int nivel;
}Cliente;

void set_id_cliente (Cliente *c, char id []){
    strcpy ((*c).id_cliente,id);
}

char* get_id_cliente (Cliente c) {
    char *p;
    p = (char *)malloc(strlen (c.id_cliente) + 1);
    if (p == NULL) exit (1);
    else {
        strcpy (p, c.id_cliente);
        return p;
    }
}

void set_nombre (Cliente *c, char nom []){
    strcpy ((*c).nombre,nom);
}

char* get_nombre (Cliente c) {
    char *p;
    p = (char *)malloc(strlen (c.nombre) + 1);
    if (p == NULL) exit (1);
    else {
        strcpy (p, c.nombre);
        return p;
    }
}

void set_apellido (Cliente *c, char apell []){
    strcpy ((*c).apellido,apell);
}

void set_canttratamientos (Cliente *c, int cantt){
    (*c).canttratamientos += cantt;
}

int get_canttratamientos (Cliente c) {
    return c.canttratamientos;
}

void initt (Cliente *c){
    (*c).canttratamientos = 0;
}

void set_nivel (Cliente *c, int nuevostr ){
    (*c).canttratamientos += nuevostr;

    if ((*c).canttratamientos == 0) {
        (*c).nivel = 0;
    } else if ((*c).canttratamientos >= 1 && (*c).canttratamientos <= 4) {
        (*c).nivel = 1;
    } else if ((*c).canttratamientos >= 5 && (*c).canttratamientos <= 10) {
        (*c).nivel = 2;
    } else {
        (*c).nivel = 3;
    }
}

int get_nivel (Cliente c) {
    return c.canttratamientos;
}

#endif // CLIENTE_H_INCLUDED
