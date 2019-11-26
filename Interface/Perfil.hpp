#ifndef ZOOLOGICO_CPP_INTERFACE_PERFIL_HPP_
#define ZOOLOGICO_CPP_INTERFACE_PERFIL_HPP_

#include "AbstractInterface.hpp"
#include "../TAD/Animal.hpp"
#include "../TAD/HistoricoMedico.hpp"
namespace Interface {

class Perfil : public Interface::AbstractInterface {
 public:
  explicit Perfil(TAD::Animal *animalSelecionado);

  void exibir() override;

 private:
  TAD::Animal animal;
  TAD::HistoricoMedico historicoMedico;

  void processarEntrada(int opcao) override;

  void verFicha();

  void cadastroHistoricoMedico();

};

}



#endif //ZOOLOGICO_CPP_INTERFACE_PERFIL_HPP_
