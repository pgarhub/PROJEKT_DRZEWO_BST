/**
 * @file FileManager.h
 * @brief Definicja klasy FileManager do zarz¹dzania operacjami wejœcia/wyjœcia.
 * @author Patryk Gargula
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "BST.h"
#include <string>

 /**
  * @class FileManager
  * @brief Klasa zajmuj¹ca siê zapisem i odczytem struktury drzewa do/z plików binarnych i tekstowych.
  */
class FileManager {
private:
    void saveBinaryRec(Node* node, std::ofstream& file);
    Node* loadBinaryRec(std::ifstream& file);

public:
    /**
     * @brief Zapisuje strukturê drzewa do pliku binarnego.
     * @param tree Referencja do obiektu drzewa, które chcemy zapisaæ.
     * @param filename Nazwa pliku binarnego.
     */
    void saveBinary(BST& tree, const std::string& filename);

    /**
     * @brief Wczytuje strukturê drzewa z pliku binarnego, zastêpuj¹c aktualne drzewo.
     * @param tree Referencja do drzewa, do którego wczytamy dane.
     * @param filename Nazwa pliku binarnego.
     */
    void loadBinary(BST& tree, const std::string& filename);

    /**
     * @brief Wczytuje ci¹g liczb z pliku tekstowego, wstawiaj¹c je po kolei do drzewa.
     * @param tree Referencja do drzewa.
     * @param filename Nazwa pliku tekstowego.
     */
    void loadFromText(BST& tree, const std::string& filename);
};

#endif