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
    float getMultiplier();
    void setMultiplier(float multiplier);
    float multiply(float mult);
    std::vector<float> multiply_list(std::vector<float> items);
    py::tuple multiply_two(float one, float two);
    std::vector<std::vector<uint8_t>> makeImage();
};

#endif