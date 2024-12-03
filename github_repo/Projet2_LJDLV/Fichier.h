#ifndef FICHIER_H
#define FICHIER_H
#include <string>
#include <vector>

using namespace std;

class Fichier {
public:
    string txt;
    string full;
    string contenu;
    vector<vector<int>>vec;

    string chemin_fichier;
    Fichier() : txt(""), full(""), contenu(""), chemin_fichier("") {} // constructeur

    string lecture(); // methode pour lire le contenue du fichier
    void vecteur();  // Methode pour installer les info dans des vecteur

};



#endif //FICHIER_H




