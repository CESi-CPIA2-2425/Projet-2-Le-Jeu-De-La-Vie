//
// Created by Admin on 29/11/2024.
//

#ifndef FICHIER_H
#define FICHIER_H
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Fichier {
    public:
        string chemin_fichier;
        Fichier() {} // constructeur

        string lecture(); // methode pour lire le contenue du fichier
        vector<string> vecteur(string txt);  // Methode pour installer les info dans des vecteur

};



#endif //FICHIER_H
