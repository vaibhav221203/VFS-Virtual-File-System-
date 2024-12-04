#include <iostream>
#include <memory>
#include "./include/FileSystem.h"
#include "./include/File.h"
#include "./include/Directory.h"

using namespace std;

int main() {
    FileSystem fs;

    std::string command;
    while (true) {
        std::cout << "\nVirtual File System Menu\n";
        std::cout << "1. Create File\n";
        std::cout << "2. Create Directory\n";
        std::cout << "3. List Contents\n";
        std::cout << "4. Change Directory\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter command number: ";
        std::getline(std::cin, command);

        if (command == "1") {
            std::string fileName, content;
            std::cout << "Enter file name: ";
            std::getline(std::cin, fileName);
            std::cout << "Enter file content: ";
            std::getline(std::cin, content);
            fs.createFile(fileName, content);
        } 
        else if (command == "2") {
            std::string dirName;
            std::cout << "Enter directory name: ";
            std::getline(std::cin, dirName);
            fs.createDirectory(dirName);
        }
        else if (command == "3") {
            fs.listContents();  // Shows contents of current directory
        }
        else if (command == "4") {
            std::string dirName;
            std::cout << "Enter directory name to navigate to: ";
            std::getline(std::cin, dirName);
            fs.changeDirectory(dirName);
        } 
        else if (command == "5") {
            break; // Exit the loop and program
        } 
        else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}

