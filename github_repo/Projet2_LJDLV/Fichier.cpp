#include "Fichier.h"
#include "Ligne.h"

#include <iostream>//entrée/sortie
#include <fstream>//fichier

#include <sstream>   // Pour std::istringstream
#include <vector>    // Pour std::vector
#include <string>    // Pour std::string


using namespace std;

string Fichier::lecture() {
    cout<<"Fichier";
    string const nomFichier("C:/Users/thais/Documents Local/CPI A2/Projet 2/Livrable/Projet-2/Fichier.txt");//entre guillement le chemin du fichier, monFlux est le nom du contenue du fichier
    ifstream monFlux(nomFichier.c_str());

    while (getline(monFlux, contenu)) {
        if(monFlux)  // si l'ouverture a fonctionné
        {
            //getline(monFlux, contenu);  // on met dans "contenu" la ligne
            // cout << contenu<<endl;  // on affiche la ligne
            full +=  contenu + "\n";


        }
        else
            cout << "Impossible d'ouvrir le fichier !" << endl;
    }

    monFlux.close();
    return full;

}
void Fichier::vecteur() {
    std::cout << "Début de la transformation en vecteur..." << std::endl;

    this->vec.clear(); // Réinitialiser `vec`

    std::istringstream stream(full); // Créer un flux à partir de `full`
    std::string ligne;

    while (std::getline(stream, ligne)) {
        if (ligne.empty()) {
            continue; // Ignorer les lignes vides
        }

        std::istringstream ligneStream(ligne); // Flux pour traiter chaque ligne
        std::vector<int> sousVecteur;
        int valeur;

        while (ligneStream >> valeur) { // Extraire chaque valeur entière de la ligne
            sousVecteur.push_back(valeur);
            std::cout << "Ajouté : " << valeur << " à sousVecteur[" << sousVecteur.size() - 1 << "]" << std::endl;
        }

        vec.push_back(sousVecteur); // Ajouter le sous-vecteur à `vec`
        std::cout << "Nouvelle ligne ajoutée à vec, taille actuelle : " << vec.size() << std::endl;
    }

    std::cout << "Transformation en vecteur terminée. Taille totale de vec : " << vec.size() << std::endl;
}


