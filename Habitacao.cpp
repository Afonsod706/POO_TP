
//
// Created by afons on 26/11/2023.
//

#include "Habitacao.h"

Habitacao::Habitacao() {};

Habitacao::Habitacao(int X, int Y) : tamanhoX(X), tamanhoY(Y) {
    zonas.resize(tamanhoY, vector<Zona>(tamanhoX, Zona(0)));
    janelas.clear(); // Limpa o vetor de janelas antes de criar novas
    janelas.reserve(tamanhoX * tamanhoY);
}


int Habitacao::exiteZona(int x, int y) {
    if (y >= 0 && y < tamanhoY && x >= 0 && x < tamanhoX)
        return zonas[x][y].obterId(); // Zona não encontrada após percorrer todas as zonas nada
    return 0;
}

void Habitacao::removerZona(int zonaId, Window &wt) {

    for (auto &linha: zonas) {
        for (auto &zona: linha) {
            if (zona.obterId() == zonaId) {
                // wt<<"\n2for:zona.obterId="<<zona.obterId();
                // Remove a associação correspondente à zona
                for (auto it = associacaoZonaJanela.begin(); it != associacaoZonaJanela.end(); ++it) {
                    if (it->first == zonaId) {
                        it->second->clear();
                        *it->second << "zona bazou";
                        associacaoZonaJanela.erase(it);
                        // Marca a zona como não utilizada
                        zona = Zona(0);
                        //  wt<<"\nCHEGOU id-zona:"<<zona.obterId();
                        return; // Sai da função após remover a zona e a associação
                    }
                }


            } else {
                // wt<<"\nERRO id-zona:"<<zonaId<<"-zona.obterId="<<zona.obterId();
            }
        }
    }
    wt << "zona nao encontrada\n";
}

void Habitacao::ListaPropriedadeZona(int zonaId, Window &w1) {
    for ( auto linha: zonas) {
        for ( auto zona: linha) {
            if (zona.obterId() == zonaId) {
                zona.listarPropriedade(w1);
            }
        }
    }
}

void Habitacao::listaComponente(int zonaId, Window &w1) {
    for ( auto linha: zonas) {
        for ( auto zona: linha) {
            if (zona.obterId() == zonaId) {
                zona.listarComponentes(w1);
            }
        }
    }
}

void Habitacao::modificaPropriZona(string nome, int zonaId, float valor, Window &wt) {

    for (const auto linha: zonas) {

        for ( auto zona: linha) {

            if (zona.obterId() == zonaId) {
                zona.modificarPropriedade(nome, valor, wt);
                return;
            }
        }
    }
    wt<<"Zona nao encontrada\n";
}

void Habitacao::cria_zona(int linha, int coluna, Window &w1) {
    if (linha >= 0 && linha < tamanhoY && coluna >= 0 && coluna < tamanhoX) {
        // w1 << "teve aqui " <<coluna<<linha<< tamanhoX << tamanhoY;
        zonas[linha][coluna] = Zona(proximoIdzona++);
        // Associa a zona atual à sua janela correspondente no vetor de pares
        associacaoZonaJanela.emplace_back(
                make_pair(zonas[linha][coluna].obterId(),&janelas[linha * tamanhoX + coluna]));

        // Limpa  janela
        janelas[linha * tamanhoX + coluna].clear();
        // Busca pela zona no vetor de associação
        for (const auto &associacao: associacaoZonaJanela) {
            if (associacao.first == zonas[linha][coluna].obterId()) {
                // Adiciona o texto na janela correspondente à zona
                *(associacao.second) << set_color(5) << "zona:" << zonas[linha][coluna].obterId();
                zonas[linha][coluna].listarComponentes(*(associacao.second));
                break; // Sai do loop depois de encontrar a associação
            }
        }
        w1.clear();
        w1 << "zona adicionada";
    } else {
        w1 << "zona em posicao invalida\n";
    }

}


void Habitacao::criarHabitacao(int nlinhas, int nColunas, Terminal &t) {
    const int w2_pos_x = 41;
    const int w2_pos_y = 0;
    const int w2_width = 79 - 2; // Largura efetiva considerando a margem de 2
    const int w2_height = 24 - 2; // Altura efetiva considerando a margem de 2

    // Calcula a altura disponível para cada janela
    int janelaAltura = (w2_height - (nlinhas + 1) * 2) / nlinhas;

    // Calcula a largura disponível para cada janela
    const int janelaLargura = (w2_width - (nColunas + 1) * 2) / nColunas;
    const int posx = janelaLargura + 2; // Espaço horizontal entre as janelas considerando a margem
//    if (nlinhas == 3) janelaAltura = 5;
    const int posy = janelaAltura + 2; // Espaço vertical entre as janelas considerando a margem
    janelaAltura = max(janelaAltura,
                       5);// Garante que a altura não seja menor que 5 feita depois de atribuir as posições das janelas para garantir maximização das janelas
//    if (nlinhas == 3)
//        janelaAltura = 7;
    janelas.clear(); // Limpa o vetor de janelas antes de criar novas

    // Cria um vetor de janelas sem sobreposição
    for (int i = 0; i < nlinhas * nColunas; ++i) {
        const int x = w2_pos_x + 2 + (i % nColunas) * posx; // Margem + espaçamento horizontal
        const int y = w2_pos_y + 2 + (i / nColunas) * posy; // Margem + espaçamento vertical

        janelas.emplace_back(
                t.create_window(x, y, janelaLargura, janelaAltura, true)
        );
    }
}


//void Habitacao::exibir_habitacao(int y,int x) const {
//    int janelaLagura=15;
//    int janelaAltura=8;
//}


//
//
//void Habitacao::mostrarHabitacao(term::Window &w) const {
//    w.clear();
//    w << "Grelha de Zona: (" << tamanhoMinX << "x" << tamanhoMinY << ") a (" << tamanhoMaxX << "x" << tamanhoMaxY
//      << ")\n";
//    w << term::set_color(0) << "mostra habitacao\n";
//    for (const auto &zona: zonas) {
//        w << "Zona Id: " << zona.obterId() << ": posicao: (" << zona.obterX() << "," << zona.obterY() << ")\n";
//    }
//    Window teste = Window(45, 4, 10, 4, 2);
//    Window te = Window(56, 4, 10, 4, 2);
//    Window tes = Window(77, 4, 10, 4, 2);
//    tes << "z2";
//    te << "z3";
//    teste << "z1";
//    getchar();
//    // Percorre as posições (x, y) da habitacao
////    for (int y = tamanhoMinY; y <= tamanhoMaxY; ++y) {
////        for (int x = tamanhoMinX; x <= tamanhoMaxX; ++x) {
////            bool zonaEncontrada = false;
////
////            // Verifica se existe uma zona na posição (x, y)
////            for (const auto& zona : zonas) {
////                if (zona.obterX() == x && zona.obterY() == y) {
////                    w << "Z ";
////
////                    zonaEncontrada = true;
////                    break;
////                }
////            }
////            if (!zonaEncontrada) {
////                w << "_ "; // Se não houver zona, imprime um espaço vazio
////            }
////        }
////        w << "\n"; // Quebra de linha para imprimir a próxima linha da matriz
////    }
//}
