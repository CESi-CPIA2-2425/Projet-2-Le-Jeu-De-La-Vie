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

void Ligne::change_etat(){
    cout<<"etat"<<endl;
    x=0;
    y=0;
    int i = 0;
    while (i<=gridWidth*gridHeight) {
        int environ = 0 ;
        cout<<jeu[x][y]<<endl;
        environ = jeu[y-1%gridHeight][x-1%gridHeight] + jeu[y-1%gridHeight][x%gridHeight] + jeu[y-1%gridHeight][x+1%h] + jeu[y%h][x-1%h] + jeu[y%h][x+1%h] + jeu[y+1%h][x-1%h] + jeu[y+1%h][x%h] + jeu[y+1%h][x+1%h];
        cout<<"environ"<<endl;
        if(jeu[y][x]==0) {
            if(environ >=3) {
                jeu[y][x] = 1;
            }

        }
        if(jeu[y][x]==1) {
            if(environ <2 && environ >=3) {
                jeu[y][x]=0;
            }
        }
        i=i+1;
        x=x+1;
        if(x>l-1) {
            x=0;
            y=y+1;
        }
    }
}