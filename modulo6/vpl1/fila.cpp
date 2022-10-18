#include "fila.h"

struct No {
  int chave;
  No* proximo;
};

Fila::Fila() {
}

void Fila::Inserir(int k) {
  myFila.push_back(k);
}

void Fila::RemoverPrimeiro() {
  if(myFila.empty()) throw ExcecaoFilaVazia();
  myFila.pop_front();
}

int Fila::primeiro() const {
  if(myFila.empty()) throw ExcecaoFilaVazia();
  return myFila.front();
}

int Fila::ultimo() const {
  if(myFila.empty()) throw ExcecaoFilaVazia();
  return myFila.back();
}

int Fila::tamanho() const {
  return myFila.size();
}