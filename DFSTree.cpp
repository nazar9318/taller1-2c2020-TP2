#include "DFSTree.hpp"

DFSTree::DFSTree(std::string file_name) {
    std::ifstream file;
    file.open(file_name);
    int i = 0;
    while (!file.eof()) {
        std::string new_line = "";
        new_line = Parser::getNextLine(file);
        if (new_line.size() > 3) {
            this->nodos.push_back(new Node(new_line));
            i++;
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

Node* DFSTree::findNodeJump(std::string const etiquette) {
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

void DFSTree::setConnections() {
    std::string word;
    size_t size = this->nodos.size();
    for (unsigned int i = 0; i < size; i++) {
        std::string word = this->nodos[i]->getValue();
        if (!Parser::isReturn(word)) {
            if (Parser::isOneArgumentJump(word)) {
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
	        }
        }
    }
}

void DFSTree::step(Node* node) {
	node->open();
	if (node->getNext_1() != NULL) {
		if (node->getNext_1()->unVisited()) {
			this->step(node->getNext_1());
		} else if (node->getNext_1()->isOpened()) {
			this->there_is_loop = true;
		}
	}
	if (node->getNext_2() != NULL) {
		if (node->getNext_2()->unVisited()) {
			this->step(node->getNext_2());
		} else if (node->getNext_2()->isOpened()) {
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

bool DFSTree::thereIsLoop() {
    return this->there_is_loop;
}

DFSTree::~DFSTree() {
    for (unsigned int i = 0; i < this->nodos.size(); i++) {
        delete this->nodos[i];
    }
}
