#include <iostream>
#include <vector>
#include "Animal.hpp"

namespace TAD {

int TAD::Animal::getId() const {
  return id;
}

void TAD::Animal::setId(int id) {
  Animal::id = id;
}

const std::string &TAD::Animal::getNome() const {
  return nome;
}

void TAD::Animal::setNome(const std::string &nome) {
  Animal::nome = nome;
}

const std::string &TAD::Animal::getEspecie() const {
  return especie;
}

void TAD::Animal::setEspecie(const std::string &especie) {
  Animal::especie = especie;
}

int TAD::Animal::getIdade() const {
  return idade;
}

void TAD::Animal::setIdade(int idade) {
  Animal::idade = idade;
}

const TAD::Ambiente &TAD::Animal::getAmbiente() const {
  return ambiente;
}

void TAD::Animal::setAmbiente(const TAD::Ambiente &ambiente) {
  Animal::ambiente = ambiente;
}
/**
 * @brief Chama função para abrir conexão com o banco de dados, insere um novo animal e chama função para fechá-lo
 * @param --
 */
void TAD::Animal::cadastrarAnimal() {
  try {
    abrirConexao();
    stmt = con->createStatement();
//    Query SQL
    stmt->execute(
        "INSERT INTO animal (id, nome, especie, idade, ambiente_id) VALUES (DEFAULT, '" + this->getNome() + "','"
            + this->getEspecie() + "'," + std::to_string(this->getIdade()) + "," + std::to_string(this->getAmbiente().getId()) + ")");
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
/**
 * @brief Chama função para abrir conexão com o banco de dados, pesquisa animal(is) por meio do nome dado e retorna as opções que contém aquela string
 * @param nomeAnimal
 * @return animais
 */
std::vector<TAD::Animal> TAD::Animal::buscarAnimalPorNome(const std::string& nomeAnimal) {
  try {
    abrirConexao();
    stmt = con->createStatement();
//    Query SQL
    res = stmt->executeQuery("SELECT an.id, an.nome, an.especie, an.idade, amb.nome AS ambiente FROM animal AS an JOIN ambiente amb ON an.ambiente_id = amb.id WHERE an.nome LIKE '%" + nomeAnimal + "%'");
    std::vector<Animal> animais;
    while (res->next()) {
      auto *animal = new Animal();
      animal->setId(res->getInt("id"));
      animal->setNome(res->getString("nome"));
      animal->setEspecie(res->getString("especie"));
      animal->setIdade(res->getInt("idade"));
      this->ambiente.setNome(res->getString("ambiente"));
      animal->setAmbiente(this->ambiente);
      animais.push_back(*animal);
    }
    fecharConexao();
    return animais;
  }  catch (sql::SQLException &e) {
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


