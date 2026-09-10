#include <iostream>
#include <list>
#include "Square.hh"
#include "Circle.hh"
using namespace std;

/*
Why are we doing this?
→ We extend an abstract base class to handle different shape types polymorphically.
→ We add shapeName() so we can identify them during traversal.
*/

void listShapes(const list<Shape*>& shapes) {
  for (auto* shape : shapes) {
    cout << shape->shapeName() << ": ";
    cout << "Area = " << shape->surface();
    cout << ", Circumference = " << shape->circumference() << endl;
  }
}

int main() {
  list<Shape*> shapes;
  shapes.push_back(new Square(3));
  shapes.push_back(new Circle(2));
  shapes.push_back(new Square(1.5));

  listShapes(shapes);

  for (auto* shape : shapes)
    delete shape;

  return 0;
}
