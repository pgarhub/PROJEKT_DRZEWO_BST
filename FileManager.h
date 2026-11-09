#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "BST.h"
#include <string>

class FileManager {
private:
    void saveBinaryRec(Node* node, std::ofstream& file);
    Node* loadBinaryRec(std::ifstream& file);

public:
    void saveBinary(BST& tree, const std::string& filename);
    void loadBinary(BST& tree, const std::string& filename);
    void loadFromText(BST& tree, const std::string& filename);
};

#endif