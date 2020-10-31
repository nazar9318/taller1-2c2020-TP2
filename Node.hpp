#ifndef NODE_H
#define NODE_H

#include <string>

enum node_state {NO_VISITED, OPEN, CLOSED};

class Node {
    private:
        node_state state;
        Node* const  next_node_1;
        Node* const  next_node_2;
        std::string const value;
    public:
        Node(std::string const value);

        //Función: 
        void setNextNode(Node* next);

        //Función: indica si el nodo no es abierto ni cerrado
        bool unVisited() const;
        
        //Función: indica si el nodo no es abierto
        bool isOpened() const;
        
        //Función: indica si el nodo no es cerrado
        bool isClosed() const;
        
        //Función: marca el nodo como abierto
        void open();
        
        //Función: marca el nodo como cerrado
        void close();
        
        //Función: obtiene el primer nodo vecino
        Node* getNext_1() const;
        
        //Función: obtiene el segundo nodo vecino
        Node* getNext_2() const;
        
        //Función: obtiene el contenido de la instrucción
        std::string getValue() const;
        
        ~Node();
};

#endif
