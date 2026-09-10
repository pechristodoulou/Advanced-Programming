#include <iostream>
#ifndef EARPIECE_HH
#define EARPIECE_HH

class Earpiece {
public:

  Earpiece() { std::cout << "Earpiece Constructor " << this << std::endl ; }
  Earpiece(const Earpiece&) { std::cout << "Earpiece Copy Constructor " << this << std::endl ; }
  ~Earpiece() { std::cout << "Earpiece Destructor " << this << std::endl ; }

private:

} ;

#endif 
