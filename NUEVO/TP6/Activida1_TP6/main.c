#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct alumno{
    char nombre;
    char registro;
    char carrera;
};

int main()
{

struct alumno *alu;
alu=(struct alumno *) malloc(sizeof(struct alumno));
printf("%i", alu);
}
