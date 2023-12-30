//
// Created by afons on 22/11/2023.
//

#include "Zona.h"


Zona::Zona(int id) : id(id) {
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

const int Zona::obterId() {
    return id;
}

void Zona::modificarPropriedade(const string nome, float novoValor, Window &w1) {
    w1 << "entra aqui\n";
    for (auto &prop: propriedades) {
        if (prop->getNome() == nome) {
            w1 << "encontra aqui\n";
            if (novoValor >= prop->getValorMin() && novoValor <= prop->getValorMax()) {
                prop->setValor(novoValor, w1);
                w1 << "\nPropriedade Alterada\n" << nome << ":" << prop->getValor();
            } else {
                w1 << "Valor fora do intervalo aceitavel para" << nome << "\n";
            }
            // listarPropriedade(w1);
            return;
        }
    }
    w1 << "Propriedade :" << nome << " nao encontrado\n";
}

void Zona::adicionarSensor(const std::string &type) {
    sensores.push_back(Sensor(type));
}

void Zona::adicionarAparelho(const std::string &type) {
    aparelhos.push_back(Aparelhos(type));
}

void Zona::listarComponentes(Window &w1) const {
    w1 << "\ncomponente na zona:" << id;
}

void Zona::listarPropriedade(Window &w1) {
    w1 << "Proriedades na zona " << id << ":\n";
    for (const auto &prop: propriedades) {
        w1 << "-" << prop->getNome() << ": Valor = " << prop->getValor() << "\n";
    }
}


//void Zona::mostrarInformacoes() const {
//    std::cout << "Zona na posição (" << x << ", " << y << ")\n";
//    for (const auto& sensor : sensor) {
//        sensor.detect();
//    }
//    for (const auto& aparelho : aparelho) {
//        aparelho.ligar();
//    }
//}