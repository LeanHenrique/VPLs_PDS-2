#include "priorityQueue.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
    for (auto it = lista_.begin(); it != lista_.end(); it++) {
        if (it->prioridade < p.prioridade) {
            lista_.insert(it, p);
            return;
        }
    }
    lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome = lista_.front().nome;
  lista_.pop_front();
  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  lista_.remove_if([nome](const Pessoa& p) { 
 return p.nome == nome; 
      });
}

int FilaDePrioridade::tamanho() {
  int tamanho = lista_.size();
  return tamanho;
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v(lista_.size());
  int i = 0;
  for(auto& Pessoa : lista_){
   v[i] = Pessoa.nome;
    i++;
  }
  return v; 
}