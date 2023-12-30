//
// Created by afons on 22/11/2023.

#ifndef POO_TP_SENSOR_H
#define POO_TP_SENSOR_H
#include <string>

class Sensor {
public:
    Sensor(const std::string& type);
    void detect() const;

private:
    std::string type;
};


#endif //POO_TP_SENSOR_H
