#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <memory>
#include "File.h"

class Directory  : public std::enable_shared_from_this<Directory> {
private:
    std::string name;
    std::vector<std::shared_ptr<File>> files;
    std::vector<std::shared_ptr<Directory>> subdirectories;
    std::shared_ptr<Directory> parent;

public:
    Directory(const std::string& name);

    void addFile(const std::shared_ptr<File>& file);
    void addDirectory(const std::shared_ptr<Directory>& directory);

    std::vector<std::shared_ptr<File>> getFiles() const;
    std::vector<std::shared_ptr<Directory>> getSubdirectories() const;

    std::string getName() const;
    void setParent(const std::shared_ptr<Directory>& parentDir) { parent = parentDir; }
    std::shared_ptr<Directory> getParent() const { return parent; }
};

#endif // DIRECTORY_H
