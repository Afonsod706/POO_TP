//
// Created by afons on 22/11/2023.

#ifndef POO_TP_SENSOR_H
#define POO_TP_SENSOR_H
#include <string>
#include <vector>
#include "Propriedade.h"
using namespace std;

class Sensor {
public:
    Sensor(char c,const string &propOb);

    int getId()const;
    char getSimbolo()const;
    string getPropriedadeObervada()const;

    float lerPropriedade(const vector<Propriedade*> prop) const;

private:
    char tipo;
    string propriedadeObervada;
    int sensorId;
    static int proxId;

};


#endif //POO_TP_SENSOR_H
