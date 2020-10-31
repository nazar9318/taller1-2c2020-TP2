#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>

class Parser {
    private:
        //Función: devuelve verdadero si la línea de código tiene una etiqueta
        static bool hasLabel(std::string const line);
    public:
        Parser();

        //Función: obtiene la siguiente línea del archivo
        static std::string getNextLine(std::ifstream& file);

        //Función: obtiene la siguiente palabra de la línea,
        //partiendo desde beginning
        static std::string getNextWord(std::string const line, size_t ini);

        //Función: obtiene la primera palabra de la línea
        static std::string getFirstWord(std::string const line);
        
        //Función: obtiene la última palabra de la línea
        static std::string getLastWord(std::string const line);
        
        //Función: obtiene la instrucción de la línea de código
        static std::string getInstruction(std::string const line);
        
        //Función: obtiene la cantidad de palabras de line de códidgo
        static size_t getWordCount(std::string const line);
        
        //Función: obtiene la cantidad de palabras de line, sin contar la etiqueta
        static size_t getInstructionWords(std::string const line);
        
        //Función: devuelve verdadero si word es un salto
        //que indica sólo la dirección de salto
        static bool isOneArgumentJump(std::string const word);
        
        //Función: devuelve verdadero si word es un salto condicional
        //de dos o más argumentos
        static bool isConditionalJump(std::string const line);
        
        //Función: devuelve verdadero si word es una instrucción ret
        static bool isReturn(std::string const word);
        
        ~Parser();
};

#endif
