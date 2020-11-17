#include "FileStore.hpp"

FileStore::FileStore() {}

void FileStore::pushFile(std::string const& file_name) {
    this->file_names.push_back(file_name);
}

std::string FileStore::getFile() {
	Lock lock(this->mutex);
	std::string name = "";
	if (this->file_names.size() > 0) {
		name = this->file_names.back();
		this->file_names.pop_back();
	}
	return name;
}

FileStore::~FileStore() {}
