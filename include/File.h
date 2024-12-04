#ifndef FILE_H
#define FILE_H

#include <string>

class File {
private:
    std::string name;
    std::string content;

public:
    File(const std::string& name, const std::string& content);

    std::string getName() const;
    std::string getContent() const;
    void writeContent(const std::string& newContent);
};

#endif // FILE_H
