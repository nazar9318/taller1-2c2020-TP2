#include "Node.hpp"

Node::Node(std::string const value) {
    this->value = value;
    this->state = NO_VISITED;
    this->left = NULL;
    this->right = NULL;
}

void Node::setNextNode(Node* next) {
    if (this->left == NULL && this->right != next) {
        this->left = next;
    } else if (this->right == NULL && this->left != next) {
        this->right = next;
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

Node* Node::getLeft() const {
    if (this->left != NULL) {
        return this->left;
    }
    return NULL;
}

Node* Node::getRight() const {
    if (this->right != NULL) {
        return this->right;
    }
    return NULL;
}

std::string Node::getValue() const {
    return this->value;
}

Node::~Node() {}
