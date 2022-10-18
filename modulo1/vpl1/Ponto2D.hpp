#ifndef PONTO2D_HPP
#define PONTO2D_HPP

struct Ponto2D{
    //Dados
    double x=0, y=0;
    
    //Construtor
    Ponto2D(double _x, double _y);
    Ponto2D() = default;

    //Operacoes
    double calcular_distancia(Ponto2D* ponto);
};

#endif
