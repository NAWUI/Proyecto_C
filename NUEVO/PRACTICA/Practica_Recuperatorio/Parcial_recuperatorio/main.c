#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 8500

typedef struct {
    char calle[50];
    int numero;
    char localidad[50];
} direccion;

typedef struct {
    char Razon_Social[50];
    char Codigo[50];
    direccion dire_P;
    int categoria;
} Proveedor;

int carga_n_proveedores(Proveedor *infoP[], int *cantT, int rep) {
    for (; *cantT < *cantT + rep; (*cantT)++) {
        printf("Ingres la Razon Social del Proveedor\n");
        scanf("%s", infoP[*cantT]->Razon_Social);
        printf("Ingrese el codigo del Proveedor\n");
        scanf("%s", infoP[*cantT]->Codigo);
        printf("Ingrese la Calle del proveedor\n");
        scanf("%s", infoP[*cantT]->dire_P.calle);
        printf("Ingrese el numero del Proveedor\n");
        scanf("%d", &infoP[*cantT]->dire_P.numero);
        printf("Ingrese la Localidad del proveedor\n");
        scanf("%s", infoP[*cantT]->dire_P.localidad);
        printf("Seleccione la Categoria del proveedor (1-4)\n");
        scanf("%d", &infoP[*cantT]->categoria);
    }
    *cantT += rep;
    return *cantT;
}

void buscar_codigo(Proveedor infoP[], char code[], int canT) {
    int i;
    for (i = 0; i < canT; i++) {
        if (strcmp(infoP[i].Codigo, code) == 0) {
            printf("Razon Social: %s\n", infoP[i].Razon_Social);
            printf("Codigo: %s\n", infoP[i].Codigo);
            printf("Calle: %s\n", infoP[i].dire_P.calle);
            printf("Numero: %d\n", infoP[i].dire_P.numero);
            printf("Localidad: %s\n", infoP[i].dire_P.localidad);
            switch (infoP[i].categoria) {
                case 1:
                    printf("Categoria: CAT1\n");
                    break;
                case 2:
                    printf("Categoria: CAT2\n");
                    break;
                case 3:
                    printf("Categoria: CAT3\n");
                    break;
                case 4:
                    printf("Categoria: CAT4\n");
                    break;
            }
        }
    }
}

// Funci�n recursiva para contar proveedores por categor�a sin usar un contador expl�cito
int cant_cat_sincontador(Proveedor infoP[], int canT, int categoria) {
    if (canT == 0) {
        return 0;
    }
    if (infoP[canT - 1].categoria == categoria) {
        return 1 + cant_cat_sincontador(infoP, canT - 1, categoria);
    }
    return cant_cat_sincontador(infoP, canT - 1, categoria);
}

/*
// Funci�n con contador
int cant_cat_contador(Proveedor infoP[], int canT, int categoria) {
    int contador = 0;
    for (int i = 0; i < canT; i++) {
        if (infoP[i].categoria == categoria) {
            contador++;
        }
    }
    return contador;
}
*/

int main() {
    Proveedor registroP[Max];
    int cantidadtotal = 0;
    char codigo_r[50];
    int num;
    int cate_r;
    int opcion;
    int repetir;

    do {
        printf("/-------Menu-------\\n");
        printf("(1)-Carga de proveedor/es\n");
        printf("(2)-Buscar proveedor por codigo\n");
        printf("(3)-Contar proveedores por X categoria\n");
        printf("(0)-Salir\n");
        printf("\------------------/\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (cantidadtotal < Max) {
                    printf("Cantidad de proveedores que cargar\n");
                    scanf("%d", &repetir);
                    carga_n_proveedores(&registroP[cantidadtotal], &cantidadtotal, repetir);
                } else {
                    printf("Maximo de proveedores alcanzado\n");
                }
                break;
            case 2:
                printf("Ingrese el Codigo del proveedor\n");
                scanf("%s", codigo_r);
                buscar_codigo(registroP, codigo_r, cantidadtotal);
                break;
            case 3:
                printf("Ingrese la categoria a contar (1-4):\n");
                scanf("%d", &cate_r);
                printf("Cantidad de proveedores en la categor�a %d: %d\n", cate_r, cant_cat_sincontador(registroP, cantidadtotal, cate_r));
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci�n inv�lida\n");
        }
    } while (opcion != 0);

    return 0;
}