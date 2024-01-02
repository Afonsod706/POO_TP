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
    Processador(const string &cmd = "") : comando(cmd), procId(proxId++) {};

    const int getNumRegras();
    void adicionarRegra(const Regra &novaRegra);
    int getId() const;
//    void listarRegras() const;
//    bool removerRegra(int regraId);
//    bool verificaRegras(const vector<Sensor> sensores) const;
//    void setComando(const string &cmd);
//    void verificaComando(const vector<Sensor> sensores);//não concluido

private:
    vector<Regra> regras;
    string comando;
    int procId;
    static int proxId;
};


#endif //POO_TP_PROCESSADOR_H
