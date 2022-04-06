#ifndef ZFraction_hpp
#define ZFraction_hpp
#include <stdio.h>
#include <iostream>

class ZFraction

{
    public :
  //  ZFraction();
  //  ZFraction(int numerateur);
    ZFraction(int numerateur = 0, int denominateur = 1 );
    void afficher(std::ostream &flux) const;
    void afficher();
    void simplifier();
    ZFraction& operator+=( const ZFraction &zfraction);
    ZFraction& operator*=( const ZFraction &zfraction);
    ZFraction& operator-=( const ZFraction &zfraction);
    ZFraction& operator/=( const ZFraction &zfraction);
    bool estEgal(ZFraction const& b) const;
    bool estPlusPetitQue(ZFraction const& b) const;
    int numerateur();
    int denominateur();
    double getReal();

    private :
    int m_numerateur;
    int m_denominateur;
    
};

std::ostream& operator<<( std::ostream &flux, ZFraction const& zfraction );
int pgcd(int a, int b);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);

#endif


