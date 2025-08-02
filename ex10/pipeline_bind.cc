#include <pybind11/pybind11.h>
#include "../ex9.3/Pipeline.hh"   // relative include path

namespace py = pybind11;

PYBIND11_MODULE(pipeline, m) {
    m.doc() = "Python bindings for the Pipeline class (Exercise 10)";

    py::class_<Pipeline>(m, "Pipeline")
        .def(py::init<int,int,int>(),
             py::arg("n_items") = 10,
             py::arg("n_consumers") = 2,
             py::arg("max_delay") = 1000)
        .def("run", &Pipeline::run);
}
