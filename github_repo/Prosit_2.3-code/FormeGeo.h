//
// Created by Admin on 15/11/2024.
//

#ifndef FORMEGEO_H
#define FORMEGEO_H
#include <set>


    class FormeGeo {
    protected:
        float x;
        float y;
    public:
    FormeGeo(): x(0),y(0) {}//constructeur

    float get_x();
    float get_y();

    void set_x(float x);
    void set_y(float y);
};



#endif //FORMEGEO_H
