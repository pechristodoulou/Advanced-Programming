#ifndef SHAPE_HH
#define SHAPE_HH

class Shape {
public:
  Shape() {}
  virtual ~Shape() {}

  virtual double surface() const = 0;
  virtual double circumference() const = 0;
  virtual const char* shapeName() const = 0;
};

#endif
