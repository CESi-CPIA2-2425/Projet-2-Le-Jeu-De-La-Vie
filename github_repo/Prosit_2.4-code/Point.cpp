#include "Point.h"

CLpoint::CLpoint(double x, double y) : x(x), y(y) {}

double CLpoint::calculDistance(const CLpoint& autre) const {
    return std::sqrt(std::pow(x - autre.x, 2) + std::pow(y - autre.y, 2));
}

void CLpoint::afficherCoordo() const {
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
}

double CLpoint::getX() const {
    return x;
}

double CLpoint::getY() const {
    return y;
}
