#include "Manager.hh"

Manager::Manager(const char* name, double salary)
  : Employee(name, salary) {}

void Manager::addSubordinate(Employee& empl) {
  _subs.insert(&empl);
}

const set<Employee*>& Manager::listOfSubordinates() const {
  return _subs;
}

void Manager::businessCard(ostream& os) const {
  // g/h) override and call base version first
  Employee::businessCard(os);

  // Then print subordinate info
  os << "   Manages " << _subs.size() << " employee(s):" << endl;
  for (const auto& e : _subs)
    os << "   - " << e->name() << endl;
}
