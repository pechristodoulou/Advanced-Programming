#include "Calorimeter.hh"

Calorimeter::Calorimeter(int nx, int ny, Point p) 
    : cgrid(nx, ny), pos(p) {}

CaloGrid& Calorimeter::grid() {
    return cgrid;
}

const CaloGrid& Calorimeter::grid() const {
    return cgrid;
}

Point& Calorimeter::position() {
    return pos;
}

const Point& Calorimeter::position() const {
    return pos;
}
