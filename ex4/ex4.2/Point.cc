#include "Point.hh"

Point::Point(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

void Point::setX(double x_) { x = x_; }
void Point::setY(double y_) { y = y_; }
void Point::setZ(double z_) { z = z_; }

void Point::setXYZ(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}
