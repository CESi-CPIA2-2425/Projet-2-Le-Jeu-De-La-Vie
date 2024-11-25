//
// Created by Admin on 12/11/2024.
//

#ifndef CRYPT_H
#define CRYPT_H
#include "iostream"
#include "string"


class crypte {
    public:
        std::string crypte_Cesar(std::string texte, int decalage);
        std::string crypte_Xor();
        crypte (std::string m);

    //private:
        std::string message;



};
#endif //CRYPT_H
