//
// Created by afons on 22/11/2023.
//

#include "Sensor.h"
#include <iostream>

int Sensor::proxId = 1;

Sensor::Sensor(const string &propOb):propriedadeObervada(propOb) {    sensorId = proxId++;};
Sensor::Sensor(char c, const string &propOb) : tipo(c), propriedadeObervada(propOb) {
    sensorId = proxId++;
}

int Sensor::getId() const {
    return sensorId;
}

char Sensor::getSimbolo() const {
    return tipo;
}

string Sensor::getPropriedadeObervada() const {
    return propriedadeObervada;
}

float Sensor::lerPropriedade(const vector<Propriedade *> prop)  {
    for (const auto &p: prop) {
        if (p->getNome() == propriedadeObervada) {
            return p->getValor();
        }
    }
    return -1;
}