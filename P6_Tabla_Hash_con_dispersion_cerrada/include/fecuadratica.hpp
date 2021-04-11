#pragma once
#include "funcionexploracion.hpp"

template<class Clave>
class feCuadratica: public FuncionExploracion<Clave> {
 public:
  unsigned operator() (const Clave& k, unsigned i) const {
    return pow(i,2);
  }
};