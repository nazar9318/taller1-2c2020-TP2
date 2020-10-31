#include "Programa.hpp"

Programa::Programa(int argc, char* argv[]) {
    this->cantidad_hilos = atoi(argv[1]);
    for (int i = 2; i < argc; i++) {
        this->files.pushFile((std::string)argv[i]);
    }
}

void Programa::ejecutar() {
    CheckStore checks;
    std::vector<Checker*> checkers;
    std::mutex mutex;
    for (int i = 0; i < this->cantidad_hilos; i++) {
        checkers.push_back(new Checker(this->files, checks, mutex));
    }
    for (int i = 0; i < this->cantidad_hilos; i++) {
        checkers[i]->start();
    }
    for (int i = 0; i < this->cantidad_hilos; i++) {
        checkers[i]->join();
    }
    for (int i = 0; i < this->cantidad_hilos; i++) {
        delete checkers[i];
    }
    checks.printResults();
}

Programa::~Programa() {}
