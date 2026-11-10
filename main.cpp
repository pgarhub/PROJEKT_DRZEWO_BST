/**
 * @file main.cpp
 * @brief Główny plik programu realizujący pętlę menu oraz interakcję z użytkownikiem.
 * @author Damian Kiełbasa, Patryk Gargula
 */

#include "BST.h"
#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Wypisuje dostępne opcje menu na standardowe wyjście (konsolę).
 */
void printMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Dodaj element\n";
    cout << "2. Usun element z drzewa\n";
    cout << "3. Usun cale drzewo\n";
    cout << "4. Szukaj drogi do elementu\n";
    cout << "5. Wyswietl drzewo\n";
    cout << "6. Zapisz drzewo do pliku TXT\n";
    cout << "7. Zapisz drzewo binarnie\n";
    cout << "8. Wczytaj drzewo binarnie\n";
    cout << "9. Wczytaj liczby z pliku TXT\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

/**
 * @brief Główna funkcja programu, uruchamia pętlę obsługującą wybory użytkownika.
 * @return 0 w przypadku pomyślnego zakończenia.
 */
int main() {
    BST tree;
    FileManager fileManager;
    int choice, val;
    string filename;

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
        case 6:
            cout << "Podaj nazwe pliku TXT do zapisu (np. drzewo.txt): "; cin >> filename;
            tree.saveToTextFile(filename);
            break;
        case 7:
            cout << "Podaj nazwe pliku binarnego do zapisu (np. drzewo.bin): "; cin >> filename;
            fileManager.saveBinary(tree, filename);
            break;
        case 8:
            cout << "Podaj nazwe pliku binarnego do odczytu: "; cin >> filename;
            fileManager.loadBinary(tree, filename);
            break;
        case 9:
            cout << "Podaj nazwe pliku TXT z liczbami: "; cin >> filename;
            fileManager.loadFromText(tree, filename);
            break;
        }
    } while (choice != 0);

    return 0;
}