#include <set>
#include "Manager.hh"
using namespace std;

/*
Why are we doing this?
→ To enable polymorphic behaviour with virtual businessCard(),
   so Manager-style cards print even when accessed through Employee*.
*/

void printAllCards(const set<Employee*>& directory) {
    for (auto* e : directory)
        e->businessCard();
}

int main() {
    Employee alice("Alice", 40000);
    Employee bob("Bob", 42000);
    Employee carol("Carol", 39000);

    Manager frank("Frank", 60000);
    frank.addSubordinate(alice);
    frank.addSubordinate(bob);

    Manager stan("Stan", 70000);
    stan.addSubordinate(frank);
    stan.addSubordinate(carol);

    set<Employee*> directory = {&alice, &bob, &carol, &frank, &stan};

    cout << "== All Business Cards ==" << endl;
    printAllCards(directory);

    return 0;
}
