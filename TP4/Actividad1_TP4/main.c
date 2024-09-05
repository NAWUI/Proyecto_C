#include <stdio.h>
#include <string.h>

// a. Definir un registro llamado parte
struct parte {
    int numero;          // Campo entero para el número de parte
    char nombre[25];     // Campo string para el nombre de parte
};

// b. Definir Parte como un tipo struct parte
typedef struct parte Parte;

int main() {
    // c. Declarar una variable a de tipo struct parte y un arreglo b[10] de tipo struct parte
    Parte a;
    Parte b[10];

    // d. Leer un número y un nombre de parte desde el teclado y almacenarlos en los campos de la variable a
    printf("Ingrese el número de parte: ");
    scanf("%d", &a.numero);

    printf("Ingrese el nombre de parte (máximo 24 caracteres): ");
    scanf("%s", a.nombre);

    // e. Asignar los valores de los campos de la variable a al elemento 3 del arreglo b
    b[3] = a;

    // f. Imprimir los campos del elemento 3 del arreglo b
    printf("Elemento 3 del arreglo b:\n");
    printf("Número de parte: %d\n", b[3].numero);
    printf("Nombre de parte: %s\n", b[3].nombre);

    return 0;
}
