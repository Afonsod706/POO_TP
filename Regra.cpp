//
// Created by afons on 22/11/2023.
//

#include "Regra.h"

Regra::Regra(int id, const string &tipo, int sensorId): id(id), tipo(tipo), sensorId(sensorId) {}
int Regra::getId() const {
    return id;
}

int Regra::getSensorId() const {
    return sensorId;
}

string Regra::getTipo() const {
    return tipo;
}

void Regra::mostrarInformacao(Window w) const {
    w<< "ID: " << id << ", Tipo: " << tipo << ", Sensor ID: " << sensorId << "\n";
}