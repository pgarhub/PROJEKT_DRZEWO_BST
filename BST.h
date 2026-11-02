#ifndef BST_H
#define BST_H

#include <iostream>

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
    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);
public:
    BST();
    void insert(int data);
    void display(int method);
};

#endif