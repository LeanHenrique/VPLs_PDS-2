#include "racional.h"

#include <cmath>
#include <iostream>

int gcm(int a, int b){
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b){
 return ((a * b) / gcm(a,b));
}




void Racional::Simplificar() {
  int mdc = gcm(numerador_,denominador_);
  numerador_= numerador_ / mdc;
  denominador_ = denominador_ / mdc;
 
}

Racional::Racional() {
  numerador_ = 0;
  denominador_ = 1;
}

Racional::Racional(int n)  {
  numerador_ = n;
  denominador_ = 1;
}

Racional::Racional(int n, int d) {
  numerador_ = n;
  denominador_ = d;
  Simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  return Racional(-numerador_,denominador_);
}

Racional Racional::somar(Racional k) const {
  int mmc = lcm(denominador_,k.denominador_);
  int soma = ((mmc / denominador_) * numerador_) + ((mmc / k.denominador_) * k.numerador_);
  return Racional(soma,mmc);
}

Racional Racional::subtrair(Racional k) const {
  int mmc = lcm(denominador_,k.denominador_);
  int sub = ((mmc / denominador_) * numerador_) - ((mmc / k.denominador_) * k.numerador_);
  return Racional(sub,mmc);
}

Racional Racional::multiplicar(Racional k) const {
  int num = numerador_ * k.numerador_;
  int den = denominador_ * k.denominador_;
  return Racional(num,den);
}

Racional Racional::dividir(Racional k) const {
  int Inum = k.denominador_;
  int Iden = k.numerador_;
  int num = numerador_ * Inum;
  int den = denominador_ * Iden;
  return Racional(num,den);
}