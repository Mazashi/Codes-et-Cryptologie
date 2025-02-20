#include "CoupleMessageProba.hpp"

/**
 *  \author Marc Chaumont
 *  \date   21 mars 2006
 *
 *  La classe CoupleMessageProba permet de g�rer des paires (message, proba). 
 *
 *  Remarque : Cette classe va �tre utilis�e lors de la construction de l'histogramme 
 *  (message <-> proba) ainsi que lors de l'initialisation de la table contenant
 *  des noeuds.
 */

    /**
     * CoupleMessageProba
     * Constructeur par d�faut.
     */    
    CoupleMessageProba::CoupleMessageProba() {
    }     
    
    /**
     * CoupleMessageProba
     * Constructeur par valeur.
     * \param message : le symbole (caract�re). 
     * \param proba   : la probabilit� du message.
     */    
    CoupleMessageProba::CoupleMessageProba(char message, double proba) {
      (*this).message = message;
      (*this).proba   = proba;
    }     

    /**
     * ~CoupleMessageProba
     * Destructeur.
     */    
    CoupleMessageProba::~CoupleMessageProba() {
    }    
    
    /**
     * Acces au message.
     * \return le message (un caract�re).
     */    
     char CoupleMessageProba::getMessage() const {
         return message;
     }    

    /**
     * Acces � la proba.
     * \return la probabilit� associ�e au message.
     */    
     double CoupleMessageProba::getProba() const {
         return proba;
     }    
    
    /**
     * Positionne le message.
     */    
     void CoupleMessageProba::setMessage(char message) {
         (*this).message = message;
     }    

    /**
     * Positionne la proba.
     */    
     void CoupleMessageProba::setProba(double proba) {
         (*this).proba = proba;
     }    

