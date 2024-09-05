#include <stdio.h>
#include <string.h>

typedef struct {
    int NroID;
    char bloque[10];
    char tipo[20];
    int mesas;
    int sillas;
    int pizarras;
    struct {
        char marca[20];
        char color[10];
        int controlRemoto;
    } proyector;
} Aula;

void imprimirAulasConControl(Aula aulas[], int n) {
    if (n == 0) return;
    if (aulas[n - 1].proyector.controlRemoto) {
        printf("Aula con ID: %d tiene proyector con control remoto.\n", aulas[n - 1].NroID);
    }
    imprimirAulasConControl(aulas, n - 1);
}

int main() {
    Aula aulas[] = {
        {101, "B1", "Teoría", 30, 40, 1, {"Epson", "Blanco", 1}},
        {102, "B2", "Laboratorio", 20, 20, 2, {"Sony", "Negro", 0}},
        {103, "B3", "Conferencia", 50, 100, 1, {"Samsung", "Gris", 1}}
    };
    int n = 3;
    imprimirAulasConControl(aulas, n);
    return 0;
}

