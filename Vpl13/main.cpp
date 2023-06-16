#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>

#include "lifegame.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

ostream &operator<<(ostream &out, JogoDaVida &t) {
  out << "  ";
  for (int i = 0; i < t.colunas(); ++i) {
    out << "X ";
  }
  out << endl;
  for (int i = 0; i < t.linhas(); ++i) {
    out << "X ";
    for (int j = 0; j < t.colunas(); ++j) {
      if (t.viva(i, j)) {
        out << "o ";
      } else {
        out << "  ";
      }
    }
    out << "X" << endl;
  }
  out << "  ";
  for (int i = 0; i < t.colunas(); ++i) {
    out << "X ";
  }
  out << endl;
  return out;
}

int main() {
  try {
    int numero_de_iteracoes;
    cin >> numero_de_iteracoes;

    int numero_de_linhas;
    cin >> numero_de_linhas;
    int numero_de_colunas;
    cin >> numero_de_colunas;

    JogoDaVida jogo(numero_de_linhas, numero_de_colunas);
    int linha, coluna;
    while (cin >> linha >> coluna) {
      try {
        jogo.Reviver(linha, coluna);
      } catch (ExcecaoCelulaInvalida e) {
        cout <<"Célula (" << e.linha << ", " << e.coluna <<") não é válida. Deseja continuar e ignorá-la? (s/n)?" << endl;
        char resposta;
        cin >> resposta;
        if (resposta != 'S' && resposta != 's') {
          return 0;
        }
      }
    }
    cout << jogo << endl;

    for (int i = 0; i < numero_de_iteracoes; i++) {
      jogo.ExecutarProximaIteracao();
      cout << jogo << endl;
      sleep_for(200ms);
    }
  } catch (const std::exception &excecao) {
    cout << "Erro: " << excecao.what() << endl;
  }

  return 0;
}
