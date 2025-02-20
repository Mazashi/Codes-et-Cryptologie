#ifndef BUILDHUFFMANTREE_HPP
#define BUILDHUFFMANTREE_HPP

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Table.hpp"
#include "CoupleMessageProba.hpp"

/**
 *  \author Marc Chaumont
 *  \date   20 mars 2006
 *
 *  La classe BuildHuffmanTree permet comme son nom l'indique de construire 
 *  l'arbre d'Huffman et ainsi attribuer à chaque message (symbole) un code 
 *  préfixé.
 *  Remarque : L'algorithme d'Huffman itère sur la table (classe Table) pour 
 *  construire l'arbre d'Huffman.
 */
class BuildHuffmanTree {

private :
    
    Table table; /**< Table contenant les associations message <-> proba.*/
    
    /**
     * printTree()
     * Permet un parcours de l'arbre en profondeur (de manière récursive) avec 
     * construction du texte permettant la visualisation du graphe sous dotty.
     * \param numPere : le numéro du noeud père.
     * \param node : le noeud courant.
     * \param bit : indique si le noeud est un fils gauche (0) ou un fils droit (1).
     */
    void printTree(int numPere, Node* node, int bit);

public :    

    /**
     * BuildArbreHuffman()
     * Constructeur par défaut (rien à faire).
     */
    BuildHuffmanTree();  

    /**
     * initTable()
     * Initialise la table contenant les messages et les probabilités ceci 
     * à partir de l'histogramme préalablement construit.
     * \param histogram : ensemble des associations message <-> probabilité. 
     */
    void initTable(const vector<CoupleMessageProba>& histogram); 

    /**
     * ~BuildArbreHuffman()
     * La destruction du contenu de la table est effectuée par le destructeur 
     * de la classe Table.
     */
    ~BuildHuffmanTree();

    /**
     * buildTree()
     * Algorithme de Huffman :
     * Méthode permettant de construire l'arbre de d'association message <-> code.
     */
    void buildTree();

    /**
     * getTree()
     * Méthode permettant de récupérer l'arbre de Huffman.
     */
    Node* getTree();
        
    /**
     * printTree()
     * Permet un parcours de l'arbre en profondeur (de manière récursive) avec 
     * construction du texte permettant la visualisation du graphe sous dotty.
     */
    void printTree();
    
};    
#endif //BUILDHUFFMANTREE_HPP
