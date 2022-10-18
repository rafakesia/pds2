#ifndef FILA_H
#define FILA_H
#include <list>

struct No;

// Fila de numeros inteiros.
class Fila {
    public:
        // Representa uma excecao que ocorre quando a fila esta vazia.
        // Ela nao tem estado, ja que toda fila vazia eh igual.
        // Consequetemente, sua implementacao eh vazia.
        class ExcecaoFilaVazia {};
  
        // Constroi uma fila vazia.
        Fila();
    
        // Insere um elemento no fim da fila.
        void Inserir(int k);
    
        // Retorna o elemento no inicio da fila.
        // Lança uma exceção do tipo EmptyException caso a fila esteja vazia.
        int primeiro() const;

        // Retorna o elemento no fim da fila.
        // Lança uma excecao do tipo EmptyException caso a fila esteja vazia.
        int ultimo() const;

        // Remove o elemento no início da fila.
        // Lança uma exceção do tipo EmptyException caso a fila esteja vazia.
        void RemoverPrimeiro(); 
    
        // Retorna o número de elementos na fila.
        int tamanho() const;
    
        std::list<int> myFila;
    
    private:
        No* primeiro_;    
        No* ultimo_;
};

#endif  // FILA_H
