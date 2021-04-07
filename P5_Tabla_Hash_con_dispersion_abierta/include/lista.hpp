#pragma once

#include <vector>

template<class Clave>
class Lista {
 public:
  Lista() {}
  ~Lista() {}

  bool Buscar(const Clave& X) const;
  bool Insertar(const Clave& X);

 private:
  std::vector<Clave> vDatos_;
};

template<class Clave>
bool Lista<Clave>::Buscar(const Clave& X) const {
  bool coincidencia = false;
  int i = 0;
  while ((!coincidencia) && (i < vDatos_.size())) {
    coincidencia = (X == vDatos_[i]);
    ++i;
  }
  return coincidencia;
}

template<class Clave>
bool Lista<Clave>::Insertar(const Clave& X) {
  bool insertado = Buscar(X) ? false : true;
  if (insertado) {
    vDatos_.push_back(X);
  }
  return insertado;
}