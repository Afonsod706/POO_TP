//
// Created by afons on 22/11/2023.
//

#ifndef POO_TP_ZONA_H
#define POO_TP_ZONA_H

#include <string>
#include <vector>
#include <iostream>
#include "Terminal.h"
#include "Sensor.h"
#include "Aparelhos.h"
#include "Processador.h"
#include "Propriedade.h"

using namespace term;
using namespace std;

class Zona {
public:
    Zona(int id);

    const int  obterId() ; //pega o id da zona
    // Modificar o valor da propriedade na zona, se existir
    void modificarPropriedade(const string nome, float novoValor,Window &w1);

    // Iterar e listar os componentes da zona com seus tipos, IDs, nomes e estados
    void listarComponentes(Window &w1) const;

    // Listar propriedades reconhecidas na zona
    void listarPropriedade(Window &w1) ;


    // Adicionar um novo componente à zona com base no tipo e na descrição(tipo|comando)
    void adicionaComponente(char tipo, const string descricao);

    void adicionarSensor(char c,const string &nomeP);

    void adicionarAparelho(const string &type);

    //Remover o componente da zona com base no tipo e no ID
    void removerComponente(const char tipo, int idComp);

    void mostraInfo(Window w2) const;

//    void adicionarSensor(const std::string& type);
//    void adicionarAparelho(const std::string& type);
//    void mostrarInformacoes() const;

    void criarPropriedadesPadrao();


private:

    int id;// adiciona id
    vector<Propriedade *> propriedades;
    vector<Sensor> sensores;
    vector<Aparelhos> aparelhos;
    //vector<Processador> processadores;

};


#endif //POO_TP_ZONA_H
