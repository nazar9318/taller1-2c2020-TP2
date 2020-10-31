#include "Parser.hpp"

Parser::Parser() {}

std::string Parser::getNextLine(std::ifstream& file) {
    std::string line = "";
    if (!file.eof()) {
        std::getline(file, line);
    }
    if (line.size() == 0 && !file.eof()) {
        std::getline(file, line);
    }
    return line;
}

bool Parser::isOneArgumentJump(std::string const line) {
    bool is_jmp = Parser::getInstruction(line)[0] == 'j';
    return (is_jmp && Parser::getInstructionWords(line) == 2);
}

bool Parser::hasLabel(std::string const line) {
    std::stringstream iss;
    std::string word = "";
    iss << line;
    iss >> word;
    return (word.back() == ':');
}

bool Parser::isConditionalJump(std::string const line) {
    return (Parser::getInstructionWords(line) > 2);
}

bool Parser::isReturn(std::string const line) {
    return (Parser::getInstruction(line).compare("ret") == 0);
}

std::string Parser::getInstruction(std::string const line) {
    std::stringstream iss;
    std::string word = "";
    iss << line;
    iss >> word;
    if (word.back() == ':') {
        iss >> word;
    }
    return word;
}

std::string Parser::getFirstWord(std::string const line) {
    std::stringstream iss;
    iss << line;
    std::string word = "";
    iss >> word;
    return word;
}

std::string Parser::getLastWord(std::string const line) {
    std::stringstream iss;
    iss << line;
    std::string word = "";
    while (iss >> word) {}
    return word;
}

size_t Parser::getWordCount(std::string const line) {
    std::stringstream iss;
    size_t word_count = 0;
    iss << line;
    std::string word = "";
    while (iss >> word) {
        word_count++;
    }
    return word_count;
}

size_t Parser::getInstructionWords(std::string const line) {
    size_t count = Parser::getWordCount(line);
    if (Parser::hasLabel(line)) {
        count--;
    }
    return count;
}

std::string Parser::getNextWord(std::string const line, size_t const ini) {
    std::stringstream iss;
    iss << line;
    std::string word = "";
    for (unsigned int i = 0; i < ini; i++) {
        iss >> word;
    }
    if (word.back() == ',') {
        word.erase(word.end()-1);
    }
    return word;
}

Parser::~Parser() {}
