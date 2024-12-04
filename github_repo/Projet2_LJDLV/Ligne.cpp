#include "Ligne.h"
#include "Fichier.h"
#include "Grille.h"
#include <iostream>
//Fichier fichier;


using namespace std;

int Ligne::get_h() const {
    return x;
}

int Ligne::get_l() const {
    return y;
}

Ligne::Ligne(std::vector<std::string> grille): grille(grille), cologne(grille[0].size()), ligne(grille.size()), x(0), y(0), gridWidth(0), gridHeight(0) {}//constructeur

int Ligne::CompteCell(int x,int y,std::vector<std::string> grille) {
    int compteur = 0;


    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(i == 0 && j == 0) continue;
            int nx = x+i;
            int ny = y+j;
            if (nx >= 0 && nx<ligne && ny>= 0 && ny < cologne) {
                compteur += grille[nx][ny] =='1';
            }
        }
    }
    return compteur;
}

// Affiche la grille actuelle
void Ligne::AfficheGrille() {
    for (const auto& l : grille) {
        std::cout << l << '\n';
    }
    std::cout << '\n';
}

void Ligne::Generation() {
    std::vector<std::string> nvlle = grille;

    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < cologne; ++j) {
            int voisin = CompteCell(i, j,grille);
            if (grille[i][j] == '1') {
                nvlle[i][j] =(voisin == 2 || voisin ==  3) ? '1' : '0';
            }else {
                nvlle[i][j] = (voisin ==3) ? '1' : '0';
            }
        }
    }
    grille = nvlle;

}