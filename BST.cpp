#include "BST.h"
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

void BST::display(int method) {
    if (root == nullptr) {
        cout << "Drzewo jest puste.\n"; return;
    }
    switch (method) {
    case 1: printPreorder(root); break;
    case 2: printInorder(root); break;
    case 3: printPostorder(root); break;
    }
    cout << endl;
}

void BST::printPreorder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    printPreorder(node->left); printPreorder(node->right);
}

void BST::printInorder(Node* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void BST::printPostorder(Node* node) {
    if (node == nullptr) return;
    printPostorder(node->left); printPostorder(node->right);
    cout << node->data << " ";
}