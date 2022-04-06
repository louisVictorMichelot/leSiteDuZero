/*
#include "Personnage.hpp"
#include <string>

using namespace std;

Personnage::Personnage() : m_arme(0), m_vie(100), m_mana(100)
 {
     m_arme = new Arme();
 }

Personnage::Personnage(string nomArme, int degatsArme) : m_arme(0), m_vie(100), m_mana(100)
{
     m_arme = new Arme(nomArme, degatsArme);
 }


void Personnage::recevoirDegats(int degatsArme)
{
    m_vie -= degatsArme;
    if (m_vie <= 0) //Pour éviter d'avoir une vie négative
        {
            m_vie = 0;
            cout<<"mort"<<endl;//On met la vie à 0 (cela veut dire mort)
        }
}

void Personnage::attaquer(Personnage &cible)
 {
     cible.recevoirDegats(m_arme->getDegats());
 }



void Personnage::boirePotionDeVie(int quantitePotion)
 {
     m_vie += quantitePotion;
     if (m_vie > 100) //Interdiction de dépasser 100 de vie
     {
m_vie = 100; }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
 {
     m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
 }

bool Personnage::estVivant()
 {
     if (m_vie > 0) //Plus de 0 de vie ?
     {
         return true; //VRAI, il est vivant !
     }
else {
         return false; //FAUX, il n'est plus vivant !
     }
}

void Personnage::afficherEtat() const
 {
     cout << "Vie : " << m_vie << endl;
     cout << "Mana : " << m_mana << endl;
     m_arme->afficher();
}



Personnage::~Personnage()
 {
     delete m_arme;
 }

// constructeur de copie

Personnage::Personnage(Personnage const& personnageACopier) : m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_arme(0)
{
    
    m_arme =  new Arme(*(personnageACopier.m_arme));
    // les deux personnages ont la même arme mais dupliquée
};

Personnage& Personnage::operator=( Personnage const& personnageACopier)
{
   
    if( this != &personnageACopier) // vérifier qu'on a bien deux objets distincts, on vérifier que leurs adresses mémoire sont différentes.
    {
    m_mana = personnageACopier.m_mana;
    m_vie = personnageACopier.m_vie;
    delete m_arme;
    m_arme = new Arme(*(personnageACopier.m_arme));
    }
    
    return *this;
    
    
}
*/

#include "Personnage.hpp"
#include <string>

using namespace std;

Personnage::Personnage() : m_vie(100), m_nom("Jack")
{
}

void Personnage::recevoirDegats(int degats)
{
    m_vie -= degats;
}

void Personnage::coupDePoing(Personnage &cible) const
{
    cible.recevoirDegats(10);
}

void Personnage::afficherEtat() const
 {
     cout << "Vie : " << m_vie << endl;
}
