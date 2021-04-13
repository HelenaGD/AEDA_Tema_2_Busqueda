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

  void printTabla();
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
  bool coincidencia = true;
  int j = 0;
  
  if (!vDatos_.at(fd_->operator()(X)).Buscar(X)) { // No está en la tabla
    do {
      coincidencia = vDatos_.at((fd_->operator()(X) + fe_->operator()(X,j)) % nDatos_).Buscar(X);
      ++j;
    } while ((coincidencia == false) && (j < vDatos_.size()));
  } 

  std::cout << "Ha hecho " << j << " exploraciones cuando buscaba\n";

  return coincidencia;
}

template<class Clave>
bool TablaHash<Clave>::Insertar(const Clave& X) {
  int j = 0;
  bool insertado = true;

  if ((!Buscar(X)) && (!vDatos_.at(fd_->operator()(X)).Insertar(X))) {
    do {
      insertado = vDatos_.at((fd_->operator()(X) + fe_->operator()(X,j)) % nDatos_).Insertar(X);
      ++j;
    } while ((insertado == false) && (j < vDatos_.size()));
  }

  std::cout << "Ha hecho " << j << " exploraciones cuando insertaba\n";

  return insertado;
}

template<class Clave>
int TablaHash<Clave>::get_sizeTabla() const {
  return nDatos_;
}

template<class Clave>
void TablaHash<Clave>::printTabla() {
  for (int i = 0; i < vDatos_.size(); ++i) {
    std::cout << "Celda " << i << ": ";
    for (int j = 0; j < vDatos_.at(i).get_vector().size(); ++j) {
      std::cout << vDatos_.at(i).get_vector().at(j) << " ";
    }
    std::cout << std::endl;
  }
}