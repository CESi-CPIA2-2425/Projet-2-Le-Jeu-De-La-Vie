#include "Ligne.h"

int Ligne::get_h() const {
    return x;
}

int Ligne::get_l() const {
    return y;
}

void Ligne::change_etat(){
    x=0;
    y=0;
    int i = 0;
    while (i<=l*h) {
        int environ = vec[y-1%h][x-1%h] + vec[y-1%h][x%h] + vec[y-1%h][x+1%h] + vec[y%h][x-1%h] + vec[y%h][x+1%h] + vec[y+1%h][x-1%h] + vec[y+1%h][x%h] + vec[y+1%h][x+1%h];
        if(vec[y][x]=0) {
            environ >=3;
            vec[y][x] = 1;
        }
        if(vec[y][x]=1) {
            environ <=2;
            vec[y][x]=0;
        }
        i=i+1;
        x=x+1;
        if(x>l-1) {
            x=0;
            y=y+1;
        }
    }
}