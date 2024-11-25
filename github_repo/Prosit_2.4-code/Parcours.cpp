#include "Parcours.h"

CLparcours::CLparcours(int capacite) {
    points.reserve(capacite);
}

CLparcours::~CLparcours() {
    for (auto point : points) {
        delete point;
    }
}

void CLparcours::ajouterPoint(CLpoint* point) {
    points.push_back(point);
}

double CLparcours::calculDistance() const {
    double distanceTotale = 0.0;
    for (size_t i = 1; i < points.size(); ++i) {
        distanceTotale += points[i - 1]->calculDistance(*points[i]);
    }
    return distanceTotale;
}

void CLparcours::message() const {
    std::cout << "CLparcours: " << points.size() << " points." << std::endl;
}

size_t CLparcours::getNombrePoints() const {
    return points.size();
}
