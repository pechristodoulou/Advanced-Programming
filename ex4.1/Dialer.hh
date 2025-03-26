#ifndef DIALER_HH
#define DIALER_HH

#include <iostream>
#include "Button.hh"

class Dialer {
public:
  Dialer();                    // Constructor
  Dialer(const Dialer&);      // Copy constructor
  ~Dialer();                   // Destructor

private:
  Button* buttons;
};

#endif
