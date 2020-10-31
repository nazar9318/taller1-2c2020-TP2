#ifndef FILE_STORE_H
#define FILE_STORE_H

#include <vector>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <bits/stdc++.h>

class FileStore {
    private:
        std::vector<std::string> file_names;
    public:
        FileStore();
   
        //Función: inserta el nombre de un archivo
        //y ordena los nombres de forma descendente
        void pushFile(std::string);
   
        //Función: devuelve el último nombre de archivo
        //y lo remueve del vector de nombres de archivos
        std::string getFile();
   
        //Función: indica si el repositorio está vacío
        bool isEmpty();
        
        ~FileStore();
};

#endif
