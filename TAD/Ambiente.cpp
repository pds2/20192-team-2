#include "Ambiente.hpp"

namespace TAD {

int TAD::Ambiente::getId() const {
  return id;
}

void TAD::Ambiente::setId(int id) {
  Ambiente::id = id;
}

const std::string &TAD::Ambiente::getNome() const {
  return nome;
}

void TAD::Ambiente::setNome(const std::string &nome) {
  Ambiente::nome = nome;
}

double TAD::Ambiente::getAltura() const {
  return altura;
}

void TAD::Ambiente::setAltura(double altura) {
  Ambiente::altura = altura;
}

double TAD::Ambiente::getLargura() const {
  return largura;
}

void TAD::Ambiente::setLargura(double largura) {
  Ambiente::largura = largura;
}

double TAD::Ambiente::getProfundidade() const {
  return profundidade;
}

void TAD::Ambiente::setProfundidade(double profundidade) {
  Ambiente::profundidade = profundidade;
}

}