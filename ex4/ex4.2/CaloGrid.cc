#include "CaloGrid.hh"
#include <iostream>
using namespace std;

CaloGrid::CaloGrid(int nx_, int ny_) {
    nx = nx_;
    ny = ny_;
    cells = new CaloCell[nx * ny];
}

CaloGrid::CaloGrid(const CaloGrid& other) {
    nx = other.nx;
    ny = other.ny;
    cells = new CaloCell[nx * ny];
    for (int i = 0; i < nx * ny; ++i) {
        cells[i] = other.cells[i];
    }
}

CaloGrid::~CaloGrid() {
    delete[] cells;
}

int CaloGrid::index(int x, int y) const {
    return y * nx + x;
}

CaloCell* CaloGrid::cell(int x, int y) {
    if (x < 0 || x >= nx || y < 0 || y >= ny)
        return nullptr;
    return &cells[index(x, y)];
}

const CaloCell* CaloGrid::cell(int x, int y) const {
    if (x < 0 || x >= nx || y < 0 || y >= ny)
        return nullptr;
    return &cells[index(x, y)];
}

int CaloGrid::getNx() const { return nx; }
int CaloGrid::getNy() const { return ny; }
