#include <functional>
#include <climits>
#include <utility>
#include <limits>
#include <iomanip>
#include "Perfil.hpp"

#define VER_FICHA 1
#define CADASTRAR_HISTORICO_MEDICO 2
#define SAIR 0
#define OPCAO_INVALIDA 400

namespace Interface {
/**
 * @brief AbstractInterface é chamada para mostrar o título
 * @param título
 */
Perfil::Perfil(TAD::Animal *animalSelecionado) : AbstractInterface("Perfil") {
  this->animal = *animalSelecionado;
}
/**
 * @brief Exibe menu para o perfil do animal
 * @param --
 */
void Perfil::exibir() {
  int opcao = 0;
  do {
    std::cout << "Escolha a opção:" << std::endl << "1 - Ver ficha" << std::endl << "2 - Cadastrar histórico médico"
              << std::endl << "0 - Sair"
              << std::endl;
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
void Perfil::processarEntrada(int opcao) {
  switch (opcao) {
    case VER_FICHA:verFicha();
      system("clear");
      break;

    case CADASTRAR_HISTORICO_MEDICO:cadastroHistoricoMedico();
      std::cout << "\033[1;32mHistórico médico cadastrado com sucesso! \033[0m" << std::endl << std::endl;
      system("clear");
      break;

    case 0: system("clear");
      std::cout << std::endl;
      break;

    default:std::__throw_invalid_argument("Digite outra opção.");
  }
}
/**
 * @brief Se a opção escolhida for 1, as caracteristicas do respectivo animal são mostrada, seguidas de todas as transações na ficha médica
 * @param --
 */
void Perfil::verFicha() {
  std::cout << "Carregando" << std::endl;
  std::vector<TAD::HistoricoMedico>
      listaHistoricoMedico = this->historicoMedico.selecionarFichaMedicaPorIdAnimal(this->animal.getId());

  system("clear");

  std::cout << "Id: " + std::to_string(this->animal.getId()) << std::endl;
  std::cout << "Nome: " + this->animal.getNome() << std::endl;
  std::cout << "Idade: " + std::to_string(this->animal.getIdade()) << std::endl;
  std::cout << "Espécie: " + this->animal.getEspecie() << std::endl;
  std::cout << "Ambiente: " + this->animal.getAmbiente().getNome() << std::endl << std::endl;

  std::cout << "Ficha médica" << std::endl;

  for (const auto &historicoMedicoIndex : listaHistoricoMedico) {
    std::cout << "Peso: ";
    std::cout <<  std::setprecision(2) << historicoMedicoIndex.getPeso() << std::endl;
    std::cout << "Altura: ";
    std::cout <<  std::setprecision(2) << historicoMedicoIndex.getAltura() << std::endl;
    std::cout << "Observação: " + historicoMedicoIndex.getObservacao() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
  }

  std::cout << "Pressione enter para sair";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}
/**
 * @brief Se a opção escolhida for 2, um novo formulário é dado para o cadastramento de uma novas observações no histórico médico
 * @param --
 */
void Perfil::cadastroHistoricoMedico() {
  std::string str;
  double val;

  std::cout << "Cadastro de histórico médico: " + this->animal.getEspecie() + " " + this->animal.getNome()  << std::endl << std::endl;

  std::cout << "Peso: ";
  std::cin >> val;
  this->historicoMedico.setPeso(val);

  std::cout << std::endl;
  std::cout << "Altura: ";
  std::cin >> val;
  this->historicoMedico.setAltura(val);

  std::cout << std::endl;
  std::cout << "Observação: ";
  std::cin.ignore();
  getline(std::cin, str);
  this->historicoMedico.setObservacao(str);

  this->historicoMedico.cadastrarHistoricoMedico(this->animal.getId());
}

}