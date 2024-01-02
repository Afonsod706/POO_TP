//
// Created by afons on 22/11/2023.
//

#include "Processador.h"

int Processador::proxId = 1;

void Processador::adicionarRegra(const Regra &novaRegra) {
    regras.push_back(novaRegra);
}

int Processador::getId() const {
    return procId;
}
const int Processador::getNumRegras() {
    return regras.size();
}

//bool Processador::removerRegra(int regraId) {
//    for(auto it =regras.begin();it!=regras.end();++it){
//        if(it->getId()==regraId){
//            it=regras.erase(it);//rmove o elemento e atualiza o iterador
//            return true;
//        }
//    }
//    return false;
//}