#ifndef LIGNE_H
#define LIGNE_H
#include <vector>

#include "Grille.h"
#include "Fichier.h"

using namespace std;

class Ligne : public Grille {
public:
    int x; //nécessaire dans le changement d'état
    int y; //nécessaire dans le changement d'état
    const int gridWidth, gridHeight;
    vector<vector<int>> jeu;

    Ligne() {}  //constructeur
    int get_h() const;
    int get_l()const;
    void change_etat()override;  //méthode abstraite
};




#endif //LIGNE_H
