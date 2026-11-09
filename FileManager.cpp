#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void FileManager::saveBinary(BST& tree, const string& filename) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        saveBinaryRec(tree.getRoot(), file);
        file.close();
        cout << "Zapisano binarnie.\n";
    }
    else {
        cout << "Blad zapisu pliku binarnego.\n";
    }
}

void FileManager::saveBinaryRec(Node* node, ofstream& file) {
    int marker = -1;
    if (node == nullptr) {
        file.write(reinterpret_cast<char*>(&marker), sizeof(int));
        return;
    }
    file.write(reinterpret_cast<char*>(&node->data), sizeof(int));
    saveBinaryRec(node->left, file);
    saveBinaryRec(node->right, file);
}

void FileManager::loadBinary(BST& tree, const string& filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        tree.clear();
        tree.setRoot(loadBinaryRec(file));
        file.close();
        cout << "Wczytano binarnie.\n";
    }
    else {
        cout << "Blad odczytu pliku binarnego.\n";
    }
}

Node* FileManager::loadBinaryRec(ifstream& file) {
    int data;
    if (!file.read(reinterpret_cast<char*>(&data), sizeof(int)) || data == -1) {
        return nullptr;
    }
    Node* node = new Node(data);
    node->left = loadBinaryRec(file);
    node->right = loadBinaryRec(file);
    return node;
}

void FileManager::loadFromText(BST& tree, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int val;
        while (file >> val) {
            tree.insert(val);
        }
        file.close();
        cout << "Wczytano liczby z pliku tekstowego.\n";
    }
    else {
        cout << "Nie mozna otworzyc pliku tekstowego.\n";
    }
}