#ifndef FICHIER_H
#define FICHIER_H
#include <string>

using namespace std;

class Fichier {
public:
    string txt;
    string full;
    string contenu;

    string chemin_fichier;
    Fichier() {} // constructeur

    string lecture(); // methode pour lire le contenue du fichier
    void vecteur();  // Methode pour installer les info dans des vecteur

};



#endif //FICHIER_H




