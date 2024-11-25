#include <iostream>//entrée/sortie
#include <string>
#include "decrypt.h"

using namespace std;
string texteChiffre ;
string code_cesar(const string texte,int decal) {
    //string textedeChiffre = "";

    for(char c : texte) {
        if (isupper(c)){
            texteChiffre+=(char(int(c - decal - 65) % 26 + 65));
        }
        else if (islower(c)) {
            texteChiffre+=(char(int(c - decal - 97) % 26 + 97));
        }
        else {
            texteChiffre += c;  // Conserver les autres caractères tels quels
        }
    }
    return texteChiffre;
}
/*
decrypt::code_xor(Fichier::lecture(), int decal){
    string code_final;
    int code_ascii = (int)contenu;
    code_final_ascii = code_ascii + decal;
    code_final = (string)code_final_ascii;
    Fichier::ecriture(code_final);
    return code_final;
}
*/
