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
    Regra(const string &tp,float v1,float v2);
    string getTipo() const;
    int getValor1 () const;
    int getValor2() const;
private:
    float valor1;
    string tipo;
    float valor2;
};


#endif //POO_TP_REGRA_H
