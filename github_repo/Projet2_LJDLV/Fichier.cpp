#include "Fichier.h"
//
// Created by Admin on 29/11/2024.
//

#include "Fichier.h"

#include <iostream>//entrée/sortie
#include <fstream>//fichier



using namespace std;

string Fichier::lecture() {

    string full;
    string contenu;
    string const nomFichier("C:/Users/Admin/Documents/CESI CPI A2/PROJET 2/projet 2 txt.txt");//entre guillement le chemin du fichier, monFlux est le nom du contenue du fichier
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
vector<string> Fichier::vecteur(string txt) {
    vector<string> liste_final;
    int nb_vecteur = txt[0];
    int len_vecteur = txt[2];

    std::vector<std::vector<string>> vectors;

    for (int i = 0; i < nb_vecteur; ++i) {
        // Créer un vecteur
        std::vector<string> vec;
        for (int j = 0; j < len_vecteur; ++j) {
            vectors.push_back(vector<string>());
        }
        liste_final.push_back(vectors);
    }
    return liste_final;
}






