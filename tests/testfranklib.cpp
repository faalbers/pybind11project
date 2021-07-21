#include "franklib.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Result: " << add(1,2) << std::endl;
    
    Base b(10);
    std::cout << b.multiply(12.34f) << std::endl;

    std::vector<float> items = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> result = b.multiply_list(items);
    std::cout << "[";
    for (int i = 0; i < items.size(); ++i)
        std::cout << result[i] << ", ";
    std::cout << "]" << std::endl;

    return 0;
}
