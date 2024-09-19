#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nomb[20];
    char ape[20];
    int edad;
} persona;

// Función para cargar una estructura
void cargar_persona(persona *p) {
    printf("Ingrese nombre: ");
    scanf("%s", p->nomb);
    printf("Ingrese apellido: ");
    scanf("%s", p->ape);
    printf("Ingrese edad: ");
    scanf("%d", &p->edad);
}

// Función para mostrar los datos de una estructura
void mostrar_persona(const persona *p) {
    printf("Nombre: %s, Apellido: %s, Edad: %d\n", p->nomb, p->ape, p->edad);
}

int main() {
    int n;
    printf("Ingrese cantidad de personas (maximo 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Cantidad excede el máximo permitido.\n");
        return 1;
    }

    // a. Solicitar memoria para n personas
    persona *personas = (persona*) malloc(n * sizeof(persona));
    if (personas == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    // d. Cargar n estructuras
    for (int i = 0; i < n; i++) {
        printf("\nPersona %d:\n", i + 1);
        cargar_persona(&personas[i]);
    }

    // c. Mostrar los datos
    printf("\nDatos de las personas ingresadas:\n");
    for (int i = 0; i < n; i++) {
        mostrar_persona(&personas[i]);
    }

    free(personas);  // Liberar memoria
    return 0;
}
