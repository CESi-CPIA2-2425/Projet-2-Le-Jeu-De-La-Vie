#include "Point3D.h"

CLpoint3D::CLpoint3D(double x, double y, double z) : CLpoint(x, y), z(z) {}

double CLpoint3D::calculDistance(const CLpoint& autre) const {
    const CLpoint3D* autre3D = dynamic_cast<const CLpoint3D*>(&autre);
    if (autre3D) {
        return std::sqrt(std::pow(x - autre3D->x, 2) +
                         std::pow(y - autre3D->y, 2) +
                         std::pow(z - autre3D->z, 2));
    }
    return CLpoint::calculDistance(autre); // Appelle la méthode de CLpoint si autre n'est pas 3D
}

void CLpoint3D::afficherCoordo() const {
    std::cout << "Point3D(" << x << ", " << y << ", " << z << ")" << std::endl;
}

double CLpoint3D::getZ() const {
    return z;
}
