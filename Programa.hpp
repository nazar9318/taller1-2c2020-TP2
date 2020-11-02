#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "Checker.hpp"

class Programa {
    private:
        int cantidad_hilos;
        std::vector<std::thread> threads;
        FileStore files;
    public:
        Programa(int argc, char* argv[]);

        //Función: ejecuta el programa de eBPF
        void ejecutar();
        
        ~Programa();
};

#endif
