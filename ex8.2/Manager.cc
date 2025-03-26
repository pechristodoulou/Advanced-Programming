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
  Employee::businessCard(os);
  os << "   Manages " << _subs.size() << " employee(s):" << endl;
  for (const auto& e : _subs)
    os << "   - " << e->name() << endl;
}
