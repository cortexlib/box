#include <iostream>
#include <matrix.hpp>

auto main() -> int
{
    cortex::matrix<int> m { { 1, 2 }
                              , { 3, 4 }
                              , { 5, 6 }
                              , { 7, 8 }
                              , { 9, 10 }};

    for (auto& elem : m)
            std::cout << elem << ", ";
        std::cout << std::endl;
}