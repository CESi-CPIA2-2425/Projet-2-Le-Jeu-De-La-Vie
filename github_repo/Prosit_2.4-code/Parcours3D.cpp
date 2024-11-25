#include "Parcours3D.h"

CLparcours3D::CLparcours3D(int capacite) : CLparcours(capacite) {}

double CLparcours3D::calculDistance() const {
    double distanceTotale = 0.0;
    for (size_t i = 1; i < points.size(); ++i) {
        const CLpoint3D* p1 = dynamic_cast<const CLpoint3D*>(points[i - 1]);
        const CLpoint3D* p2 = dynamic_cast<const CLpoint3D*>(points[i]);
        if (p1 && p2) {
            distanceTotale += p1->calculDistance(*p2);
        }
    }
    return distanceTotale;
}

void CLparcours3D::message() const {
    std::cout << "CLparcours3D: " << points.size() << " points 3D." << std::endl;
}
