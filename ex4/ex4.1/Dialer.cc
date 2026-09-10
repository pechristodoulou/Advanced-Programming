#include "Dialer.hh"

Dialer::Dialer() {
  std::cout << "Dialer Constructor " << this << std::endl;
  buttons = new Button[12];  // allocate dynamically
}

Dialer::Dialer(const Dialer& other) {
  std::cout << "Dialer Copy Constructor " << this << std::endl;
  buttons = new Button[12];  // deep copy
  for (int i = 0; i < 12; ++i)
    buttons[i] = other.buttons[i];
}

Dialer::~Dialer() {
  std::cout << "Dialer Destructor " << this << std::endl;
  delete[] buttons;
}
