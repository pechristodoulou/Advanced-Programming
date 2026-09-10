#ifndef STACK_HH
#define STACK_HH

#include "Array.hh"
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
  Stack(int size = 10) : s(size, T()), count(0) {}

  void push(T val) {
    if (count >= s.size())
      s.resize(s.size() + 10); // just expand
    s[count++] = val;
  }

  T pop() {
    if (empty()) {
      cout << "Stack is empty!" << endl;
      return T();
    }
    return s[--count];
  }

  bool empty() const { return count == 0; }
  int nitems() const { return count; }

  void inspect() const {
    cout << "Stack contents (top to bottom):" << endl;
    for (int i = count - 1; i >= 0; --i)
      cout << " [" << i << "]: " << s[i] << endl;
  }

private:
  Array<T> s;
  int count;
};

#endif
