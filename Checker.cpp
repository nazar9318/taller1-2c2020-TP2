#include "Checker.hpp"

Checker::Checker(FileStore &files, CheckStore &checks, std::mutex &m) : 
files(files), checks(checks), mutex(m) {}

void Checker::run() {
    this->mutex.lock();
    while (!this->files.isEmpty()) {
	    std::string name = this->files.getFile();
        std::string result;
        DFSTree tree(name);
        tree.walk();
        if (tree.thereIsLoop()) {
            result = "FAIL: cycle detected";
        } else if (!tree.allInstructionsUsed()) {
            result = "FAIL: unused instructions detected";
        } else {
	        result = "GOOD";
    	}
        this->checks.addCheck(name, result);
    }
    this->mutex.unlock();
}

void Checker::checkErrors() {
    this->run();
}

Checker::~Checker() {}
