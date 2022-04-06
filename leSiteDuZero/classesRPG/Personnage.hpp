#ifndef Personnage_hpp
#define Personnage_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include "Arme.hpp"

class Personnage

{
    public:
  /*Personnage();
    Personnage(std::string nomArme, int mana);    // personnage sans ET avec defined nomArme et degatsArme
    
    Personnage(Personnage const& personnageACopier);    // constructeur de copie
    Personnage& operator=(Personnage const &personnageACopier);
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() ;
    void afficherEtat() const;
    ~Personnage();  */
    Personnage();
    void recevoirDegats(int degats);
    void coupDePoing(Personnage &cible) const;
    void afficherEtat() const;

    private:// tous les attribut (=variables de classe) en private for the user not to be able to modify them
  /*int m_vie;
    int m_mana;
    Arme *m_arme;*/
    int m_vie;
    std::string m_nom;

};

#endif


