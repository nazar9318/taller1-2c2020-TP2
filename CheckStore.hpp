#ifndef CHECK_STORE_H
#define CHECK_STORE_H

#include "Lock.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <bits/stdc++.h>

class CheckStore {
    private:
        std::mutex mutex;
        std::vector<std::string> resultados;
    public:
        explicit CheckStore();
    
        //Función: imprime el contenido del vector de resultados
        void printResults() const;
    
        //Función: concatena nombre de archivo y resultado de chequeo,
        //luego lo agrega al vector de resultados
        void addCheck(std::string const& name, std::string const& result);
    
        ~CheckStore();
};

#endif
