
#include <iostream>

#include "Cercle.h"
#include "FormeGeo.h"
#include "Rectangle.h"
#include "triangle.h"

int main() {

    FormeGeo carre;



    carre.set_x(12.0);
    carre.set_y(0.0);

    float x = carre.get_x();
    float y = carre.get_y();

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    Cercle cercle;

    cercle.setR(19.0);
    float rayaon = cercle.getR();
    std::cout << "rayaon = " << rayaon << std::endl;

    float aire_cercle = cercle.getArea(rayaon);
    std::cout << "aire cercle = " << aire_cercle << std::endl;

    float per_cercle = cercle.getPerime(rayaon);
    std::cout << "perimetre cercle = " << per_cercle << std::endl;


    Rectangle rectangle;

    rectangle.setXr(7.8);
    rectangle.setYr(3.8);

    float a = rectangle.getXr();
    float b = rectangle.getYr();



    float longeur = rectangle.getl(a,x);
    float largeur = rectangle.getL(b,y);

    std::cout << "longeur = " << longeur << std::endl;
    std::cout << "largeur = " << largeur << std::endl;

   float aire_rect = rectangle.aireRect(largeur,longeur);

   float per_rect =  rectangle.periRect(largeur,longeur);

    std::cout << "perimetre rectangle = " << per_rect << std::endl;
    std::cout << "aire rectangle = " << aire_rect  << std::endl;


    Triangle triangle;
    triangle.set_x(0.0);
    triangle.set_y(0.0);
    triangle.setX2(3.0);
    triangle.setY2(0.0);
    triangle.setX3(0.0);
    triangle.setY3(4.0);

    float aire_triangle = triangle.aireTriangle();
    float per_triangle = triangle.periTriangle();

    std::cout << "aire triangle = " << aire_triangle << std::endl;
    std::cout << "perimetre triangle = " << per_triangle << std::endl;





    return 0;
}
