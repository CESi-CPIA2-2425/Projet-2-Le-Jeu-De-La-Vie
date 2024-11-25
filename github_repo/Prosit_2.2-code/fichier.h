#ifndef FICHIER_H // Prévenir les inclusions multiples
#define FICHIER_H

#include <string>
using namespace std;

class Fichier {
public:
    // Constructeur (optionnel, selon si vous avez besoin d'initialiser quelque chose)
    Fichier();

    // Méthodes pour la lecture et l'écriture
    string lecture();
    void ecriture();

private:
    //std::string nomFichier; // Stocke le nom ou le chemin du fichier
};

#endif // FICHIER_H
