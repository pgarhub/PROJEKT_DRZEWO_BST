/**
 * @file BST.h
 * @brief Definicja struktury wêz³a oraz klasy binarnego drzewa poszukiwañ (BST).
 * @author Damian Kie³basa, Patryk Gargula
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

 /**
  * @struct Node
  * @brief Struktura reprezentuj¹ca pojedynczy wêze³ w drzewie BST.
  */
struct Node {
    int data;       /**< Wartoœæ przechowywana w wêŸle */
    Node* left;     /**< WskaŸnik na lewe poddrzewo (wartoœci mniejsze) */
    Node* right;    /**< WskaŸnik na prawe poddrzewo (wartoœci wiêksze) */

    /**
     * @brief Konstruktor tworz¹cy nowy wêze³.
     * @param val Wartoœæ do przypisania nowemu wêz³owi.
     */
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/**
 * @class BST
 * @brief Klasa implementuj¹ca binarne drzewo poszukiwañ (Binary Search Tree).
 */
class BST {
private:
    Node* root; /**< WskaŸnik na korzeñ drzewa */

    Node* insertRec(Node* node, int data);
    Node* deleteRec(Node* node, int data);
    Node* minValueNode(Node* node);
    void destroyTree(Node* node);
    bool searchPathRec(Node* node, int data, std::vector<int>& path);
    void saveToTextFileRec(Node* node, std::ofstream& file);

    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);

public:
    /**
     * @brief Konstruktor domyœlny, inicjalizuje puste drzewo.
     */
    BST();

    /**
     * @brief Destruktor, czyœci pamiêæ zajmowan¹ przez drzewo.
     */
    ~BST();

    /**
     * @brief Dodaje now¹ wartoœæ do drzewa.
     * @param data Wartoœæ ca³kowita do dodania.
     */
    void insert(int data);

    /**
     * @brief Usuwa podan¹ wartoœæ z drzewa, jeœli istnieje.
     * @param data Wartoœæ do usuniêcia.
     */
    void remove(int data);

    /**
     * @brief Usuwa wszystkie wêz³y i zwalnia pamiêæ (czyszczenie drzewa).
     */
    void clear();

    /**
     * @brief Szuka i wyœwietla œcie¿kê do podanego elementu.
     * @param data Wartoœæ docelowa do znalezienia.
     */
    void searchPath(int data);

    /**
     * @brief Wyœwietla wartoœci drzewa na ekranie wybran¹ metod¹.
     * @param method 1 - Preorder, 2 - Inorder, 3 - Postorder.
     */
    void display(int method);

    /**
     * @brief Zapisuje uk³ad drzewa (preorder) do pliku tekstowego.
     * @param filename Nazwa pliku wyjœciowego.
     */
    void saveToTextFile(const std::string& filename);

    /**
     * @brief Zwraca wskaŸnik na korzeñ (u¿ywane przez FileManager).
     * @return WskaŸnik na obiekt root.
     */
    Node* getRoot() const { return root; }

    /**
     * @brief Ustawia nowy korzeñ drzewa (u¿ywane przy wczytywaniu z pliku bin).
     * @param newRoot WskaŸnik na nowy korzeñ.
     */
    void setRoot(Node* newRoot) { root = newRoot; }
};

#endif