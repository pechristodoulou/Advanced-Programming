#ifndef CALOGRID_HH
#define CALOGRID_HH

#include "CaloCell.hh"

class CaloGrid {
public:
    CaloGrid(int nx, int ny);
    CaloGrid(const CaloGrid& other);
    ~CaloGrid();

    CaloCell* cell(int x, int y);
    const CaloCell* cell(int x, int y) const;

    int getNx() const;
    int getNy() const;

private:
    int nx, ny;
    CaloCell* cells;

    int index(int x, int y) const; // convert 2D to 1D index
};

#endif
