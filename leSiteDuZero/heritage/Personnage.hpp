//
//  Personnage.hpp
//  heritage
//
//  Created by Louis-Victor MICHELOT on 16/03/2022.
//

#ifndef Personnage_hpp
#define Personnage_hpp

#include <stdio.h>

#endif /* Personnage_hpp */

#include <iostream>
#include <string>




class Personnage
{
    public:
        Personnage();
        void recevoirDegats(int degats);
        void coupDePoing(Personnage &cible) const;
        void sePresenter() const;
    
 // private:
    protected: //Privé, mais accessible aux éléments enfants (Guerrier, Magicien)
        int m_vie;
        std::string m_nom;
};





class Guerrier : public Personnage  // la classe guerrier hérite de la classe Personnage, et don c dde ses attributs et méthodes
{
    public:
        void frapperAvecUnMarteau() const;
        void sePresenter() const;
};


class Magicien : public Personnage  // la classe guerrier hérite de la classe Personnage, et don c dde ses attributs et méthodes
{
    public:
        Magicien();
    
    private :
    int m_mana;
};
