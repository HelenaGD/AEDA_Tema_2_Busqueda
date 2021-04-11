#pragma once
#include "funciondispersion.hpp"

template<class Clave>
class fdModulo: public FuncionDispersion<Clave> {
 public:
  fdModulo (const unsigned n) : nDatos(n) {}
  unsigned operator() (const Clave& k) const {
    return k.get_value() % nDatos;
  }
 private:
  unsigned nDatos;
};