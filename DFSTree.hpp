#ifndef DFS_TREE_H
#define DFS_TREE_H

#include <vector>
#include <string>
#include "Node.hpp"
#include "Parser.hpp"

class DFSTree {
    private:
        std::vector<Node*> nodos;
        void setConnections();
        void connect(size_t pos, size_t s, std::string const &w);
        void connectCondJump(size_t pos, size_t s, std::string const &w);
        void step(Node* node);
        Node* findNodeJump(std::string const& etiquette);
        bool there_is_loop;

    public:
        explicit DFSTree(std::string const& file_name);
  
        //Función: indica si se encontró un loop
        //en las instrucciones del archivo con el
        //que fue construido el árbol
        bool thereIsLoop() const;

        //Función: indica si hay instrucciones sin usar
        //en el archivo con el que fue construido el árbol
        bool allInstructionsUsed();
  
        //Función: recorre las instrucciones del archivo hasta
        //que las visita todas o hasta encuentra un bucle
        void walk();
  
        ~DFSTree();
};

#endif
