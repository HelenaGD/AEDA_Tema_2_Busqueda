template<class Clave>
class fdModulo: public FuncionDispersion<Clave> {
 public:
  fdModulo (const unsingned n) : nDatos(n) {}
  unsined operato() (const Clave& k) const {
    return k % nDatos;
  }
 private:
  unsigned nDatos;
};