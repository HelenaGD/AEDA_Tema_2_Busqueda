#include "funciondispersion.hpp"

template<class Clave>
class TablaHash {
 public:
  TablaHash(int tamaño_tabla, FuncionDispersion puntero);

  bool Buscar(Clave& X) const; // true si X del tipo Clave está guardado en la tabla hash
  bool Insertar(const Clave& X); // true si puede insertar el valor X del tipo Clave en al tabla hash
                                // false si el valor ya está guardado en la tabla

 private:
  int nDatos; // Tamaño de la tabla
  std::vector<Clave> vDatos; // Array de nDatos posiciones en c/u de las cuales habŕa un contenedor de claves
  FuncionDispersion<Clave> *fd;
};