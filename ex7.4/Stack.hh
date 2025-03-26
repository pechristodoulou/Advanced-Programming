#ifndef STACK_HH
#define STACK_HH

#include <deque>
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
  Stack() {}

  void push(const T& val) {
    s.push_back(val);
  }

  T pop() {
    if (empty()) {
      cout << "Stack is empty!" << endl;
      return T();
    }
    T val = s.back();
    s.pop_back();
    return val;
  }

  bool empty() const {
    return s.empty();
  }

  int nitems() const {
    return s.size();
  }

  void inspect() const {
    cout << "Stack contents (top to bottom):" << endl;
    for (typename deque<T>::const_reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
      cout << *it << endl;
  }

private:
  deque<T> s;
};

#endif
