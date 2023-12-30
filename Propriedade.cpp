//
// Created by afons on 28/12/2023.
//
#include "Propriedade.h"

void Propriedade::setValor(float v,term::Window &w1) {
    if (v >= min && v <= max) {
        valor = v ;
       // w1<<"\nvalor alterado:"<<valor<<" MIN:"<<min<<" MAX:"<<max;
    } else {
        //mensagem que esta fora do limite;
        w1<<"\nvalor fora dos limite :"<<v;
    }
}



string Propriedade::getNome() const {
    return nome;
}

float Propriedade::getValor()  const{
    return valor;
}

float Propriedade::getValorMax() {
    return max;
}

float Propriedade::getValorMin(){
    return min;

}