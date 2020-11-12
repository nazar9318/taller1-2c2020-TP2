#include "Programa.hpp"

Programa::Programa(int argc, char* argv[]) : argc(argc), argv(argv) {
    this->cantidad_hilos = strtol(argv[1], (char**)NULL, 10);
}

void Programa::ejecutar() {
    FileStore files;
    for (int i = 2; i < argc; i++) {
        files.pushFile((std::string)argv[i]);
    }
    CheckStore checks;
    std::vector<Checker*> checkers;
    for (int i = 0; i < this->cantidad_hilos; i++) {
        checkers.push_back(new Checker(files, checks));
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

