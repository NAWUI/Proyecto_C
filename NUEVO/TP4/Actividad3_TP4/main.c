
//f. Un aula: tipo de aula deberá incluir: Nº de identificación, ubicación (bloque) y tipo (Laboratorio, Conferencia, Teoría‐Práctica); cantidad de mesas, cantidad de sillas, cantidad de pizarras, proyector (deberá incluir: marca, color y control remoto (si o no)).
struct Proyector {
    char marca[30];
    char color[20];
    int control_remoto; // 1 para sí, 0 para no
};

struct Aula {
    int numero_identificacion;
    char ubicacion[50];
    char tipo[30]; // Laboratorio, Conferencia, Teoría‐Práctica
    int cantidad_mesas;
    int cantidad_sillas;
    int cantidad_pizarras;
    struct Proyector proyector;
};

#include <stdio.h>

// Prototipos de funciones
void ingresarDatosAula(struct Aula *aula);
void mostrarDatosAula(const struct Aula *aula);

int main() {
    struct Aula aula;

    // Ingresar y mostrar datos del aula
    ingresarDatosAula(&aula);
    mostrarDatosAula(&aula);

    return 0;
}

void ingresarDatosAula(struct Aula *aula) {
    printf("Ingrese el número de identificación del aula: ");
    scanf("%d", &aula->numero_identificacion);

    printf("Ingrese la ubicación del aula (bloque): ");
    scanf("%s", aula->ubicacion);

    printf("Ingrese el tipo de aula (Laboratorio, Conferencia, Teoría‐Práctica): ");
    scanf("%s", aula->tipo);

    printf("Ingrese la cantidad de mesas: ");
    scanf("%d", &aula->cantidad_mesas);

    printf("Ingrese la cantidad de sillas: ");
    scanf("%d", &aula->cantidad_sillas);

    printf("Ingrese la cantidad de pizarras: ");
    scanf("%d", &aula->cantidad_pizarras);

    printf("Ingrese la marca del proyector: ");
    scanf("%s", aula->proyector.marca);

    printf("Ingrese el color del proyector: ");
    scanf("%s", aula->proyector.color);

    printf("¿El proyector tiene control remoto? (1 para sí, 0 para no): ");
    scanf("%d", &aula->proyector.control_remoto);
}

void mostrarDatosAula(const struct Aula *aula) {
    printf("\nDatos del aula:\n");
    printf("Número de identificación: %d\n", aula->numero_identificacion);
    printf("Ubicación: %s\n", aula->ubicacion);
    printf("Tipo: %s\n", aula->tipo);
    printf("Cantidad de mesas: %d\n", aula->cantidad_mesas);
    printf("Cantidad de sillas: %d\n", aula->cantidad_sillas);
    printf("Cantidad de pizarras: %d\n", aula->cantidad_pizarras);
    printf("Proyector marca: %s\n", aula->proyector.marca);
    printf("Proyector color: %s\n", aula->proyector.color);
    printf("Proyector con control remoto: %s\n", aula->proyector.control_remoto ? "Sí" : "No");
}
