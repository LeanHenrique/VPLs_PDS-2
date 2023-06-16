#include "lifegame.h"

JogoDaVida::JogoDaVida(int l, int c) {
  // Inicializa o torus com l linhas e c colunas.
  if (l <= 0 || c <= 0) {
    throw std::invalid_argument("Tamanho inválido para o torus.");
  }
  vivas_.resize(l, std::vector<bool>(c, false));
}

int JogoDaVida::linhas() const {
  // Retorna o número de linhas do torus.
  return vivas_.size();
}

int JogoDaVida::colunas() const {
  // Retorna o número de colunas do torus.
  return vivas_[0].size();
}

bool JogoDaVida::viva(int i, int j) const {
  // Retorna o estado da célula [i, j].
  if (i < 0 || i >= linhas() || j < 0 || j >= colunas()) {
    ExcecaoCelulaInvalida x;
    x.linha = i;
    x.coluna = j;
    throw x;
  }
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
  // Mata a célula [i, j].
  if (i < 0 || i >= linhas() || j < 0 || j >= colunas()) {
    ExcecaoCelulaInvalida x;
    x.linha = i;
    x.coluna = j;
    throw x;
  }
  vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j) {
  // Revive a célula [i, j].
  if (i < 0 || i >= linhas() || j < 0 || j >= colunas()) {
    ExcecaoCelulaInvalida x;
    x.linha = i;
    x.coluna = j;
    throw x;
  }
  vivas_[i][j] = true;
}

void JogoDaVida::ExecutarProximaIteracao() {
  std::vector<std::vector<bool>> novo_estado =
      vivas_; // Cria uma cópia do estado atual.

  int linhas = vivas_.size();
  int colunas = vivas_[0].size();

  // Percorre todas as células do torus.
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      int vizinhas_vivas = NumeroDeVizinhasVivas(i, j);

      if (vivas_[i][j]) {
        // Célula viva.
        if (vizinhas_vivas <= 1 || vizinhas_vivas > 3) {
          // Morte por solidão ou superpopulação.
          novo_estado[i][j] = false;
        }
      } else {
        // Célula morta.
        if (vizinhas_vivas == 3) {
          // Nascimento de uma nova célula.
          novo_estado[i][j] = true;
        }
      }
    }
  }

  // Atualiza o estado do torus.
  vivas_ = novo_estado;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int contador = 0;
  int linhas = vivas_.size();
  int colunas = vivas_[0].size();

  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i == 0 && j == 0) {
        continue; // Ignora a célula atual.
      }

      int linha_vizinha = (x + i + linhas) % linhas;    // Lógica do torus.
      int coluna_vizinha = (y + j + colunas) % colunas; // Lógica do torus.

      if (vivas_[linha_vizinha][coluna_vizinha]) {
        contador++;
      }
    }
  }

  return contador;
}
