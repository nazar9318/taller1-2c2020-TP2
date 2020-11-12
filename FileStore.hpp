#ifndef FILE_STORE_H
#define FILE_STORE_H

#include <vector>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <bits/stdc++.h>
#include "Lock.hpp"

class FileStore {
    private:
        std::mutex mutex;
        std::vector<std::string> file_names;
    public:
        FileStore();
   
        //Función: inserta el nombre de un archivo
        //y ordena los nombres de forma descendente
        void pushFile(std::string const& file_name);
   
        //Función: devuelve el último nombre de archivo
        //y lo remueve del vector de nombres de archivos
        std::string getFile();
        
        ~FileStore();
};

#endif
