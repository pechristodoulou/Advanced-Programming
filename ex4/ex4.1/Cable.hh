#ifndef CABLE_HH
#define CABLE_HH

#include <iostream>

class Cable {
public:
  Cable() { std::cout << "Cable Constructor " << this << std::endl; }
  Cable(const Cable&) { std::cout << "Cable Copy Constructor " << this << std::endl; }
  ~Cable() { std::cout << "Cable Destructor " << this << std::endl; }

private:
};

#endif
