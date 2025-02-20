#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdlib.h>
using namespace std;

#include <vector>
#include "Node.hpp"

/**
 *  \author Marc Chaumont
 *  \date   20 mars 2006
 *
 *  La classe Table permet de gérer la table contenant les messages 
 *  (symboles) et les probabilités associées. La classe Table ne sert que de 
 *  conteneur et ne met à disposition que trois accesseurs : 
 *  - ajout d'un noeud : méthode addEntry.
 *  - suppression d'un noeud : méthode delEntry.
 *  - nombre d'entrées dans la table (nombre de noeuds): méthode nbEntry.
 *
 *  Remarque : L'algorithme d'Huffman itère sur cette table (message <-> proba) 
 *  pour construire l'arbre d'Huffman.
 */
class Table {
private :
    vector<Node*> table; /**< table contenant les associations message <-> proba 
    contenus dans un noeud.*/
    
    /**
     * setEntry()
     * positionne en ième position le noeud.
     */
    void setEntry(int i, Node* node);    
    
public:
    Table();
    ~Table();

    /**
     * nbEntry()
     * \return Retourne le nombre d'entrée dans la table.
     */
    int nbEntry();

    /**
     * addEntry()
     * Ajoute dans la table un noeud (message et probabilité associée)
     * \attention l'ajout doit être fait de manière à conserver l'ordre 
     * décroissant des probabilités.
     */
    void addEntry(Node* node);

    /**
     * delEntry()
     * Supprime le dernier élément de la table.
     * \attention La suppression concerne le dernier élément de la table.
     * \attention La suppression ne désalloue pas le noeud...
     * \return pointeur sur le noeud que l'on vient d'enlever de la table.
     */
    Node* delEntry();

    /**
     * getEntry(...)
     * \return pointeur sur ième noeud de la table.
     */
    Node* getEntry(int i);
};    
#endif //TABLE_HPP
