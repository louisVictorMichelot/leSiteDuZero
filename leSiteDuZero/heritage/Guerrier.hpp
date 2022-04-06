//
//  Guerrier.hpp
//  heritage
//
//  Created by Louis-Victor MICHELOT on 16/03/2022.
//

#ifndef Guerrier_hpp
#define Guerrier_hpp

#include <stdio.h>

#endif /* Guerrier_hpp */

#include <iostream>
#include <string>
#include "Personnage.hpp"
 
class Guerrier : public Personnage  // la classe guerrier hérite de la classe Personnage, et don c dde ses attributs et méthodes
{
    public:
        void frapperAvecUnMarteau() const;
};
