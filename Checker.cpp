#include "Checker.hpp"

Checker::Checker(FileStore &files, CheckStore &checks) : 
files(files), checks(checks) {}

void Checker::run() {
	std::string name = this->files.getFile();
	while (name != "") {
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
		name = this->files.getFile();
	}
}

Checker::~Checker() {}
