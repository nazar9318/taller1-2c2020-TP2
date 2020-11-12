#ifndef DFS_TREE_H
#define DFS_TREE_H

#include <vector>
#include "Node.hpp"
#include "Parser.hpp"

class DFSTree {
    private:
        std::vector<Node*> nodos;
        void setConnections();
        void connect(Node* n, size_t s, std::string const &w, size_t i);
        void step(Node* node);
        Node* findNodeJump(std::string const& etiquette);
        bool there_is_loop;
    public:
        explicit DFSTree(std::string& file_name);
  
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
