#include <iostream>
#ifndef HOUSING_HH
#define HOUSING_HH

#include "Chassis.hh"
#include "Shell.hh"

class Housing {
public:

  Housing() { std::cout << "Housing Constructor " << this << std::endl ; }
  Housing(const Housing&) { std::cout << "Housing Copy Constructor " << this << std::endl ; }
  ~Housing() { std::cout << "Housing Destructor " << this << std::endl ; }

private:

  Chassis chassis ;
  Shell shell ;

} ;

#endif 
