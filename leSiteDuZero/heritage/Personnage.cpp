//
//  Personnage.cpp
//  heritage
//
//  Created by Louis-Victor MICHELOT on 16/03/2022.
//

#include "Personnage.hpp"
 
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


void Guerrier::frapperAvecUnMarteau() const
{
    
    
}
Magicien::Magicien() : Personnage(), m_mana(100)
{
 
}
void Personnage::sePresenter() const
{
    cout << "Bonjour, je m'appelle " << m_nom << "." << endl;
    cout << "J'ai encore " << m_vie << " points de vie." << endl;
}
void Guerrier::sePresenter() const  // redifinition de la fonction sePresenter spécifiquement pour la classe Guerrier
{
    Personnage::sePresenter(); // demasquage,, on économise du code
    cout << "Je suis un Guerrier redoutable." << endl;
}
