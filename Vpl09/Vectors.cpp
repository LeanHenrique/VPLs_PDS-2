#include "vector.h"
#include <iostream>
#include <string>

using namespace std;

  // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
  // PRECONDIÇÃO: fim >= inicio.
  Vetor::Vetor(int inicio, int fim){
     if(fim >= inicio){
       inicio_ = inicio;
      elementos_= new string[fim - inicio + 1];
     }
  }

  // Altera o valor do índice i.
  // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
  void Vetor::atribuir(int i, std::string valor){
    int indice = i - inicio_;
    elementos_[indice] = valor;  
    }
  
  // Retorna o valor do índice i.
  // PRECONDIÇÕES:
  // (1) i está dentro do intervalo de índices do vetor.
  // (2) i foi inicializando anteriormente.
  string Vetor::valor(int i) const{
    int indice = i - inicio_;
    return elementos_[indice];
  }

  // Desaloca a memória reservada para os elementos do vetor.
  Vetor::~Vetor(){
    delete[]elementos_;
  }


