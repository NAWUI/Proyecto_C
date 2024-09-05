#include <stdio.h>
#include <string.h>

void imprimirZA(Empleado empleados[], int n) {
    if (n == 0) return;
    printf("Nombre: %s\n", empleados[n - 1].nombre);
    imprimirZA(empleados, n - 1);
}
void imprimirAZ(Empleado empleados[], int n) {
    if (n == 0) return;
    imprimirAZ(empleados, n - 1);
    printf("Nombre: %s\n", empleados[n - 1].nombre);
}

typedef struct {
    char nombre[50];
    char apellido[50];
    int edad;
} Empleado;

void buscarPorApellido(Empleado empleados[], int n, char apellido[]) {
    if (n == 0) return;
    if (strcmp(empleados[n - 1].apellido, apellido) == 0) {
        printf("Nombre: %s, Apellido: %s, Edad: %d\n", empleados[n - 1].nombre, empleados[n - 1].apellido, empleados[n - 1].edad);
    }
    buscarPorApellido(empleados, n - 1, apellido);
}

int main() {
    Empleado empleados[] = {{"Juan", "Garcia", 30}, {"Ana", "Perez", 25}, {"Luis", "Garcia", 40}};
    int n = 3;
    buscarPorApellido(empleados, n, "Garcia");
    return 0;
}
