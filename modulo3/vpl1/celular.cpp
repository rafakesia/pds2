#include "celular.hpp"

int Celular::codigo=0;

int Celular::captaCodigo(){
    return this->codigo;
}

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
    _modelo = modelo;
    _fabricante = fabricante;
    _armazenamento = armazenamento;
    _memoria = memoria;
    _peso = peso;
    _cor = cor;
    _qtd = qtd;
    _valor = valor;
    Celular::codigo++;
    this->codigoAuxiliar = this->captaCodigo();
}

bool Celular::operator<(const Celular& other) {
    std::string concatenaThis;
    std::string concatenaOther;
    concatenaThis = (this->_fabricante) + (this->_modelo);
    concatenaOther = (other._fabricante) + (other._modelo);
    return(concatenaThis < concatenaOther);
}