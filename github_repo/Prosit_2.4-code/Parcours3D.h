#ifndef PARCOURS3D_H
#define PARCOURS3D_H

#include "Parcours.h"
#include "Point3D.h"

class CLparcours3D : public CLparcours {
public:
    explicit CLparcours3D(int capacite = 10);
    ~CLparcours3D() override = default;

    double calculDistance() const override;
    void message() const override;
};

#endif // PARCOURS3D_H
