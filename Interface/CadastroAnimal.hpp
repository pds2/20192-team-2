#ifndef ZOOLOGICO_CPP_CADASTROANIMAL_HPP
#define ZOOLOGICO_CPP_CADASTROANIMAL_HPP

#include "AbstractInterface.hpp"
#include "../TAD/Animal.hpp"

namespace Interface {

class CadastroAnimal : public Interface::AbstractInterface {
 public:
  CadastroAnimal();

  void exibir() override;

 private:
  TAD::Animal animal;
  TAD::Ambiente ambiente;

};

}

#endif //ZOOLOGICO_CPP_CADASTROANIMAL_HPP
