#ifndef TDAFILA_H_INCLUDED
#define TDAFILA_H_INCLUDED

#define MAX 100

typedef struct {
    char datos[MAX];
    int inicio, fin;
} Fila;

void init_fila(Fila *f) {
    f->inicio = 0;
    f->fin = 0;
}

int es_vacia_fila(Fila f) {
    return f.inicio == f.fin;
}

int es_llena_fila(Fila f) {
    return (f.fin + 1) % MAX == f.inicio;
}

void encolar(Fila *f, char valor) {
    if (!es_llena_fila(*f)) {
        f->datos[f->fin] = valor;
        f->fin = (f->fin + 1) % MAX;
    }
}

char desencolar(Fila *f) {
    if (!es_vacia_fila(*f)) {
        char valor = f->datos[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return valor;
    }
    return '\0';  // Si la fila está vacía
}

char frente(Fila f) {
    if (!es_vacia_fila(f)) {
        return f.datos[f.inicio];
    }
    return '\0';  // Si la fila está vacía
}

#endif // TDAFILA_H_INCLUDED
