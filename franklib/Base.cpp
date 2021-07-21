#include "Base.hpp"

Base::Base(float multipier) : multipier_(multipier)
{

}

float Base::multiply(float mult)
{
    return (multipier_ * mult);
}

std::vector<float> Base::multiply_list(std::vector<float> items)
{
    for (auto i = 0; i < items.size(); i++)
        items[i] = multiply(items[i]);
    return items;
}

py::tuple Base::multiply_two(float one, float two)
{
    return py::make_tuple(multiply(one), multiply(two));
}