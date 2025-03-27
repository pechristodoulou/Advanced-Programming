#include <pybind11/pybind11.h>
using namespace pybind11;

int square(int x) {
    return x * x;
}

double add(double a, double b) {
    return a + b;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "Example module for Exercise 10";
    m.def("square", &square, "Return square of integer");
    m.def("add", &add, "Add two floats");
}
