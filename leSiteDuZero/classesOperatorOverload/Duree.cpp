#include "Duree.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
    if(m_secondes >= 60)
    {
        m_minutes += m_secondes/60;
        m_secondes = m_secondes%60;
    }
    if(m_minutes >= 60)
    {
        m_heures += m_minutes/60;
        m_minutes = m_minutes%60;
    }
}

void Duree::afficher()
{
    cout<<m_heures<<" heures, "<<m_minutes<<" minutes, "<<m_secondes<<" secondes."<<endl;
}

Duree& Duree::operator+=(const Duree &duree2)
{
    m_secondes += duree2.m_secondes;
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    m_minutes += duree2.m_minutes;
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    m_heures += duree2.m_heures;

    return *this;
}

Duree& Duree::operator-=(const Duree &duree2)
{
    m_secondes -= duree2.m_secondes;
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    m_minutes -= duree2.m_minutes;
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    m_heures -= duree2.m_heures;

    return *this;
}

Duree& Duree::operator+=(int secondes)
{
    m_secondes += secondes;
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    m_heures += m_minutes / 60;
    m_minutes %= 60;

    return *this;
}


Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a); // copie de a pour ne pas modifier a
    copie += b; // appel methode operator+= pour accès aux attributs
    return copie; // renvoie du resultat
}


Duree operator+(Duree const& duree, int secondes)
{
    Duree copie(duree);
    copie += secondes;
    return copie;
}

Duree operator-(Duree const& a, Duree const& b)
{
    Duree copie(a); // copie de a pour ne pas modifier a
    copie -= b; // appel methode operator+= pour accès aux attributs
    return copie; // renvoie du resultat
}

ostream& operator<<( ostream &flux, Duree const& duree )
{
    duree.afficher(flux) ;
    return flux;
}

void Duree::afficher(ostream &flux) const
 {
     flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
 }



bool Duree::estEgal(Duree const& b) const
{
    if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
        return true;
    else
        return false;
}


bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    if(a==b)
        return false;
    else
        return true;
}



bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures<b.m_heures)
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes)
        return true;
    else if(m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
        return true;
    else
        return false;
}

bool operator<(Duree const& a, Duree const& b)
{
    if(a.estPlusPetitQue(b))
        return true;
    else
        return false;
}

bool operator>(Duree const& a, Duree const& b)
{
    if(a.estPlusPetitQue(b))
        return false;
    else
        return true;
}

bool Duree::estPlusPetitQueOuEgal(Duree const& b) const
{
    if (m_heures<b.m_heures)
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes)
        return true;
    else if(m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
        return true;
    else if(m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
        return true;
    else
        return false;
}

bool operator<=(Duree const& a, Duree const& b)
{
    if(a.estPlusPetitQueOuEgal(b))
        return true;
    else
        return false;
}
