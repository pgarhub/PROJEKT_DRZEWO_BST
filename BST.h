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
public:
    BST();
    void insert(int data);
};

#endif