//
// Created by Admin on 17/11/2024.
//
#include <cmath>
#include "Cercle.h"


float Cercle::getR(){
  return R;
}

void Cercle::setR(float R){
  this->R = R;
}

float Cercle::getArea(float Rayon) {
  return M_PI*(Rayon*Rayon);
}

float Cercle::getPerime(float Rayon) {
  return 2*M_PI*(Rayon);
}

