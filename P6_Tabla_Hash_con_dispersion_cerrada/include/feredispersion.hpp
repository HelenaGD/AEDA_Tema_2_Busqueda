#pragma once

#include "funcionexploracion.hpp"
#include "funciondispersion.hpp"

template<class Clave>
class feReDispersion: public FuncionExploracion<Clave> {
 public:
  feReDispersion(FuncionDispersion<Clave> *fd) {
    fd_ = fd;
  }

  unsigned operator() (const Clave& k, unsigned i) const {
    //fd_->operator()(k) * i
    //return pow(i,2);
    return 0;
  }
 private:
  FuncionDispersion<Clave> *fd_;
};