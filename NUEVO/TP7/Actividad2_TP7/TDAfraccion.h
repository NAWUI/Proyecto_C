#include "TDAfraccion.h"
#include <stdio.h>

Fraccion init_fraccion(int numerador, int denominador) {
    Fraccion f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

int get_numerador(Fraccion f) {
    return f.numerador;
}

int get_denominador(Fraccion f) {
    return f.denominador;
}

float get_valor_real(Fraccion f) {
    return (float)f.numerador / f.denominador;
}

Fraccion sumar(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

Fraccion restar(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

Fraccion multiplicar(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

Fraccion dividir(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    return resultado;
}
