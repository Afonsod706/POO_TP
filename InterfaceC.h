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

    class Interface {
    private:
        Terminal *t;           // Ponteiro para uma instância do Terminal
        Window w1;              // Janela 1 para informações
        Window w2;              // Janela 2 para visualização
        Window w3;              // Janela 3 para comandos
        vector<Propriedade> prop; // Vetor de propriedades
        Habitacao habitacao;       // Objeto da classe Habitacao
        int instanteAtual;         // Instante para controle de instâncias
        bool flagHabitacao;        // Flag para controlar se a habitação está criada ou não
        vector<Zona> zonas;       // Vetor de zonas
        vector<string> parametros; // Vetor para armazenar parâmetros
        vector<Window> janelas;   // Vetor de janelas

    public:
        // Cria as propriedades padrão
        void criarPropriedadesPadrao();

        // Construtor
        Interface() : t(&Terminal::instance()), // Inicializa o ponteiro para a instância de Terminal
                      w1(0, 0, 40, 24, true),  // Inicializa a janela w1 para informações
                      w2(41, 0, 79, 24, true), // Inicializa a janela w2 para visualização
                      w3(0, 24, 120, 6, true), flagHabitacao(false) // Inicializa a janela w3 para comandos
        {}

        // Cria uma nova habitação com base no número de linhas e colunas
        void cria_nova_habitacao(int linhas, int colunas);

        // Remove a habitação atual
        void remove_Habitacao();

        // Inicia a interface
        void startInterface();

        // Lê o comando
        void ler_comando();

        // Conta o número de parâmetros em uma string de entrada
        int contaParametro(string &input);

        // Cria uma nova zona com base no número de linhas e colunas
        void cria_zona(int linhas, int colunas);

        // Remove uma zona com base no ID da zona
        void remover_zona(int idZona);

        // Mostra as propriedades de uma zona específica
        void Zprops(int idZona);

        // Modifica uma propriedade de uma zona com base no ID da zona, nome da propriedade e valor
        void Pmod(int idzona, string nome, float valor);
    };

}

#endif //POO_TP_INTERFACEC_H
