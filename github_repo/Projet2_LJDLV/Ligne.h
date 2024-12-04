#ifndef LIGNE_H
#define LIGNE_H
#include <vector>
#include "Fichier.h"
using namespace std;

class Ligne {
public:
    std::vector<std::string>grille;
    int cologne ;
    int ligne;
    int x;
    int y;
    int gridWidth;
    int gridHeight;

    Ligne(std::vector<std::string> grille);// consturcteur temp
    int CompteCell(int x,int y,std::vector<std::string> grille);
    void Generation();
    void AfficheGrille();
    int get_h() const;
    int get_l()const;


};






#endif //LIGNE_H
