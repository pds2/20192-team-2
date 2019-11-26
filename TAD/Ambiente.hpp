#ifndef ZOOLOGICO_CPP_AMBIENTE_HPP
#define ZOOLOGICO_CPP_AMBIENTE_HPP

#include "AbstractConnection.hpp"

namespace TAD {

class Ambiente : public TAD::AbstractConnection {

 private:
  int id;
  std::string nome;
  double altura;
  double largura;
  double profundidade;

 public:
  int getId() const;

  void setId(int id);

  const std::string &getNome() const;

  void setNome(const std::string &nome);

  double getAltura() const;

  void setAltura(double altura);

  double getLargura() const;

  void setLargura(double largura);

  double getProfundidade() const;

  void setProfundidade(double profundidade);

};

}

#endif //ZOOLOGICO_CPP_AMBIENTE_HPP
