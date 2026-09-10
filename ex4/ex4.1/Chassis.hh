#ifndef CHASSIS_HH
#define CHASSIS_HH

#include <iostream>

class Chassis {
public:

  Chassis() { std::cout << "Chassis Constructor " << this << std::endl ; }
  Chassis(const Chassis&) { std::cout << "Chassis Copy Constructor " << this << std::endl ; }
  ~Chassis() { std::cout << "Chassis Destructor " << this << std::endl ; }

private:

} ;

#endif 
