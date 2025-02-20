#include "Table.hpp"

/**
 *  \author Marc Chaumont
 *  \date   20 mars 2006
 *
 *  La classe Table permet de gérer la table contenant les messages 
 *  (symboles) et les probabilités associées. La classe Table ne sert que de 
 *  conteneur et ne met à disposition que trois accesseurs : 
 *  - ajout d'un noeud : méthode addEntry.
 *  - suppression d'un noeud : méthode delEntry.
 *  - nombre d'entrée dans la table (nombre de noeuds): méthode nbEntry.
 *
 *  Remarque : L'algorithme d'Huffman itère sur cette table (message <-> proba) 
 *  pour construire l'arbre d'Huffman.
 */

    Table::Table() {
    }    
    
    Table::~Table() {
      cout<<"Table::~Table: Le destructeur n'est pas écrit...\n";
    }    

    /**
     * nbEntry()
     * \return Retourne le nombre d'entrée dans la table.
     */
    int Table::nbEntry() {
      return table.size();
    }    

    /**
     * getEntry()
     * \return pointeur sur ième noeud de la table.
     */
    Node* Table::getEntry(int i) {
#ifndef RELEASE
      if ( (i<0) || ( i>= nbEntry()) ) {
        cout<<"Node::getEntry: Erreur, l'entrée "<<i<<" n'existe pas\n";
        exit(-1);
      }    
#endif
      return table[i];
    }    

    /**
     * setEntry()
     * positionne le ième noeud de la table.
     */
    void Table::setEntry(int i, Node* node) {
#ifndef RELEASE
      if ( (i<0) || (i>=nbEntry()) ) {
        cout<<"Node::setEntry: Erreur, l'entrée "<<i<<" n'existe pas\n";
        exit(-1);
      }    
#endif
      table[i] = node;
    }

    /**
     * addEntry()
     * Ajoute dans la table un noeud (message et probabilité associée)
     * \attention l'ajout doit être fait de manière à conserver l'ordre 
     * décroissant des probabilités.
     */
    void Table::addEntry(Node* node) {
 
      /***************/
      /* A COMPLETER */
      /***************/
    }    

    /**
     * delEntry()
     * Supprime le dernier élément de la table.
     * \attention La suppression concerne le dernier élément de la table.
     * \attention La suppression ne désalloue pas le noeud...
     * \return pointeur sur le noeud que l'on vient d'enlever de la table.
     */
    Node* Table::delEntry() {
#ifndef RELEASE
      if (nbEntry() == 0) {
        cout<<"Node::delEntry: Erreur, la table est vide\n";
        exit(-1);
      }    
#endif
      Node* node = table[nbEntry()-1];
      table.pop_back();
      return node;
    }
