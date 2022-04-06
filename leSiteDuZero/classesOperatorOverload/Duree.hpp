#ifndef Duree_hpp
#define Duree_hpp
#include <stdio.h>
#include <iostream>
#include <string>

class Duree

{
    public :
   
    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    Duree& operator+=(const Duree &duree);          // operator
    Duree& operator+=(int secondes);
    Duree& operator-=(const Duree &duree);
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    void afficher(std::ostream &flux) const;
    void afficher();
    bool estPlusPetitQueOuEgal(Duree const& b) const;

   
    private :
    
    int m_heures;
    int m_minutes;
    int m_secondes;

};

Duree operator+(Duree const& a, Duree const& b); // pas une méthode, est une fonction, ne peur pas acceder aux attributs de "Duree duree1" car en private. donc appelle une méthode(operator+=) de Duree qui elle additionne les durees car étant une méthode de la classe, elle a accès aux attributs.

// reference pour éviter copie de l'objet, dans cette application, le gain est minime, mais pour un long texte/string, cela devient plus important
// aussi on veut éviter que la fonction/ la méthode ne modifie les attrivuts de nos objest, on utilise alors des constantes "const"

/*
 
 operator+ est appellé dans Duree.hdd mais en dehors de la classe
 
 operator+ est défini dans Duree.cpp        cette définition appelle une methode (operator+=)
 
 operator+= est appellé dans Duree.hdd à l'intérieur de la classe (pour accès aux attributs)
 
 operator+= est défini dans Duree.cpp
 // la méthode operator+= n'appelle qu'un seul objet en argument, celui qui sera additioner au premier appellé
 
 ...
 
 */

Duree operator+(Duree const& duree, int secondes);

Duree operator-(Duree const& a, Duree const& b);

std::ostream& operator<<( std::ostream &flux, Duree const& duree );

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
bool operator>(Duree const& a, Duree const& b);
bool operator<=(Duree const& a, Duree const& b);

#endif
