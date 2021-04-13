#pragma once

#include <vector>

template<class Clave>
class Vector {
 public:
  Vector(int size = 0);
  ~Vector() {}

  bool Buscar(const Clave& X) const;
  bool Insertar(const Clave& X);
  bool EstaLleno() const;

  int get_max_size() const;
  void set_max_size(const int& max_size);
  std::vector<Clave> get_vector();

 private:
  std::vector<Clave> vDatos_;
  int nSinonimos_;
};

template<class Clave>
Vector<Clave>::Vector(int size) {
  nSinonimos_ = size;
  //vDatos_.resize(nSinonimos_);
}

template<class Clave>
bool Vector<Clave>::Buscar(const Clave& X) const {
  bool coincidencia = false;
  int i = 0;
  while ((!coincidencia) && (i < vDatos_.size())) {
    coincidencia = (X == vDatos_[i]);
    ++i;
  }
  return coincidencia;
}

template<class Clave>
bool Vector<Clave>::Insertar(const Clave& X) {
  bool insertado = (Buscar(X) || EstaLleno()) ? false : true;
  if (insertado) {
    vDatos_.push_back(X);
  }
  return insertado;
}

template<class Clave>
bool Vector<Clave>::EstaLleno() const {
  return (vDatos_.size() == get_max_size()); // true si está lleno, false si hay huecos
}

template<class Clave>
int Vector<Clave>::get_max_size() const{
  return nSinonimos_;
}

template<class Clave>
void Vector<Clave>::set_max_size(const int& max_size) {
  nSinonimos_ = max_size;
}

template<class Clave>
std::vector<Clave> Vector<Clave>::get_vector() {
  return vDatos_;
}