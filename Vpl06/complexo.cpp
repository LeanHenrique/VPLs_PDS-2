// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  modulo_ = 0;
  argumento_ = 0;
}

Complexo::Complexo(double a, double b) {
  modulo_ = a;
  argumento_ = b;
}

double Complexo::real() {
  return modulo_;
}

double Complexo::imag() {
  return argumento_;
}

bool Complexo::igual(Complexo x) {
  double real = cos(argumento_) * modulo_;
  double imag = sin(argumento_) * modulo_;
  double realx = cos(x.argumento_) * x.modulo_;
  double imagx = sin(x.argumento_) * x.modulo_;

  if ((real == realx) && (imag == imagx)) {
    return true;
  }
  return false;
}

void Complexo::Atribuir(Complexo x) {
  modulo_ = x.modulo_;
  argumento_ = x.argumento_;
}

double Complexo::modulo() { return modulo_; }

Complexo Complexo::conjugado() {
  Complexo c;
  c.modulo_ = modulo_;
  c.argumento_ = -argumento_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.modulo_ = -modulo_;
  c.argumento_ = -argumento_;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.modulo_ = pow(modulo_, 0.5);
  i.argumento_ = -argumento_;
  return i;
}

Complexo Complexo::somar(Complexo y) {

  Complexo s;
  s.modulo_ = modulo_ + y.modulo_;
  s.argumento_ = argumento_ + argumento_;
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.modulo_ = modulo_ - y.modulo_;
  s.argumento_ = argumento_ - argumento_;
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.modulo_ = modulo_ * y.modulo_;
  p.argumento_ = argumento_ + y.argumento_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.modulo_ = modulo_ / y.modulo_;
  d.argumento_ = argumento_ - y.argumento_;
  return d;
}