#pragma once

#include "funciondispersion.hpp"
#include "lista.hpp"

#include <vector>

template<class Clave>
class TablaHash {
 public:
  TablaHash(int tamaño_tabla, FuncionDispersion<Clave> *puntero_objeto);
  ~TablaHash() {}

  bool Buscar(const Clave& X) const; // true si X del tipo Clave está guardado en la tabla hash
  bool Insertar(const Clave& X); // true si puede insertar el valor X del tipo Clave en al tabla hash
                                // false si el valor ya está guardado en la tabla

 private:
  int nDatos_; // Tamaño de la tabla
  std::vector<Lista<Clave>> vDatos_; // Array de nDatos posiciones en c/u de las cuales habŕa un contenedor de claves
  FuncionDispersion<Clave> *fd_;
};

template<class Clave>
TablaHash<Clave>::TablaHash(int tamaño_tabla, FuncionDispersion<Clave> *puntero_objeto) {
  nDatos_ = tamaño_tabla;
  vDatos_.resize(nDatos_);
  fd_ = puntero_objeto;
}

template<class Clave>
bool TablaHash<Clave>::Buscar(const Clave& X) const {
  return vDatos_.at(fd->operator()(X)).Buscar(X);
}

template<class Clave>
bool TablaHash<Clave>::Insertar(const Clave& X) {
  return vDatos_.at(fd_->operator()(X)).Insertar(X);
}
