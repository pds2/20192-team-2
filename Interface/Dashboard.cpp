#include <functional>
#include <climits>
#include "Dashboard.hpp"
#include "CadastroAnimal.hpp"
#include "BuscaAnimal.hpp"

#define CADASTRAR_ANIMAL 1
#define BUSCAR_ANIMAL 2
#define SAIR 0
#define OPCAO_INVALIDA 400

namespace Interface {
/**
 * @brief AbstractInterface é chamada para mostrar o título
 * @param título
 */
Dashboard::Dashboard() : AbstractInterface("Menu") {}
/**
 * @brief Exibe o menu principal
 * @param --
 */
void Dashboard::exibir() {
  int opcao = 0;
  system("clear");
  do {
    std::cout << std::endl << "\033[1;36mOlá!\033[0m"
              << std::endl
              << std::endl;
    std::cout << "Escolha a opção:" << std::endl << "1 - Cadastrar animal" << std::endl << "2 - Buscar animal"
              << std::endl << "0 - Sair" << std::endl;
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
/**
 * @brief Após exibir o menu, o usuário escolhe uma opção, a entrada é processada e a função correspondente é chamada
 * @param opcao
 */
void Dashboard::processarEntrada(int opcao) {
  switch (opcao) {
    case CADASTRAR_ANIMAL:cadastrarAnimal();
      system("clear");
      std::cout << "\033[1;32mAnimal cadastrado com sucesso! \033[0m" << std::endl << std::endl;
      break;

    case BUSCAR_ANIMAL:buscarAnimal();
      system("clear");
      break;

    case 0: system("clear");
      std::cout << std::endl;
      break;

    default:std::__throw_invalid_argument("Digite outra opção.");
  }
}
/**
 * @brief Se a opção escolhida for 1, um cadastro do animal é criado
 * @param --
 */
void Dashboard::cadastrarAnimal() {
  auto *cadastroAnimal = new CadastroAnimal();
  cadastroAnimal->exibir();
}
/**
 * @brief Se a opção escolhida for 2, uma busca por animal é criada
 * @param --
 */
void Dashboard::buscarAnimal() {
  auto *buscaAnimal = new BuscaAnimal();
  buscaAnimal->exibir();
}

}


