//
// Created by Admin on 17/11/2024.
//

#ifndef CERCLE_H
#define CERCLE_H

#include "FormeGeo.h"

class Cercle : public FormeGeo {     //heritage des point x,y
  private:
    float R;
  public:
    Cercle(): R(0) {}// constructeur
    float getR();
    void setR(float Rayon);

    float getArea(float Rayon);
    float getPerime(float Rayon);

};



#endif //CERCLE_H
