#include "HistoricoMedico.hpp"

namespace TAD {

int HistoricoMedico::getId() const {
  return id;
}

void HistoricoMedico::setId(int id) {
  HistoricoMedico::id = id;
}

double HistoricoMedico::getPeso() const {
  return peso;
}

void HistoricoMedico::setPeso(double peso) {
  HistoricoMedico::peso = peso;
}

double HistoricoMedico::getAltura() const {
  return altura;
}

void HistoricoMedico::setAltura(double altura) {
  HistoricoMedico::altura = altura;
}

const std::string &HistoricoMedico::getObservacao() const {
  return observacao;
}

void HistoricoMedico::setObservacao(const std::string &observacao) {
  HistoricoMedico::observacao = observacao;
}
/**
 * @brief Chama função para abrir conexão com o banco de dados, seleciona e retorna a ficha médica por meio do ID do animal e fecha conexão.
 * @param animalId
 * @return listaHistoricoMedico
 */
std::vector<TAD::HistoricoMedico> TAD::HistoricoMedico::selecionarFichaMedicaPorIdAnimal(int animalId) {
  try {
    abrirConexao();
    stmt = con->createStatement();
//    Query SQL
    res = stmt->executeQuery(
        "SELECT hm.peso, hm.altura, hm.observacao FROM historicoMedico AS hm JOIN animal a ON hm.animal_id = a.id WHERE a.id = "
            + std::to_string(animalId));
    std::vector<HistoricoMedico> listaHistoricoMedico;
    while (res->next()) {
      this->setPeso(res->getDouble("peso"));
      this->setAltura(res->getDouble("altura"));
      this->setObservacao(res->getString("observacao"));
      listaHistoricoMedico.push_back(*this);
    }
    fecharConexao();
    return listaHistoricoMedico;
  } catch (sql::SQLException &e) {
    std::cout << "# ERR: SQLException in " << __FILE__;
    //cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    std::cout << "# ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    fecharConexao();
  } catch (std::exception &e) {
    std::cout << "# ERR: " << e.what();
    fecharConexao();
  }
}
/**
 * @brief Chama função para abrir conexão com o banco de dados, adiciona uma nova ficha médica por meio do ID do animal e fecha conexão.
 * @param animalId
 */
void TAD::HistoricoMedico::cadastrarHistoricoMedico(int animalId) {
  try {
    abrirConexao();
    stmt = con->createStatement();
//    Query SQL
    stmt->execute(
        "INSERT INTO historicoMedico (id, peso, altura, observacao, animal_id) VALUES (DEFAULT, '" + std::to_string(this->getPeso()) + "','"
            + std::to_string(this->getAltura()) + "','" + this->getObservacao() + "','" + std::to_string(animalId) + "')");
    fecharConexao();

  } catch (sql::SQLException &e) {
    std::cout << "# ERR: SQLException in " << __FILE__;
    //cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    std::cout << "# ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    fecharConexao();
  } catch (std::exception &e) {
    std::cout << "# ERR: " << e.what();
    fecharConexao();
  }
}

}