#include "Directory.h"

Directory::Directory(const std::string& name)
    : name(name) {}

void Directory::addFile(const std::shared_ptr<File>& file) {
    files.push_back(file);
}

void Directory::addDirectory(const std::shared_ptr<Directory>& directory) {
    directory->setParent(shared_from_this()); // Set the parent directory
    subdirectories.push_back(directory);
}


std::vector<std::shared_ptr<File>> Directory::getFiles() const {
    return files;
}

std::vector<std::shared_ptr<Directory>> Directory::getSubdirectories() const {
    return subdirectories;
}

std::string Directory::getName() const {
    return name;
}
