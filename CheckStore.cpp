#include "CheckStore.hpp"

CheckStore::CheckStore() {}

void CheckStore::printResults() const {
    for (unsigned int i = 0; i < resultados.size(); i++) {
        std::cout << resultados.at(i) << std::endl;
    }
}

void CheckStore::addCheck(std::string const name, std::string const result) {
    std::string nuevo = name + " " + result;
    this->resultados.push_back(nuevo);
}

CheckStore::~CheckStore() {}
