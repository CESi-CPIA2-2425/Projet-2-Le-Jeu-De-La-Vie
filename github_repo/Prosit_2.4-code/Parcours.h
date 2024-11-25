#ifndef PARCOURS_H
#define PARCOURS_H

#include <vector>
#include "Point.h"

class CLparcours {
protected:
    std::vector<CLpoint*> points;

public:
    explicit CLparcours(int capacite = 10);
    virtual ~CLparcours();

    void ajouterPoint(CLpoint* point);
    virtual double calculDistance() const;
    virtual void message() const;

    // Accesseur
    size_t getNombrePoints() const;
};

#endif // PARCOURS_H
