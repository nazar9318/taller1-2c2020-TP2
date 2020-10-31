#include "Node.hpp"

Node::Node(std::string const value) {
    this->value = value;
    this->state = NO_VISITED;
    this->next_node_1 = NULL;
    this->next_node_2 = NULL;
}

void Node::setNextNode(Node* next) {
    if (this->next_node_1 == NULL && this->next_node_2 != next) {
        this->next_node_1 = next;
    } else if (this->next_node_2 == NULL && this->next_node_1 != next) {
        this->next_node_2 = next;
    }
}

bool Node::unVisited() const {
    return this->state == NO_VISITED;
}

bool Node::isOpened() const {
    return this->state == OPEN;
}

bool Node::isClosed() const {
    return this->state == CLOSED;
}

void Node::open() {
    this->state = OPEN;
}

void Node::close() {
    this->state = CLOSED;
}

Node* Node::getNext_1() const {
    if (this->next_node_1 != NULL) {
        return this->next_node_1;
    }
    return NULL;
}

Node* Node::getNext_2() const {
    if (this->next_node_2 != NULL) {
        return this->next_node_2;
    }
    return NULL;
}

std::string Node::getValue() const {
    return this->value;
}

Node::~Node() {}
