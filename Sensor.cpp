//
// Created by afons on 22/11/2023.
//

#include "Sensor.h"
#include <iostream>

Sensor::Sensor(const std::string& type) : type(type) {}

void Sensor::detect() const {
    std::cout << "Sensor " << type << " detectou algo.\n";
}
