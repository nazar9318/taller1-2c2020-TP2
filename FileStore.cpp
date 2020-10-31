#include "FileStore.hpp"

FileStore::FileStore() {}

void FileStore::pushFile(std::string file_name) {
    this->file_names.push_back(file_name);
    sort(file_names.begin(), file_names.end(), std::greater<std::string>());
}

std::string FileStore::getFile() {
    std::string name = "";
    if (this->file_names.size() > 0) {
        name = this->file_names.back();
        this->file_names.pop_back();
    }
    return name;
}

bool FileStore::isEmpty() {
    return (this->file_names.size() == 0);
}

FileStore::~FileStore() {}
