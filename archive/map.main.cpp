#include <box.hpp>
#include <iostream>

auto square = [](const auto& x) { return x * x; };

auto main() -> int
{
    auto xor_3 = [](const auto& x) { return x ^ 3; };

    cortex::box<int> bx { { 0, 1 }
                        , { 2, 3 }
                        , { 4, 5 }
                        , { 6, 7 }
                        , { 8, 9 } };

    for(auto& x : bx)
        std::cout << x << ", ";
    std::cout << std::endl;

    auto ibx { bx.map(square) };

    for(auto& x : ibx)
        std::cout << x << ", ";
    std::cout << std::endl;

    auto rbx { ibx.map(xor_3) };

    for(auto& x : rbx)
        std::cout << x << ", ";
    std::cout << std::endl;
}