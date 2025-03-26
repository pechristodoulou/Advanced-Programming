#ifndef CALORIMETER_HH
#define CALORIMETER_HH

#include "CaloGrid.hh"
#include "Point.hh"

class Calorimeter {
public:
    Calorimeter(int nx, int ny, Point pos = Point());

    CaloGrid& grid();
    const CaloGrid& grid() const;

    Point& position();
    const Point& position() const;

private:
    CaloGrid cgrid;
    Point pos;
};

#endif
