#include "CadastroAnimal.hpp"

namespace Interface {
/**
 * @brief AbstractInterface é chamada para mostrar o título
 * @param título
 */
CadastroAnimal::CadastroAnimal() : AbstractInterface("Cadastro animal") {}
/**
 * @brief Exibe um formulário para preenchimento das caracteristicas do animal
 * @param --
 */
void CadastroAnimal::exibir() {
  std::string str;
  int val;

  std::cout << "Digite os dados do animal conforme for requisitado:" << std::endl << std::endl;

  std::cout << "Nome do animal:" << std::endl;
  std::cin >> str;
  this->animal.setNome(str);

  std::cout << "Espécie do animal:" << std::endl;
  std::cin >> str;
  this->animal.setEspecie(str);

  std::cout << "Idade do animal:" << std::endl;
  std::cin >> val;
  this->animal.setIdade(val);

  std::cout << "Id do ambiente:" << std::endl;
  std::cin >> val;
  this->ambiente.setId(val);
  this->animal.setAmbiente(this->ambiente);

  std::cout << "Aguarde um instante" << std::endl;

  this->animal.cadastrarAnimal();
}

}
