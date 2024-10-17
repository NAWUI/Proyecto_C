#include <stdio.h>

int main() {
    FILE *archivo;
    int cuenta;
    char tipo;
    float monto;

    archivo = fopen("transacciones.dat", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (1) {

        printf("Ingrese el numero de cuenta: \n");
        printf("? ");
        scanf("%d", &cuenta);
        getchar();
        printf("Ingrese el tipo de transaccion (D para deposito, E para extracción): \n");
        printf("? ");
        scanf("%c", &tipo);
        getchar();
        printf("ingrese el monto(0 para finalizar): \n");
        printf("? ");
        scanf("%f", &monto);
        getchar();

        if (monto == 0) break;

        fprintf(archivo, "%d\t%c\t%.2f\n", cuenta, tipo, monto);
    }

    fclose(archivo);
    printf("Datos guardados en transacciones.dat correctamente.\n");

    return 0;
}
