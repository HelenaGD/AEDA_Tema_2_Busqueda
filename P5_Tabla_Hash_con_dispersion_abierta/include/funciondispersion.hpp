#pragma once

template<class Clave>
class FuncionDispersion {
 public:
  virtual unsingned operator() (const Clave& k) const = 0;
};