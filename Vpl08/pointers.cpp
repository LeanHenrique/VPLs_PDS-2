#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int a = 10;
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo (aka 'nullptr')
    int * pointer = nullptr; 
    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int vector[10] = {9,8,7,6,5,4,3,2,1,0};
    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &a << endl;
    // 5) Imprima o CONTEÚDO da variável declarada em (1)
    cout << a << endl;  
    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &pointer << endl;
    // 7) Imprima o CONTEÚDO da variável declarada em (2)
    cout << pointer << endl;
    // 8) Imprima o ENDEREÇO da variável declarada em (3
    cout << &vector << endl;
    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vector[0] << endl;
    // 10) Imprima o CONTEÚDO da primeira posição da variável declarada em (3)
    cout << vector[0] << endl;
    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    pointer = &a;
    // 12) Imprima o CONTEÚDO da variável declarada em (2)
    cout << pointer << endl;
    // 13) Imprima o CONTEÚDO da varíavel que é apontada por (2)
    cout << *pointer << endl;
    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do CONTEÚDO de (2)
    cout << (&a == pointer) << endl; 
    // 15) Coloque o VALOR '5' na varíavel que é apontada pela variável de (2)
    *pointer = 5;
    // 16) Imprima o CONTEÚDO da variável declarada em (1)
    cout << a << endl;
    // 17) Atribua o CONTEÚDO da variável de (3) à variável de (2)
    pointer = vector;
    // 18) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << pointer << endl;
    // 19) Imprima o CONTEÚDO da variável que é apontada pela variável de (2)
    cout << *pointer << endl;
    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável de (2)
    pointer = &vector[0];
    // 21) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << pointer << endl;
    // 22) Imprima o CONTEÚDO da variável que é apontada pela variável de (2) 
    cout << *pointer << endl;
    // 23) Imprima os elementos de (3) utilizando a notação [] (e.g. v[i])
    cout << vector[0] << " " << vector[1] << " " << vector[2] << " " << vector[3] << " " << vector[4] << " " << vector[5] << " " << vector[6] << " " << vector[7] << " " << vector[8] << " " << vector[9] << endl;
    // 24) Imprima os elementos de (3) utilizando a notação ponteiro/deslocamento (e.g. *(v + i))
    for(int i = 0; i < 10; i++){
    cout << *(vector + i) << " ";
    }
cout << endl;
    return 0;
}