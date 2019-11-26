#include <iostream>
#include "Interface/Dashboard.hpp"

int main() {
    auto *dashboard = new Interface::Dashboard();
    dashboard->exibir();
    return 0;
}