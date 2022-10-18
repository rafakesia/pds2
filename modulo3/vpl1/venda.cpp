#include "venda.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void Venda::adicionaCelular(const Celular& celular) {
    m_celulares.insert(m_celulares.begin(), celular);
}

void Venda::ordena() {
    m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd) {
    for(std::list<Celular>::iterator itr = m_celulares.begin(); itr != m_celulares.end(); itr++){
        if(itr->codigoAuxiliar == cod) itr->_qtd += qtd;
    }
}

void Venda::efetuaVenda(int cod, int qtd) {
    for(std::list<Celular>::iterator itr = m_celulares.begin(); itr != m_celulares.end(); itr++){
        if(itr->codigoAuxiliar == cod){
            if(itr->_qtd >= qtd){
                itr->_qtd -= qtd;
            }
        } 
    }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
    for(std::list<Celular>::iterator itr = m_celulares.begin(); itr != m_celulares.end(); itr++){
        if(itr->_fabricante == fabricante) itr->_valor -= ((desconto/100)*itr->_valor);
    }
}

void Venda::removeModelo(int cod) {
    for(std::list<Celular>::iterator itr = m_celulares.begin(); itr != m_celulares.end(); itr++){
        if(itr->codigoAuxiliar == cod){
            m_celulares.erase(itr);
        break;
        } 
    }
}

void Venda::imprimeEstoque() const {
    for(std::list<Celular>::const_iterator itr = m_celulares.begin(); itr != m_celulares.end(); itr++){
        double rounded = std::floor((itr->_valor * 100) + .5) / 100;
        if(itr->_qtd > 1){
            cout << itr->_fabricante << " " << itr->_modelo << ", " << itr->_armazenamento << "GB, " << itr->_memoria << "GB RAM, " << std::fixed << std::setprecision(0) << (itr->_peso)*1000 << " gramas, " << itr->_cor << ", " << itr->_qtd << " restantes, R$ ";
            printf("%.2f\n", rounded);
        }
        else if(itr->_qtd == 1){
            cout << itr->_fabricante << " " << itr->_modelo << ", " << itr->_armazenamento << "GB, " << itr->_memoria << "GB RAM, " << (itr->_peso)*1000 << " gramas, " << itr->_cor << ", 1 restante, R$ ";
            printf("%.2f\n", rounded);
        }
    }
}