//
// Created by afons on 26/11/2023.
//

#ifndef POO_TP_HABITACAO_H
#define POO_TP_HABITACAO_H

#include <iostream>
#include "curses.h"
#include "Terminal.h"
#include "Zona.h"
#include "Propriedade.h"
#include <vector>
#include <map>

using namespace term;
using namespace std;

class Habitacao {

public:
    Habitacao(); // Construtor padrão

    Habitacao(int X, int Y); // Construtor com parâmetros X e Y

    void removerZona(int zonaId, Window &wt); // Remove uma zona da habitação

    void ListaPropriedadeZona(int zonaId, Window &w1); // Lista propriedades de uma zona específica

    void criarHabitacao(int nlinha, int nColunas, Terminal &t); // Cria uma habitação com linhas e colunas

    int exiteZona(int x, int y); // Verifica se uma zona existe em uma posição específica

    void listaComponente(int zonaId, Window &w1); // Lista componentes de uma zona

    void adicionaCompomentes(int ZonaId, char tipo, const string descricao, Window &w1); // Adiciona componentes a uma zona

    void cria_zona(int linha, int coluna, Window &wt); // Cria uma zona em uma determinada posição

    void modificaPropriZona(string nome, int zonaId, float valor, Window &wt); // Modifica a propriedade de uma zona

private:
    int tamanhoX{}; // Tamanho X da habitação
    int tamanhoY{}; // Tamanho Y da habitação
    vector<vector<Zona>> zonas; // Vetor bidimensional de zonas
    vector<Window> janelas; // Vetor de janelas para representar as zonas
    int proximoIdzona = 1; // Próximo ID de zona a ser utilizado
    vector<Processador> Processadores; // Vetor de processadores
    // Vetor de pares para associar ID da zona ao ponteiro para a janela correspondente
    map<int, Window*> associacaoZonaJanela;

};

#endif //POO_TP_HABITACAO_H
