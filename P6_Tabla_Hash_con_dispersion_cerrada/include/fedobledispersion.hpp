#pragma once

#include "funcionexploracion.hpp"
#include "funciondispersion.hpp"

template<class Clave>
class feDobleDispersion: public FuncionExploracion<Clave> {
 public:
  feDobleDispersion(FuncionDispersion<Clave> *fd) {
    fd_ = fd;
  }

  unsigned operator() (const Clave& k, unsigned i) const {
    return fd_->operator()(k) * i;
  }

 private:
  FuncionDispersion<Clave> *fd_;
};