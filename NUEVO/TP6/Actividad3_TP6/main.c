#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char a;
    int b;
} Info;

int main() {

    Info *info = (Info*) malloc(sizeof(Info));
    if (info == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Asigna un valor para 'a':\n");
    scanf("%c", &info->a);
    printf("Asigna un valor para 'b':\n");
    scanf("%d", &info->b);

    printf("Estructura Info: a = %c, b = %d\n", info->a, info->b);

    free(info);  // Libera memoria
    return 0;
}
