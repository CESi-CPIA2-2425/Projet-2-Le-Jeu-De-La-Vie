#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class CLpoint {
protected:
    double x;
    double y;

public:
    CLpoint(double x = 0.0, double y = 0.0);
    virtual ~CLpoint() = default;

    virtual double calculDistance(const CLpoint& autre) const;
    virtual void afficherCoordo() const;

    // Accesseurs
    double getX() const;
    double getY() const;
};

#endif // POINT_H
