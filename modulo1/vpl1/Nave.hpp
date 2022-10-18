#ifndef NAVE_HPP
#define NAVE_HPP
#include "Ponto2D.hpp"

struct Nave{
    //Dados
    Ponto2D posicao;
    double forca;
    double energia=100;

    //Construtor
    Nave(Ponto2D _posicao, double _forca);
    Nave() = default;

    //Operacoes
    void mover(double dx, double dy);
    double calcular_distancia(Nave* nave);
    Nave* determinar_nave_mais_proxima(Nave** naves, int n);
    void atacar(Nave** naves, int n);
    void imprimir_status();
};

#endif
