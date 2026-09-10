#ifndef EMPLOYEE_HH
#define EMPLOYEE_HH

#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
  Employee(const char* name, double salary) : _name(name), _salary(salary) {}

  const char* name() const { return _name.c_str(); }
  double salary() const { return _salary; }

  virtual void businessCard(ostream& os = cout) const {
    os << "   +------------------+  " << endl
       << "   | ACME Corporation |  " << endl 
       << "   +------------------+  " << endl
       << "   " << name() << endl;
  }

private:
  string _name;
  double _salary;
};

#endif
