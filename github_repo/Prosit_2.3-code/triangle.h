//
// Created by Admin on 18/11/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "FormeGeo.h"

class Triangle : public FormeGeo {
private:
    float x2, y2; // Coordonnées du deuxième sommet
    float x3, y3; // Coordonnées du troisième sommet

public:
    // Constructeur par défaut
    Triangle() : FormeGeo(), x2(0), y2(0), x3(0), y3(0) {}

    // Méthodes d'accès
    void setX2(float x);
    void setY2(float y);
    void setX3(float x);
    void setY3(float y);

    float getX2();
    float getY2();
    float getX3();
    float getY3();

    // Méthodes pour calculer les propriétés du triangle
    float periTriangle();   // Calcul du périmètre
    float aireTriangle();   // Calcul de l'aire
};

#endif // TRIANGLE_H
