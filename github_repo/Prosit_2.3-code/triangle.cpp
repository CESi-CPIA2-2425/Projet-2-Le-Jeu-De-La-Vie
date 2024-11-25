//
// Created by Admin on 18/11/2024.
//

#include "triangle.h"
#include <cmath>

// Définitions des méthodes d'accès
void Triangle::setX2(float x) {
    this->x2 = x;
}

void Triangle::setY2(float y) {
    this->y2 = y;
}

void Triangle::setX3(float x) {
    this->x3 = x;
}

void Triangle::setY3(float y) {
    this->y3 = y;
}

float Triangle::getX2() {
    return x2;
}

float Triangle::getY2() {
    return y2;
}

float Triangle::getX3() {
    return x3;
}

float Triangle::getY3() {
    return y3;
}

// Méthode pour calculer le périmètre du triangle
float Triangle::periTriangle() {
    float d1 = std::sqrt(std::pow(x2 - x, 2) + std::pow(y2 - y, 2));
    float d2 = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    float d3 = std::sqrt(std::pow(x3 - x, 2) + std::pow(y3 - y, 2));
    return d1 + d2 + d3;
}

// Méthode pour calculer l'aire du triangle
float Triangle::aireTriangle() {
    // Formule de l'aire avec les coordonnées des sommets
    return std::abs((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2.0f);
}
