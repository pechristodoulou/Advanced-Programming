#ifndef SHELL_HH
#define SHELL_HH

#include <iostream>

class Shell {
public:

  Shell() { std::cout << "Shell Constructor " << this << std::endl ; }
  Shell(const Shell&) { std::cout << "Shell Copy Constructor " << this << std::endl ; }
  ~Shell() { std::cout << "Shell Destructor " << this << std::endl ; }

private:

} ;

#endif 
