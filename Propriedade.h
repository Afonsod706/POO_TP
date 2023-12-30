//
// Created by afons on 28/12/2023.
//

#ifndef POO_TP_PROPRIEDADE_H
#define POO_TP_PROPRIEDADE_H

#include <string>
#include <limits>
#include "Terminal.h"
using namespace std;

class Propriedade {
public:
    Propriedade(const string &n, float v = 0, float mn = -numeric_limits<float>::max(),
                float mx = numeric_limits<float>::max()) : nome(n), valor(v), min(mn), max(mx) {};

    string getNome() const ;

    float getValor() const ;

    float getValorMin() ;

    float getValorMax() ;

    void setValor(float v,term::Window &w1);

private:
    string nome;
    float min;
    float max;
    float valor;
};

#endif //POO_TP_PROPRIEDADE_H
