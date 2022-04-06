#include "ZFraction.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;

/*
 ZFraction::ZFraction() : m_numerateur(0), m_denominateur(1)
{}
ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1)
{}
*/
ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
    
    if ( m_denominateur == 0)
    {
        cout << "you dumb fucking cunt" << endl;
        throw exception();
    }
    
    ZFraction::simplifier();
    
}

void ZFraction::afficher()
{
    cout<<m_numerateur<<"/"<<m_denominateur;
}
int ZFraction::numerateur()
{
    return m_numerateur;
}
int ZFraction::denominateur()
{
    return m_denominateur;
}

ostream& operator<<( ostream &flux, ZFraction const& zfraction )
{
    zfraction.afficher(flux) ;
    return flux;
}

void ZFraction::afficher(ostream &flux) const
 {
     flux << m_numerateur<<"/"<<m_denominateur;
 }

void ZFraction::simplifier()
{
    int pgcd1 = pgcd(m_numerateur, m_denominateur);
    m_numerateur=m_numerateur/pgcd1;
    m_denominateur=m_denominateur/pgcd1;
    
    if(m_denominateur<0)
    {   m_denominateur = m_denominateur * -1;
        m_numerateur = m_numerateur * -1;       }
}

int pgcd(int a, int b)
{
     while (b != 0)
     {
         const int t = b;
         b = a%b;
         a=t;
     }
return a;
}


ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a); // copie de a pour ne pas modifier a
    copie += b; // appel methode operator+= pour accès aux attributs
    return copie; // renvoie du resultat
}
ZFraction& ZFraction::operator+=( const ZFraction &zfraction2)
{
    m_numerateur = m_numerateur*zfraction2.m_denominateur + zfraction2.m_numerateur * m_denominateur;
    m_denominateur = m_denominateur*zfraction2.m_denominateur;
    ZFraction::simplifier();
    return *this;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a); // copie de a pour ne pas modifier a
    copie *= b; // appel methode operator+= pour accès aux attributs
    return copie; // renvoie du resultat
}
ZFraction& ZFraction::operator*=( const ZFraction &zfraction2)
{
    m_numerateur *= zfraction2.m_numerateur;
    m_denominateur *= zfraction2.m_denominateur;
    ZFraction::simplifier();
    return *this;
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a); // copie de a pour ne pas modifier a
    copie -= b; // appel methode operator+= pour accès aux attributs
    return copie; // renvoie du resultat
}
ZFraction& ZFraction::operator-=( const ZFraction &zfraction2)
{
    m_numerateur = m_numerateur*zfraction2.m_denominateur - zfraction2.m_numerateur * m_denominateur;
    m_denominateur = m_denominateur*zfraction2.m_denominateur;
    ZFraction::simplifier();
    return *this;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a); // copie de a pour ne pas modifier a
    copie /= b; // appel methode operator+= pour accès aux attributs
    return copie; // renvoie du resultat
}
ZFraction& ZFraction::operator/=( const ZFraction &zfraction2)
{
    m_numerateur *= zfraction2.m_denominateur;
    m_denominateur *= zfraction2.m_numerateur;
    ZFraction::simplifier();
    return *this;
}

bool ZFraction::estEgal(ZFraction const& b) const
{
    if (m_numerateur==b.m_numerateur && m_denominateur==b.m_denominateur)
        return true;
    else
        return false;
}
bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.estEgal(b);
}
bool operator!=(ZFraction const& a, ZFraction const& b)
{
    if(a==b)
        return false;
    else
        return true;
}

bool ZFraction::estPlusPetitQue(ZFraction const& b) const
{
    if( m_numerateur * b.m_denominateur < b.m_numerateur * m_denominateur)
        return true;
    else
        return false;
}
bool operator<(ZFraction const& a, ZFraction const& b)
{
    return a.estPlusPetitQue(b);
}
bool operator>(ZFraction const& a, ZFraction const& b)
{
    if(a.estPlusPetitQue(b))
        return false;
    else
        return true;
}



bool operator<=(ZFraction const& a, ZFraction const& b)
{
    if( a.estPlusPetitQue(b))
        return true;
    else if (a.estEgal(b))
        return true;
    else
        return false;
}
bool operator>=(ZFraction const& a, ZFraction const& b)
{
    if( a.estPlusPetitQue(b))
        return false;
    else if (a.estEgal(b))
        return true;
    else
        return true;
}

double ZFraction::getReal()
{
    double a(m_numerateur), b(m_denominateur);
    return a/b;
}
