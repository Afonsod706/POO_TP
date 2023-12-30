// Arquivo: InterfaceC.h


#ifndef POO_TP_INTERFACEC_H
#define POO_TP_INTERFACEC_H

#include "curses.h"
#include <vector>
#include "Terminal.h"
#include <cstring>
#include <fstream>
#include "Habitacao.h"
#include "Zona.h"
#include "Propriedade.h"

using namespace std;
using namespace term;

namespace inter {

    class Interface{
    private:
        Terminal *t;           // Ponteiro para uma instância do Terminal
        Window w1;              // Janela 1
        Window w2;              // Janela 2
        Window w3;              // Janela 3
        vector<Propriedade> prop;
        Habitacao habitacao;
        int instanteAtual;//instante para control de instancias
        bool flagHabitacao;// flag para controlar habitação se esta criada ou não
        vector<Zona> zonas;
        vector<string> parametros;  // Vetor para armazenar parâmetros
        vector<Window> janelas;


    public:
        void criarPropriedadesPadrao();
        // Construtor
        Interface() : t(&Terminal::instance()), // Inicializa o ponteiro para a instância de Terminal
                      w1(0, 0, 40, 24, true),  // Inicializa a janela w1  informacao
                      w2(41, 0, 79, 24, true), // Inicializa a janela w2 visualizacao
                      w3(0, 24, 120, 6, true), flagHabitacao(false) // Inicializa a janela w3 comandos
        {}

        void cria_nova_habitacao(int linhas, int colunas);
        void remove_Habitacao();
        // Inicia a interface
        void startInterface();
        // Lê o comando
        void ler_comando();
        // Conta o número de parâmetros
        int contaParametro(string &input);
        void cria_zona(int linhas,int colunas);
        void remover_zona(int idZona);
        void Zprops(int idZona);
        void Pmod(int idzona,string nome,float valor);

    };

}

#endif //POO_TP_INTERFACEC_H
