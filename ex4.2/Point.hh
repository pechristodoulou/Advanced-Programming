#ifndef POINT_HH
#define POINT_HH

class Point {
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setXYZ(double x, double y, double z);

private:
    double x, y, z;
};

#endif
