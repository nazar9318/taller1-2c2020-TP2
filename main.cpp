#include <stdio.h>
#include <iostream>
#include "Programa.hpp"

int main(int argc, char* argv[]) {
    Programa programa(argc, argv);
    programa.ejecutar();
    return 0;
}
