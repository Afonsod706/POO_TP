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


using namespace term;
using namespace std;



class Habitacao {

public:
    Habitacao();

    Habitacao(int X, int Y);

//    void adicionarZona(int x, int y, Window &w);
    void removerZona(int zonaId, Window &wt);

    void ListaPropriedadeZona(int zonaId, Window &w1);

//    void listarZonas() const;
    void criarHabitacao(int nlinha, int nColunas, Terminal &t);

//    void limparHabitacao();
    int exiteZona(int x, int y);

    void listaComponente(int zonaId, Window &w1);
//
//    void mostrarHabitacao(term::Window &w) const;

    //  void exibir_habitacao(int y,int x) const;
    // ~Habitacao(){};
    void cria_zona(int linha, int coluna, Window &wt);

    void modificaPropriZona(string nome, int zonaId, float valor, Window &wt);

private:
    int tamanhoX{};
    int tamanhoY{};
    vector<vector<Zona>> zonas;
    vector<Window> janelas; // Vector de janelas para representar as zonas
    int proximoIdzona = 1;
    // Vetor de pares para associar ID da zona ao ponteiro para a janela correspondente
    vector<pair<int, Window *>> associacaoZonaJanela;
};


#endif //POO_TP_HABITACAO_H
