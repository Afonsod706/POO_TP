//
// Created by afons on 22/11/2023.
//

#ifndef POO_TP_REGRA_H
#define POO_TP_REGRA_H
#include <string>
#include <iostream>
#include <vector>
#include "Terminal.h"
#include <algorithm>

using namespace std;
using namespace term;
class Regra {
public:
    Regra(int id, const string& tipo, int sensorId );
    int getId() const;
    string getTipo() const;
    int getSensorId () const;
    void mostrarInformacao(Window w) const;
private:
    int id;
    string tipo;
    int sensorId;
};


#endif //POO_TP_REGRA_H
