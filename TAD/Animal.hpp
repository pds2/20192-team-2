#ifndef ZOOLOGICO_CPP_ANIMAL_HPP
#define ZOOLOGICO_CPP_ANIMAL_HPP

#include "AbstractConnection.hpp"
#include "Ambiente.hpp"
#include <vector>

namespace TAD {

class Animal : public TAD::AbstractConnection {

 private:
  int id;
  std::string nome;
  std::string especie;
  int idade;
  TAD::Ambiente ambiente;

 public:
  int getId() const;

  void setId(int id);

  const std::string &getNome() const;

  void setNome(const std::string &nome);

  const std::string &getEspecie() const;

  void setEspecie(const std::string &especie);

  int getIdade() const;

  void setIdade(int idade);

  const Ambiente &getAmbiente() const;

  void setAmbiente(const Ambiente &ambiente);

  void cadastrarAnimal();

  std::vector<Animal> buscarAnimalPorNome(const std::string& nome);
};

}

#endif //ZOOLOGICO_CPP_ANIMAL_HPP
