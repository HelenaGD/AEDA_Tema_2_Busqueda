#pragma once

template<class Clave>
class fdModulo: public FuncionDispersion<Clave> {
 public:
  fdModulo (const unsingned n) : nDatos(n) {}
  unsined operator() (const Clave& k) const {
    return k % nDatos;
  }
 private:
  unsigned nDatos;
};