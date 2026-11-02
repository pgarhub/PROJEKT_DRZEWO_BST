#include "BST.h"
#include <iostream>
using namespace std;

void printMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Dodaj element\n";
    cout << "5. Wyswietl drzewo\n";
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
        else if (choice == 5) {
            int method;
            cout << "Metoda (1-pre, 2-in, 3-post): "; cin >> method;
            tree.display(method);
        }
    } while (choice != 0);
    return 0;
}