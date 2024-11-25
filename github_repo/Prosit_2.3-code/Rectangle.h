
//
// Created by Admin on 17/11/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdio.h>

#include "FormeGeo.h"



class Rectangle : public FormeGeo{
    private:
    float xr;
    float yr;

    // float L;
    // float l;

    public:

   // Rectangle(float xr, float yr, float L): FormeGeo() {}// constructeur

    Rectangle(): FormeGeo(), xr(xr), yr(yr) {}

    void setXr(float x);
    void setYr(float y);
    // void setL(float Long);
    //void setl(float large);

    float getXr();
    float getYr();

    float getL(float Xr,float x);
    float getl(float Yr,float y);

    float periRect(float Large, float Long);
    float aireRect(float Large,float Long);



};



#endif //RECTANGLE_H
