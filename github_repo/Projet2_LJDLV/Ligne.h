//
// Created by Admin on 29/11/2024.
//

#ifndef LIGNE_H
#define LIGNE_H
#include <vector>
#include <string>

class Ligne {

    private:
        std::vector<std::string>grille;
        int cologne ;
        int ligne;
    public:

    Ligne(std::vector<std::string>grille);// consturcteur temp
    int CompteCell(int x,int y,std::vector<std::string> grille);
    void Generation();
    void AfficheGrille();


};



#endif //LIGNE_H
