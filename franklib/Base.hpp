#ifndef BASE_H
#define BASE_H

#include <vector>
#include <pybind11/pybind11.h> // we can also add python types to our library

namespace py = pybind11;

class Base
{
    float multipier_;
public:
    Base(float multipier = 0.0);
    float multiply(float mult);
    std::vector<float> multiply_list(std::vector<float> items);
    py::tuple multiply_two(float one, float two);
};

#endif