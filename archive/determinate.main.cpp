#include <matrix.hpp>
#include <iostream>

auto main() -> int
{
    cortex::matrix<int> m = { { 0, 1 }
                            , { 2, 3 } };

    auto r { m.det() };

    std::cout << r << std::endl;

    return 0;
}