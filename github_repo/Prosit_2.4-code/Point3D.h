#ifndef POINT3D_H
#define POINT3D_H

#include "Point.h"

class CLpoint3D : public CLpoint {
protected:
    double z;

public:
    CLpoint3D(double x = 0.0, double y = 0.0, double z = 0.0);
    ~CLpoint3D() override = default;

    double calculDistance(const CLpoint& autre) const override;
    void afficherCoordo() const override;

    // Accesseur
    double getZ() const;
};

#endif // POINT3D_H
