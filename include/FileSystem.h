#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <memory>
#include <string>
#include "Directory.h"

class FileSystem {
private:
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;

public:
    FileSystem();

    void createFile(const std::string& name, const std::string& content);
    void createDirectory(const std::string& name);
    void listContents();
    void changeDirectory(const std::string& name);
};

#endif // FILESYSTEM_H
