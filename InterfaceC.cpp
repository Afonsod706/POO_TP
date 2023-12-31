//
// Created by afons on 22/11/2023.
//
#include "InterfaceC.h"


namespace inter {

    int Interface::contaParametro(string &input) {
        parametros.clear();
        istringstream iss(input);
        int nparametros = 0;
        string token;

        while (iss >> token) {
            if (nparametros == 0) {
                input = token;
            } else {
                parametros.push_back(token);
            }
            ++nparametros;
        }
        return nparametros - 1;

    }

    void Interface::remove_Habitacao() {
        if (flagHabitacao)
            habitacao = Habitacao(0, 0);
        flagHabitacao = false;
        w1 << "habitacao foi destruida";
    }

    void Interface::cria_nova_habitacao(int linhas, int colunas) {
        if (flagHabitacao) {
            w1.clear();
            w1 << "Habitacao ja existe\n";
            return;
        }
        if (linhas < 2 || linhas > 4 || colunas < 2 || colunas > 4) {
            w1.clear();
            w1 << set_color(4) << "num invalido linha/coluna.\nApenas entre 2 e 4\n";
            return;
        }
        habitacao = Habitacao(colunas, linhas);
        w2.clear();
        habitacao.criarHabitacao(linhas, colunas, reinterpret_cast<Terminal &>(t));
        flagHabitacao = true;
        w1 << set_color(2) << "Nova Habitacao criada com sucesso\n";
    }

    void Interface::cria_zona(int linhas, int colunas) {

        if (!flagHabitacao) {
            w1.clear();
            w1 << "Habitacao nao ja existe\n";
            return;
        }
        if (habitacao.exiteZona(linhas, colunas) == 0) {
            habitacao.cria_zona(linhas, colunas, w1);

        } else {
            w1.clear();
            w1 << "ja existe zona";
        }


    }

    void Interface::Pmod(int idzona, string nome, float valor) {
        if (flagHabitacao)
            habitacao.modificaPropriZona(nome,idzona,valor,w1);
        else
            w1 << "habitacao nao existe\n";
    }

    void Interface::remover_zona(int idZona) {
        if (flagHabitacao)
            habitacao.removerZona(stoi(parametros[0]), w1);
        else
            w1 << "habitacao nao existe\n";
    }

    void Interface::Zprops(int idZona) {
        if (flagHabitacao)
            habitacao.ListaPropriedadeZona(idZona, w1);
        else
            w1 << "habitacao nao existe\n";

    }

    void Interface::startInterface() {


        //incializa ou define as cores do terminal a ser usadas posteriormente
        for (int i = 0; i < 20; i++)
            t->init_color(i, i, 0);

        // Criação das três janelas

        // Janela 1
        w1 << set_color(0) << "Janela 1 ";
        //w1.getchar(); // Aguarda uma tecla
        w2 << set_color(0) << "Janela 2 ";


        ler_comando();

//        // Janela 2
//        w2 << set_color(0) << "Janela 2 ";
//        // Janela 3 com comandos
//        w3 << set_color(3) << "Janela 3";

        w1 << set_color(0) << "Sair...Pressione uma tecla";
        t->getchar(); //aguarda uma tecla antes de fechar
        w1.clear();
        endwin(); // Encerra o ambiente do terminal
    }


    void Interface::ler_comando() {
        bool sair = false;
        string comando;
        string leitura_ficheiro;
        ifstream ficheiro;
        int numLinhaFicheiro = 0;
        int tipo = 0, i = 0, linha, coluna;


        while (!sair) {

            //limpa a janela 3 para receber um novo comando
            w3.getchar();
            w3.clear();

            if (tipo == 1) {
                if (i < numLinhaFicheiro) {
                    getline(ficheiro, comando);
                    ++i;
                    w3 << set_color(0) << "\n" << i << "\n" << numLinhaFicheiro;
                } else {
                    ficheiro.close(); // Fecha o arquivo após a leitura
                    tipo = 0;
                    numLinhaFicheiro = 0;
                    i = 0;
                    w3 << set_color(0) << "\n<<estava aqui";
                    continue;

                }
            } else {
//                    //limpa a janela 3 para receber um novo comando
//                   w3.getchar();
                w3 << set_color(0) << "comando#> ";
                w3 << set_color(1) >> comando;
            }

            //função que retorna o numero de paramentros
            int nParametro = contaParametro(comando);
            //serve apenas para verificar se os parametros estão a ser bem distribuidos
            w3 << set_color(0) << "N:" << nParametro << "[" << comando;
            for (int j = 0; j < nParametro; ++j) {
                w3 << "_" << parametros[j] << "_";
            }
            w3 << set_color(0) << "]";

            if (nParametro == 0) {
                if (comando == "sair") {
                    sair = true;
                    w1.clear();
                } else if (comando == "prox") {
                    w1 << set_color(2) << "\ncomando valido:[" << comando << "]\n";
                    w2 << "HABITACAO";
                } else if (comando == "clear") {
                    w1.clear();
                    w2.clear();
                    w1 << set_color(6) << "1\n";
                    w2 << set_color(6) << "2 \n";
                } else if (comando == "zlista") {
                    w1 << set_color(2) << "comando valido:[" << comando << "]\n";
                    //    habit.mostrarHabitacao(w2);
                    //habit.listarZonas();
                } else if (comando == "plista") {
//                        w1.clear();
                    w1 << set_color(2) << "\ncomando valido:[" << comando << "]\n";
                } else if (comando == "hrem") {
//                        w1.clear();
                    remove_Habitacao();
                    w1 << set_color(2) << "comando valido:[" << comando << "]\n";
                    // habit.limparHabitacao();
                } else {
//                        w1.clear();
                    w1 << set_color(4) << "comando invalido[" << comando << "]\n";
                }
            } else if (nParametro == 1) {
                if (comando == "prem") {

                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_nome\n";
                } else if (comando == "avanca") {
//                        w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_ <n>\n";
                } else if (comando == "prepoe") {
//                        w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_ <nome> \n";
                } else if (comando == "zcomp") {
//                        w1.clear();
habitacao.listaComponente(stoi(parametros[0]),w1);
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_ID zona\n";
                } else if (comando == "zprops") {
                    w1.clear();
                    Zprops(stoi(parametros[nParametro - 1]));
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_ID zona\n";
                } else if (comando == "zrem") {
                    w1.clear();
                    remover_zona(stoi(parametros[nParametro - 1]));
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_ID zona\n";
                } else if (comando == "exec" && tipo != 1) {
                    w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << " <nome de ficheiro>\n";
                    // Certifique-se de que 'nParametro' está definido corretamente
                    // Verificar se 'parametros[nParametro]' contém o nome do arquivo
                    if (parametros[nParametro - 1] == "comandos.txt") {

                        ficheiro.open(parametros[nParametro - 1]);
                        if (ficheiro.is_open()) { // Verifica se o arquivo foi aberto com sucesso para leitura
                            w1 << "\nConteudo do arquivo:\n";
                            while (getline(ficheiro, comando)) {
                                ++numLinhaFicheiro;
                                w1 << numLinhaFicheiro << "\n"; // Exibe cada linha do arquivo na janela
                            }
                            ficheiro.clear();  // Limpar as flags de erro do arquivo
                            ficheiro.seekg(0); // Retornar ao início do arquivo
                            tipo = 1;
                        } else {
                            w1 << "Erro ao abrir o arquivo para leitura.\n"; // Exibe uma mensagem de erro na janela
                        }
                        w1 << set_color(2) << "Os dados foram lidos do arquivo.\n";

                    } else {
                        w1 << set_color(2) << "\n nome do ficheiro errado\n";
                    }
                } else {
                    w1.clear();
                    w1 << set_color(4) << "comando invalido[" << comando << "]";
                }
            } else if (nParametro == 2) {
                if (comando == "znova") {

                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_linha_coluna\n";
                    linha = stoi(parametros[0]);
                    coluna = stoi(parametros[1]);
                    //verifica se ja existe uma zona se não adiciona
//                    if (habit.exiteZona(linha, coluna) == 0) {
//                        habit.adicionarZona(linha, coluna, w2);
//                    } else {
//                        w2 << "ja existe uma zona aqui\n";
//                    }
                    cria_zona(linha, coluna);
                } else if (comando == "rlista") {
                    //   w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_ID zona_proc regras\n";
                } else if (comando == "hnova") {
                    //w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]_<num linhas> <num colunas>\n";
                    linha = stoi(parametros[0]);
                    coluna = stoi(parametros[1]);
                    cria_nova_habitacao(linha, coluna);
                } else {
                    w1 << set_color(4) << "comando invalido[" << comando << "]";
                }
            } else if (nParametro == 3) {
                if (comando == "pmuda") {
                    //  w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando
                       << "]\n<ID zona> <ID proc. regras> <novo comando>\n";
                } else if (comando == "asoc") {
                    //  w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando
                       << "]\n<ID zona> <ID proc. regras> <ID aparelho>\n";
                } else if (comando == "rrem") {
                    //   w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando
                       << "]\n<ID zona> <ID proc. regras> <ID regra>a\n";
                } else if (comando == "crem ") {
                    //  w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]\n<ID zona> <s | p | a> <ID>\n";
                } else if (comando == "cnovo") {
                       w1.clear();
                       habitacao.adicionaCompomentes(stoi(parametros[0]),parametros[1][0],parametros[2],w1);
                    w1 << set_color(2) << "comando valido:\n[" << comando
                       << "]\n<ID zona> <s | p | a> <tipo | comando>\n";
                } else if (comando == "psalva") {
                    //  w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]\n<ID zona> <ID proc. regras> <nome>\n";
                } else if (comando == "acom") {
                    // w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando << "]\n<ID zona> <ID aparelho> <comando>\n";
                } else if (comando == "ades") {
                    // w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando
                       << "]\n<ID zona> <ID proc. regras> <ID aparelho>\n";
                } else if (comando == "pmod") {
                     w1.clear();
                     w1<<parametros[0]<<parametros[1]<<parametros[2];
                    Pmod(stoi(parametros[0]),parametros[1],stof(parametros[2]));
                    w1 << set_color(2) << "\ncomando valido:\n[" << comando << "]\n<ID zona> <nome> <valor> \n";
                } else {
                    // w1.clear();
                    w1 << set_color(4) << "comando invalido[" << comando << "]";
                }
            } else if (nParametro > 4) {
                if (comando == "rnova") {
                    // w1.clear();
                    w1 << set_color(2) << "comando valido:\n[" << comando
                       << "]\na <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]\n";
                } else {
                    // w1.clear();
                    w1 << set_color(4) << "comando invalido[" << comando << "]";
                }
            }

        }


    }
}
