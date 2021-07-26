#include <pybind11/pybind11.h>
#include <pybind11/stl.h>   // included to handle vector params type mismatch corectly
#include <pybind11/numpy.h> // included get ppybind11::array
#include "franklib.hpp"
#include <vector>

namespace py = pybind11;

PYBIND11_MODULE(franklib_bindings, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    // Add function
    m.def("add", &add, "A function which adds two numbers");

    // Add class , set initialization and expose members
    py::class_<Base>( m, "PyBase" )
        .def(py::init<float>())
        // adding getter and setter
        .def_property("multiplier", &Base::getMultiplier, &Base::setMultiplier)
        .def("multiply", &Base::multiply)
        .def("multiply_list", &Base::multiply_list)
        .def("multiply_two", &Base::multiply_two)
        // Adding methode that does not exist in the class code using lambda
        // If you don't want to access Python library on your own code like franklib
        .def("multiply_two_l", [](Base &self, float one, float two) {
                return py::make_tuple(self.multiply(one), self.multiply(two));
            })
        // normal large nested array
        .def("makeImage", &Base::makeImage)
        // casting it into a numpy array is way more efficient
        .def("makeImageNumPy", [](Base &self) {
                py::array out = py::cast(self.makeImage());
                return out;
            })
        // changing a function into a property is pretty cool
        .def_property_readonly("image", [](Base &self) {
                py::array out = py::cast(self.makeImage());
                return out;
            })
        ;
}
