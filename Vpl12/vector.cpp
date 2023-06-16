#include "vector.h"
#include <iostream>
#include <string>

using namespace std;

// Cria um vetor cujos índices variam de 'inicio' até 'fim'.
// PRECONDIÇÃO: fim >= inicio.
Vetor::Vetor(int inicio, int fim) {
  if (fim < inicio) {
    IntervaloVazio x;
    x.inicio = inicio;
    x.fim = fim;
    throw x;
  }
  inicio_ = inicio;
  fim_ = fim;
  elementos_ = new string[fim - inicio + 1];
}

// Altera o valor do índice i.
// PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
void Vetor::atribuir(int i, std::string valor) {
  if (i < inicio_ || i > fim_) {
    IndiceInvalido x;
    x.indice = i;
    x.inicio = inicio_;
    x.fim = fim_;
    throw x;
  }
  int indice = i - inicio_;
  elementos_[indice] = valor;
}

// Retorna o valor do índice i.
// PRECONDIÇÕES:
// (1) i está dentro do intervalo de índices do vetor.
// (2) i foi inicializando anteriormente.
string Vetor::valor(int i) const {
  if (i < inicio_ || i > fim_) {
    IndiceInvalido x;
    x.indice = i;
    x.inicio = inicio_;
    x.fim = fim_;
    throw x;
  }
  int indice = i - inicio_;
  if (elementos_[i - inicio_].empty()) {
    IndiceNaoInicializado x;
    x.indice = i;
    throw x;
  }
  return elementos_[indice];
}

// Desaloca a memória reservada para os elementos do vetor.
Vetor::~Vetor() { delete[] elementos_; }

