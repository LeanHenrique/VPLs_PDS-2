#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multipliermatrix(vector<vector<int>> matrixone,vector<vector<int>> matrixtwo){
  int l1 = matrixone.size();
  int l2 = matrixtwo.size();
  int c2 = matrixtwo[0].size();
  vector<vector<int>> matrixresult(l1, vector<int>(c2));
  for (int i = 0; i < l1; i++) {
    for (int k = 0; k < c2; k++) {
      int soma = 0;
      for (int j = 0; j < l2; j++) {
       soma = soma + (matrixone[i][j] * matrixtwo[j][k]);
      }
      matrixresult[i][k] = soma;
    }
  }
  return matrixresult;
}

int main() {

  int l1, l2, c2;
  cin >> l1 >> l2 >> c2;
  vector<vector<int>> matrixone(l1, vector<int>(l2));
  vector<vector<int>> matrixtwo(l2, vector<int>(c2));
  vector<vector<int>> matrixresult(l1, vector<int>(c2));

  for (int i = 0; i < l1; i++) {
       for (int j = 0; j < l2; j++) {
         cin >> matrixone[i][j];
       }
  }
  for (int i = 0; i < l2; i++) {
       for (int j = 0; j < c2; j++) {
         cin >> matrixtwo[i][j];
       }
  }

  matrixresult = multipliermatrix(matrixone,matrixtwo);

  for (int i = 0; i < l1; i++) {
       for (int j = 0; j < c2; j++) {
         cout << " " << matrixresult[i][j];
       }
      cout << endl;
    }
}
