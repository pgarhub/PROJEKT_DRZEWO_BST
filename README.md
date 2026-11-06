# Drzewo BST w C++

## O projekcie
Projekt przedstawia implementację Drzewa Poszukiwań Binarnych (BST - Binary Search Tree) w języku C++. Program działa w oparciu o interaktywne menu konsolowe i został zaprojektowany z wykorzystaniem programowania obiektowego. Ponadto, do obsługi wyszukiwania ścieżki w drzewie wykorzystano kontener z biblioteki STL (`std::vector`).

Projekt został zrealizowany jako zadanie grupowe, którego głównym celem było praktyczne zapoznanie się z możliwościami platformy GitHub podczas pracy zespołowej (tworzenie gałęzi, praca równoległa, scalanie, celowe generowanie i rozwiązywanie konfliktów).

## Funkcjonalności
* **Zarządzanie elementami:**
  * Dodawanie nowego elementu do drzewa.
  * Usuwanie pojedynczego, wybranego węzła.
  * Usuwanie (czyszczenie) całego drzewa.
* **Przeszukiwanie i wyświetlanie:**
  * Wyszukiwanie ścieżki od korzenia do zadanego elementu.
  * Wyświetlanie drzewa graficznie na ekranie trzema metodami: `Preorder`, `Inorder`, `Postorder`.
* **Obsługa plików (klasa FileManager):**
  * Zapis wygenerowanego drzewa do pliku tekstowego.
  * Zapis utworzonego drzewa do pliku w formacie binarnym.
  * Odczyt drzewa z pliku binarnego.
  * Wczytywanie liczb z pliku tekstowego, umożliwiające budowę drzewa od zera lub dodawanie do istniejącego.

## Struktura plików
Projekt został podzielony na osobne pliki zgodnie z dobrymi praktykami C++:
* `main.cpp` – plik główny zawierający logikę menu i sterowanie programem.
* `BST.h` / `BST.cpp` – deklaracja i implementacja struktury węzła (`Node`) oraz samej klasy drzewa.
* `FileManager.h` / `FileManager.cpp` – deklaracja i implementacja klasy dedykowanej do operacji wejścia/wyjścia na plikach txt i binarnych.

## Kompilacja i uruchomienie

### W środowisku Visual Studio
1. Utwórz **Pusty projekt** (C++).
2. Dodaj pliki źródłowe (`main.cpp`, `BST.cpp`, `FileManager.cpp`) i nagłówkowe (`BST.h`, `FileManager.h`) do projektu (Opcja: *Dodaj -> Istniejący element*).
3. Skompiluj i uruchom za pomocą skrótu `Ctrl + F5`.

### Z użyciem kompilatora g++ (w konsoli)
Będąc w folderze z plikami projektu, wpisz polecenie:
```bash
g++ main.cpp BST.cpp FileManager.cpp -o drzewo_bst
