#pragma once

#include "funcionexploracion.hpp"
#include "funciondispersion.hpp"

template<class Clave>
class feReDispersion: public FuncionExploracion<Clave> {
 public:
  unsigned operator() (const Clave& k, unsigned i) const {
    srand(k);
    unsigned solucion;
    for (int j = 0; j<i; ++j) {
      solucion = rand();
    }
    return solucion;
  }
};