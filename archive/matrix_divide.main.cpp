#include <iostream>
#include <matrix.hpp>

auto main() -> int
{
    std::cout << typeid(5 / 2.).name() << std::endl;
    return 0;
}