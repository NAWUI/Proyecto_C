#include <stdio.h>
#include <stdlib.h>

int prendas3x2(int pre1, int pre2, int pre3) {
    int max_P;

    // Encuentra el precio más alto
    if (pre1 > pre2 && pre1 > pre3) {
        max_P = pre1;
    } else if (pre2 > pre1 && pre2 > pre3) {
        max_P = pre2;
    } else {
        max_P = pre3;
    }

    // La cantidad a pagar es la suma de los dos precios más bajos
    return (pre1 + pre2 + pre3) - max_P;
}

int main() {
    int C_producto = 1;
    int prenda1 = 0, prenda2 = 0, prenda3 = 0;
    int pre_prenda = 0;
    int resp;
    int total = 0;

    do {
        printf("**************************\n");
        printf("LISTA DE PRODUCTOS\n");
        printf("**************************\n");
        printf("(1)-Prenda 1 ($2500)\n");
        printf("(2)-Prenda 2 ($2500)\n");
        printf("(3)-Prenda 3 ($5500)\n");
        printf("(4)-Prenda 4 ($2500)\n");
        printf("(5)-Prenda 5 ($1500)\n");
        printf("(6)-Prenda 6 ($4500)\n");
        printf("(7)-Prenda 7 ($5000)\n");
        printf("**************************\n");
        printf("(0)- Terminar de Comprar\n");
        printf("**************************\n");

        scanf("%d", &resp);
        system("cls");
        switch(resp) {
            case 1: pre_prenda = 2500; break;
            case 2: pre_prenda = 2500; break;
            case 3: pre_prenda = 5500; break;
            case 4: pre_prenda = 2500; break;
            case 5: pre_prenda = 1500; break;
            case 6: pre_prenda = 4500; break;
            case 7: pre_prenda = 5000; break;
            case 0: break;
            default:
                printf("No existe ese producto, seleccione algun producto de la lista\n");
                continue;
                system("cls");
        }

        if (resp > 0) {
            if (C_producto == 1) prenda1 = pre_prenda;
            else if (C_producto == 2) prenda2 = pre_prenda;
            else if (C_producto == 3) prenda3 = pre_prenda;
            total += pre_prenda;
            C_producto++;
        }

    } while(resp != 0);

    if (C_producto > 3) { // Si se seleccionaron exactamente 3 prendas
        total = prendas3x2(prenda1, prenda2, prenda3);
    }

    printf("El total a pagar es %d\n", total);

    return 0;
}
