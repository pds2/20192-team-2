#ifndef ZOOLOGICO_CPP_ABSTRACTINTERFACE_HPP
#define ZOOLOGICO_CPP_ABSTRACTINTERFACE_HPP

#include <iostream>



namespace Interface {

class AbstractInterface {
 private:
  std::string titulo;
 public:
  explicit AbstractInterface(const std::string &titulo);

  virtual void exibir() = 0;

  virtual void processarEntrada(int opcao) {};

  const std::string &getTitulo() const;
};

}

#endif //ZOOLOGICO_CPP_ABSTRACTINTERFACE_HPP
