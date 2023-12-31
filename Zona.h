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

    const int  obterId() ; // Obtém o ID da zona

    // Modifica o valor da propriedade na zona, se existir
    void modificarPropriedade(const string nome, float novoValor, Window &w1);

    // Itera e lista os componentes da zona com seus tipos, IDs, nomes e estados
    void listarComponentes(Window &w1);

    // Lista propriedades reconhecidas na zona
    void listarPropriedade(Window &w1);

    // Adiciona um novo componente à zona com base no tipo e na descrição (tipo | comando)
    char adicionaComponente(char tipo, const string descricao, Window &w1);

    // Adiciona um sensor à zona
    void adicionarSensor(char c, const string &nomeP, Window &w1);

    // Adiciona um processador de regra à zona
    void adicionaProcessadorRegra(const string comando, Window &w1);

    // Adiciona um aparelho à zona
    void adicionarAparelho(const string &type);

    // Remove o componente da zona com base no tipo e no ID
    void removerComponente(const char tipo, int idComp);

    // Mostra informações (não está implementada no código fornecido)
    void mostraInfo(Window w2) const;

    // Cria propriedades padrão na zona
    void criarPropriedadesPadrao();

private:
    int id; // ID da zona
    vector<Propriedade*> propriedades; // Vetor de propriedades
    vector<Sensor*> sensores; // Vetor de sensores
    vector<Aparelhos> aparelhos; // Vetor de aparelhos
    vector<Processador*> processadores; // Vetor de processadores
};

#endif //POO_TP_ZONA_H
