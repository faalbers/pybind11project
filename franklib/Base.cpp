#include "Base.hpp"

Base::Base(float multipier) : multipier_(multipier)
{

}

float Base::getMultiplier()
{
    return multipier_;
}

void Base::setMultiplier(float multiplier)
{
    multipier_ = multiplier;
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

std::vector<std::vector<uint8_t>> Base::makeImage()
{
    auto out = std::vector<std::vector<uint8_t>>();
    for (auto i = 0; i < 128; i++) {
        out.push_back(std::vector<uint8_t>(64));
    }
    for (auto i = 0; i < 30; i++) {
        for (auto j = 0; j < 30; j++) {
            out[i][j] = 255;
        }
    }
    return out;
}

