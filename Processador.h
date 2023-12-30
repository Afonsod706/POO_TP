//
// Created by afons on 22/11/2023.
//

#ifndef POO_TP_PROCESSADOR_H
#define POO_TP_PROCESSADOR_H
#include "Regra.h"
#include <string>
#include <iostream>
#include <vector>
#include "Terminal.h"

class Processador {
public:
    Processador();
    void adicionarRegra(int idRegra,int idSensore);
    void listarRegras( ) const;
    void removerRegra(int id);

    ~Processador();
private:
    int idRegra=0;
    int idSensor=0;
    vector <Regra> * regras;
};


#endif //POO_TP_PROCESSADOR_H
