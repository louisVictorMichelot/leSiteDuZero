#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include "Personnage.hpp"
#include "Arme.hpp"
#include "Guerrier.hpp"

using namespace std;

int main() {
    
    
    //Création des personnages
 //   Personnage goliath("Épée aiguisée",100);
   
    //Au combat !
     /*goliath.attaquer(david);
     david.boirePotionDeVie(20);
     goliath.attaquer(david);
     david.attaquer(goliath);
     goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
     goliath.attaquer(david);*/
    
//    david = goliath;
//    Personnage david = goliath;
    
    //Temps mort ! Voyons voir la vie de chacun...
  //   cout << "David" << endl;
    // david.afficherEtat();
    // cout << endl << "Goliath" << endl;
     //goliath.afficherEtat();
    
    
    Personnage *monPersonnage(0);
    Guerrier   *monGuerrier = new Guerrier();
    monPersonnage = monGuerrier; // Mais... mais... Ça marche !?

    monGuerrier->afficherEtat();
    cout<<endl;
    monGuerrier->afficherEtat();
    cout<<endl;

    cout<<endl;
    return 0;
    
}
