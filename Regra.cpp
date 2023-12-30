//
// Created by afons on 22/11/2023.
//

#include "Regra.h"

Regra::Regra(const string &tp, float v1, float v2) : tipo(tp), valor1(v1), valor2(v2) {};

int Regra::getValor2() const {
    return valor2;
}

int Regra::getValor1() const {
    return valor1;
}

string Regra::getTipo() const {
    return tipo;
}
