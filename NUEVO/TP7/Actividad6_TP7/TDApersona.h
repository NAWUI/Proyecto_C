#ifndef TDAPERSONA_H_INCLUDED
#define TDAPERSONA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_char 50

typedef struct {
    char nombre[max_char];
    char apellido[max_char];
    int dni;
    char email[max_char];
} Persona;

void set_nombre(Persona *P, const char *nombre) {
    strcpy(P->nombre, nombre);
}

void set_apellido(Persona *P, const char *apellido) {
    strcpy(P->apellido, apellido);
}

void set_dni(Persona *P, int dni) {
    P->dni = dni;
}

void set_email(Persona *P, const char *email) {
    strcpy(P->email, email);
}

char* get_nombre(Persona P) {
    char *nombre = (char *)malloc((strlen(P.nombre) + 1) * sizeof(char));
    if (nombre != NULL) {
        strcpy(nombre, P.nombre);
    }
    return nombre;
}

char* get_apellido(Persona P) {
    char *apellido = (char *)malloc((strlen(P.apellido) + 1) * sizeof(char));
    if (apellido != NULL) {
        strcpy(apellido, P.apellido);
    }
    return apellido;
}

int get_dni(Persona P) {
    return P.dni;
}

char* get_email(Persona P) {
    char *email = (char *)malloc((strlen(P.email) + 1) * sizeof(char));
    if (email != NULL) {
        strcpy(email, P.email);
    }
    return email;
}

#endif // TDAPERSONA_H_INCLUDED