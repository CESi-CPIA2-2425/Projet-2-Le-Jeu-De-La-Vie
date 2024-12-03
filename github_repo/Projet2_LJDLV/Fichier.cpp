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

vector<string> Fichier::vecteur(const string& txt) {

    vector<string> liste;
    stringstream ss(txt);
    string ligne;

    while (std::getline(ss,ligne)) {
        liste.push_back(ligne);
    }



    return liste;
}





