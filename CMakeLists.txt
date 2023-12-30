cmake_minimum_required(VERSION 3.24)
project(POO_TP)

set(CMAKE_CXX_STANDARD 23)

add_executable(POO_TP main.cpp "C:/Users/afons/CLionProjects/POO/POO_TP/main.cpp"  InterfaceC.h Terminal.cpp InterfaceC.cpp Habitacao.h Zona.h Zona.cpp Sensor.cpp Aparelhos.cpp Habitacao.cpp Processador.h Regra.h Regra.cpp Processador.cpp Compomentes.h Propriedade.h Propriedade.cpp)
target_link_libraries(${PROJECT_NAME} C:/Users/afons/CLionProjects/POO/PDCurses-3.9/PDCurses-3.9/wincon/pdcurses.a)