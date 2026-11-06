#include "BST.h"
#include <iostream>

using namespace std;

void printMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Dodaj element\n";
    cout << "2. Usun element z drzewa\n";
    cout << "3. Usun cale drzewo\n";
    cout << "4. Szukaj drogi do elementu\n";
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

        switch (choice) {
        case 1:
            cout << "Podaj wartosc: "; cin >> val;
            tree.insert(val);
            break;
        case 2:
            cout << "Podaj wartosc do usuniecia: "; cin >> val;
            tree.remove(val);
            break;
        case 3:
            tree.clear();
            cout << "Drzewo usuniete.\n";
            break;
        case 4:
            cout << "Podaj wartosc do znalezienia: "; cin >> val;
            tree.searchPath(val);
            break;
        case 5:
            int method;
            cout << "Metoda (1-pre, 2-in, 3-post): "; cin >> method;
            tree.display(method);
            break;
        }
    } while (choice != 0);

    return 0;
}