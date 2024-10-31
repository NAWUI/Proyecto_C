#ifndef LISTAE_CLIENTE_H_INCLUDED
#define LISTAE_CLIENTE_H_INCLUDED
#include "cliente.h"
#define MAX_CLIENTES 100

typedef struct {
    Cliente vipd[MAX_CLIENTES];
    int ultimo;
    int cursor;
} lista_de_clientes;

// Cambi� el nombre de la funci�n a 'init_cliente' para evitar conflictos
void init_cliente(lista_de_clientes *l) {
    (*l).ultimo = -1;
    (*l).cursor = 0;
}

void reset(lista_de_clientes *l) {
    (*l).cursor = 0;
}

int isempty(lista_de_clientes l) {
    return (l.ultimo == -1);
}

int isfull(lista_de_clientes l) {
    return (l.ultimo == MAX_CLIENTES - 1);
}

// Cambi� el nombre de la funci�n a 'forwards_cliente' para evitar conflictos
void forwards_cliente(lista_de_clientes *l) {
    if ((*l).cursor <= (*l).ultimo) {
        (*l).cursor++;
    }
}

int isOos(lista_de_clientes l) {
    return (l.cursor > l.ultimo);
}

Cliente coppy(lista_de_clientes l) {
    return (l.vipd[l.cursor]);
}

// Cambi� la funci�n a 'void' ya que no devuelve un Cliente
void insertl(lista_de_clientes *l, Cliente c) {
    for (int i = (*l).ultimo; i >= (*l).cursor; i--) {
        (*l).vipd[i + 1] = (*l).vipd[i];
    }
    (*l).vipd[(*l).cursor] = c;
    (*l).ultimo++;
}

// Cambi� la funci�n a 'void' ya que no devuelve un Cliente
void supress(lista_de_clientes *l) {
    for (int i = (*l).cursor; i < (*l).ultimo; i++) {
        (*l).vipd[i] = (*l).vipd[i + 1];
    }
    (*l).ultimo--;
}

#endif // LISTAE_CLIENTE_H_INCLUDED
