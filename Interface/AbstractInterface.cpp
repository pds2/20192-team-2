#include "AbstractInterface.hpp"

namespace Interface {

/**
 * @brief Mostra títulos das interfaces
 * @param titulo
 */
AbstractInterface::AbstractInterface(const std::string &titulo) : titulo(titulo) {
  system("clear");
  std::cout << "\b" << titulo << std::endl;
}

const std::string &AbstractInterface::getTitulo() const {
  return titulo;
}

}
