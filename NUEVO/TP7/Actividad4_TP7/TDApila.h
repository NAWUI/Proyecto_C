#ifndef TDAPILA_H_INCLUDED
#define TDAPILA_H_INCLUDED

#define MAX 100

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void init_pila(Pila *p) {
    p->tope = -1;
}

int es_vacia(Pila p) {
    return p.tope == -1;
}

int es_llena(Pila p) {
    return p.tope == MAX - 1;
}

void push(Pila *p, int valor) {
    if (!es_llena(*p)) {
        p->datos[++(p->tope)] = valor;
    }
}

int pop(Pila *p) {
    if (!es_vacia(*p)) {
        return p->datos[(p->tope)--];
    }
    return -1;  // Si la pila está vacía
}

int peek(Pila p) {
    if (!es_vacia(p)) {
        return p.datos[p.tope];
    }
    return -1;  // Si la pila está vacía
}

#endif // TDAPILA_H_INCLUDED
