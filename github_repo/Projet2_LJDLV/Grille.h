#ifndef GRILLE_H
#define GRILLE_H



class Grille {

public:
    int h;
    int l;
    int x;
    int y;

    Grille(){}  //constructeur
    virtual ~Grille() = default;  //destructeur
    int get_h();
    int get_l();
    virtual void change_etat()=0;  //méthode abstraite
    int get_h() const;

    int get_l() const;
};

#endif //GRILLE_H
