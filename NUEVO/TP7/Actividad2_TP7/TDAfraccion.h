#ifndef TDAFRACCION_H_INCLUDED
#define TDAFRACCION_H_INCLUDED
#include <stdio.h>

// Definici�n de la estructura Fracci�n
typedef struct {
    int numerador;
    int denominador;
} Fraccion;

// Funci�n para crear una fracci�n
Fraccion Set_crear_fraccion(int numerador, int denominador) {
    Fraccion f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

// Funci�n para obtener el numerador
int Get_obtener_numerador(Fraccion f) {
    return f.numerador;
}

// Funci�n para obtener el denominador
int Get_obtener_denominador(Fraccion f) {
    return f.denominador;
}

// Funci�n para obtener el valor real de la fracci�n
float Get_valor_real(Fraccion f) {
    return (float)f.numerador / f.denominador;
}

// Funci�n para sumar dos fracciones
Fraccion Get_sumar_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// Funci�n para restar dos fracciones
Fraccion Get_restar_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// Funci�n para multiplicar dos fracciones
Fraccion Get_multiplicar_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// Funci�n para dividir dos fracciones
Fraccion Get_dividir_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    return resultado;
}

// Funci�n para imprimir una fracci�n
void imprimir_fraccion(Fraccion f) {
    printf("%d/%d\n", f.numerador, f.denominador);
}
#endif // TDAFRACCION_H_INCLUDED
