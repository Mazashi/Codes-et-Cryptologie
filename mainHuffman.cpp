#include <iostream>
#include <stdlib.h>
using namespace std;

#include <vector>
#include <fstream>
#include <string.h>

#include "CoupleMessageProba.hpp"
#include "BuildHuffmanTree.hpp"

char fileName [200]; //Le nom du fichier à traiter

/**
 * printHistogram()
 * Affiche l'histogramme
 * \param histogram : histogramme stockant les couples message - probabilité.
 */
void printHistogram(const vector<CoupleMessageProba>& histogram) {
  int i;                          //Indice de boucle
  int taille = histogram.size();  //Taille de l'histogramme

  for (i=0;  i<taille; i++) {
    cout<<"p( "<<histogram[i].getMessage()<<" ) = "<<histogram[i].getProba()<<endl;
  } //Fin du for
}


/**
 * readFileAndBuildHistogram.
 * Lit un fichier et calcul les probabilités associées à chaque message.
 * \param inFileName : nom du fichier à lire.
 * \param histogram : histogramme stockant les couples message - probabilité. C'est un paramètre d'entrée sortie
 */
void readFileAndBuildHistogram(char* inFileName, vector<CoupleMessageProba>& histogram) {

  char car;                      //Caractère lu
  int indice;                    //Indice du caractère dans l'histogramme
  double proba;                  //Proba du caractère lu
  int tailleSource;              //Taille de la source (nombre de caractère)
  CoupleMessageProba messproba;  //Un couple message <-> proba

  //EFFACAGE DU VECTEUR HISTOGRAMME
  histogram.resize(0);

  /*FLUX D'ENTREE POUR LE FICHIER*/
  ifstream ifs(inFileName,ios::in);

  /*TEST D'OUVERTURE*/
  if (!ifs.is_open()) {
    cout<<"main::readFileAndBuildHistogram(...): Erreur, le fichier "<<inFileName<<" n'est pas ouvrable\n";
    exit(-1);
  }

  /*LECTURE DU FICHIER ET CONSTRUCTION DE L'HISTOGRAMME*/
//  while (!ifs.eof()) {
  while (ifs>>car) {

//    ifs>>car; //Lecture du caractère courant (sous la tête de lecture)
    cout<<car<<endl;

    /***************/
    /* A COMPLETER */
    /***************/

  }

  /***************/
  /* A COMPLETER */
  /***************/


  //POST-CONDITION
#ifndef RELEASE
  if (histogram.size() == 0) {
    cout<<"main::readFileAndBuildHistogram(...): Erreur, l'histogramme n'est pas construit (taille = 0)";
    exit(-1);
  }
#endif //RELEASE

  ifs.close();
}

//==============================================================================
void printUsage(char* name) {
  cout << "\nUsage : "
       <<name
       <<" filename\n";
  exit(-1);
}

//==============================================================================
void processOptionsInLine(int argc, char** argv){
  if (argc != 2) {
    printUsage(argv[0]);
  }
  //RECOPIE DU NOM DU FICHIER DANS LA VARIABLE fileName
  strcpy(fileName, argv[1]);
}


/**
 * main.
 * Programme principal ...
 */
int main(int argc, char *argv[]) {

  vector<CoupleMessageProba> histogram; //Histogramme stockant les messages et les proba associées

  /*TRAITE LES OPTIONS*/
  processOptionsInLine(argc, argv);

  /*CONSTRUCTION DE L'HISTOGRAMME*/
  //strcpy(fileName, "test.txt");
  readFileAndBuildHistogram(fileName, histogram);
  /*DEBUG*/printHistogram(histogram);

  /*CONSTRUCTION DE L'ARBRE D'HUFFMAN*/
  BuildHuffmanTree huffmanContructeur;
  huffmanContructeur.initTable(histogram); //Initialisation de la table message <-> symbole
  huffmanContructeur.buildTree();          //Construction à proprement parler
  huffmanContructeur.printTree();
}


