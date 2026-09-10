#include <iostream>
#ifndef HANDSET_HH
#define HANDSET_HH

#include "Mouthpiece.hh"
#include "Earpiece.hh"
#include "Cable.hh"

class Handset {
public:

  Handset() { std::cout << "Handset Constructor " << this << std::endl ; }
  Handset(const Handset&) { std::cout << "Handset Copy Constructor " << this << std::endl ; }
  ~Handset() { std::cout << "Handset Destructor " << this << std::endl ; }

private:

  Mouthpiece mouthpiece ;
  Earpiece earpiece ;
  Cable cable ;


} ;

#endif 
