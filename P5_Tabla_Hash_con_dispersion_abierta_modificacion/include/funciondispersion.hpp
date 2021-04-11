#pragma once

template<class Clave>
class FuncionDispersion {
 public:
  virtual unsigned operator() (const Clave& k) const = 0;
};