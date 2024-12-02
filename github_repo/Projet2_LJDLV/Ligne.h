#ifndef LIGNE_H
#define LIGNE_H

#include "Grille.h"

class Ligne : public Grille {
private :
    int x; //nécessaire dans le changement d'état
    int y; //nécessaire dans le changement d'état

public:
    //Ligne(int){}  //constructeur
    int get_h() const;
    int get_l()const;
    void change_etat()override;  //méthode abstraite
};




#endif //LIGNE_H
