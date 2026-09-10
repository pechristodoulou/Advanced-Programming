#include <iostream>
#ifndef MOUTHPIECE_HH
#define MOUTHPIECE_HH

class Mouthpiece {
public:

  Mouthpiece() { std::cout << "Mouthpiece Constructor " << this << std::endl ; }
  Mouthpiece(const Mouthpiece&) { std::cout << "Mouthpiece Copy Constructor " << this << std::endl ; }
  ~Mouthpiece() { std::cout << "Mouthpiece Destructor " << this << std::endl ; }

private:

} ;

#endif 
