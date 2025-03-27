#ifndef MANAGER_HH
#define MANAGER_HH

#include <set>
#include "Employee.hh"

class Manager : public Employee {
public:
  Manager(const char* name, double salary);

  void addSubordinate(Employee& empl);
  const set<Employee*>& listOfSubordinates() const;

  void businessCard(ostream& os = cout) const;

private:
  set<Employee*> _subs;
};

#endif
