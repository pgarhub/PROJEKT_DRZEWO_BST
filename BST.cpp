#include "BST.h"

using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::insert(int data) {
    root = insertRec(root, data);
}

Node* BST::insertRec(Node* node, int data) {
    if (node == nullptr) return new Node(data);
    if (data < node->data) node->left = insertRec(node->left, data);
    else if (data > node->data) node->right = insertRec(node->right, data);
    return node;
}

void BST::remove(int data) {
    root = deleteRec(root, data);
}

Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* BST::deleteRec(Node* node, int data) {
    if (node == nullptr) return node;

    if (data < node->data) node->left = deleteRec(node->left, data);
    else if (data > node->data) node->right = deleteRec(node->right, data);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteRec(node->right, temp->data);
    }
    return node;
}

void BST::clear() {
    destroyTree(root);
    root = nullptr;
}

void BST::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BST::searchPath(int data) {
    vector<int> path;
    if (searchPathRec(root, data, path)) {
        cout << "Droga do " << data << ": ";
        for (int val : path) cout << val << " -> ";
        cout << "Koniec\n";
    }
    else {
        cout << "Element nie znaleziony.\n";
    }
}

bool BST::searchPathRec(Node* node, int data, vector<int>& path) {
    if (node == nullptr) return false;
    path.push_back(node->data);
    if (node->data == data) return true;
    if (searchPathRec(node->left, data, path) || searchPathRec(node->right, data, path))
        return true;
    path.pop_back();
    return false;
}

void BST::display(int method) {
    if (root == nullptr) {
        cout << "Drzewo jest puste.\n";
        return;
    }
    switch (method) {
    case 1: printPreorder(root); break;
    case 2: printInorder(root); break;
    case 3: printPostorder(root); break;
    default: cout << "Nieznana metoda.\n";
    }
    cout << endl;
}

void BST::printPreorder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void BST::printInorder(Node* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void BST::printPostorder(Node* node) {
    if (node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}