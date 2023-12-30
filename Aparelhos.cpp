//
// Created by afons on 22/11/2023.
//

#include "Aparelhos.h"
#include <iostream>

Aparelhos::Aparelhos(const std::string& type) : type(type) {}

void Aparelhos::ligar() const {
    std::cout << "Aparelho " << type << " ligado.\n";
}

void Aparelhos::desligar() const {
    std::cout << "Aparelho " << type << " desligado.\n";
}