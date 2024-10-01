#ifndef TDAFRACCION_H_INCLUDED
#define TDAFRACCION_H_INCLUDED
#include <stdio.h>

// Definición de la estructura Fracción
typedef struct {
    int numerador;
    int denominador;
} Fraccion;

// Función para crear una fracción
Fraccion Set_crear_fraccion(int numerador, int denominador) {
    Fraccion f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

// Función para obtener el numerador
int Get_obtener_numerador(Fraccion f) {
    return f.numerador;
}

// Función para obtener el denominador
int Get_obtener_denominador(Fraccion f) {
    return f.denominador;
}

// Función para obtener el valor real de la fracción
float Get_valor_real(Fraccion f) {
    return (float)f.numerador / f.denominador;
}

// Función para sumar dos fracciones
Fraccion Get_sumar_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// Función para restar dos fracciones
Fraccion Get_restar_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// Función para multiplicar dos fracciones
Fraccion Get_multiplicar_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

// Función para dividir dos fracciones
Fraccion Get_dividir_fracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    return resultado;
}

// Función para imprimir una fracción
void imprimir_fraccion(Fraccion f) {
    printf("%d/%d\n", f.numerador, f.denominador);
}
#endif // TDAFRACCION_H_INCLUDED
