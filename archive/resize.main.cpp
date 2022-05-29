#include <matrix.hpp>

auto main() -> int
{
    cortex::matrix<int> bx(0, 10, 1);

    std::cout << bx.size() << std::endl;

    for (auto& elem : bx)
        std::cout << elem << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    bx.resize(12, 10);

    std::cout << bx.size() << std::endl;

    for (auto& elem : bx)
        std::cout << elem << ", ";
    std::cout << std::endl;

    return 0;
}