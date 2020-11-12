#include "DFSTree.hpp"

DFSTree::DFSTree(std::string& file_name) {
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()) {
        std::string new_line = Parser::getNextLine(file);
        if (new_line.size() > 0) {
            this->nodos.push_back(new Node(new_line));
        }
    }
    file.close();
    this->there_is_loop = false;
    this->setConnections();
}

bool DFSTree::allInstructionsUsed() {
    bool visited = true;
    for (unsigned int i = 0; i < this->nodos.size() && visited; i++) {
        visited = this->nodos[i]->isClosed();
    }
    return visited;
}

Node* DFSTree::findNodeJump(std::string const& etiquette) {
    std::string label = etiquette;
    label += ":";
    Parser parser;
    for (unsigned int i = 0; i < this->nodos.size(); i++) {
        std::string value = Parser::getFirstWord(this->nodos[i]->getValue());
        if (value.compare(label) == 0) {
            return this->nodos[i];
        }
    }
    return NULL;
}

void DFSTree::connect(Node* n, size_t s, std::string const &w, size_t i) {
    if (Parser::isOneArgumentJump(w)) {
        std::string salto = Parser::getLastWord(w);
        n->setNextNode(this->findNodeJump(salto));
    } else if (Parser::isConditionalJump(w)) {
        std::string salto = Parser::getLastWord(w);
        n->setNextNode(this->findNodeJump(salto));
        if (Parser::getInstructionWords(w) == 4) {
            size_t count = Parser::getWordCount(w) - 1;
            salto = Parser::getNextWord(w, count);
            n->setNextNode(this->findNodeJump(salto));
        } else {
			if (i+1 < s) {
			    n->setNextNode(this->nodos[i+1]);
			}
        }
    } else if (i+1 < s) {
        n->setNextNode(this->nodos[i+1]);
    }
}

void DFSTree::setConnections() {
    size_t size = this->nodos.size();
    for (unsigned int i = 0; i < size; i++) {
        std::string word = this->nodos[i]->getValue();
        if (!Parser::isReturn(word)) {
            connect(this->nodos[i], size, word, i);
            /*if (Parser::isOneArgumentJump(word)) {
                std::string salto = Parser::getLastWord(word);
                this->nodos[i]->setNextNode(this->findNodeJump(salto));
            } else if (Parser::isConditionalJump(word)) {
                std::string salto = Parser::getLastWord(word);
                this->nodos[i]->setNextNode(this->findNodeJump(salto));
                if (Parser::getInstructionWords(word) == 4) {
                    size_t count = Parser::getWordCount(word) - 1;
                    salto = Parser::getNextWord(word, count);
                    this->nodos[i]->setNextNode(this->findNodeJump(salto));
                } else {
			        if (i+1 < size) {
				        this->nodos[i]->setNextNode(this->nodos[i+1]);
			        }
                }
            } else if (i+1 < size) {
		        this->nodos[i]->setNextNode(this->nodos[i+1]);
	        }*/
        }
    }
}

void DFSTree::step(Node* node) {
	node->open();
	if (node->getLeft() != NULL) {
		if (node->getLeft()->unVisited()) {
			this->step(node->getLeft());
		} else if (node->getLeft()->isOpened()) {
			this->there_is_loop = true;
		}
	}
	if (node->getRight() != NULL) {
		if (node->getRight()->unVisited()) {
			this->step(node->getRight());
		} else if (node->getRight()->isOpened()) {
			this->there_is_loop = true;
		}
	}
    node->close();
}

void DFSTree::walk() {
    if (this->nodos.size() > 0) {
	    this->step(this->nodos.front());
    }
}

bool DFSTree::thereIsLoop() const{
    return this->there_is_loop;
}

DFSTree::~DFSTree() {
    for (unsigned int i = 0; i < this->nodos.size(); i++) {
        delete this->nodos[i];
    }
}

