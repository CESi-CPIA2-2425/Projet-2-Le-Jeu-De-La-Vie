#ifndef GRILLE_H
#define GRILLE_H



class Grille {

private :
    int h;
    int l;

public:
    Grille(int, int){}  //constructeur
    void get_h();
    void get_l();
    virtual void change_etat()=0;  //méthode abstraite
};

#endif //GRILLE_H
