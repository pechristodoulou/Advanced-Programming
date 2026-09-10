#ifndef ARRAY_HH
#define ARRAY_HH

#include <iostream>
using namespace std;

template <class T>
class Array {
public:
  // g) Constructor with default value
  Array(int size, T defVal = T()) : _size(size), _default(defVal) {
    _arr = new T[_size];
    for (int i = 0; i < _size; ++i)
      _arr[i] = _default;
  }

  // Copy constructor
  Array(const Array& other) : _size(other._size), _default(other._default) {
    _arr = new T[_size];
    for (int i = 0; i < _size; ++i)
      _arr[i] = other._arr[i];
  }

  // Destructor
  ~Array() {
    delete[] _arr;
  }

  // Assignment operator
  Array& operator=(const Array& other) {
    if (this == &other) return *this;
    if (_size != other._size)
      resize(other._size);
    _default = other._default;
    for (int i = 0; i < _size; ++i)
      _arr[i] = other._arr[i];
    return *this;
  }

  // e) operator[] with auto-resize
  T& operator[](int index) {
    if (index >= _size)
      resize(index + 1);
    return _arr[index];
  }

  const T& operator[](int index) const {
    return _arr[index];  // const version won't auto-resize
  }

  int size() const { return _size; }

  // Resize with default value fill
  void resize(int newSize) {
    T* newArr = new T[newSize];
    for (int i = 0; i < newSize; ++i)
      newArr[i] = (i < _size) ? _arr[i] : _default;
    delete[] _arr;
    _arr = newArr;
    _size = newSize;
  }

private:
  int _size;
  T* _arr;
  T _default;
};

#endif
