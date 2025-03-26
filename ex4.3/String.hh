#ifndef STRING_HH
#define STRING_HH

#include <cstring>

class String {
public:
  String(const char* str = "") : _s(0) { insert(str); }
  String(const String& a) : _s(0) { insert(a._s); }
  ~String() { delete[] _s; }

  int length() const { return _len; }
  const char* data() const { return _s; }

  // d) operator=
  String& operator=(const String& a) {
    if (this != &a)
      insert(a._s);
    return *this;
  }

  // e/f) operator+=
  String& operator+=(const String& other) {
    char* tmp = new char[_len + other._len + 1];
    strcpy(tmp, _s);
    strcat(tmp, other._s);
    delete[] _s;
    _s = tmp;
    _len += other._len;
    return *this;
  }

  // g) operator+
  friend String operator+(const String& a, const String& b) {
    String temp = a;
    temp += b;
    return temp;
  }

  // k) operator const char*
  operator const char*() const {
    return _s;
  }

private:
  char* _s;
  int _len;

  void insert(const char* str) {
    _len = strlen(str);
    if (_s) delete[] _s;
    _s = new char[_len + 1];
    strcpy(_s, str);
  }
};

#endif
