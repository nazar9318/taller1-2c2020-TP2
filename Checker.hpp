#ifndef CHECKER_H
#define CHECKER_H

#include <mutex>
#include "Thread.hpp"
#include "DFSTree.hpp"
#include "FileStore.hpp"
#include "CheckStore.hpp"

class Checker : public Thread{
    private:
        FileStore &files;
        CheckStore &checks;
        std::mutex &mutex;
        void run();
    public:
        Checker(FileStore &files, CheckStore &checks, std::mutex &m);

        //Función: valida todos los archivos del repositorio de archivos
        //y agrega el nombre de cada uno con su respectivo resultado
        //al repositorio de verificaciones
        void checkErrors();
        
        ~Checker();
};

#endif
