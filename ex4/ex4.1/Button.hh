#ifndef BUTTON_HH
#define BUTTON_HH

#include <iostream>

class Button {
public:

  Button() { std::cout << "Button Constructor " << this << std::endl ; }
  Button(const Button&) { std::cout << "Button Copy Constructor " << this << std::endl ; }
  ~Button() { std::cout << "Button Destructor " << this << std::endl ; }

private:

} ;

#endif 
