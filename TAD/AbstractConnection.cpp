#include "AbstractConnection.hpp"

namespace TAD {

/**
* @brief Abre conexão com o banco de dados nas classes que herdam de AbstractConnetcion
*/
void AbstractConnection::abrirConexao() {
//        Criando conexão
  driver = get_driver_instance();
//        Dados do banco MySQL
  con = driver->connect("kf3k4aywsrp0d2is.cbetxkdyhwsb.us-east-1.rds.amazonaws.com",
                        "j69eenkrzzegzofm",
                        "xrulxu4pdslt4eof");
//        Escolhendo o database
  con->setSchema("ydluehwuodaotc6r");
}
/**
 * @brief Fecha conexão com o banco de dados nas classes que herdam de AbstractConnetcion
 */
void AbstractConnection::fecharConexao() {

  delete res;

  delete stmt;
  delete con;
}

}