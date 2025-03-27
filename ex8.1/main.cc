#include "Manager.hh"
using namespace std;

/*
Why are we doing this?
→ To learn how inheritance lets us extend base class functionality (Employee → Manager),
   and how polymorphism begins to emerge with shared interfaces like businessCard().
*/

int main() {
  Employee alice("Alice", 40000);
  Employee bob("Bob", 42000);
  Employee carol("Carol", 39000);

  Manager frank("Frank", 60000);
  frank.addSubordinate(alice);
  frank.addSubordinate(bob);

  Manager stan("Stan", 70000);
  stan.addSubordinate(frank);  // Managers are also Employees!
  stan.addSubordinate(carol);

  cout << "Business card for Stan:" << endl;
  stan.businessCard();

  cout << "\nBusiness card for Frank:" << endl;
  frank.businessCard();

  return 0;
}
