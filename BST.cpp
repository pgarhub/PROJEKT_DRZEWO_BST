#include "bst.h"
using namespace std;

BST::BST() : root(nullptr) {}

void BST::insert(int data) {
    root = insertRec(root, data);
}

Node* BST::insertRec(Node* node, int data) {
    if (node == nullptr) return new Node(data);
    if (data < node->data) node->left = insertRec(node->left, data);
    else if (data > node->data) node->right = insertRec(node->right, data);
    return node;
}