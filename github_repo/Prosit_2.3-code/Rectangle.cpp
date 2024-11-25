
//
// Created by Admin on 17/11/2024.
//

#include "Rectangle.h"

#include <cmath>
#include <math.h>

void Rectangle::setXr(float x) {
 this->xr = x;
}

void Rectangle::setYr(float y) {
 this->yr = y;
}

/*
void Rectangle::setl(float large) {
 this->l = large;
}

void Rectangle::setL(float Long) {
 this->l = Long;
}
*/

float Rectangle::getXr() {
 return xr;
}

float Rectangle::getYr() {
 return yr;
}

float Rectangle::getL(float xr,float x) {
 return fabs(xr - x);
}

float Rectangle::getl(float yr,float y) {
 return fabs(yr - y);
}

float Rectangle::periRect(float Large, float Long) {
 return 2*(Large+Long);
}

float Rectangle::aireRect(float Long, float Large) {
 return (Large*Long);
}



