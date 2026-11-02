#include "bst.h"
#include <iostream>
using namespace std;

void printMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Dodaj element\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

int main() {
    BST tree;
    int choice, val;
    do {
        printMenu();
        cin >> choice;
        if (choice == 1) {
            cout << "Podaj wartosc: "; cin >> val;
            tree.insert(val);
        }
    } while (choice != 0);
    return 0;
}