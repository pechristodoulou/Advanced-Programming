#ifndef CALOCELL_HH
#define CALOCELL_HH

class CaloCell {
public:
    CaloCell(double e = 0.0, int id = -1);

    double getEnergy() const;
    int getID() const;

    void setEnergy(double e);
    void setID(int id);

private:
    double energy;
    int ID;
};

#endif
