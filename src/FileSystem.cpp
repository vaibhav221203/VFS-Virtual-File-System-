#include "FileSystem.h"
#include <iostream>

FileSystem::FileSystem() {
    root = std::make_shared<Directory>("root");
    currentDirectory = root;
}

void FileSystem::createFile(const std::string& name, const std::string& content) {
    std::shared_ptr<File> file = std::make_shared<File>(name, content);
    currentDirectory->addFile(file);
}

void FileSystem::createDirectory(const std::string& name) {
    std::shared_ptr<Directory> directory = std::make_shared<Directory>(name);
    currentDirectory->addDirectory(directory);
}

void FileSystem::changeDirectory(const std::string& dirName) {
    if (dirName == "root") {
        currentDirectory = root;  // If user wants to go back to root, set currentDirectory to root
        std::cout << "Changed directory to root.\n";
    } else {
        bool found = false;
        // Loop through all subdirectories of the current directory
        for (const auto& dir : currentDirectory->getSubdirectories()) {
            if (dir->getName() == dirName) {
                currentDirectory = dir;
                std::cout << "Changed directory to " << dirName << ".\n";
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Directory not found: " << dirName << "\n";
        }
    }
}



void FileSystem::listContents() {
    std::cout << "Contents of " << currentDirectory->getName() << ":\n";
    for (auto& file : currentDirectory->getFiles()) {
        std::cout << "File: " << file->getName() << std::endl;
    }
    for (auto& dir : currentDirectory->getSubdirectories()) {
        std::cout << "Directory: " << dir->getName() << std::endl;
    }
}


