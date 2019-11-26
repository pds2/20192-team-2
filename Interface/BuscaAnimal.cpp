#include <functional>
#include <climits>
#include "BuscaAnimal.hpp"
#include "Perfil.hpp"

#define AVANCAR 1
#define RETROCEDER 2
#define PERFIL 3
#define SAIR 0
#define OPCAO_INVALIDA 400

namespace Interface {
/**
 * @brief Chama interface para mostrar o título
 * @param titulo
 */
BuscaAnimal::BuscaAnimal() : AbstractInterface("Busca animal") {}
/**
 * @brief Pede inicialmente o nome de um animal para busca e analisa se este existe no banco. Se positivo, um menu para escolha é dado.
 * @param --
 */
void BuscaAnimal::exibir() {
  std::string termoBusca;

  std::cout << "Digite o nome do animal desejado:" << std::endl;
  std::cin >> termoBusca;

  this->animais = this->animal.buscarAnimalPorNome(termoBusca);
  if (this->animais.empty()) {
    std::cout << "Não foram encontrados animais com o nome: " + termoBusca << std::endl;
  } else {
    int opcao = 0;
    this->index = 0;
    system("clear");
    do {
//		std::cout << "Carregando..." << std::endl;

      exibirAnimal(this->animais.at(this->index));
      std::cout << "Escolha a opção:" << std::endl << "1 - Avançar" << std::endl << "2 - Retroceder" << std::endl
                << "3 - Entrar no perfil" << std::endl
                << "0 - Sair" << std::endl;

      try {
        std::cin >> opcao;
        while (std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          opcao = OPCAO_INVALIDA;
          std::__throw_bad_function_call();
        }
        this->processarEntrada(opcao);
      } catch (std::invalid_argument &e) {
        system("clear");
        std::cout << std::endl << "\033[1;31mArgumento inválido: " << e.what() << std::endl
                  << "Tente novamente.\033[0m" << std::endl << std::endl;
      } catch (std::bad_function_call &e) {
        system("clear");
        std::cout << std::endl << "\033[1;33mErro. Escolha uma opção válida do menu.\033[0m" << std::endl
                  << std::endl;
      } catch (std::out_of_range &e) {
        std::cout << std::endl << "\033[1;31mErro: " << e.what() << "\033[0m" << std::endl << std::endl;
      }
    } while (opcao != 0);
  }
}
/**
 * @brief Após exibir o menu, o usuário escolhe uma opção, a entrada é processada e a função correspondente é chamada.
 * @param opcao
 */

void BuscaAnimal::processarEntrada(int opcao) {
  switch (opcao) {
    case AVANCAR:
      if (this->animais.empty()) {
        std::__throw_out_of_range("Você não tem mais animais para exibir");
      } else {
        avancarAnimal();
      }
      break;

    case RETROCEDER:
      if (this->animais.empty()) {
        std::__throw_out_of_range("Você não tem mais animais para exibir");
      } else {
        retrocederAnimal();
      }
      break;

    case PERFIL:perfil();
      break;

    case 0: system("clear");
      std::cout << std::endl;
      break;

    default:std::__throw_invalid_argument("Digite outra opção.");
  }
}
/**
 * @brief Se a opção escolhida for 1, a função avancarAnimal prossegue para o proximo da lista se este existir
 * @param --
 */
void BuscaAnimal::avancarAnimal() {
  if (this->index + 1 >= this->animais.size()) {
    system("clear");
    std::cout << "\033[1;36mNão é possível avançar mais.\033[0m" << std::endl;
  } else {
    this->index++;
    system("clear");
  }
}
/**
 * @brief Se a opção escolhida for 2, a função retrocederAnimal volta para o animal anterior se este existir
 * @param --
 */
void BuscaAnimal::retrocederAnimal() {
  if (this->index <= 0) {
    system("clear");
    std::cout << "\033[1;36mNão é possível retroceder mais.\033[0m" << std::endl;
  } else {
    this->index--;
    system("clear");
  }
}
/**
 * @brief Se a opção escolhida for 3, a função exibirAnimal mostra as características do animal
 * @param animalAtual
 */
void BuscaAnimal::exibirAnimal(const TAD::Animal &animalAtual) {
  std::cout << "Animal " + std::to_string((index + 1)) + " de " + std::to_string(this->animais.size()) << std::endl
            << std::endl;
  std::cout << "Nome: " << animalAtual.getNome() << std::endl;
  std::cout << "Espécie: " << animalAtual.getEspecie() << std::endl;
  std::cout << "Ambiente: " << animalAtual.getAmbiente().getNome() << std::endl << std::endl;
}
/**
 * @brief Retorna animal escolhido de acordo com o índice dado
 * @param --
 * @return &this->animais.at(index)
 */
TAD::Animal *BuscaAnimal::obterAnimalPeloIndice() {
  return &this->animais.at(index);
};
/**
 * @brief Exibe perfil do animal escolhido através do índice
 * @param --
 */
void BuscaAnimal::perfil() {
  auto *perfil = new Perfil(obterAnimalPeloIndice());
  perfil->exibir();
  system("clear");
}

}