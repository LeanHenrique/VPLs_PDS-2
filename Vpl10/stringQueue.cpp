#include "stringQueue.h"
#include <iostream>
#include <string>
using std::string;

// Cria uma fila vazia;
Fila::Fila() {
  primeiro_ = nullptr;
  ultimo_ = nullptr;
}

// Retorna o primeiro elemento da fila.
// Precondição: a fila *não* pode estar vazia.
string Fila::primeiro() {
  if (vazia() == false) {
    return primeiro_->chave;
  }
}

// Retorna o último elemento da fila.
// Precondição: a fila *não* pode estar vazia.
string Fila::ultimo() {
  if (vazia() == false) {
    return ultimo_->chave;
  }
}

// Informa se a fila está vazia.
bool Fila::vazia() {
  if (primeiro_ == nullptr) {
    return true;
  }
  return false;
}

// Insere um elemento no fim da fila.
void Fila::Inserir(string k) {
  No *novoelemento = new No;
  novoelemento->chave = k;
  novoelemento->proximo = nullptr;
  if (vazia() == true) {
    primeiro_ = novoelemento;
    ultimo_ = novoelemento;
  } else {
    ultimo_->proximo = novoelemento;
    ultimo_ = novoelemento;
  }
}

// Remove o elemento no início da fila.
// Precondição: a fila *não* pode estar vazia.
void Fila::Remover() {
  if (vazia() == false) {
    No *aux = new No;
    aux = primeiro_->proximo;
    delete primeiro_;
    primeiro_ = aux;
  }
}

// Retorna o número de elementos na fila.
int Fila::tamanho() {
  int tamanho = 0;
  No *cont = primeiro_;

  while (cont != nullptr) {
    tamanho++;
    cont = cont->proximo;
  }

  return tamanho;
}


// Libera toda a memória alocada para a fila.
Fila::~Fila() {
  while (!vazia()) {
    Remover();
  }
}
