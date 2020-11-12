#include "CheckStore.hpp"

CheckStore::CheckStore(std::mutex &mutex) : mutex(mutex) {}

void CheckStore::printResults() const {
    for (unsigned int i = 0; i < resultados.size(); i++) {
        std::cout << resultados.at(i) << std::endl;
    }
}

void CheckStore::addCheck(std::string const& name, std::string const& result) {
    Lock lock(this->mutex);
    std::string nuevo = name + " " + result;
    this->resultados.push_back(nuevo);
    sort(resultados.begin(), resultados.end());
}

CheckStore::~CheckStore() {}
