#ifndef ZOOLOGICO_CPP_INTERFACE_BUSCAANIMAL_HPP_
#define ZOOLOGICO_CPP_INTERFACE_BUSCAANIMAL_HPP_

#include <vector>
#include "AbstractInterface.hpp"
#include "../TAD/Animal.hpp"
namespace Interface {

class BuscaAnimal : public Interface::AbstractInterface {
 public:
  BuscaAnimal();

  void exibir() override;

  void processarEntrada(int opcao) override;

  void exibirAnimal(const TAD::Animal& animal);

  void avancarAnimal();

  void retrocederAnimal();

  TAD::Animal *obterAnimalPeloIndice();

  void perfil();

 private:
  unsigned long index{};
  TAD::Animal animal;
  std::vector<TAD::Animal> animais;

};

}



#endif //ZOOLOGICO_CPP_INTERFACE_BUSCAANIMAL_HPP_
