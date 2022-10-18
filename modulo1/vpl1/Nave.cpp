#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Nave.hpp"

using namespace std;

Nave::Nave(Ponto2D _posicao, double _forca){
    posicao = _posicao;
    forca = _forca;
}

void Nave::mover(double dx, double dy){
    posicao.x += dx;
    posicao.y += dy;
}

double Nave::calcular_distancia(Nave* nave){
    double dx = nave->posicao.x - this->posicao.x;
    double dy = nave->posicao.y - this->posicao.y;
    return sqrt(dx*dx + dy*dy);
}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n){
    Nave* menor;
    
    for(int j=0;j<n;j++){
        if(naves[j] != this){
            menor = naves[j];
            break;
        }
    }
    
    for(int i=0;i<n;i++){
        if((calcular_distancia(naves[i]) < calcular_distancia(menor)) && (naves[i] != this)){
            menor = naves[i];
        }    
    }
    
    return menor;
}

void Nave::atacar(Nave** naves, int n){
    Nave* maisProxima = determinar_nave_mais_proxima(naves, n);
    double d = calcular_distancia(maisProxima);
    double dano = (100/d)*(this->forca);
    if(dano>30) dano=30;
    maisProxima->energia -= dano;
    if(maisProxima->energia <= 50) cout << "Energia baixa!" << endl;
}

void Nave::imprimir_status(){
    cout << posicao.x << " " << posicao.y << " " << energia << endl;
}
