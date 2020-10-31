#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>

class Parser {
    private:
        //Función: devuelve verdadero si la línea de código tiene una etiqueta
        bool hasLabel(std::string const line);
    public:
        Parser();

        //Función: obtiene la siguiente línea del archivo
        std::string getNextLine(std::ifstream& file);

        //Función: obtiene la siguiente palabra de la línea,
        //partiendo desde beginning
        std::string getNextWord(std::string const line, size_t const beginning);

        //Función: obtiene la primera palabra de la línea
        std::string getFirstWord(std::string const line);
        
        //Función: obtiene la última palabra de la línea
        std::string getLastWord(std::string const line);
        
        //Función: obtiene la instrucción de la línea de código
        std::string getInstruction(std::string const line);
        
        //Función: obtiene la cantidad de palabras de line de códidgo
        size_t getWordCount(std::string const line);
        
        //Función: obtiene la cantidad de palabras de line, sin contar la etiqueta
        size_t getInstructionWords(std::string const line);
        
        //Función: devuelve verdadero si word es un salto
        //que indica sólo la dirección de salto
        bool isOneArgumentJump(std::string const word);
        
        //Función: devuelve verdadero si word es un salto condicional
        //de dos o más argumentos
        bool isConditionalJump(std::string const line);
        
        //Función: devuelve verdadero si word es una instrucción ret
        bool isReturn(std::string const word);
        
        ~Parser();
};

#endif
