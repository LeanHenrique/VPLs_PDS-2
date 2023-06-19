#include "dicionario.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

Dicionario::Dicionario() : elementos_() {
    // Construtor vazio
}

Dicionario::~Dicionario() {
    // Destrutor vazio ou qualquer outra ação necessária para liberar memória
}

int Dicionario::tamanho() {
    return elementos_.size();
}

bool Dicionario::pertence(string chave) {
    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it->chave == chave) {
            return true;
        }
    }
    return false;
}

string Dicionario::menor() {
    if (elementos_.empty()) {
        throw DicionarioVazio{"Não foi possível realizar a operação: Dicionário vazio"};
    } 
        string comparative = elementos_.begin()->chave;
        for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
            string aux = it->chave;
            if (aux < comparative) {
                comparative = aux;
            }
        }
        return comparative;
    }

string Dicionario::valor(string chave) {
    if (!pertence(chave)) {
        ChaveInexistente x;
        x.chave = chave;
        throw x;
    }
    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it->chave == chave) {
            return it->valor;
        }
    }
    return "";
}

void Dicionario::Inserir(string chave, string valor) {
    if (pertence(chave)) {
        ChaveRepetida x;
        x.chave = chave;
        throw x;
    }
    Elemento m;
    m.chave = chave;
    m.valor = valor;
    elementos_.push_back(m);
}

void Dicionario::Remover(string chave) {
    if (!pertence(chave)) {
        ChaveInexistente x;
        x.chave = chave;
        throw x;
    }

    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it->chave == chave) {
            elementos_.erase(it);
            break; // Importante: interromper o loop após a remoção
        }
    }
}

void Dicionario::Alterar(string chave, string valor) {
    if (!pertence(chave)) {
        ChaveInexistente x;
        x.chave = chave;
        throw x;
    }

    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it->chave == chave) {
            it->valor = valor;
            break; // Importante: interromper o loop após a alteração
        }
    }
}
