#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "Checker.hpp"
#include <string>
#include <vector>

class Programa {
    private:
        int cantidad_hilos;
        std::vector<std::thread> threads;
        int argc;
        char** argv;
    public:
        Programa(int argc, char* argv[]);

        //Función: ejecuta el programa de eBPF
        void ejecutar();
        
        ~Programa();
};

#endif
