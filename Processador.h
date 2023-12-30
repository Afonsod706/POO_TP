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
    Processador(const string &cmd =""):comando(cmd){};

    void adicionarRegra(const string &novaRegra);
    void listarRegras( ) const;
    void removerRegra(const string &novaRegra);
    void setComando(const string &cmd);
    void verificaRegras();//não concluido
    void verificaComando();//não concluido

    ~Processador();
private:
   vector<Regra> regras;
   string comando;
   int procId;
};


#endif //POO_TP_PROCESSADOR_H
