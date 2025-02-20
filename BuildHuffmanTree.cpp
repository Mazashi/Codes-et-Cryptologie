#include "BuildHuffmanTree.hpp"

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

    /**
     * BuildHuffmanTree()
     * Constructeur par défaut (rien à faire).
     */
    BuildHuffmanTree::BuildHuffmanTree() {
    }    

    /**
     * initTable()
     * Inititialise la table contenant les messages et les probabilité ceci 
     * à partir de l'histogramme préalablement construit.
     * \param histogram : ensemble des association message <-> probabilité. 
     */
    void BuildHuffmanTree::initTable(const vector<CoupleMessageProba>& histogram) {

      /***************/
      /* A COMPLETER */
      /***************/
    }    

    /**
     * ~BuildHuffmanTree
     * La destruction du contenu de la table est effectuée par le destructeur 
     * de la classe Table.
     */
    BuildHuffmanTree::~BuildHuffmanTree() { 
    }
          
    /**
     * buildTree()
     * Algorithme de Huffman :
     * Méthode permettant de construire l'arbre de d'association message <-> code.
     */
    void BuildHuffmanTree::buildTree() {

      /***************/
      /* A COMPLETER */
      /***************/
    } 
                   
    /**
     * getTree()
     * Méthode permettant de récupérer l'arbre de Huffman.
     */
    Node* BuildHuffmanTree::getTree() {
        return table.getEntry(0);
    }    

    /**
     * printTree()
     * Affiche l'arbre (appel récursif).
     */
    static int cmpt;
    void BuildHuffmanTree::printTree() {
       Node* node = getTree();
       cmpt = 0;
       cout<<"Affichage pour Dotty\n";
       cout<<"digraph g {\n";
       printTree(cmpt, node, 0);
       cout<<"}\n";       
    }    
    /**
     * printTree()
     * Affiche l'arbre.
     */
    void BuildHuffmanTree::printTree(int numPere, Node* node, int bit) {

      int numNoeud = ++cmpt; //Numero attribué au noeud
      
      if (numNoeud > 1) {
        cout<<"  node_"<<numPere<<" -> node_"<<cmpt<<" [label ="<<bit<<"];\n";
      }    
      if (node->isFeuille()) {
        cout<<"  node_"<<cmpt<<" [label ="<<'"'<<"message : "<<node->getMessage()
                                <<"\\"<<"nproba : "<<node->getProba()<<'"'<<"];\n";
      }
      else {
        printTree(numNoeud, node->getFils0(), 0);    
        printTree(numNoeud, node->getFils1(), 1);
      }
    }
