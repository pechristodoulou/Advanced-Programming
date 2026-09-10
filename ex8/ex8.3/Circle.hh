#ifndef CIRCLE_HH
#define CIRCLE_HH

#include "Shape.hh"
#include <cmath>

class Circle : public Shape {
public:
  Circle(double radius) : _r(radius) {}
  virtual ~Circle() {}

  virtual double surface() const { return M_PI * _r * _r; }
  virtual double circumference() const { return 2 * M_PI * _r; }
  virtual const char* shapeName() const { return "Circle"; }

private:
  double _r;
};

#endif
