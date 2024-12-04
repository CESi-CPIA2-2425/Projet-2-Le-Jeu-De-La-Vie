#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Fichier.h"
#include "Ligne.h"
using namespace std;

int main () {

    Fichier fichier;
    string txt = fichier.lecture();
    vector<string> liste = fichier.vecteur(txt);

    // Affichage des éléments du vecteur
    for (const auto& ligne : liste) {
        std::cout << ligne << std::endl;
    }

    cout <<"--------------------------------" << endl;
    liste.erase(liste.begin());

    for (const auto& ligne : liste) {
        std::cout << ligne << std::endl;
    }

    //penser a retirer les dimenstion de la grille

    Ligne   jeu(liste);

    int tst = jeu.CompteCell(1,1,liste);
    cout << tst << "ici" << endl;

    for (int i = 0; i < 5; ++i) {
        // Simul 5 gen
        std::cout << "GEN " << i + 1 << " :\n";
        jeu.Generation();
        jeu.AfficheGrille();
    }
   // int s = jeu.CompteCell(0,0,liste);
  //  cout << s << endl;

                //int boucle = cout << txt[0]<< endl;
               //cout << txt[0]<< endl;
                // cout << txt<< endl;


    //std::cout << "Contenu du vecteur : ";
    //for (string elem : liste) {
       // std::cout << elem << " ";
    //}
    //::cout << std::endl; // Terminer la ligne






    //cout << 'tst apres fichier.vecteur()'<< endl;


    return 0;
}
