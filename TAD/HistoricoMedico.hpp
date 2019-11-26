#ifndef ZOOLOGICO_CPP_TAD_HISTORICOMEDICO_HPP_
#define ZOOLOGICO_CPP_TAD_HISTORICOMEDICO_HPP_

#include "AbstractConnection.hpp"
#include "Animal.hpp"
namespace TAD {

class HistoricoMedico : public TAD::AbstractConnection {
 private:
  int id;
  double peso;
  double altura;
  std::string observacao;

 public:
  int getId() const;

  void setId(int id);

  double getPeso() const;

  void setPeso(double peso);

  double getAltura() const;

  void setAltura(double altura);

  const std::string &getObservacao() const;

  void setObservacao(const std::string &observacao);

  std::vector<TAD::HistoricoMedico> selecionarFichaMedicaPorIdAnimal(int animalId);

  void cadastrarHistoricoMedico(int animalId);
};

}

#endif //ZOOLOGICO_CPP_TAD_HISTORICOMEDICO_HPP_
