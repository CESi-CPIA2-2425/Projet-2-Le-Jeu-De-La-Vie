#include "Fichier.h"
#include "Ligne.h"

#include <iostream>//entrée/sortie
#include <fstream>//fichier



using namespace std;

string Fichier::lecture() {


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
void Fichier::vecteur() {
    int nb_vecteur = txt[0];
    for (int i = 0; i < nb_vecteur; ++i) {
        // Créer un vecteur
        vector<vector<int>> vec;


        bool tabulationTrouvee = false;
        for (char c : full) {
            if (c == '\t') {
                tabulationTrouvee = true; // Une fois que la tabulation est rencontrée, passe au deuxième vecteur
                continue;
            }

            if (!tabulationTrouvee) {
                int cellule = c-'0';
                vec[i].push_back(cellule);
            }
            else {
                i=i+1;
            }
        }
    }
}
