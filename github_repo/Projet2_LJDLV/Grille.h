////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////////////////////// LE JEU DE LA VIE ////////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////////////////////// Classe Grille ///////////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

#ifndef GRILLE_H
#define GRILLE_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
//////////////////////////////////////////////Déclaration de la classe//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

class Grille {  //Classe abstraite

private:
    int h;
    int l;
    int x;
    int y;

public:
    Grille(){}  //Constructeur
    virtual ~Grille() = default;  //Destructeur

    int get_h() const;
    int get_l() const;

    virtual void change_etat()=0;  //Méthode virtuelle pure
};

#endif //GRILLE_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.


