#pragma once

#include <vector>

template<class Clave>
class Lista {
 public:
  Lista(int size_position);
  ~Lista() {}

  bool Buscar(const Clave& X) const;
  bool Insertar(const Clave& X);
  bool EstaLleno() const;

  int get_max_size() const;
  void set_max_size(const int& max_size);

 private:
  std::vector<Clave> vDatos_;
  int nSinonimos_;
};

template<class Clave>
Lista<Clave>::Lista(int size_position) {
  nSinonimos_ = size_position;
  //vDatos_.resize(nSinonimos_);
}

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

template<class Clave>
bool Lista<Clave>::EstaLleno() const {
  return (vDatos_.size() == get_max_size()); // true si está lleno, false si hay huecos
}

template<class Clave>
int Lista<Clave>::get_max_size() const{
  return nSinonimos_;
}

template<class Clave>
void Lista<Clave>::set_max_size(const int& max_size) {
  nSinonimos_ = max_size;
}