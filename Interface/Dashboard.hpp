#ifndef ZOOLOGICO_CPP_DASHBOARD_HPP
#define ZOOLOGICO_CPP_DASHBOARD_HPP

#include "AbstractInterface.hpp"
#include "../TAD/Animal.hpp"

namespace Interface {

class Dashboard : public Interface::AbstractInterface {
 public:
  Dashboard();

  void exibir() override;

 private:
  void processarEntrada(int opcao) override;

  void cadastrarAnimal();

  void buscarAnimal();
};

}

#endif //ZOOLOGICO_CPP_DASHBOARD_HPP
