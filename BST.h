#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* node, int data);
    Node* deleteRec(Node* node, int data);
    Node* minValueNode(Node* node);
    void destroyTree(Node* node);
    bool searchPathRec(Node* node, int data, std::vector<int>& path);
    void saveToTextFileRec(Node* node, std::ofstream& file);

    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);

public:
    BST();
    ~BST();
    void insert(int data);
    void remove(int data);
    void clear();
    void searchPath(int data);
    void display(int method);
    void saveToTextFile(const std::string& filename);

    Node* getRoot() const { return root; }
    void setRoot(Node* newRoot) { root = newRoot; }
};

#endif