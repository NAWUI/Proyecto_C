#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USER 10
/*lista de prototipos*/
void ingreDatos();//funcion que guarda los datos en el struct y se guarda en el arreglo user[MAX_USER]
void mustraDatos();//mustra los datos guardados
void modifiDatos();//modifica los datos del struct
void guarDatos();//guardar datos en un arreglo llamado userOLD[MAX_USER]
void inicio();// funcion donde se inicia la secion y se pide nombre y contrasenia si es la primera vez que se inicie el programa te pide cargar los usuarios del admin
void ordenarAZ();// funcion que guarde los usuarios cargados en el arrglo userAZ[MAX_USER] Y QUE SEa DE FORMA RECURSIVA y lo muestra por pantalla
/*Fin Prototipo*/

/*lista de struct*/
typedef struct {
    int ID;
    char nombre[35];
    char apellido[35];
    char contrasenia[35];
    char comentario[120];
}Usuarios ;

typedef struct {
    int ID;
    char nombre[35];
    char apellido[35];
    char contrasenia[35];
    char comentario[120];
}UsuariosOLD ;
/*fin lista de struct*/

Usuarios user[MAX_USER];
int userCount = 0; // Número de usuarios ingresados

void ingreDatos() {
    if (userCount >= MAX_USER) {
        printf("No se pueden agregar más usuarios.\n");
        return;
    }

    Usuarios newUser;
    newUser.ID = userCount + 1;
    printf("Ingrese nombre: ");
    scanf("%s", newUser.nombre);
    printf("Ingrese apellido: ");
    scanf("%s", newUser.apellido);
    printf("Ingrese contrasenia: ");
    scanf("%s", newUser.contrasenia);
    printf("Ingrese comentario: ");
    scanf(" %[^\n]s", newUser.comentario);

    user[userCount] = newUser;
    userCount++;
}
void mustraDatos() {
    if (userCount == 0) {
        printf("No hay usuarios ingresados.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        printf("ID: %d\nNombre: %s\nApellido: %s\nContrasenia: %s\nComentario: %s\n\n",
               user[i].ID, user[i].nombre, user[i].apellido, user[i].contrasenia, user[i].comentario);
    }
}
void modifiDatos() {
    int id;
    printf("Ingrese el ID del usuario a modificar: ");
    scanf("%d", &id);

    if (id <= 0 || id > userCount) {
        printf("ID no válido.\n");
        return;
    }

    id--; // Para ajustar al índice del arreglo

    printf("Modificando datos del usuario con ID %d\n", id + 1);
    printf("Ingrese nuevo nombre: ");
    scanf("%s", user[id].nombre);
    printf("Ingrese nuevo apellido: ");
    scanf("%s", user[id].apellido);
    printf("Ingrese nueva contrasenia: ");
    scanf("%s", user[id].contrasenia);
    printf("Ingrese nuevo comentario: ");
    scanf(" %[^\n]s", user[id].comentario);

    printf("Datos modificados con éxito.\n");
}
UsuariosOLD userOLD[MAX_USER];
int userOLDCount = 0;

void guarDatos() {
    if (userOLDCount >= MAX_USER) {
        printf("No se pueden guardar más datos antiguos.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        userOLD[userOLDCount].ID = user[i].ID;
        strcpy(userOLD[userOLDCount].nombre, user[i].nombre);
        strcpy(userOLD[userOLDCount].apellido, user[i].apellido);
        strcpy(userOLD[userOLDCount].contrasenia, user[i].contrasenia);
        strcpy(userOLD[userOLDCount].comentario, user[i].comentario);
        userOLDCount++;
    }

    // Vaciar el arreglo user
    userCount = 0;

    printf("Datos guardados y el arreglo de usuarios se ha vaciado.\n");
}
void mostrarComentarios() {
    if (userCount == 0) {
        printf("No hay usuarios ingresados.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        printf("Nombre: %s\nApellido: %s\nComentario: %s\n\n",
               user[i].nombre, user[i].apellido, user[i].comentario);
    }
}
void mostrarListasGuardadas() {
    if (userOLDCount == 0) {
        printf("No hay usuarios antiguos guardados.\n");
    } else {
        printf("\n-- Lista de Usuarios Antiguos --\n");
        for (int i = 0; i < userOLDCount; i++) {
            printf("ID: %d\nNombre: %s\nApellido: %s\nContrasenia: %s\nComentario: %s\n\n",
                   userOLD[i].ID, userOLD[i].nombre, userOLD[i].apellido, userOLD[i].contrasenia, userOLD[i].comentario);
        }
    }

    if (userCount == 0) {
        printf("\nNo hay usuarios actuales en el sistema.\n");
    } else {
        printf("\n-- Lista de Usuarios Ordenados (A-Z) --\n");
        for (int i = 0; i < userCount; i++) {
            printf("ID: %d\nNombre: %s\nApellido: %s\nContrasenia: %s\nComentario: %s\n\n",
                   user[i].ID, user[i].nombre, user[i].apellido, user[i].contrasenia, user[i].comentario);
        }
    }
}

void swap(Usuarios *a, Usuarios *b) {
    Usuarios temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarAZRecursivo(int n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (strcmp(user[i].nombre, user[i + 1].nombre) > 0) {
            swap(&user[i], &user[i + 1]);
        }
    }

    ordenarAZRecursivo(n - 1);
}

void ordenarAZ() {
    if (userCount == 0) {
        printf("No hay usuarios para ordenar.\n");
        return;
    }

    ordenarAZRecursivo(userCount);
    printf("Usuarios ordenados alfabéticamente por nombre.\n");
}
int main() {
    int opcion;

    do {
        printf("\n---Menu---\n");
        printf("(1)-Ingresar Usuario\n");
        printf("(2)-Mostrar Usuarios\n");
        printf("(3)-Modificar Usuarios\n");
        printf("(4)-Mostrar comentarios de los usuarios\n");
        printf("(5)-Ordenar Y guardar datos de A-Z (Nombre)\n");
        printf("(6)-Guardar datos viejos (vacía lista actual)\n");
        printf("(7)-Mostrar listas guardadas\n");
        printf("(0)-Salir del sistema\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingreDatos();
                break;
            case 2:
                mustraDatos();
                break;
            case 3:
                modifiDatos();
                break;
            case 4:
                mostrarComentarios();
                break;
            case 5:
                ordenarAZ();
                break;
            case 6:
                guarDatos();
                break;
            case 7:
                mostrarListasGuardadas();
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

