#include "Fichier.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>//entrée/sortie
#include <fstream>//fichier
#include <sstream>



using namespace std;

string Fichier::lecture() {

    string full;
    string contenu;
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

vector<string> Fichier::vecteur(const string& txt) {

    vector<string> liste;
    stringstream ss(txt);
    string ligne;

    while (std::getline(ss,ligne)) {
        liste.push_back(ligne);
    }



    return liste;
}




