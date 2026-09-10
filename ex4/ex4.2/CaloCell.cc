#include "CaloCell.hh"

CaloCell::CaloCell(double e, int id) {
    energy = e;
    ID = id;
}

double CaloCell::getEnergy() const {
    return energy;
}

int CaloCell::getID() const {
    return ID;
}

void CaloCell::setEnergy(double e) {
    energy = e;
}

void CaloCell::setID(int id) {
    ID = id;
}
