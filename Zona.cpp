//
// Created by afons on 22/11/2023.
//

#include "Zona.h"

Zona::Zona(int id) : id(id), sensores(vector<Sensor*>()), processadores(vector<Processador*>())  {
    criarPropriedadesPadrao();
}

void Zona::criarPropriedadesPadrao() {
    propriedades.push_back(new Propriedade("Temperatura", 25.0, -273.0));
    propriedades.push_back(new Propriedade("Luz", 25.0, 0));
    propriedades.push_back(new Propriedade("Radiacao", 25.0, 0));
    propriedades.push_back(new Propriedade("Vibracao", 25.0, 0));
    propriedades.push_back(new Propriedade("Humidade", 25.0, 0, 100));
    propriedades.push_back(new Propriedade("Fumo", 25.0, 0, 100));
    propriedades.push_back(new Propriedade("Som", 25.0, 0));

}

char Zona::adicionaComponente(char tipo, const string descricao,Window &w1) {
    switch (tipo) {
        case 's':
            adicionarSensor(tipo, descricao,w1);
            return tipo;
        case 'p':
            adicionaProcessadorRegra(descricao,w1);
            return tipo;
        default: return 'n';
    }
}

const int Zona::obterId() {
    return id;
}

void Zona::adicionaProcessadorRegra(const string comando,Window &w1) {
    Processador* novoProcessador=new Processador(comando);
    processadores.push_back(novoProcessador);
    listarComponentes(w1);
}

void Zona::modificarPropriedade(const string nome, float novoValor, Window &w1) {

    for (auto &prop: propriedades) {
        if (prop->getNome() == nome) {

            if (novoValor >= prop->getValorMin() && novoValor <= prop->getValorMax()) {
                prop->setValor(novoValor, w1);
                w1 << "\nPropriedade Alterada\n" << nome << ":" << prop->getValor();
            } else {
                w1 << "Valor fora do intervalo aceitavel para" << nome << "\n";
            }
            listarComponentes(w1);
            // listarPropriedade(w1);
            return;
        }
    }
    w1 << "Propriedade :" << nome << " nao encontrado\n";
}

void Zona::adicionarSensor(char c, const string &nomeP,Window &w1) {
    sensores.push_back(new Sensor(nomeP));
    listarComponentes(w1);
}

void Zona::adicionarAparelho(const std::string &type) {
    aparelhos.push_back(Aparelhos(type));
}

void Zona::listarComponentes(Window &w1)  {
    w1 << "\ncomponente na zona:" << id;
    int t=sensores.size();
    w1 << "\nSensores:"<<t;
    for ( auto &sensor: sensores) {
        w1<<"entra aqui\n";
        w1 << "\n" << sensor->getSimbolo() << sensor->getId() << ":" << sensor->getPropriedadeObervada() << "="
           << sensor->lerPropriedade(propriedades);
    }
    t=processadores.size();
    w1 << "\nProcessadores:"<<t;
    for (auto &proce:processadores) {
        w1<<proce->getId()<<"-Num:"<<proce->getNumRegras()<<"\n";
    }
}

void Zona::listarPropriedade(Window &w1) {

    w1 << "Proriedades na zona " << id << ":\n";
    for (const auto &prop: propriedades) {
        w1 << "-" << prop->getNome() << ": Valor = " << prop->getValor() << "\n";
    }
}

