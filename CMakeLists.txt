cmake_minimum_required(VERSION 3.15)
project(zoologico_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(zoologico_cpp main.cpp TAD/Animal.cpp TAD/Animal.hpp TAD/AbstractConnection.cpp TAD/AbstractConnection.hpp Interface/Dashboard.cpp Interface/Dashboard.hpp Interface/AbstractInterface.cpp Interface/AbstractInterface.hpp Interface/CadastroAnimal.cpp Interface/CadastroAnimal.hpp TAD/Ambiente.cpp TAD/Ambiente.hpp Interface/BuscaAnimal.cpp Interface/BuscaAnimal.hpp Interface/Perfil.cpp Interface/Perfil.hpp TAD/HistoricoMedico.cpp TAD/HistoricoMedico.hpp)
target_link_libraries(zoologico_cpp mysqlcppconn)

add_custom_target(run
        COMMAND zoologico_cpp
        DEPENDS zoologico_cpp
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
        )