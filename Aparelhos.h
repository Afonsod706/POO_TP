//
// Created by afons on 22/11/2023.
//

#ifndef POO_TP_APARELHOS_H
#define POO_TP_APARELHOS_H

#include <string>
class Aparelhos {
public:
    Aparelhos(const std::string& type);

    void ligar() const;
    void desligar() const;

private:
    std::string type;
};


#endif //POO_TP_APARELHOS_H
