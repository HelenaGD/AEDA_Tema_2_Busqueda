#pragma once

#include "funciondispersion.hpp"
#include "funcionexploracion.hpp"
#include "vector.hpp"

#include <vector>

template<class Clave>
class TablaHash {
 public:
  TablaHash(int size_tabla, int cantidad_sinonimos, FuncionDispersion<Clave> *fd, FuncionExploracion<Clave> *fe);
  ~TablaHash() {};

  bool Buscar(const Clave& X) const; // true si X del tipo Clave está guardado en la tabla hash
  bool Insertar(const Clave& X); // true si puede insertar el valor X del tipo Clave en al tabla hash
                                // false si el valor ya está guardado en la tabla

  int get_sizeTabla() const;

 private:
  int nDatos_; // Tamaño de la tabla
  int nSinonimos_; // Tamaño máximo dentro de c/posicion de la tabla
  std::vector<Vector<Clave>> vDatos_; // Array de nDatos posiciones en c/u de las cuales habŕa un contenedor de claves
  FuncionDispersion<Clave> *fd_;
  FuncionExploracion<Clave> *fe_;
};

template<class Clave>
TablaHash<Clave>::TablaHash(int size_tabla, int cantidad_sinonimos, FuncionDispersion<Clave> *fd, FuncionExploracion<Clave> *fe) {
  nDatos_ = size_tabla;
  nSinonimos_ = cantidad_sinonimos;
  vDatos_.resize(nDatos_);
  fd_ = fd;
  fe_ = fe;
  
  for (int i = 0; i < vDatos_.size(); ++i) {
    vDatos_[i].set_max_size(nSinonimos_);
    std::cout << "Tamaño vector " << i << " = " << vDatos_[i].get_max_size() << "\n";
  }
}

template<class Clave>
bool TablaHash<Clave>::Buscar(const Clave& X) const {
  return vDatos_.at(fd_->operator()(X)).Buscar(X);
}

template<class Clave>
bool TablaHash<Clave>::Insertar(const Clave& X) {
  return vDatos_.at(fd_->operator()(X)).Insertar(X);
}

template<class Clave>
int TablaHash<Clave>::get_sizeTabla() const {
  return nDatos_;
}